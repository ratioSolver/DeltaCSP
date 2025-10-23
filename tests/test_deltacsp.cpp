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
    test_enum_val ev1("A");
    test_enum_val ev2("B");
    test_enum_val ev3("C");
    auto var1 = s.new_var({ev1, ev2});
    auto var2 = s.new_var({ev2, ev3});
}

int main()
{
    test0();

    return 0;
}
