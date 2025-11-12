#include "XyzEmployeeManager.H"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "Exception.H"
#include "XYZEmployee.H"


XyzEmployeeManager* XyzEmployeeManager::mInstance = nullptr;

XyzEmployeeManager::XyzEmployeeManager()
{
} 

XyzEmployeeManager& XyzEmployeeManager::getInstance() {
    if (mInstance == nullptr)
        mInstance = new XyzEmployeeManager();
    return *mInstance;
}

void XyzEmployeeManager::createRandomEmployee()
{
    XYZEmployeeType sType = randomType();
    std::string sEmpID;
    XyzEmployee* sEmployee = nullptr;

    switch(sType)
    {
        case FULL_TIME:
        {
            FullTimeBuilder builder;
            sEmployee = builder.setName(randomName())
                               .setDOB(randomDate(1985, 1997))
                               .setDOJ(randomDate(2015, 2025))
                               .setDOL()
                               .setGender(randomGender())
                               .setLeavesAvailed(std::rand() % 10)
                               .setLeavesLeft(10 + std::rand() % 20)
                               .build();
            sEmpID = createEmployeeID(FULL_TIME);
            break;
        }

        case CONTRACTOR:
        {
            ContractorBuilder builder;
            sEmployee = builder.setName(randomName())
                               .setDOB(randomDate(1985, 1997))
                               .setDOJ(randomDate(2015, 2025))
                               .setDOL()
                               .setGender(randomGender())
                               .setAgency(randomAgency())
                               .build();
            sEmpID = createEmployeeID(CONTRACTOR);
            break;
        }

        case INTERN:
        {
            InternBuilder builder;
            sEmployee = builder.setName(randomName())
                               .setDOB(randomDate(1985, 1995))
                               .setDOJ(randomDate(2015, 2025))
                               .setDOL()
                               .setGender(randomGender())
                               .setCollege(randomCollege())
                               .setBranch(randomBranch())
                               .build();
            sEmpID = createEmployeeID(INTERN);

            break;
        }
    }

    sEmployee->setID(sEmpID);
    addToDatabase(sEmployee);
    std::cout << "Random Employee Created\n";
}


void XyzEmployeeManager::getCommonEmployeeAttributesFromUser(std::string& nameParm, Date& DOBParm, Date& DOJParm, Gender& genderParm)
{
    Exception<std::string>::input(nameParm, "Enter Employee Name:\t");
    Exception<Date>::input(DOBParm, "Enter Employee DOB:");
    Exception<Date>::input(DOJParm, "Enter Employee DOJ:");
    std::string genderString;
    Exception<std::string>::input(genderString, "Enter Gender (M/F):");
    for (char &charIter : genderString) 
    {
        charIter = std::toupper(static_cast<unsigned char>(charIter)); 
    }
    if(genderString == "M" || genderString == "MALE")
        genderParm = MALE;
    else
        genderParm = FEMALE;
}

void XyzEmployeeManager::getFullTimeAttributesFromUser(int& leavesAvailed, int& leavesLeft)
{
    Exception<int>::input(leavesAvailed, "Enter Leaves Availed: ");
    Exception<int>::input(leavesLeft, "Enter Leaves Left: ");
}

void XyzEmployeeManager::getContractorAttributesFromUser(Agency& agencyParm)
{
    std::cout << "Choose from the given Agencies:\n";
    std::cout << "1. Avengers\n"
              << "2. Justice League\n"
              << "3. X-Men\n";
    int agencyType;
    Exception<int>::input(agencyType, "");
    switch(agencyType)
    {
        case AVENGERS:
            agencyParm = AVENGERS;
            break;
        case JUSTICE_LEAGUE:
            agencyParm = JUSTICE_LEAGUE;
            break;
        case X_MEN:
            agencyParm = X_MEN;
            break;
        default:
            agencyParm = AVENGERS;
            break;
    }   
}

