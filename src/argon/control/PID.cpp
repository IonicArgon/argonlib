//* ArgonLib
//* PID control source
#include "argon/control/PID.hpp"

namespace argon {
    PID::PID(PIDGains p_gains) : m_gains{p_gains} {
        std::cout << "[CTRL] PID created: " << pros::millis() << " ms.\n";
    }

    PID::PID(PIDGains p_gains, Filter p_filter) : m_gains{p_gains} {
        set_derivative_filter(p_filter);
        std::cout << "[CTRL] PID created: " << pros::millis() << " ms.\n";
    }

    PID::~PID() {
        std::cout << "[CTRL] PID destroyed: " << pros::millis() << " ms.\n";
    }

    double PID::calculate(double p_current) {
        m_error = std::copysign(1.0, m_target) - (p_current / m_target);
        m_derivative = m_last_error - m_error;
        
        double dT = m_timer.get_Dt_last();

        m_derivative = (dT) ? m_derivative / dT : 0.0;
        m_derivative = m_filter.filter(m_derivative);

        if (m_max_error_to_integrate == 0xFFFFFFFF || std::fabs(m_error) <= m_max_error_to_integrate)
            m_integral += m_error * dT * m_gains.m_kI;
        if (m_if_integral_reset && std::copysign(1.0, m_error) != std::copysign(1.0, m_last_error))
            m_integral = 0.0;
        m_integral = std::clamp(m_integral, m_int_min, m_int_max);

        m_last_error = m_error;

        return (m_error * m_gains.m_kP) + m_integral + (m_derivative * m_gains.m_kD) + std::copysign(m_gains.m_kBias, m_error);
    }

    PID& PID::reset() {
        m_target = 0.0;
        m_error = 0.0;
        m_integral = 0.0;
        m_derivative = 0.0;
        m_last_error = 0.0;
        return *this;
    }

    PID& PID::set_gains(PIDGains p_gains) {
        m_gains = p_gains;
        return *this;
    }

    PID& PID::set_target(double p_target) {
        m_target = p_target;
        return *this;
    }

    PID& PID::set_integral_limits(double p_int_min, double p_int_max) {
        m_int_min = p_int_min;
        m_int_max = p_int_max;
        return *this;
    }

    PID& PID::set_integral_reset(bool p_reset) {
        m_if_integral_reset = p_reset;
        return *this;
    }

    PID& PID::set_max_error_to_integrate(double p_max_error) {
        m_max_error_to_integrate = p_max_error;
        return *this;
    }

    PID& PID::set_derivative_filter(Filter p_filter) {
        m_filter = p_filter;
        return *this;
    }
}