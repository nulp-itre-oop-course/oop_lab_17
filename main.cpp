#include "./inc/caps_list.hpp"

int main()
{

    auto list_1 = std::make_shared<caps_list<capacitor>>();
    list_1->print_caps_list();
    auto list_dummy = std::make_shared<caps_list<dummy_cap>>();
    list_dummy->print_caps_list();
    return 0;
}