void XyzEmployeeManager::getInternAttributesFromUser(College& collegeParm, Branches& branchParm)
{
    std::cout << "Choose from the given College\n";
    std::cout << "1. IIT_DELHI\n"
        "2. IIT_MUMBAI\n"
        "3. IIT_KANPUR\n"
        "4. IIT_HYDERABAD\n"
        "5. NIT_WARANGAL\n"
        "6. NIT_TRICHY\n"
        "7. IIIT_HYDERABAD\n";
    int collegeType;
    Exception<int>::input(collegeType, "");
    switch(collegeType)
    {
        case IIT_DELHI:
            collegeParm = IIT_DELHI;
            break;
        case IIT_MUMBAI:
            collegeParm = IIT_MUMBAI;
            break;
        case IIT_KANPUR:
            collegeParm = IIT_KANPUR;
            break;
        case IIT_HYDERABAD:
            collegeParm = IIT_HYDERABAD;
            break;
        case NIT_WARANGAL:
            collegeParm = NIT_WARANGAL;
            break;
        case NIT_TRICHY:
            collegeParm = NIT_TRICHY;
            break;
        case IIIT_HYDERABAD:
            collegeParm = IIIT_HYDERABAD;
            break;
        default:
            std::cout << "Default allocation to IIT DELHI\n";
            collegeParm = IIT_DELHI;
            break;
    } 

    int branchType;
    std::cout << "Choose from the given Branches\n";
    std::cout << "1. CSE\n"
        << "2. CSIT\n"
        << "3. ECE\n";
    Exception<int>::input(branchType, "");
    switch(branchType)
    {
        case CSE:
            branchParm = CSE;
            break;
        case CSIT:
            branchParm = CSIT;
            break;
        case ECE:
            branchParm = ECE;
            break;
        default:
            std::cout << "Default allocation to CSE\n";
            branchParm = CSE;
            break;
    }
}

void XyzEmployeeManager::createEmployee(const XYZEmployeeType& sEmpTypeParm, XyzEmployee* sEmpPtr)
{
    std::string sEmpID;

    switch(sEmpTypeParm)
    {
        case FULL_TIME:
        {
            FullTimeBuilder builder;
            std::string sName="";
            Date sDOB, sDOJ;
            Gender sGender;
            int sLeavesAvailed=0, sLeavesLeft = 0;
            getCommonEmployeeAttributesFromUser(sName, sDOB, sDOJ, sGender);
            getFullTimeAttributesFromUser(sLeavesAvailed, sLeavesLeft);

            sEmpPtr = builder.setName(sName)
                    .setDOB(sDOB)
                    .setDOJ(sDOJ)
                    .setDOL()
                    .setGender(sGender)
                    .setLeavesAvailed(sLeavesAvailed)
                    .setLeavesLeft(sLeavesLeft)
                    .build();
            sEmpID = createEmployeeID(XYZEmployeeType::FULL_TIME);
            break;
        }
        case CONTRACTOR:
        {
            ContractorBuilder builder;
            std::string sName="";
            Date sDOB, sDOJ;
            Gender sGender;
            Agency sAgency;
            getCommonEmployeeAttributesFromUser(sName, sDOB, sDOJ, sGender);
            getContractorAttributesFromUser(sAgency);

            sEmpPtr = builder.setName(sName)
                    .setDOB(sDOB)
                    .setDOJ(sDOJ)
                    .setDOL()
                    .setGender(sGender)
                    .setAgency(sAgency)
                    .build();
            sEmpID = createEmployeeID(XYZEmployeeType::CONTRACTOR);
            break;
        }
        case INTERN:
            InternBuilder builder;
            std::string sName="";
            Date sDOB, sDOJ;
            Gender sGender;
            College sCollege;
            Branches sBranch;
            getCommonEmployeeAttributesFromUser(sName, sDOB, sDOJ, sGender);
            getInternAttributesFromUser(sCollege, sBranch);

            sEmpPtr = builder.setName(sName)
                    .setDOB(sDOB)
                    .setDOJ(sDOJ)
                    .setDOL()
                    .setGender(sGender)
                    .setCollege(sCollege)
                    .setBranch(sBranch)
                    .build();
            sEmpID = createEmployeeID(XYZEmployeeType::INTERN);
            break;
    }

    sEmpPtr->setID(sEmpID);
    addToDatabase(sEmpPtr);
}

void XyzEmployeeManager::convertEmployeeToFullTime(const std::string& IDParm)
{
    XyzEmployee* ptr = searchEmployeeByID(IDParm);
    if(ptr == nullptr)
    {
        std::cout << "No Employee Found with the provided name\n";
        return;
    }
    else{
        XyzEmployee* ptrFullTime;
        FullTimeBuilder builder;

        ptrFullTime = builder.setName(ptr->getName())
                    .setDOB(ptr->getDOB())
                    .setDOJ(ptr->getDOJ())
                    .setDOL()
                    .setGender(ptr->getGender())
                    .setLeavesAvailed(0)
                    .setLeavesLeft(0)
                    .build();

        ptrFullTime->setID(createEmployeeID(XYZEmployeeType::FULL_TIME));

        addToDatabase(ptrFullTime);
        removeEmployeeByID(ptr->getID());
    }
    
}

