#include <fstream>
#include "ram.h"
#include <algorithm>

void RAM::translate(const std::string& fName)
{
    std::ifstream file ;
    file.open(fName);
    if (!file.is_open()) 
    {
        std::cerr << "Failed to open the file!" ;
        exit(0);
    }
    std::vector<std::string> vec;
    int key = 0 ;
    while (!file.eof())
    {
        std::string str;
        std::getline(file, str);
        int a = 0;
        int b = 0;
        int c = 0;
        bool flag = true;
        for (int i = 0; i < str.size(); ++i) 
        {
            if (str[i] == ' ' && flag )
            {
                a = i ; 
                flag = false ;
            }
            if (str[i] == ',') 
            { 
                b = i ; 
            }
            if (str[i] == ':') 
            { 
                c = i ; 
            }
        }
        if (str.size() != 0) 
        {
            vec.push_back(str.substr(0, a));
            if (vec[0] == "fPrint" || vec[0] == "fDec" || vec[0] == "fInc")
            {
                vec.push_back(str.substr(a, c - a));
            }
            else
            {
                vec.push_back(str.substr(a, b - a));
                vec.push_back(str.substr(b + 1, c - b - 1));
            }
            for (auto& i : vec) 
            {
                i.erase(std::remove(i.begin(), i.end(), ' '), i.end()) ;
            }
        }
        if (vec.size() != 0)
        {
            memory[key] = vec;
        }
        vec.clear();
        ++key;
    }
}

