/* Copyright © 2017 Apple Inc. All rights reserved.
 *
 * Use of this source code is governed by a BSD-3-clause license that can
 * be found in the LICENSE.txt file or at https://opensource.org/licenses/BSD-3-Clause
 */
#ifndef __TC_VEGA_DATA
#define __TC_VEGA_DATA

#include "histogram.hpp"
#include "transformation.hpp"

namespace turi {
  namespace visualization {
    class EXPORT vega_data {
      private:
        bool m_has_spec = false;
      protected:
        std::stringstream m_spec;

      public:
        vega_data();

        struct Image {
          size_t idx;
          std::string column;
          flex_image img;
        };

        virtual std::string create_sframe_spec(size_t i, size_t num_rows,flex_type_enum type, std::string element_title, const std::shared_ptr<transformation_output>& result);
        virtual vega_data& operator<<(const std::string&);
        virtual std::string get_data_spec(double progress);
    };
  }
}

#endif