void XyzEmployeeManager::convertEmployeeToResigned(const std::string& IDParm)
{
    XyzEmployee* sEmpPtr = searchEmployeeByID(IDParm);
    if(sEmpPtr == nullptr)
    {
        std::cout << "Employee not found" << std::endl;
        return;
    }

    Date DOL;
    std::cout << "Add Date of resigning: ";
    std::cin >> DOL;

    sEmpPtr->setStatus(XYZEmployeeStatus::RESIGNED); 
    sEmpPtr->setDOL(DOL);

    if (sEmpPtr->getType() == XYZEmployeeType::FULL_TIME)
        mDequeFullTime.removeElement(sEmpPtr);
    else if (sEmpPtr->getType() == XYZEmployeeType::CONTRACTOR)
        mDequeContractor.removeElement(sEmpPtr);
    else if (sEmpPtr->getType() == XYZEmployeeType::INTERN)
        mDequeIntern.removeElement(sEmpPtr);

    mDequeAllEmployees.removeElement(sEmpPtr);
    sEmpPtr->setStatus(XYZEmployeeStatus::RESIGNED);
    mDequeResigned.push_back(sEmpPtr);

    std::cout << "Employee " << sEmpPtr->getName() << " marked as RESIGNED on " << DOL << "\n";
}


void XyzEmployeeManager::addLeavesToFullTime()
{
    int leavesAddition = 0;
    Exception<int>::input(leavesAddition, "Enter leaves to be added for all the Full Time Employees: ");
    for(int sIter=0; sIter<mDequeFullTime.size(); ++sIter)
    {
        XyzEmployee* sEmpPtr = mDequeFullTime[sIter];
        EmployeeFullTime* empPtrFT = dynamic_cast<EmployeeFullTime*>(sEmpPtr);
        int curr_leaves = empPtrFT->getLeavesLeft();
        empPtrFT->setLeavesLeft(curr_leaves+leavesAddition);
    }
    std::cout << "Leaves incremented for all full-time employees.\n";
}

void XyzEmployeeManager::addToDatabase(XyzEmployee* empParm)
{
    if(empParm->getStatus() != XYZEmployeeStatus::RESIGNED)
    {
        switch (empParm->getType())
        {
            case XYZEmployeeType::FULL_TIME:
                mDequeFullTime.push_back(empParm);
                break;
            case XYZEmployeeType::CONTRACTOR:
                mDequeContractor.push_back(empParm);
                break;
            case XYZEmployeeType::INTERN:
                mDequeIntern.push_back(empParm);
                break;
            default:
                break;
        }
        mDequeAllEmployees.push_back(empParm);
    }
    else
    {
        mDequeResigned.push_back(empParm);
    }
}

void XyzEmployeeManager::printFullTimeEmployees()
{
    XyzEmployee* sEmpPtr;
    for(int sIter=0;sIter<mDequeFullTime.size();++sIter)
    {
        sEmpPtr = mDequeFullTime[sIter];
        sEmpPtr->print();
    }
}

void XyzEmployeeManager::printContractEmployees()
{
    XyzEmployee* sEmpPtr;
    for(int sIter=0;sIter<mDequeContractor.size();++sIter)
    {
        sEmpPtr = mDequeContractor[sIter];
        sEmpPtr->print();
    }
}

void XyzEmployeeManager::printInternEmployees()
{
    for(int sIter=0;sIter<mDequeIntern.size();++sIter)
    {
        mDequeIntern[sIter]->print();
    }
}

void XyzEmployeeManager::printResignedEmployees()
{
    XyzEmployee* sEmpPtr;
    for(int sIter=0;sIter<mDequeResigned.size();++sIter)
    {
        sEmpPtr = mDequeResigned[sIter];
        sEmpPtr->print();
    }
}

