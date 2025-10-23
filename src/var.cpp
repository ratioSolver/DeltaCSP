#include "var.hpp"
#include <cassert>

namespace deltacsp
{
    var::var(const std::unordered_set<const utils::enum_val *> &&dom, const utils::enum_val *init_v) noexcept : domain(std::move(dom)), value(init_v) { assert(init_v == nullptr || domain.find(init_v) != domain.end()); }
} // namespace deltacsp
