#pragma once

// --------------------------------------------------------
// Function to get the number, it accepts the types of std::optional
template <class T>
T get_number()
{
    T buff_num_val = 0;
    std::cout << "Please enter number:\n";
    // Validate if entered the number (uint)
    std::cin >> buff_num_val.value();
    if (std::cin.fail())
    {
        do
        {
            std::cout << "Only a number allowed! Please try again\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> buff_num_val.value();
        } while (std::cin.fail());
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return buff_num_val;
}

// --------------------------------------------------------
// General function to get the parameter from the list, it accepts the types of std::vector - std::string, int, float
template <typename T>
int get_from_list(T *list_to_print)
{
    std::cout << "Please select from the list by the number (below)\n";
    for (int list_count = 0; list_count < list_to_print->size(); list_count++)
    {
        std::cout << "Param #" << list_count + 1 << ": " << list_to_print->at(list_count) << " \n";
    }
    int selected = get_number<std::optional<int>>().value();
    if (selected <= 0 || selected > list_to_print->size())
        throw std::range_error("There is no such a number in the list\n");
    else
        return selected - 1;
}