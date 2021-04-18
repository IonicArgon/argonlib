//* ArgonLib
//* EMA filter control header
#pragma once
#include "argon/control/filter/AbstractFilter.hpp"

namespace argon {
    class EMAFilter : public AbstractFilter {
        public:
            explicit EMAFilter(double p_alpha);
            virtual ~EMAFilter();

            void reset(void) override;
            double filter(double p_U) override;

        private:
            const double m_alpha;
            double m_output;
            double m_last_output;

    };
}