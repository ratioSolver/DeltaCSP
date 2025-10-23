#include "constraint.hpp"
#include "deltacsp.hpp"

namespace deltacsp
{
    clause::clause(std::vector<utils::lit> &&lits) noexcept : lits{std::move(lits)} {}

    unsigned int clause::violations(const std::map<utils::var, const utils::enum_val &> &assignment) const noexcept
    {
        for (const auto &lit : lits)
            if (auto it = assignment.find(utils::variable(lit)); it != assignment.end())
                if (&it->second == (utils::sign(lit) ? &bool_val::True : &bool_val::False))
                    return 0; // Clause is satisfied
        return 1;             // Clause is violated
    }

    std::string clause::to_string() const noexcept
    {
        std::string result = "(";
        for (auto it = lits.begin(); it != lits.end(); ++it)
        {
            result += utils::to_string(*it);
            if (it + 1 != lits.end())
                result += " ∨ ";
        }
        result += ")";
        return result;
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

    std::string eq::to_string() const noexcept { return "v" + std::to_string(var1) + " = v" + std::to_string(var2); }

    neq::neq(utils::var var1, utils::var var2) noexcept : var1{var1}, var2{var2} {}

    unsigned int neq::violations(const std::map<utils::var, const utils::enum_val &> &assignment) const noexcept
    {
        auto it1 = assignment.find(var1);
        auto it2 = assignment.find(var2);

        if (it1 == assignment.end() || it2 == assignment.end())
            return 0;

        return (&it1->second == &it2->second) ? 1 : 0;
    }

    std::string neq::to_string() const noexcept { return "v" + std::to_string(var1) + " ≠ v" + std::to_string(var2); }
} // namespace deltacsp
