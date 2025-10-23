#pragma once

#include "lit.hpp"
#include "enum.hpp"
#include <vector>
#include <map>

namespace deltacsp
{
  class constraint
  {
  public:
    virtual ~constraint() = default;

    virtual unsigned int violations(const std::map<utils::var, const utils::enum_val &> &assignment) const noexcept = 0;

    virtual std::string to_string() const noexcept = 0;
  };

  class clause final : public constraint
  {
  public:
    clause(std::vector<utils::lit> &&lits) noexcept;

    unsigned int violations(const std::map<utils::var, const utils::enum_val &> &assignment) const noexcept override;

    std::string to_string() const noexcept override;

  private:
    std::vector<utils::lit> lits;
  };

  class eq final : public constraint
  {
  public:
    eq(utils::var var1, utils::var var2) noexcept;

    unsigned int violations(const std::map<utils::var, const utils::enum_val &> &assignment) const noexcept override;

    std::string to_string() const noexcept override;

  private:
    utils::var var1;
    utils::var var2;
  };

  class neq final : public constraint
  {
  public:
    neq(utils::var var1, utils::var var2) noexcept;

    unsigned int violations(const std::map<utils::var, const utils::enum_val &> &assignment) const noexcept override;

    std::string to_string() const noexcept override;

  private:
    utils::var var1;
    utils::var var2;
  };
} // namespace deltacsp
