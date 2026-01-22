#pragma once

#include <iostream>
#include <exception>
#include <optional>
#include <vector>
#include <limits>
#include <memory>
#include "general.hpp"

struct param
{
    std::optional<double> value;
    std::string units;
};

struct
{
    std::vector<std::string> units_list = {"F", "uF", "nF", "pF"};
    std::vector<std::string> voltage_units_list = {"uV", "mV", "V", "kV"};
    std::vector<std::string> mater_list = {"tantal", "ceramic", "electrolitic"};
    std::vector<std::string> use_case_list = {"industial", "medical", "aero-space"};
    std::vector<std::string> eq_res_units_list = {"Ohm", "kOhm", "MOhm"}; 
} caps_lists;

