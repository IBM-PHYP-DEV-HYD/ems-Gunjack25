#ifndef MANAGER_H
#define MANAGER_H

#include "EDLL.H"
#include "Utils.H"
#include "XYZEmployee.H"
#include "XYZEmployeeIF.H"
#include "XYZEmployeeBuilder.H"

class XyzEmployeeManager 
{
    public:
        void createEmployee(const XYZEmployeeType& sEmpTypeParm, XyzEmployee* empPtr=nullptr);
        void createRandomEmployee();
        virtual void printFullTimeEmployees();
        virtual void printContractEmployees();
        virtual void printInternEmployees();
        virtual void printResignedEmployees();
        virtual void printAllEmployees();
        void printAllEmployeeSummary();
        virtual void printEmployeeWithName(const std::string& nameParm);
        virtual void printEmployeeWithID(const std::string& IDParm);
        
        void printEmployeeByGender(Gender sGender);
        void printEmployeeByType(XYZEmployeeType empTypeParm);
        void printEmployeeByStatus(XYZEmployeeStatus statusParm);

        void convertEmployeeToFullTime(const std::string& nameParm);
        void removeEmployeeByID(const std::string& IDParm);
        void removeEmployeeByName(const std::string& nameParm);
        void addLeavesToFullTime();
        
        static XyzEmployeeManager& getInstance();
        void convertEmployeeToResigned(const std::string& IDParm);

    private:
        EDLL<XyzEmployee*> mDequeFullTime;
        EDLL<XyzEmployee*> mDequeContractor;
        EDLL<XyzEmployee*> mDequeIntern;
        EDLL<XyzEmployee*> mDequeAllEmployees;
        EDLL<XyzEmployee*> mDequeResigned;
        
        static XyzEmployeeManager* mInstance;

        XyzEmployeeManager();
        XyzEmployeeManager(const XyzEmployeeManager&);
        XyzEmployeeManager& operator=(const XyzEmployeeManager&);

        std::string createEmployeeID(const XYZEmployeeType& typeParm);
        void addToDatabase(XyzEmployee* empPtrParm);
        void getCommonEmployeeAttributesFromUser(std::string& nameParm, Date& DOBParm, Date& DOJParm, Gender& genderParm);
        void getFullTimeAttributesFromUser(int& leavesAvailedParm, int& leavesLeftParm);
        void getContractorAttributesFromUser(Agency& agencyParm);
        void getInternAttributesFromUser(College& collegeParm, Branches& branchParm);
        XyzEmployee* searchEmployeeByID(const std::string& IDParm);
        XyzEmployee* searchEmployeeByName(const std::string& nameParm);
};


#endif