void XyzEmployeeManager::printAllEmployees()
{
    std::cout << "All Employee List:" << std::endl;
    XyzEmployee* sEmpPtr;
    for(int sIter=0;sIter<mDequeAllEmployees.size();++sIter)
    {
        sEmpPtr = mDequeAllEmployees[sIter];
        sEmpPtr->print();
    }
    printResignedEmployees();
 }

 void XyzEmployeeManager::printAllEmployeeSummary()
 {
    std::cout << "All Employee List:" << std::endl;
    XyzEmployee* sEmpPtr;
    for(int sIter=0;sIter<mDequeAllEmployees.size();++sIter)
    {
        sEmpPtr = mDequeAllEmployees[sIter];
        sEmpPtr->printCommonDetails();
    }
 }

void XyzEmployeeManager::printEmployeeByType(XYZEmployeeType empTypeParm)
{
    switch(empTypeParm)
    {
        case XYZEmployeeType::FULL_TIME:
            printFullTimeEmployees();
            break;
        case XYZEmployeeType::CONTRACTOR:
            printContractEmployees();
            break;
        case XYZEmployeeType::INTERN:
            printInternEmployees();
            break;
        default:
            break;
    }
}

void XyzEmployeeManager::printEmployeeByGender(Gender sGenderParm)
{
    for (int sIter = 0; sIter < mDequeFullTime.size(); ++sIter)
    {
        if (mDequeFullTime[sIter]->getGender() == sGenderParm) 
            mDequeFullTime[sIter]->print();
    }
    for(int sIter = 0; sIter < mDequeContractor.size(); ++sIter)
    {
        if (mDequeContractor[sIter]->getGender() == sGenderParm) 
            mDequeContractor[sIter]->print(); 
    }
    for(int sIter = 0; sIter < mDequeIntern.size(); ++sIter)
    {
        if (mDequeIntern[sIter]->getGender() == sGenderParm) 
            mDequeIntern[sIter]->print(); 
    }    
}

void XyzEmployeeManager::printEmployeeByStatus(XYZEmployeeStatus statusParm)
{
    for (int sIter = 0; sIter < mDequeFullTime.size(); ++sIter)
    {
        if (mDequeFullTime[sIter]->getStatus() == statusParm) 
            mDequeFullTime[sIter]->print();
    }
    
    for(int sIter = 0; sIter < mDequeContractor.size(); ++sIter)
    {
        if (mDequeContractor[sIter]->getStatus() == statusParm) 
            mDequeContractor[sIter]->print(); 
    }

    for(int sIter = 0; sIter < mDequeIntern.size(); ++sIter)
    {
        if (mDequeIntern[sIter]->getStatus() == statusParm) 
            mDequeIntern[sIter]->print(); 
    }    
}

void XyzEmployeeManager::printEmployeeWithName(const std::string& nameParm)
{
    XyzEmployee* sEmpPtr = searchEmployeeByName(nameParm);
    if(sEmpPtr != nullptr)
    {
        sEmpPtr->print();
    }
}

void XyzEmployeeManager::printEmployeeWithID(const std::string& IDParm)
{
    XyzEmployee* sEmpPtr = searchEmployeeByID(IDParm);
    if(sEmpPtr != nullptr)
    {
        sEmpPtr->print();
    }
}

XyzEmployee* XyzEmployeeManager::searchEmployeeByID(const std::string& IDParm)
{
    for(int sIter=0;sIter<mDequeAllEmployees.size();++sIter)
    {
        if(mDequeAllEmployees[sIter]->getID() == IDParm)
            return mDequeAllEmployees[sIter];
    }

    for (int sIter = 0; sIter < mDequeResigned.size(); ++sIter)
    {
        if (mDequeResigned[sIter]->getID() == IDParm) 
            return mDequeResigned[sIter];
    }

    std::cout << "Employee ID not found: " << IDParm << "\n";
    return nullptr;
}

XyzEmployee* XyzEmployeeManager::searchEmployeeByName(const std::string& nameParm)
{
    for(int sIter=0;sIter<mDequeAllEmployees.size();++sIter)
    {
        if(mDequeAllEmployees[sIter]->getName() == nameParm)
            return mDequeAllEmployees[sIter];
    }

    for (int sIter = 0; sIter < mDequeResigned.size(); ++sIter)
    {
        if (mDequeResigned[sIter]->getName() == nameParm) 
            return mDequeResigned[sIter];
    }

    std::cout << "Employee name not found: " << nameParm << "\n";
    return nullptr;
}

