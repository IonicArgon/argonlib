//* ArgonLib
//* Timer utility header
#pragma once
#include "api.h"
#include "argon/misc/Units.hpp"

namespace argon {
    class Timer {
        public:
            Timer();
            ~Timer();

            void set_mark(void);
            void clear_mark(void);
            ms get_curr(void);
            ms get_Dt_last(void);
            ms get_Dt_start(void);
            ms get_Dt_mark(void);
        
        private:
            const ms m_start_time;
            ms m_last_called;
            ms m_mark;

    };
}