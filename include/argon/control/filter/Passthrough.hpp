//* ArgonLib
//* Passthrough filter utility header
#pragma once
#include "argon/control/filter/AbstractFilter.hpp"

namespace argon {
    class PassthroughFilter : public AbstractFilter {
        public:
            PassthroughFilter();
            virtual ~PassthroughFilter();

            virtual void reset();
            virtual double filter(double p_U);

        private:
            double m_U {0.0};

    };
}