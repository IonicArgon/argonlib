#include "main.h"
#include "argon/api.hpp"

void initialize() {}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
    argon::Timer timer{};
    argon::Async async{};
    argon::KalmanFilter kalman{40.0, 10.0};
    argon::PassthroughFilter passthrough{};
}