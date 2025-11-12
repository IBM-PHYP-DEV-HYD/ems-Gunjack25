#include "EDLL.H"
#include "XYZEmployee.H"

using namespace XyzTypes;

XyzEmployee::XyzEmployee() : mName(""), mID(""), mDOB({0,0,0}), mDOJ({0,0,0}), mDOL({0,0,0}), mEmpType(XYZEmployeeType::FULL_TIME), mEmpStatus(XYZEmployeeStatus::ACTIVE), mGender(Gender::MALE)
{
    assignRandomAttributes();
}

XyzEmployee::~XyzEmployee()
{
}

void XyzEmployee::assignRandomAttributes()
{
    this->mName = randomName();
    int random_date = randomDay();
    int random_month = randomMonth();
    int random_year = randomYear();
    Date sDOB(random_date, random_month, random_year);
    setDOB(sDOB);
    random_date = randomDay();
    random_month = randomMonth();
    random_year = randomYear(sDOB);
    Date sDOJ(random_date, random_month, random_year);
    setDOJ(sDOJ);
    setType(randomType());
    setGender(randomGender());
}

EmployeeFullTime::EmployeeFullTime() : XyzEmployee()
{
    setType(XYZEmployeeType::FULL_TIME);
    setStatus(XYZEmployeeStatus::ACTIVE);
    mLeavesAvailed = randomLeaves();
    mLeavesLeft = randomLeaves();
}

EmployeeFullTime::~EmployeeFullTime()
{
}

EmployeeContractor::EmployeeContractor() : XyzEmployee()
{
    setType(XYZEmployeeType::CONTRACTOR);
    setStatus(XYZEmployeeStatus::ACTIVE);
}

EmployeeContractor::~EmployeeContractor()
{
}

EmployeeIntern::EmployeeIntern() : XyzEmployee()
{
    setType(XYZEmployeeType::INTERN);
    setStatus(XYZEmployeeStatus::ACTIVE);
}

EmployeeIntern::~EmployeeIntern()
{
}

