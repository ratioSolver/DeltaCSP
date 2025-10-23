#include "deltacsp.hpp"
#include <cassert>

namespace deltacsp
{
    const bool_val bool_val::True{true};
    const bool_val bool_val::False{false};

    utils::var solver::new_sat(std::optional<bool> initial_value) noexcept
    {
        const auto x = vars.size();
        std::unordered_set<const utils::enum_val *> domain_set = {&bool_val::True, &bool_val::False};
        vars.emplace_back(std::move(domain_set), initial_value.has_value() ? (initial_value.value() ? &bool_val::True : &bool_val::False) : nullptr);
        return x;
    }

    utils::var solver::new_var(const std::vector<std::reference_wrapper<const utils::enum_val>> &domain, std::optional<const utils::enum_val> initial_value) noexcept
    {
        const auto x = vars.size();
        std::unordered_set<const utils::enum_val *> domain_set;
        for (const auto &ev_ref : domain)
            domain_set.insert(&ev_ref.get());
        vars.emplace_back(std::move(domain_set), initial_value.has_value() ? &initial_value.value() : nullptr);
        return x;
    }

    std::string to_string(const solver &s) noexcept
    {
        std::string res;
        for (size_t i = 0; i < s.vars.size(); ++i)
            res += "v" + std::to_string(i) + to_string(s.vars[i]) + "\n";
        return res;
    }
} // namespace deltacsp
