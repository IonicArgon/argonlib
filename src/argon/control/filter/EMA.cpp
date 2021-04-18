//* ArgonLib
//* EMA filter control source
#include "argon/control/filter/EMA.hpp"

namespace argon {
    EMAFilter::EMAFilter(double p_alpha) : m_alpha{p_alpha} {
        std::cout << "[CTRL] EMAFilter created: " << pros::millis() << " ms.\n";
    }

    EMAFilter::~EMAFilter() {
        std::cout << "[UTIL] EMAFilter destroyed: " << pros::millis() << " ms.\n";
    }

    void EMAFilter::reset() {
        m_output = 0.0;
        m_last_output = 0.0;
    }

    double EMAFilter::filter(double p_U) {
        m_output = m_alpha * p_U + (1.0 - m_alpha) * m_last_output;
        m_last_output = m_output;
        return m_output;
    }
}