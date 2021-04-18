//* ArgonLib
//* AbstractFilter control header
#pragma once
#include "api.h"

namespace argon {
    class Filter {
        public:
            Filter();
            virtual ~Filter();

            virtual void reset(void);
            virtual double filter(double p_U);
    };
}