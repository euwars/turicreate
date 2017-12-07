/* Copyright © 2017 Apple Inc. All rights reserved.
 *
 * Use of this source code is governed by a BSD-3-clause license that can
 * be found in the LICENSE.txt file or at https://opensource.org/licenses/BSD-3-Clause
 */
#include <unity/lib/gl_sarray.hpp>
#include <unity/lib/gl_sframe.hpp>
#include <unity/toolkits/coreml_export/mlmodel_include.hpp>
#include <unity/toolkits/coreml_export/xgboost_exporter.hpp>
#include <unity/toolkits/coreml_export/mldata_exporter.hpp>
#include <unity/toolkits/coreml_export/coreml_export_utils.hpp>

namespace turi {


// Returns the hexadecimal represenation of float in little endian
static std::string float_to_hexadecimal(float value) {
  unsigned char* p = (unsigned char*)(&value);
  char ret[9];

  // check if we are little endian
  bool is_little_endian = true;
  {
    int test = 1;
    is_little_endian = ((unsigned char*)(&test))[0] != NULL;
  }
  if (is_little_endian) {
    snprintf(ret, 9, "%02X%02X%02X%02X", p[0],p[1],p[2],p[3]);
  } else {
    snprintf(ret, 9, "%02X%02X%02X%02X", p[3],p[2],p[1],p[0]);
  }
  ret[8] = '\0';
  return std::string(ret);
}

// Returns the hexadecimal represenation of float in little endian
static double hexadecimal_to_float(std::string hex) {
  float value = 0;
  unsigned char *p = (unsigned char*)(&value);

  // check if we are little endian
  bool is_little_endian = true;
  {
    int test = 1;
    is_little_endian = ((unsigned char*)(&test))[0] != NULL;
  }

  /*    int val[8];
        char digits[17] = "0123456789ABCDEF";
        for(int i = 0; i < 8; ++i) {
        val[i] = int(std::find(digits, digits+16, hex[i]) - digits);
        }

        for(int i = 0; i < 4; ++i) {
        p[i] = val[2*i] + 16 * val[2+i + 1];
        }
  */
  if (is_little_endian) {
    sscanf(hex.c_str(), "%02X%02X%02X%02X", &(p[0]), &(p[1]), &(p[2]), &(p[3]));

    //std::istringstream(hex) >> std::hex >> p[3] >> p[2] >> p[1] >> p[0];
  } else {
    //std::istringstream(hex) >> std::hex >> p[0] >> p[1] >> p[2] >> p[3];
    sscanf(hex.c_str(), "%02X%02X%02X%02X", &(p[3]), &(p[2]), &(p[1]), &(p[0]));
  }

  // DASSERT_EQ(out, hex.size());

#ifndef NDEBUG
  {
    std::string test_hex = float_to_hexadecimal(value);
    DASSERT_EQ(test_hex, hex);
  }
#endif

  return value;
}


void export_xgboost_model(const std::string& filename,
    const std::shared_ptr<ml_metadata>& metadata,
    const std::vector<std::string>& trees,
    bool is_classifier, bool is_random_forest,
    const std::map<std::string, flexible_type>& context) {

  CoreML::Pipeline pipeline(
      is_classifier
      ? CoreML::Pipeline::Classifier(
            metadata->target_column_name(),
            metadata->target_column_name() + "Probability",
            "")
      : CoreML::Pipeline::Regressor(
          metadata->target_column_name(),
          ""));

  // set up the pipeline from metadata.
  setup_pipeline_from_mldata(pipeline, metadata);
  std::map<size_t, size_t> dict_indices;
  for (size_t c = 0; c < metadata->num_columns(); c++) {
    if (metadata->column_type(c) == flex_type_enum::DICT) {
      for (size_t i = 0; i < metadata->column_size(c); i++) {
          dict_indices[metadata->global_index_offset(c) + i] = 1;
      }
    }
  }

  // Now set up the tree model.
  auto target_output_data_type = CoreML::FeatureType::Double();
  std::string target_additional_name;
  auto target_additional_data_type = CoreML::FeatureType::Double();


  // Put it into an sarray in order to
  gl_sarray ft_data(flex_list(trees.begin(), trees.end()));
  ft_data = ft_data.astype(flex_type_enum::DICT).unpack()["X.vertices"];

  std::shared_ptr<CoreML::TreeEnsembleBase> tree_ensemble;

  size_t num_dimensions = 0;

  if(!is_classifier) {
    tree_ensemble.reset(new CoreML::TreeEnsembleRegressor(
        metadata->target_column_name(),
        "Tree Ensemble",
        "Tree Ensemble"));

    num_dimensions = 1;

    // This default value of 0.5 is one of the parameters to the xgboost
    // model (base_value), but as far as I can tell, Turi Create does not
    // expose it so it's safe to set it to the default value.
    tree_ensemble->setDefaultPredictionValue(0.5);
    target_output_data_type = CoreML::FeatureType::Double();
    target_additional_data_type = CoreML::FeatureType::Double();

  } else {

    auto ti = metadata->target_indexer();

    size_t num_classes = ti->indexed_column_size();

    auto tc = new CoreML::TreeEnsembleClassifier(
        metadata->target_column_name(),
        metadata->target_column_name() + "Probability",
        "Tree Ensemble",
        "Tree Ensemble");

    target_additional_name = metadata->target_column_name() + "Probability";

    if(num_classes == 2) {
      num_dimensions = 1;
      tc->setPostEvaluationTransform
        (CoreML::PostEvaluationTransform::Regression_Logistic);
    } else {
      num_dimensions = num_classes;
      tc->setPostEvaluationTransform(
          CoreML::PostEvaluationTransform::Classification_SoftMax);
    }

    if(metadata->target_column_type() == flex_type_enum::STRING) {
      std::vector<std::string> classes(num_classes);
      for(size_t i = 0; i < num_classes; ++i) {
        classes[i] = ti->map_index_to_value(i).get<std::string>();
      }
      tc->setOutputClassList(classes);
      target_output_data_type = CoreML::FeatureType::String();
      target_additional_data_type = CoreML::FeatureType::Dictionary(MLDictionaryFeatureTypeKeyType_stringKeyType);
    } else if(metadata->target_column_type() == flex_type_enum::INTEGER) {
      std::vector<int64_t> classes(num_classes);
      for(size_t i = 0; i < num_classes; ++i) {
        classes[i] = ti->map_index_to_value(i).get<flex_int>();
      }
      tc->setOutputClassList(classes);
      target_output_data_type = CoreML::FeatureType::Int64();
      target_additional_data_type = CoreML::FeatureType::Dictionary(MLDictionaryFeatureTypeKeyType_int64KeyType);
    } else {
      log_and_throw("Only exporting classifiers with an output class "
                    "of integer or string is supported.");
    }
    tc->setDefaultPredictionValue(std::vector<double>(num_dimensions, 0));

    tree_ensemble.reset(tc);
  }

  size_t tree_counter = 0;
  for(const flexible_type& ft : ft_data.range_iterator()) {
    size_t tree_id = tree_counter; // Start from 0
    ++tree_counter;
    for(const flexible_type& node_dict_really_raw : ft.get<flex_list>() ) {
      const flex_dict& node_dict_raw = node_dict_really_raw.get<flex_dict>();

      std::map<flex_string, flexible_type> node_dict(node_dict_raw.begin(), node_dict_raw.end());
      flex_int node_id = node_dict.at("id").get<flex_int>();
      flex_string type = node_dict.at("type").get<flex_string>();
      flex_float value = node_dict.at("value").get<flex_float>();

      // Get the exact non-lossy double value and use that.  But it's stored as an
      flex_float exact_value = hexadecimal_to_float(node_dict.at("value_hexadecimal").get<flex_string>());

      if(type == "leaf") {
        if(is_random_forest) {
          size_t num_classes = metadata->target_indexer()->indexed_column_size();
          size_t num_trees_per_class;
          if (num_classes <= 2) {
            num_trees_per_class = trees.size();
          } else {
            num_trees_per_class = trees.size() / num_classes;
          }
          exact_value /= num_trees_per_class;
        }
        tree_ensemble->setupLeafNode(tree_id, node_id,
                                     { {tree_id % num_dimensions, exact_value} });
      } else {
        flex_int yes_child = node_dict.at("yes_child").get<flex_int>();
        flex_int no_child = node_dict.at("no_child").get<flex_int>();
        flex_int missing_child = node_dict.at("missing_child").get<flex_int>();
        flex_string feature_name = node_dict.at("name").get<flex_string>();
        flex_string feature_type = node_dict.at("type").get<flex_string>();

        size_t feature_index = 0;

        size_t n = sscanf(feature_name.c_str(), "{%zd}\0", &feature_index);
        ASSERT_EQ(n, 1);

        // This means that we need to swap out the no and the missing columns.
        if(feature_type == "indicator") {
          tree_ensemble->setupBranchNode(
              tree_id,
              node_id,
              size_t(feature_index),
              CoreML::BranchMode::BranchOnValueEqual,
              1,
              yes_child, missing_child);
        // For dictionaries, set the threshold separately
        } else if(dict_indices.find(size_t(feature_index)) != dict_indices.end()) {
          tree_ensemble->setupBranchNode(
              tree_id,
              node_id,
              size_t(feature_index),
              CoreML::BranchMode::BranchOnValueLessThanEqual,
              0,
              missing_child, no_child);
        } else {
          tree_ensemble->setupBranchNode(
              tree_id,
              node_id,
              size_t(feature_index),
              CoreML::BranchMode::BranchOnValueLessThanEqual,
              exact_value,
              yes_child, no_child);
        }
      }
    }
  }

  // This output is provided by __vectorized_features__.
  tree_ensemble->addInput("__vectorized_features__",
                          CoreML::FeatureType::Array({metadata->num_dimensions()}));
  tree_ensemble->addOutput(metadata->target_column_name(), target_output_data_type);
  if(is_classifier)
    tree_ensemble->addOutput(target_additional_name, target_additional_data_type);
  tree_ensemble->finish();

  pipeline.add(*tree_ensemble);
  pipeline.addOutput(metadata->target_column_name(), target_output_data_type);
  if(is_classifier)
    pipeline.addOutput(target_additional_name, target_additional_data_type);

  // Add metadata
  add_metadata(pipeline.m_spec, context);

  CoreML::Result r = pipeline.save(filename);
  if(!r.good()) {
    log_and_throw("Could not export model: " + r.message());
  }
}

} // End namespace.

