#include <iostream>
#include "Menu.H"
#include "XyzEmployeeManager.H"
#include "Utils.H"
#include "Exception.H"

using namespace XyzTypes;

int Menu::addEmployeeMenu()
{
    int sChoice;
    menuHeader();
    std::cout << "|\tAdd an Employee\t\t|\n"
    << "|\t1. Add a Random Employee\t|\n"
    << "|\t2. Add Employee (F/C/I)\t\t|\n"
    << "|\t(Enter -1 to go back)\t\t|\n";
    menuFooter();

    Exception<int>::input(sChoice, "Your Choice: ");
    return sChoice;
}

int Menu::removeEmployeeMenu()
{
    int sChoice;
    menuHeader();
    std::cout << "|\tRemove an Employee\t\t|\n"
    << "|\t1. Remove by ID\t\t|\n"
    << "|\t2. Remove by Name\t|\n"
    << "|\t(Enter -1 to go back)\t|\n";
    menuFooter();

    Exception<int>::input(sChoice, "Your Choice: ");
    return sChoice;
}

int Menu::otherMenu()
{
    int choice;

    menuHeader();
    std::cout << "|\tOthers\t|\n"
    "|\t1. Add n number of leaves to all the Full-Time employees\t|\n"
    "|\t2. Convert an Intern to Full-Time employee.\t|\n"
    "|\t3. Search an Employee by ID\t|\n"
    "|\t4. Search an Employee by Name\t|\n"
    "|\t5. (Press -1 to go back to Menu)\t\n";
    menuFooter();

    Exception<int>::input(choice, "Your Choice: ");
    return choice;
}

XYZEmployeeType Menu::chooseType()
{
    int sChoice;
    do {
        std::cout 
        << "-------------------------------\n"
        << "|\tChoose Employee Type\t|\n"
        << "-------------------------------\n"
        << "|\t1. Full-Time\t|\n"
        << "|\t2. Contractor\t|\n"
        << "|\t3. Intern\t|\n"
        << "--------------------------------\n";
        Exception<int>::input(sChoice, "Your Choice: ");
    } while (sChoice < 1 || sChoice > 3);
    return XYZEmployeeType(sChoice);
}

XYZEmployeeStatus Menu::chooseStatus()
{
    int sChoice;
    do {
        std::cout 
        << "-------------------------------\n"
        << "|\tChoose Employee Status\t|\n"
        << "-------------------------------\n"
        << "|\t1. ACTIVE\t|\n"
        << "|\t2. INACTIVE\t|\n" 
        << "|\t3. RESIGNED\t|\n"
        << "--------------------------------\n";
        Exception<int>::input(sChoice, "Your Choice: ");
    } while (sChoice < 1 || sChoice > 3);
    
    return XYZEmployeeStatus(sChoice);
}

bool Menu::chooseGender()
{
    int sChoice;
    do {
        std::cout 
        << "-------------------------------\n"
        << "|\tChoose Gender\t|\n"
        << "-------------------------------\n"
        << "|\t1. Male\t|\n"
        << "|\t2. Female\t|\n"
        << "--------------------------------\n"
        << "\tYour Choice: ";
        Exception<int>::input(sChoice, "Your Choice: ");
    } while (sChoice < 1 || sChoice > 2);
    sChoice -= 1;

    return (sChoice == FEMALE);
}

int Menu::mainMenu()
{
    int sChoice;
    menuHeader();
    std::cout << "|\t1. Add an Employee\t|\n"
    "|\t2. Remove an Employee\t|\n"
    "|\t3. Get Employee Details\t|\n"
    "|\t4. Do something else\t|\n"
    "|\t5.  (Enter -1 to exit)\t|\n";
    menuFooter();
    
    Exception<int>::input(sChoice, "Your Choice: ");
    return sChoice;
}

