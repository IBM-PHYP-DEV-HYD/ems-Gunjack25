#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <cstdlib>
#include "EDLL.H"

namespace XyzTypes
{
    enum XYZEmployeeType {
        FULL_TIME = 0,
        CONTRACTOR = 1,
        INTERN = 2
    };

    enum XYZEmployeeStatus {
        ACTIVE = 0,
        INACTIVE = 1,
        RESIGNED = 2
    };

    enum Agency {
        AVENGERS=1,
        JUSTICE_LEAGUE,
        X_MEN
    };

    enum College {
        IIT_DELHI=1,
        IIT_MUMBAI,
        IIT_KANPUR,
        IIT_HYDERABAD,
        NIT_WARANGAL,
        NIT_TRICHY,
        IIIT_HYDERABAD
    };

    enum Branches {
        CSE=1,
        CSIT,
        ECE
    };

    enum Gender {
        MALE = 0,
        FEMALE = 1
    };

    enum MenuOptions {
        ADD_EMPLOYEE_MENU = 1,
        REMOVE_EMPLOYEE_MENU,
        GET_EMPLOYEE_DETAILS,
        OTHER_MENU
    };

    enum AddEmployeeOptions {
        ADD_RANDOM_EMPLOYEE = 1,
        ADD_EMPLOYEE_TYPE
    };

    enum RemoveEmployeeOptions {
        REMOVE_EMPLOYEE_ID = 1,
        REMOVE_EMPLOYEE_NAME
    };

    enum EmployeeDisplayOptions
    {
        GET_ALL_EMPLOYEES = 1,
        GET_EMPLOYEE_TYPE,
        GET_EMPLOYEE_GENDER,
        GET_EMPLOYEE_STATUS,
        GET_EMPLOYEE_ID
    };

    enum OtherMenuOptions {
        ADD_N_LEAVES_TO_EMPLOYEES = 1,
        CONVERT_INTERN_TO_FULL_TIME,
        SEARCH_EMPLOYEE_BY_ID,
        SEARCH_EMPLOYEE_BY_NAME
    };

    void printCollege(College collegeParm);
    void printBranch(Branches branchParm);
    void printAgency(Agency agencyParm);
}

struct Date {
    size_t day;
    size_t month;
    size_t year;

    Date(size_t dayParm, size_t monthParm, size_t yearParm)
        : day(dayParm), month(monthParm), year(yearParm) {}

    Date& operator=(const Date& right)
    {
        this->day = right.day;
        this->month = right.month;
        this->year = right.year;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Date& dateParm); 
    friend std::istream& operator>>(std::istream& os, const Date& dateParm); 

    Date() : day(1),
        month(1),
        year(2000)
        {
        }
    
    void print() const
    {
        std::cout << (day < 10 ? "0" : "") << day << "-"
                  << (month < 10 ? "0" : "") << month << "-"
                  << year;
    }

    friend std::ostream& operator<<(std::ostream& os, const Date& dateParm)
    {
        os << (dateParm.day < 10 ? "0" : "") << dateParm.day << "-"
           << (dateParm.month < 10 ? "0" : "") << dateParm.month << "-"
           << dateParm.year;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Date& dateParm)
    {
        std::cout << "\nEnter the day: ";
        is >> dateParm.day;
        std::cout << "Enter the month: ";
        is >> dateParm.month;
        std::cout << "Enter the year: ";
        is >> dateParm.year;
        return is;
    }
};

std::string randomName();

inline int randomDay()
{
    return (std::rand()%28+1);
}

inline int randomMonth()
{
    return (std::rand()%12+1);
}

inline int randomYear()
{
    return (std::rand()%50+1960);
}

inline int randomYear(Date DOJParm)
{
    return (std::rand()%((2025 - DOJParm.year)+1) + DOJParm.year);
}

inline Date randomDate(int startYear = 1980, int endYear = 2000) {
    int year = startYear + std::rand() % (endYear - startYear + 1);
    int month = randomMonth();
    int day = randomDay();
    return Date(day, month, year);
}

inline XyzTypes::Gender randomGender()
{
    return XyzTypes::Gender(std::rand()%2);
}

inline XyzTypes::XYZEmployeeType randomType()
{
    return XyzTypes::XYZEmployeeType(std::rand()%3);
}

inline int randomLeaves()
{
    return (std::rand()%22);
}

inline XyzTypes::Agency randomAgency()
{
    return XyzTypes::Agency((std::rand()%3)+1);
}

inline XyzTypes::College randomCollege()
{
    return XyzTypes::College((std::rand()%7)+1);
}

inline XyzTypes::Branches randomBranch()
{
    return XyzTypes::Branches((std::rand()%3)+1);
}

inline void menuHeader()
{
    std::cout << "=============================================\n"
              << "||    XYZ Employee Management System     ||\n"
              << "=============================================\n";
}

inline void menuFooter()
{
    std::cout << "=============================================\n";
}

#endif
