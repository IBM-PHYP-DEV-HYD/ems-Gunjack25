#ifndef XYZ_EMPLOYEE_H
#define XYZ_EMPLOYEE_H

#include "EDLL.H"
#include "Utils.H"
#include "XYZEmployeeIF.H"
#include <cstdlib> 

using namespace XyzTypes;

class XyzEmployee : public XyzEmployeeIF {
    private:
        std::string mName;
        std::string mID;
        Date mDOB;
        Date mDOJ;
        Date mDOL;
        XYZEmployeeType mEmpType;
        XYZEmployeeStatus mEmpStatus;
        Gender mGender;

     public:
        XyzEmployee();
        XyzEmployee(std::string nameParm, Date DOBParm, Date DOJParm, Gender genderParm) : mName(nameParm),
                                                                            mDOB(DOBParm),
                                                                            mDOJ(DOJParm),
                                                                            mEmpStatus(XYZEmployeeStatus::ACTIVE),
                                                                            mGender(genderParm)
                                                                            {}
        virtual ~XyzEmployee();
        std::string getName() override { return mName; }
        std::string getID() override { return mID; }
        Gender getGender() override { return mGender; }
        Date getDOB() override { return mDOB; }
        Date getDOJ() override { return mDOJ; }
        Date getDOL() override { return mDOL; }
        virtual XYZEmployeeStatus getStatus() override { return mEmpStatus; }
        virtual XYZEmployeeType getType() override { return mEmpType; }
        virtual void setName(const std::string& nameParm) override { mName = nameParm; }
        virtual void setDOJ(const Date& DOJParm) override { mDOJ = DOJParm; }
        virtual void setDOB(const Date& DOBParm) override { mDOB = DOBParm; }
        virtual void setDOL(const Date& DOLParm) override { mDOL = DOLParm; }
        virtual void setGender(const Gender& genderParm) override { mGender = genderParm; }
        virtual void setType(const XYZEmployeeType& typeParm) override { mEmpType = typeParm; }
        virtual void setStatus(const XYZEmployeeStatus& statusParm) override { mEmpStatus = statusParm; }
        virtual void setID(const std::string& sIDParm) override {mID = sIDParm;}
        virtual void assignRandomAttributes();
        virtual void printCommonDetails() {
        std::cout << "---------------------------------\n"
                  << "\tEmployee Name: " << mName << "\n\tEmployee ID:" << mID << "\n"
                  << "\tGender: " << (mGender == Gender::MALE ? "Male" : "Female") << "\n"
                  << "\tDate Of Birth: " << mDOB << "\n" 
                  << "\tDate Of Joining: " << mDOJ << "\n"
                  << "\tEmployee Status: " << (mEmpStatus == XYZEmployeeStatus::ACTIVE ? "Active" : "Resigned") << "\n";
        }

        virtual void print() override {
            printCommonDetails();
        }

};


class EmployeeFullTime : public XyzEmployee 
{
    private:
        int mLeavesAvailed;
        int mLeavesLeft;
    public:
        EmployeeFullTime();

        virtual ~EmployeeFullTime();
        virtual void setLeavesAvailed(int leavesParm) { mLeavesAvailed = leavesParm; }
        virtual void setLeavesLeft(int leavesParm) { mLeavesLeft = leavesParm; }
        virtual int getLeavesAvailed() const { return mLeavesAvailed; }
        virtual int getLeavesLeft() const { return mLeavesLeft; }
        virtual void assignRandomAttributes()
        {
            XyzEmployee::assignRandomAttributes();
            mLeavesAvailed = randomLeaves();
            mLeavesLeft = randomLeaves();
        }

        virtual void print()
        {
            printCommonDetails();
            std::cout << "\tLeaves Availed: " << mLeavesAvailed << "\n";
            std::cout << "\tLeaves Left: " << mLeavesLeft << "\n";
            std::cout << "\tEmployee Type: " << "FULL TIME" << "\n";
        }
};

class EmployeeContractor : public XyzEmployee 
{
    private:
        Agency mAgency;
    
    public:
        EmployeeContractor();
        virtual ~EmployeeContractor();
        virtual void setAgency(Agency agencyParm) { mAgency = agencyParm;}
        Agency getAgency() const { return mAgency; }
        virtual void assignRandomAttributes()
        {
            XyzEmployee::assignRandomAttributes();
            mAgency = randomAgency();
        }
        virtual void print()
        {
            printCommonDetails();
            XyzTypes::printAgency(mAgency);
            std::cout << "\tEmployee Type: " << "CONTRACTOR" << "\n";
        }
};

class EmployeeIntern : public XyzEmployee 
{
    private:
        College mCollege;
        Branches mBranch;
    public:
        EmployeeIntern();
        virtual ~EmployeeIntern();
        void setCollege(College collegeParm) {mCollege = collegeParm; }
        College getCollege() {return mCollege; }
        void setBranch(Branches branchParm) {mBranch = branchParm; }
        Branches getBranch() {return mBranch; }
        virtual void assignRandomAttributes()
        {
            XyzEmployee::assignRandomAttributes();
            mCollege = randomCollege();
            mBranch = randomBranch();
        }
        virtual void print()
        {
            printCommonDetails();
            XyzTypes::printCollege(mCollege);
            XyzTypes::printBranch(mBranch);
            std::cout << "\tEmployee Type: " << "Intern" << "\n";
        }
};


#endif