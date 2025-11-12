#ifndef XYZIF_H
#define XYZIF_H

#include "EDLL.H"
#include "Utils.H"
#include <cstdlib> 

using namespace XyzTypes;

class XyzEmployeeIF {
public:
    virtual std::string getName() = 0;
    virtual std::string getID() = 0;
    virtual Gender getGender() = 0;
    virtual Date getDOB() = 0;
    virtual Date getDOJ() = 0;
    virtual Date getDOL() = 0;
    virtual XYZEmployeeStatus getStatus() = 0;
    virtual XYZEmployeeType getType() = 0;
    virtual void setName(const std::string& nameParm) = 0;
    virtual void setDOJ(const Date& DOJParm) = 0;
    virtual void setDOB(const Date& DOBParm) = 0;
    virtual void setDOL(const Date& DOLParm) = 0;
    virtual void setGender(const Gender& genderParm) = 0;
    virtual void setType(const XYZEmployeeType& typeParm) = 0;
    virtual void setStatus(const XYZEmployeeStatus& statusParm) = 0;
    virtual void print() = 0;
    virtual void setID(const std::string& sIDParm) = 0;
};


#endif