void XyzEmployeeManager::removeEmployeeByID(const std::string& ID)
{
    for (int sIter = 0; sIter < mDequeFullTime.size(); ++sIter)
    {
        if (mDequeFullTime[sIter]->getID() == ID)
        {
            XyzEmployee *sEmpPtr = mDequeFullTime[sIter];
            mDequeAllEmployees.removeElement(sEmpPtr);
            mDequeFullTime.removeElement(sEmpPtr);
            sEmpPtr->setStatus(XYZEmployeeStatus::RESIGNED);
            mDequeResigned.push_back(sEmpPtr);
            //delete sEmpPtr;
            std::cout << "Employee removed: " << ID << "\n";
            return;
        }
    }

    for (int sIter = 0; sIter < mDequeContractor.size(); ++sIter)
    {
        if (mDequeContractor[sIter]->getID() == ID)
        {
            XyzEmployee *sEmpPtr = mDequeContractor[sIter];
            mDequeAllEmployees.removeElement(sEmpPtr);
            mDequeContractor.removeElement(sEmpPtr);
            sEmpPtr->setStatus(XYZEmployeeStatus::RESIGNED);
            mDequeResigned.push_back(sEmpPtr);
            std::cout << "Employee removed: " << ID << "\n";
            return;
        }
    }

    for (int sIter = 0; sIter < mDequeIntern.size(); ++sIter)
    {
        if (mDequeIntern[sIter]->getID() == ID)
        {
            XyzEmployee *sEmpPtr = mDequeIntern[sIter];
            mDequeAllEmployees.removeElement(sEmpPtr);
            mDequeIntern.removeElement(sEmpPtr);
            sEmpPtr->setStatus(XYZEmployeeStatus::RESIGNED);
            mDequeResigned.push_back(sEmpPtr);
            std::cout << "Employee removed: " << ID << "\n";
            return;
        }
    }
    std::cout << "Employee not found for removal: " << ID << "\n";
}


void XyzEmployeeManager::removeEmployeeByName(const std::string& name)
{
    for (int sIter = 0; sIter < mDequeFullTime.size(); ++sIter)
    {
        if (mDequeFullTime[sIter]->getName() == name)
        {
            XyzEmployee *sEmpPtr = mDequeFullTime[sIter];
            mDequeAllEmployees.removeElement(sEmpPtr);
            mDequeFullTime.removeElement(sEmpPtr);
            sEmpPtr->setStatus(XYZEmployeeStatus::RESIGNED);
            mDequeResigned.push_back(sEmpPtr);
            //delete sEmpPtr;
            std::cout << "Employee removed: " << name << "\n";
            return;
        }
    }

    for (int sIter = 0; sIter < mDequeContractor.size(); ++sIter)
    {
        if (mDequeContractor[sIter]->getName() == name)
        {
            XyzEmployee *sEmpPtr = mDequeContractor[sIter];
            mDequeAllEmployees.removeElement(sEmpPtr);
            mDequeContractor.removeElement(sEmpPtr);
            sEmpPtr->setStatus(XYZEmployeeStatus::RESIGNED);
            mDequeResigned.push_back(sEmpPtr);
            //delete sEmpPtr;
            std::cout << "Employee removed: " << name << "\n";
            return;
        }
    }

    for (int sIter = 0; sIter < mDequeIntern.size(); ++sIter)
    {
        if (mDequeIntern[sIter]->getName() == name)
        {
            XyzEmployee *sEmpPtr = mDequeIntern[sIter];
            mDequeAllEmployees.removeElement(sEmpPtr);
            mDequeIntern.removeElement(sEmpPtr);
            sEmpPtr->setStatus(XYZEmployeeStatus::RESIGNED);
            mDequeResigned.push_back(sEmpPtr);
            //delete sEmpPtr;
            std::cout << "Employee removed: " << name << "\n";
            return;
        }
    }
    std::cout << "Employee not found for removal: " << name << "\n";
}

std::string XyzEmployeeManager::createEmployeeID(const XYZEmployeeType& type)
{
    static int counter = 1;
    std::ostringstream oss;
    oss << "XYZ" << std::setw(4) << std::setfill('0') << counter++;

    switch (type)
    {
        case XYZEmployeeType::FULL_TIME: oss << "F"; break;
        case XYZEmployeeType::CONTRACTOR: oss << "C"; break;
        case XYZEmployeeType::INTERN: oss << "I"; break;
    }

    return oss.str();
}

