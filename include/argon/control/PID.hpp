//* ArgonLib
//* PID control header
#pragma once
#include <algorithm>
#include <memory>

#include "api.h"
#include "argon/control/filter/Passthrough.hpp"
#include "argon/util/Timer.hpp"

namespace argon {
    struct PIDGains {
        double m_kP;
        double m_kI;
        double m_kD;
        double m_kBias;
    };

    using filter_ptr = std::unique_ptr<AbstractFilter>;

    class PID {
        public:
            explicit PID(PIDGains p_gains);
            explicit PID(PIDGains p_gains, filter_ptr p_filter);
            ~PID();

            double calculate(double p_current);
            PID& reset(void);
            PID& set_gains(PIDGains p_gains);
            PID& set_target(double p_target);
            PID& set_integral_limits(double p_int_min, double p_int_max);
            PID& set_integral_reset(bool p_reset);
            PID& set_max_error_to_integrate(double p_max_error);
            PID& set_derivative_filter(filter_ptr p_filter);

        private:
            PIDGains m_gains;
            filter_ptr m_filter{ std::make_unique<PassthroughFilter>() };
            Timer m_timer{};

            double m_target{0.0};
            double m_error{0.0};
            double m_integral{0.0};
            double m_derivative{0.0};

            double m_last_error{0.0};
            double m_int_min{-1.0};
            double m_int_max{1.0};
            double m_max_error_to_integrate{0xFFFFFFFF};
            bool m_if_integral_reset{true};

    };
}