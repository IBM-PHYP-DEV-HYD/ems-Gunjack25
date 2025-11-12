#ifndef EMPLOYEE_BUILDER_H
#define EMPLOYEE_BUILDER_H

#include "EDLL.H"
#include "XYZEmployee.H"

class EmployeeBuilder {
public:
    virtual ~EmployeeBuilder() = default;

    virtual EmployeeBuilder& setName(const std::string& nameParm) = 0;
    virtual EmployeeBuilder& setDOB(const Date& DOBParm) = 0;
    virtual EmployeeBuilder& setDOJ(const Date& DOJParm) = 0;
    virtual EmployeeBuilder& setDOL() = 0;
    virtual EmployeeBuilder& setGender(Gender genderParm) = 0;
    virtual EmployeeBuilder& setID(const std::string& idParm) = 0;
    virtual XyzEmployee* build() = 0;
};

class FullTimeBuilder : public EmployeeBuilder {
private:
    EmployeeFullTime* mFullTimePtr;

public:
    FullTimeBuilder() {
        mFullTimePtr = new EmployeeFullTime();
        mFullTimePtr->setType(XYZEmployeeType::FULL_TIME);
    }

    ~FullTimeBuilder() override = default;

    FullTimeBuilder& setName(const std::string& nameParm) override {
        mFullTimePtr->setName(nameParm);
        return *this;
    }

    FullTimeBuilder& setDOB(const Date& DOBParm) override {
        mFullTimePtr->setDOB(DOBParm);
        return *this;
    }

    FullTimeBuilder& setDOJ(const Date& DOJParm) override {
        mFullTimePtr->setDOJ(DOJParm);
        return *this;
    }
    
    FullTimeBuilder& setGender(Gender genderParm) override {
        mFullTimePtr->setGender(genderParm);
        return *this;
    }

    FullTimeBuilder& setDOL() override {
        Date sDOL;
        sDOL.day = 0;
        sDOL.month = 0;
        sDOL.year = 0;
        mFullTimePtr->setDOL(sDOL);
        return *this;
    }

    FullTimeBuilder& setID(const std::string& IDParm) override {
        mFullTimePtr->setID(IDParm);
        return *this;
    }

    FullTimeBuilder& setLeavesAvailed(int leavesParm) {
        mFullTimePtr->setLeavesAvailed(leavesParm);
        return *this;
    }

    FullTimeBuilder& setLeavesLeft(int leavesParm) {
        mFullTimePtr->setLeavesLeft(leavesParm);
        return *this;
    }

    XyzEmployee* build() override {
        return mFullTimePtr;
    }
};

class ContractorBuilder : public EmployeeBuilder {
private:
    EmployeeContractor* mContractorPtr;

public:
    ContractorBuilder() {
        mContractorPtr = new EmployeeContractor();
        mContractorPtr->setType(XYZEmployeeType::CONTRACTOR);
        mContractorPtr->setStatus(XYZEmployeeStatus::ACTIVE);
    }

    ~ContractorBuilder() override = default;

    ContractorBuilder& setName(const std::string& name) override {
        mContractorPtr->setName(name);
        return *this;
    }

    ContractorBuilder& setDOB(const Date& dob) override {
        mContractorPtr->setDOB(dob);
        return *this;
    }

    ContractorBuilder& setDOJ(const Date& doj) override {
        mContractorPtr->setDOJ(doj);
        return *this;
    }

    ContractorBuilder& setDOL() override {
        Date sDOL = mContractorPtr->getDOJ();
        sDOL.year += 1;
        mContractorPtr->setDOL(sDOL);
        return *this;
    }

    ContractorBuilder& setID(const std::string& IDParm) override {
        mContractorPtr->setID(IDParm);
        return *this;
    }

    ContractorBuilder& setGender(Gender gender) override {
        mContractorPtr->setGender(gender);
        return *this;
    }

    ContractorBuilder& setAgency(Agency agency) {
        mContractorPtr->setAgency(agency);
        return *this;
    }

    XyzEmployee* build() override {
        return mContractorPtr;
    }
};

class InternBuilder : public EmployeeBuilder {
private:
    EmployeeIntern* mInternPtr;

public:
    InternBuilder() {
        mInternPtr = new EmployeeIntern();
        mInternPtr->setType(XYZEmployeeType::INTERN);
        mInternPtr->setStatus(XYZEmployeeStatus::ACTIVE);

    }

    ~InternBuilder() override = default;

    InternBuilder& setName(const std::string& name) override {
        mInternPtr->setName(name);
        return *this;
    }

    InternBuilder& setDOB(const Date& dob) override {
        mInternPtr->setDOB(dob);
        return *this;
    }

    InternBuilder& setDOJ(const Date& doj) override {
        mInternPtr->setDOJ(doj);
        return *this;
    }

    InternBuilder& setGender(Gender gender) override {
        mInternPtr->setGender(gender);
        return *this;
    }

    InternBuilder& setDOL() override {
        Date sDOL = mInternPtr->getDOJ();
        if(sDOL.month > 6)
        {
            sDOL.year += 1;
            sDOL.month = (sDOL.month + 6) % 12;
        }
        else
            sDOL.month += 6;

        mInternPtr->setDOL(sDOL);
        return *this;
    }

    InternBuilder& setID(const std::string& IDParm) override {
        mInternPtr->setID(IDParm);
        return *this;
    }

    InternBuilder& setCollege(College college) {
        mInternPtr->setCollege(college);
        return *this;
    }

    InternBuilder& setBranch(Branches branch) {
        mInternPtr->setBranch(branch);
        return *this;
    }

    XyzEmployee* build() override {
        return mInternPtr;
    }
};

#endif