#include "var.hpp"
#include <cassert>

namespace deltacsp
{
    var::var(const std::unordered_set<const utils::enum_val *> &domain, const utils::enum_val *initial_value) noexcept : domain(domain), value(initial_value) { assert(initial_value == nullptr || domain.find(initial_value) != domain.end()); }
} // namespace deltacsp
