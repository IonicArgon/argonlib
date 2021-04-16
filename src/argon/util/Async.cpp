//* ArgonLib
//* Async utility source
#include "argon/util/Async.hpp"

namespace argon {
    Async::Async() : m_async_queue{}, m_async_task{[this](){
        while (!pros::competition::is_disabled() && m_async_task.notify_take(0, TIMEOUT_MAX)) {
            auto pair = m_async_queue.front();
            m_async_queue.pop();
            pair.first();
            pros::delay(pair.second);
            std::cout << "[UTIL] Async func finished: " << pros::millis() << " ms.\n";
        }
    }}{
        std::cout << "[UTIL] Async created: " << pros::millis() << " ms.\n";
    }

    Async::~Async() {
        //? remove task from scheduler
        m_async_task.remove();
        //? empty the queue
        std::queue<func_pair>().swap(m_async_queue);
        std::cout << "[UTIL] Async destroyed: " << pros::millis() << " ms.\n";
    }

    void Async::run(std::function<void()> p_func, ms p_delay) {
        auto pair = std::make_pair(p_func, p_delay);
        m_async_queue.push(pair);
        m_async_task.notify();
        std::cout << "[UTIL] Async func added: " << pros::millis() << " ms.\n";
    }
}