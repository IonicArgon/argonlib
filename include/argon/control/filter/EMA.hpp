//* ArgonLib
//* EMA filter control header
#pragma once
#include "argon/control/filter/Filter.hpp"

namespace argon {
    class EMAFilter : public Filter {
        public:
            explicit EMAFilter(double p_alpha);
            virtual ~EMAFilter();

            void reset(void) override;
            double filter(double p_U) override;
            EMAFilter& set_alpha (double p_alpha);

        private:
            double m_alpha;
            double m_output;
            double m_last_output;

    };
}