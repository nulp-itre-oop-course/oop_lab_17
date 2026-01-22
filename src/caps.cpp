#include "../inc/caps.hpp"

// --------------------------------------------------------
// Capacity filling method
void capacitor::capacity_fill()
{
    try
    {
        // Get capacity values
        std::cout << "Capacity value. ";
        double temp = get_number<std::optional<double>>().value();
        if (temp <= 0)
            throw std::runtime_error("Capacity incorrect\n");
        else
            this->capacity.value = temp;
        std::cout << "Choose capacity units. ";
        this->capacity.units = caps_lists.units_list.at(get_from_list<std::vector<std::string>>(&caps_lists.units_list));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "\n__________________________\nPlease enter the capacity again\n";
        capacity_fill();
    }
}

// --------------------------------------------------------
// Voltage filling method
void capacitor::nom_voltage_fill()
{
    try
    {
        // Get voltage values
        std::cout << "Nominal voltage value. ";
        double temp = get_number<std::optional<double>>().value();
        if (temp <= 0)
            throw std::runtime_error("Capacity incorrect\n");
        else
            this->nom_voltage.value = temp;
        std::cout << "Choose voltage units. ";
        this->nom_voltage.units = caps_lists.voltage_units_list.at(get_from_list<std::vector<std::string>>(&caps_lists.voltage_units_list));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "\n__________________________\nPlease enter nominal voltage again\n";
        nom_voltage_fill();
    }
}

// --------------------------------------------------------
// Material filling method
void capacitor::mater_fill()
{
    try
    {
        // Get material
        std::cout << "Choose capacitor material. ";
        this->mater.units = caps_lists.mater_list.at(get_from_list<std::vector<std::string>>(&caps_lists.mater_list));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "\n__________________________\nPlease enter material again\n";
        mater_fill();
    }
}

// --------------------------------------------------------
// Method to set container empty
void capacitor::set_empty()
{
    this->name = "default_empty";
    this->capacity.value = 0;
    this->capacity.units = "empty";
    this->nom_voltage.value = 0;
    this->nom_voltage.units = "empty";
    this->mater.units = "empty";
}

// --------------------------------------------------------
// Constructor
capacitor::capacitor()
{
    this->set_empty();
}

// --------------------------------------------------------
// Constructor
capacitor::capacitor(std::string name) : name(name)
{
    std::cout << "\nEnter data to " << this->name << "\n";
    this->cap_fill();
}

// --------------------------------------------------------
// Capacitor filling method
void capacitor::cap_fill()
{
    try
    {
        capacity_fill();
        nom_voltage_fill();
        mater_fill();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

// --------------------------------------------------------
// Capacitor print method
void capacitor::cap_print()
{
    std::cout << "Capacitor " << this->name << ": "
              << "Capacity: " << this->capacity.value.value() << " " << this->capacity.units
              << ", Nominal voltage: " << this->nom_voltage.value.value() << " " << this->nom_voltage.units
              << ", Material: " << this->mater.units << "\n";
}

// --------------------------------------------------------
// Method to get the capacitor name
void capacitor::get_name()
{
    std::cout << "Cap name: " << this->name << "\n";
}

// --------------------------------------------------------
// Destructor
capacitor::~capacitor()
{
}

// -----------------------------------------------------------------------------
// Child class with equivalent resistance

// --------------------------------------------------------
// Method to fill the equiv resistance
void cap_w_res::res_fill()
{
    try
    {
        // Get resistance value
        std::cout << "Equivalent resistance value. ";
        double temp = get_number<std::optional<double>>().value();
        if (temp <= 0)
            throw std::runtime_error("Value incorrect\n");
        else
            this->equiv_res.value = temp;
        std::cout << "Choose units. ";
        this->equiv_res.units = caps_lists.eq_res_units_list.at(get_from_list<std::vector<std::string>>(&caps_lists.eq_res_units_list));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "\n__________________________\nPlease enter equivalent resistance again\n";
        res_fill();
    }
}

// --------------------------------------------------------
// Constuctor
cap_w_res::cap_w_res()
{
    this->set_empty();
    this->equiv_res.value = 0;
    this->equiv_res.units = "empty";
}

// --------------------------------------------------------
// Constuctor with argument
cap_w_res::cap_w_res(std::string name)
{
    this->name = name;
    this->cap_fill();
    this->res_fill();
}

// --------------------------------------------------------
// Destructor
cap_w_res::~cap_w_res()
{
}

// -----------------------------------------------------------------------------
// Child class with fild of use

// --------------------------------------------------------
// Method to fill the
void cap_w_use_f::use_case_fill()
{
    try
    {
        // Get material
        std::cout << "Choose capacitor use case. ";
        this->fild_of_use = caps_lists.use_case_list.at(get_from_list<std::vector<std::string>>(&caps_lists.use_case_list));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "\n__________________________\nPlease enter use case again\n";
        use_case_fill();
    }
}

// --------------------------------------------------------
// Constuctor
cap_w_use_f::cap_w_use_f()
{
    this->set_empty();
    this->fild_of_use = "empty";
}

// --------------------------------------------------------
// Constuctor with argument
cap_w_use_f::cap_w_use_f(std::string name)
{
    this->name = name;
    this->set_empty();
    this->fild_of_use = "empty";
}

// --------------------------------------------------------
// Destructor
cap_w_use_f::~cap_w_use_f()
{
}

// -----------------------------------------------------------------------------
// Child class with fild of use

// --------------------------------------------------------
// Constuctor
dummy_cap::dummy_cap()
{
    this->set_empty();
    this->name = "dummy";
}

// --------------------------------------------------------
// Destructor
dummy_cap::~dummy_cap()
{
}
