#include <iostream>
#include <cstdlib>
#include "EDLL.H"
#include "Utils.H"

namespace XyzTypes 
{
    using namespace XyzTypes;
void printCollege(XyzTypes::College collegeParm)
{
    std::cout << "\tCollege: ";
    switch(collegeParm)
    {
        case College::IIT_DELHI:
            std::cout << "IIT DELHI\n";
            break;
        case College::IIT_MUMBAI:
            std::cout << "IIT MUMBAI\n";
            break;
        case College::IIT_KANPUR:
            std::cout << "IIT KANPUR\n";
            break;
        case College::IIT_HYDERABAD:
            std::cout << "IIT HYDERABAD\n";
            break;
        case College::NIT_WARANGAL:
            std::cout << "NIT WARANGAL\n";
            break;
        case College::NIT_TRICHY:
            std::cout << "NIT TRICHY\n";
            break;
        case College::IIIT_HYDERABAD:
            std::cout << "IIIT HYDERABAD\n";
            break;
        default:
            std::cout << "Unknown\n";
            break;
    }
}

void printBranch(Branches branchParm)
{
    std::cout << "\tBranch: ";
    switch(branchParm)
    {
        case Branches::CSE:
            std::cout << "CSE\n";
            break;
        case Branches::CSIT:
            std::cout << "CSIT\n";
            break;
        case Branches::ECE:
            std::cout << "ECE\n";
            break;
        default:
            std::cout << "Unknown\n";
            break;
    }
}

void printAgency(Agency agencyParm)
{
    std::cout << "\tAgency: ";
    switch(agencyParm)
    {
        case Agency::AVENGERS:
            std::cout << "AVENGERS\n";
            break;
        case Agency::JUSTICE_LEAGUE:
            std::cout << "JUSTICE LEAGUE\n";
            break;
        case Agency::X_MEN:
            std::cout << "X-MEN\n";
            break;
        default:
            std::cout << "Unknown\n";
            break;
    }
} 
}

std::string randomName()
{
    Deque<std::string> sNames;
    sNames.push_back(std::string("Gurpreet"));
    sNames.push_back(std::string("Pranjal"));
    sNames.push_back(std::string("Jaspreet"));

    std::string sName = sNames[std::rand() % sNames.size()];
    return sName;
}

