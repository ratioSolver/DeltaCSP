#include "deltacsp.hpp"
#include <cassert>

namespace deltacsp
{
    utils::var solver::new_var(const std::vector<std::reference_wrapper<const utils::enum_val>> &domain, std::optional<const utils::enum_val> initial_value) noexcept
    {
        const auto x = vars.size();
        std::unordered_set<const utils::enum_val *> domain_set;
        for (const auto &ev_ref : domain)
            domain_set.insert(&ev_ref.get());
        vars.emplace_back(domain_set, initial_value.has_value() ? &initial_value.value() : nullptr);
        return x;
    }
} // namespace deltacsp
