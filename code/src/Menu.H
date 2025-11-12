#ifndef MENU_H
#define MENU_H

#include "Exception.H"
#include "XyzEmployeeManager.H"
#include <iostream>


class Menu
{
public:
    Menu(); 
    int mainMenu();
    int addEmployeeMenu();
    int removeEmployeeMenu();
    int getEmployeeDetails();
    int otherMenu();
    XYZEmployeeType chooseType();
    XYZEmployeeStatus chooseStatus();
    bool chooseGender();

    void addEmployeeProcess(int choiceParm);
    void removeEmployeeProcess(int choiceParm);
    void getEmployeeDetailProcess(int choiceParm);
    void otherMenuProcess(int choiceParm);
};

#endif
