//* ArgonLib
//* Async utility source
#include "argon/util/Async.hpp"

namespace argon {
    Async::Async() : async_queue{}, async_task{[this](){
        while (!pros::competition::is_disabled() && async_task.notify_take(0, TIMEOUT_MAX)) {
            auto pair = async_queue.front();
            async_queue.pop();
            pair.first();
            pros::delay(pair.second);
        }
    }}{
        std::cout << "[UTIL] Async created: " << pros::millis() << " ms.\n";
    }

    Async::~Async() {
        //? remove task from scheduler
        async_task.remove();
        //? empty the queue
        std::queue<func_pair>().swap(async_queue);
        std::cout << "[UTIL] Async destroyed: " << pros::millis() << " ms.\n";
    }

    void Async::run(std::function<void()> func, ms delay) {
        auto pair = std::make_pair(func, delay);
        async_queue.push(pair);
        async_task.notify();
    }
}