#pragma once

#include "enum.hpp"
#include <unordered_set>

namespace deltacsp
{
  class var
  {
    friend class solver;

  public:
    var(const std::unordered_set<const utils::enum_val *> &domain, const utils::enum_val *initial_value = nullptr) noexcept;

  private:
    std::unordered_set<const utils::enum_val *> domain;
    const utils::enum_val *value;
  };
} // namespace deltacsp
