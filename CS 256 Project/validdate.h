#ifndef VALIDATEREGEX_H
#define VALIDATEREGEX_H

#include <string>
#include <regex>

bool validateDate(std::string date);
std::string getValueAfterValidate(std::string value, std::function<bool(std::string)> validateFunc);

bool validateDate(std::string date)
{
    std::regex date_pattern("(^(((0[1-9]|1[0-9]|2[0-8])[\\/](0[1-9]|1[012]))|((29|30|31)[\\/](0[13578]|1[02]))|((29|30)[\\/](0[4,6,9]|11)))[\\/](19|[2-9][0-9])\\d\\d$)|(^29[\\/]02[\\/](19|[2-9][0-9])(00|04|08|12|16|20|24|28|32|36|40|44|48|52|56|60|64|68|72|76|80|84|88|92|96)$)");
    return std::regex_match(date, date_pattern);
}

std::string getValueAfterValidate(std::string value, std::function<bool(std::string)> validateFunc)
{
    while (true)
    {
        if (validateFunc(value))
        {
            return value;
        }
        std::cout << "---------------------------------------------" << '\n';
        std::cout << "     ERROR! wrong format (dd/mm/yyyy).       " << '\n';
        std::cout << "---------------------------------------------" << '\n';
        std::cout << "     Please enter again: ";
        std::getline(std::cin, value);
    }
}

#endif