//* ArgonLib
//* Kalman filter utility header
#pragma once
#include "api.h"

namespace argon {
    class KalmanFilter {
        public:
            explicit KalmanFilter(double p_R, double p_Q);
            ~KalmanFilter();

            double filter(double p_U);
            void reset(double p_Q);

        private:
            const double m_R; // noise covariance
            const double m_H {1.00}; // measurement map scalar (we assume 1 dimensional kalman)
            double m_Q;   // covariance estimate
            double m_P {0.0}; // error covariance estimate
            double m_U_hat {0.0}; // estimated state
            double m_K {0.0}; // Kalman gain

    };
}