int Menu::getEmployeeDetails()
{
    int sChoice;
    menuHeader();
    std::cout << "|\tEmployee Details\t|\n"
    "|\t1. All Employees Summary \t|\n"
    "|\t2. Employee Summary (F/C/I) \t|\n"
    "|\t3. Employee Summary (M/F) \t|\n"
    "|\t4. Employee Summary (A/I/R) \t|\n"
    "|\t5. Display Employee Details \t|\n"
    "|\t  (Enter -1 to exit)\t|\n";
    menuFooter();
    
    Exception<int>::input(sChoice, "Your Choice: ");
    return sChoice;
}

void Menu::addEmployeeProcess(int choiceParm)
{
    XyzEmployeeManager& manager = XyzEmployeeManager::getInstance();
    switch(choiceParm)
    {
        case ADD_RANDOM_EMPLOYEE:
            manager.createRandomEmployee();
            break;
        case ADD_EMPLOYEE_TYPE:
            {
                int sType = chooseType();
                sType -= 1;
                switch(sType)
                {
                    case FULL_TIME:
                        manager.createEmployee(XYZEmployeeType::FULL_TIME);
                        break;
                    case CONTRACTOR:
                        manager.createEmployee(XYZEmployeeType::CONTRACTOR);
                        break;
                    case INTERN:
                        manager.createEmployee(XYZEmployeeType::INTERN);
                        break;
                    default:
                        break;
                } 
                break;
            }
    }
}

void Menu::removeEmployeeProcess(int choiceParm)
{
    XyzEmployeeManager& manager = XyzEmployeeManager::getInstance();
    std::string sChoice;
    switch(choiceParm)
    {
        case REMOVE_EMPLOYEE_ID:
            Exception<std::string>::input(sChoice, "Choose ID: ");
            manager.removeEmployeeByID(sChoice);
            break;
        case REMOVE_EMPLOYEE_NAME:
            Exception<std::string>::input(sChoice, "Choose Employee Name: ");
            manager.removeEmployeeByName(sChoice);
            break;            
    }
}

void Menu::getEmployeeDetailProcess(int choiceParm)
{
    XyzEmployeeManager& manager = XyzEmployeeManager::getInstance();
    std::string sChoice;

    switch(choiceParm)
    {
        case GET_ALL_EMPLOYEES:
            manager.printAllEmployees();
            break;
        case GET_EMPLOYEE_TYPE:
        {
            XYZEmployeeType sType = chooseType();
            manager.printEmployeeByType(sType);
            break;
        }
        case GET_EMPLOYEE_GENDER:
        {
            Gender sGender = Gender(chooseGender());
            manager.printEmployeeByGender(sGender);
            break;
        }
        case GET_EMPLOYEE_STATUS:
        {
            XYZEmployeeStatus sStatus = chooseStatus();
            manager.printEmployeeByStatus(sStatus);
            break;
        }
        case GET_EMPLOYEE_ID:
        {
            Exception<std::string>::input(sChoice, "Choose ID: ");
            manager.printEmployeeWithID(sChoice);
            break;
        }
        default:
            break;
    }
}

void Menu::otherMenuProcess(int choiceParm)
{
    XyzEmployeeManager& manager = XyzEmployeeManager::getInstance();

    switch(choiceParm)
    {
        case ADD_N_LEAVES_TO_EMPLOYEES:
            manager.addLeavesToFullTime();
            break;
        case CONVERT_INTERN_TO_FULL_TIME:
        {
            std::string sID;
            Exception<std::string>::input(sID, "Enter ID: ");
            manager.convertEmployeeToFullTime(sID);
            break;
        }
        case SEARCH_EMPLOYEE_BY_ID:
        {
            std::string sID;
            Exception<std::string>::input(sID, "Enter ID: ");
            manager.printEmployeeWithID(sID);
            break;
        }
        case SEARCH_EMPLOYEE_BY_NAME:
        {
            std::string sName; 
            Exception<std::string>::input(sName, "Enter Name: ");
            manager.printEmployeeWithName(sName);
            break;
        }
        default:
            break;
    }
}

Menu::Menu()
{
}



