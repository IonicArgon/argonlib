#include "main.h"
#include "argon/api.hpp"

void initialize() {}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
    argon::Timer timer{};
    argon::Async async{};
    argon::EMAFilter ema{1.0};
    argon::KalmanFilter kalman{40.0, 10.0};
    argon::Filter filter{};

    argon::PID pid{{1.0, 1.0, 1.0, 10.0}, ema};
    pid.reset().set_derivative_filter(kalman).set_target(69.0);
}