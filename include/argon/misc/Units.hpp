//* ArgonLib
//* Timer utility header
#pragma once
#include "api.h"

namespace argon {
    //? Typedefs
    using ms = uint32_t;

    //? Units
    constexpr uint32_t operator"" _s(long double x) {
        //? truncate just in case ediat ting
        return (uint32_t)(x * 1000);
    }
}