#pragma once
#include "./lab17.hpp"

class capacitor
{
private:
    param capacity;
    param nom_voltage;
    param mater;
    void capacity_fill();
    void nom_voltage_fill();
    void mater_fill();

public:
    std::string name;
    capacitor();
    capacitor(std::string name);
    void set_empty();
    void cap_fill();
    void cap_print();
    void get_name();
    ~capacitor();
};

class cap_w_res : public capacitor
{
private:
public:
    param equiv_res;
    void res_fill();
    cap_w_res();
    cap_w_res(std::string name);
    ~cap_w_res();
};

class cap_w_use_f : public capacitor
{
private:
public:
    std::string fild_of_use;
    void use_case_fill();
    cap_w_use_f();
    cap_w_use_f(std::string name);
    ~cap_w_use_f();
};

class dummy_cap : public capacitor
{
public:
    bool is_dummy;
    dummy_cap();
    ~dummy_cap();
};
