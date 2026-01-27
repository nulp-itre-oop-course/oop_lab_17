#include "./inc/caps_list.hpp"

int main()
{

    auto list_1 = std::make_shared<caps_list<int, capacitor>>();
    list_1->print_caps_list();
    auto list_dummy = std::make_shared<caps_list<int, dummy_cap>>();
    list_dummy->print_caps_list();
    auto list_res = std::make_shared<caps_list<int, cap_w_res>>();
    list_res->print_caps_list();
    auto list_field = std::make_shared<caps_list<std::string, cap_w_use_f>>();
    list_field->print_caps_list();
    return 0;
}
