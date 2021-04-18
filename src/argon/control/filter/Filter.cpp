//* ArgonLib
//* AbstractFilter control source
#include "argon/control/filter/Filter.hpp"

namespace argon {
    Filter::Filter() = default;
    Filter::~Filter() = default;

    void Filter::reset() {}
    double Filter::filter(double p_U) {return p_U;}
}