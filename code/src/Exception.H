#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <string>
#include "Utils.H"

template <typename T>
class Exception {
    public:
        static void input(T& val, const std::string& str="")  {
            bool valid = false;
            while(!valid)
            {
                std::cout << str;
                std::cin >> val;
                if(std::cin.fail())
                {
                    std::cout << "Please select the correct input according to the defined type\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } else {
                    valid = true;
                }
            }
        }      
};

#endif