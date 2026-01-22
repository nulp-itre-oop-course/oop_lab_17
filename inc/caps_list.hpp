#pragma once
#include "../inc/caps.hpp"

template <class T>
class caps_list
{
private:
    std::vector<T> capacitor_list;

public:
    caps_list()
    {
        std::cout << "How many caps do you want to add?\n";
        capacitor_list.resize(get_number<std::optional<int>>().value());
    }

    void print_caps_list()
    {
        for (int i = 0; i < capacitor_list.size(); i++)
        {
            capacitor_list.at(i).get_name();
        }
    }

    ~caps_list() {};
};

template <>
class caps_list<dummy_cap>
{
private:
    std::vector<dummy_cap> capacitor_list;

public:
    caps_list()
    {
        std::cout << "This is the dummy class, it holds 3 instances of capacitor dummy class\n";
        capacitor_list.resize(3);
    };
    void print_caps_list()
    {
        for (int i = 0; i < capacitor_list.size(); i++)
        {
            capacitor_list.at(i).get_name();
        }
    }

    ~caps_list() {};
};
