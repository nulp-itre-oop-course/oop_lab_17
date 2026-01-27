#pragma once
#include "../inc/caps.hpp"

// T_1 is the type of data to be inserted in special field (equivalent resistance, field of use)
// T_2 sets the class that gonna be stored
template <typename T_1, class T_2>
class caps_list
{
private:
    std::vector<T_2> capacitor_list;

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

template <typename T>
class caps_list<T, dummy_cap>
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

template <>
class caps_list<int, cap_w_res>
{
private:
    std::vector<cap_w_res> capacitor_list;

public:
    caps_list()
    {
        std::cout << "How many caps do you want to add?\n";
        capacitor_list.resize(get_number<std::optional<int>>().value());
        std::cout << "Enter the default value for resistance (in ohm)\n";
        auto defaul_val = get_number<std::optional<int>>().value();
        for (int i = 0; i < capacitor_list.size(); i++)
        {
            capacitor_list.at(i).equiv_res.value = defaul_val;
            capacitor_list.at(i).equiv_res.units = "ohm";
        }
    };
    void print_caps_list()
    {
        for (int i = 0; i < capacitor_list.size(); i++)
        {
            capacitor_list.at(i).get_name();
            std::cout << "Resistance: " << this->capacitor_list.at(i).equiv_res.value.value() << " " << this->capacitor_list.at(i).equiv_res.units << "\n";
        }
    }
    ~caps_list() {};
};

template <>
class caps_list<std::string, cap_w_use_f>
{
private:
    std::vector<cap_w_use_f> capacitor_list;

public:
    caps_list()
    {
        std::cout << "How many caps do you want to add?\n";
        capacitor_list.resize(get_number<std::optional<int>>().value());
        std::cout << "Chose the default use field:\n";
        std::string use_field = caps_lists.use_case_list.at(get_from_list<std::vector<std::string>>(&caps_lists.use_case_list));
        for (int i = 0; i < capacitor_list.size(); i++)
        {
            capacitor_list.at(i).fild_of_use = use_field;
        }
    };
    void print_caps_list()
    {
        for (int i = 0; i < capacitor_list.size(); i++)
        {
            capacitor_list.at(i).get_name();
            std::cout << "Field of use: " << this->capacitor_list.at(i).fild_of_use << "\n";
        }
    }
    ~caps_list() {};
};
