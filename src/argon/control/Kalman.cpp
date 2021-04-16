//* ArgonLib
//* Kalman filter utility source
#include "argon/control/Kalman.hpp"

namespace argon {
    KalmanFilter::KalmanFilter(double p_R, double p_Q) : m_R{p_R}, m_Q{p_Q} {
        std::cout << "[CTRL] Kalman created: " << pros::millis() << " ms.\n";
    }

    KalmanFilter::~KalmanFilter() {
        std::cout << "[CTRL] Kalman destroyed: " << pros::millis() << " ms.\n";
    }

    double KalmanFilter::filter(double p_U) {
        //? calculate Kalman gain
        m_K = m_P * m_H / (m_H * m_P * m_H + m_R);
        //? update estimate
        m_U_hat += m_K * (p_U - m_H * m_U_hat);
        //? update error covariance
        m_P = (1 - m_K * m_H) * m_P + m_Q;
        return m_U_hat;
    }

    void KalmanFilter::reset(double p_Q) {
        m_Q = p_Q;
        m_P = 0.0;
        m_U_hat = 0.0;
        m_K = 0.0;
    }
}