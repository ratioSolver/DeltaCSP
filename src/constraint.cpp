#include "constraint.hpp"
#include "deltacsp.hpp"

namespace deltacsp
{
    clause::clause(std::vector<utils::lit> lits) noexcept : lits{std::move(lits)} {}

    unsigned int clause::violations(const std::map<utils::var, const utils::enum_val &> &assignment) const noexcept
    {
        for (const auto &lit : lits)
            if (auto it = assignment.find(variable(lit)); it != assignment.end())
                if (&it->second == (sign(lit) ? &solver::True : &solver::False))
                    return 0; // Clause is satisfied
        return 1;             // Clause is violated
    }

    eq::eq(utils::var var1, utils::var var2) noexcept : var1{var1}, var2{var2} {}

    unsigned int eq::violations(const std::map<utils::var, const utils::enum_val &> &assignment) const noexcept
    {
        auto it1 = assignment.find(var1);
        auto it2 = assignment.find(var2);

        if (it1 == assignment.end() || it2 == assignment.end())
            return 0;

        return (&it1->second != &it2->second) ? 1 : 0;
    }

    neq::neq(utils::var var1, utils::var var2) noexcept : var1{var1}, var2{var2} {}

    unsigned int neq::violations(const std::map<utils::var, const utils::enum_val &> &assignment) const noexcept
    {
        auto it1 = assignment.find(var1);
        auto it2 = assignment.find(var2);

        if (it1 == assignment.end() || it2 == assignment.end())
            return 0;

        return (&it1->second == &it2->second) ? 1 : 0;
    }
} // namespace deltacsp
