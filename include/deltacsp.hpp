#pragma once

#include "var.hpp"
#include <vector>
#include <functional>
#include <optional>

namespace utils
{
  using var = std::size_t;
} // namespace utils

namespace deltacsp
{
  class solver
  {
  public:
    [[nodiscard]] utils::var new_var(const std::vector<std::reference_wrapper<const utils::enum_val>> &domain, std::optional<const utils::enum_val> initial_value = std::nullopt) noexcept;

  private:
    std::vector<var> vars; // index is the variable id
  };
} // namespace deltacsp
