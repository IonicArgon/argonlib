//* ArgonLib
//* Timer utility source
#include "argon/util/Timer.hpp"

namespace argon {
    Timer::Timer() : m_start_time{pros::millis()}, m_last_called{m_start_time}, m_mark{0} {
        std::cout << "[UTIL] Timer created: " << m_start_time << " ms.\n";
    }

    Timer::~Timer() {
        std::cout << "[UTIL] Timer destroyed: " << pros::millis() << " ms.\n";
    }

    void Timer::set_mark() {
        m_mark = pros::millis();
        std::cout << "[UTIL] Timer marker set: " << m_mark << " ms.\n";
    }

    void Timer::clear_mark() {
        m_mark = 0;
        std::cout << "[UTIL] Timer marker cleared: " << pros::millis() << " ms.\n";
    }

    ms Timer::get_curr() {
        return pros::millis();
    }

    ms Timer::get_Dt_last() {
        ms Dt = pros::millis() - m_last_called;
        m_last_called = pros::millis();
        return Dt;
    }

    ms Timer::get_Dt_start() {
        return pros::millis() - m_start_time;
    }

    ms Timer::get_Dt_mark() {
        return pros::millis() - m_mark;
    }
}