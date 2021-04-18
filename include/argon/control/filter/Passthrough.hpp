//* ArgonLib
//* Passthrough filter control header
#pragma once
#include "argon/control/filter/AbstractFilter.hpp"

namespace argon {
    class PassthroughFilter : public AbstractFilter {
        public:
            PassthroughFilter();
            virtual ~PassthroughFilter();

            void reset(void) override;
            double filter(double p_U) override;

        private:
            double m_U {0.0};

    };
}