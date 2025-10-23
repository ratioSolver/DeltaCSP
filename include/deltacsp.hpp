#pragma once

#include "var.hpp"
#include "constraint.hpp"
#include <vector>
#include <functional>
#include <optional>

namespace deltacsp
{
  class solver
  {
  public:
    static const utils::enum_val True;
    static const utils::enum_val False;

    [[nodiscard]] utils::var new_sat(std::optional<bool> initial_value = std::nullopt) noexcept;
    [[nodiscard]] utils::var new_var(const std::vector<std::reference_wrapper<const utils::enum_val>> &domain, std::optional<const utils::enum_val> initial_value = std::nullopt) noexcept;

  private:
    std::vector<var> vars; // index is the variable id
  };
} // namespace deltacsp
