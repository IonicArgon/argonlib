//* ArgonLib
//* Passthrough filter utility source
#include "argon/control/filter/Passthrough.hpp"

namespace argon {
    PassthroughFilter::PassthroughFilter() {
        std::cout << "[CTRL] PassthroughFilter created: " << pros::millis() << " ms.\n";
    }

    PassthroughFilter::~PassthroughFilter() {
        std::cout << "[UTIL] PassthroughFilter destroyed: " << pros::millis() << " ms.\n";
    }

    void PassthroughFilter::reset() {
        m_U = 0.0;
    }

    double PassthroughFilter::filter(double p_U) {
        m_U = p_U;
        return m_U;
    }
}