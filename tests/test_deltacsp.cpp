#include "deltacsp.hpp"
#include "logging.hpp"
#include <cassert>

class test_enum_val : public utils::enum_val
{
public:
    explicit test_enum_val(std::string name) : name(std::move(name)) {}

    [[nodiscard]] const std::string &get_name() const { return name; }

private:
    std::string name;
};

void test0()
{
    deltacsp::solver s;
    const auto v1 = s.new_sat();
    const auto v2 = s.new_sat();
    LOG_DEBUG(deltacsp::to_string(s));
}

int main()
{
    test0();

    return 0;
}
