//* ArgonLib
//* AbstractFilter control header
#pragma once
#include "api.h"

namespace argon {
    class AbstractFilter {
        public:
            AbstractFilter();
            virtual ~AbstractFilter();

            virtual void reset() = 0;
            virtual double filter(double p_U) = 0;
    };
}