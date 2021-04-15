//* ArgonLib
//* Async utility header
#pragma once
#include <functional>
#include <queue>
#include <utility>

#include "api.h"
#include "argon/misc/Units.hpp"

namespace argon {
    using func_pair = std::pair<std::function<void()>, ms>;

    class Async {
        public:
            Async();
            ~Async();

            void run(std::function<void()> func, ms delay = 1);

        private:
            std::queue<func_pair> async_queue;
            pros::Task async_task;

    };
}