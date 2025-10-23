#pragma once

#include "var.hpp"
#include "constraint.hpp"
#include <vector>
#include <functional>
#include <optional>
#include <unordered_set>
#include <memory>

namespace deltacsp
{
  class enum_val : public utils::enum_val
  {
  public:
    virtual ~enum_val() = default;

    virtual std::string to_string() const = 0;
  };

  class bool_val : public enum_val
  {
  public:
    static const bool_val True;
    static const bool_val False;

    bool_val(bool v) : value(v) {}

    bool get_value() const { return value; }

    std::string to_string() const override { return value ? "True" : "False"; }

  private:
    bool value;
  };

  class solver
  {
  public:
    [[nodiscard]] utils::var new_sat(std::optional<bool> initial_value = std::nullopt) noexcept;
    [[nodiscard]] utils::var new_var(const std::vector<std::reference_wrapper<const utils::enum_val>> &domain, std::optional<const utils::enum_val> initial_value = std::nullopt) noexcept;

    void add_constraint(const std::shared_ptr<constraint> &c) noexcept;
    void remove_constraint(const std::shared_ptr<constraint> &c) noexcept;

    friend std::string to_string(const solver &s) noexcept;

  private:
    std::map<utils::var, const utils::enum_val &> get_current_assignment() const noexcept;

  private:
    std::vector<var> vars;                                       // index is the variable id
    std::unordered_set<std::shared_ptr<constraint>> constraints; // all constraints in the solver
  };

  [[nodiscard]] std::string to_string(const solver &s) noexcept;
} // namespace deltacsp
