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

            void run(std::function<void()> p_func, ms p_delay = 1);

        private:
            std::queue<func_pair> m_async_queue;
            pros::Task m_async_task;

    };
}