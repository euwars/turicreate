/* Copyright © 2017 Apple Inc. All rights reserved.
 *
 * Use of this source code is governed by a BSD-3-clause license that can
 * be found in the LICENSE.txt file or at https://opensource.org/licenses/BSD-3-Clause
 */
#ifndef TURI_BOOSTED_TREES_H_
#define TURI_BOOSTED_TREES_H_
// unity xgboost
#include <toolkits/supervised_learning/xgboost.hpp>

#include <export.hpp>

namespace turi {
namespace supervised {
namespace xgboost {

/**
 * Boosted trees regression.
 *
 */
class EXPORT boosted_trees_regression: public xgboost_model {  
  
  public:
  
  /**
   * Returns the name of the model.
   */
  std::string name(void) override;

  /**
   * Set one of the options in the algorithm.
   *
   * This values is checked	against the requirements given by the option
   * instance. Options that are not present use default options.
   *
   * \param[in] opts Options to set
   */
  void init_options(const std::map<std::string,flexible_type>& _opts) override; 

  /** 
   * Configure booster from options 
   */
  void configure(void) override;
};


/**It can also be used to predict the class of
 * Boosted trees classifier.
 *
 */
class EXPORT boosted_trees_classifier: public xgboost_model {  
  
  public:
  
  /**
   * Returns the name of the model.
   */
  std::string name(void) override;
  
  /**
   * Initialize things that are specific to your model.
   *
   * \param[in] data ML-Data object created by the init function.
   *
   */
  void model_specific_init(const ml_data& data, 
                           const ml_data& valid_data) override;

  /**
   * Set one of the options in the algorithm.
   *
   * This values is checked	against the requirements given by the option
   * instance. Options that are not present use default options.
   *
   * \param[in] opts Options to set
   */
  void init_options(const std::map<std::string, flexible_type>& _opts) override;
 
  /** 
   * Configure booster from options 
   */
  void configure(void) override;

  /**
   * Set the default evaluation metric during model evaluation..
   */
  void set_default_evaluation_metric(){
    set_evaluation_metric({
        "accuracy", 
        "auc", 
        "confusion_matrix",
        "f1_score", 
        "log_loss",
        "precision", 
        "recall",  
        "roc_curve",
        }); 
  }
  
  /**
   * Set the default evaluation metric for progress tracking.
   */
  void set_default_tracking_metric(){
    set_tracking_metric({
        "accuracy", "log_loss"
       });
  }


};


}  // namespace xgboost
}  // namespace supervised
}  // namespace turi
#endif
