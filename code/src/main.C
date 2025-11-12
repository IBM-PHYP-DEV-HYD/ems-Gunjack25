#include "Menu.H"
#include <iostream>

int main()
{
    Menu menuObject;
    int sChoice;
    int sUserChoice;
    do {
        sChoice = menuObject.mainMenu();
        switch(sChoice)
        {
            case ADD_EMPLOYEE_MENU: {
                do  {
                sUserChoice = menuObject.addEmployeeMenu();
                menuObject.addEmployeeProcess(sUserChoice);
                } while(sUserChoice != -1);
                break;
            }
            case REMOVE_EMPLOYEE_MENU: {
                do  {
                sUserChoice = menuObject.removeEmployeeMenu();
                menuObject.removeEmployeeProcess(sUserChoice);
                } while(sUserChoice != -1);
                break;
            }
            case GET_EMPLOYEE_DETAILS: {
                do  {
                sUserChoice = menuObject.getEmployeeDetails();
                menuObject.getEmployeeDetailProcess(sUserChoice);
                } while(sUserChoice != -1);
                break;
            }
            case OTHER_MENU:  {
                do  {
                sUserChoice = menuObject.otherMenu();
                menuObject.otherMenuProcess(sUserChoice);
                } while(sUserChoice != -1);
                break;
            }
            default:
                break;

        }
    } while(sChoice != -1);


    return 0;
}