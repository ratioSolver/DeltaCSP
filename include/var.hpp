#pragma once

#include "enum.hpp"
#include <unordered_set>
#include <string>

namespace deltacsp
{
  class var
  {
    friend class solver;

  public:
    var(const std::unordered_set<const utils::enum_val *> &&dom, const utils::enum_val *init_v = nullptr) noexcept;

    friend std::string to_string(const var &x) noexcept;

  private:
    std::unordered_set<const utils::enum_val *> domain;
    const utils::enum_val *value;
  };

  [[nodiscard]] std::string to_string(const var &x) noexcept;
} // namespace deltacsp
