#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

class Date
{
private:
    unsigned short day;
    unsigned short month;
    unsigned short year;

public:
    // CONSTRUCTORS
    Date()
    {

        this->day = 0;
        this->month = 0;
        this->year = 9999;
        return;
    }

    Date(const std::string date)
    {
        std::stringstream ss(date);
        char delimiter;
        ss >> day >> delimiter >> month >> delimiter >> year;
        this->day = day;
        this->month = month;
        this->year = year;
        return;
    }

    ~Date()
    {
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }

    friend std::ostream &operator<<(std::ostream &os, const Date &date)
    {
        if (date.day < 10)
        {
            os << 0 << date.day;
        }
        else
        {
            os << date.day;
        }
        os << '/';
        if (date.month < 10)
        {
            os << 0 << date.month;
        }
        else
        {
            os << date.month;
        }
        os << '/';
        os << date.year;
        return os;
    }

    // PROPERTIES
    unsigned short getDay() const
    {
        return this->day;
    }

    unsigned short getMonth() const
    {
        return this->month;
    }

    unsigned short getYear() const
    {
        return this->year;
    }

    friend std::ostream &operator<<(std::ostream &os, const Date *date)
    {
        if (date->day < 10)
        {
            os << 0 << date->day;
        }
        else
        {
            os << date->day;
        }
        os << '/';
        if (date->month < 10)
        {
            os << 0 << date->month;
        }
        else
        {
            os << date->month;
        }
        os << '/';
        os << date->year;

        return os;
    }

    bool soonerOrEqual(const Date *otherDate) const
    {
        if (this->year < otherDate->year)
        {
            return true;
        }
        else if (this->year == otherDate->year)
        {
            if (this->month < otherDate->month)
            {
                return true;
            }
            else if (this->month == otherDate->month)
            {
                if (this->day <= otherDate->day)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

string checkState(const Date *d1, const Date *d2)
{
    // d1: deadline
    // d2: submission
    if (d2->getYear() == 9999)
    {
        return "Not Submit.";
    }
    else
    {

        if (d2->soonerOrEqual(d1))
        {
            return "On-time.";
        }
        else
        {
            return "Late.";
        }
    }
}

string getCurrentDate()
{
    auto t = time(nullptr);
    auto tm = *localtime(&t);

    ostringstream oss;
    oss << put_time(&tm, "%d/%m/%Y");
    return oss.str();
}