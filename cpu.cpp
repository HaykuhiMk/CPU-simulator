#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include "cpu.h"
#include "ram.h"

int CPU::getRegister(const std::string& regName)
{
    if (regName == "fEax")
    {
        return this->mEax;
    }
    else if (regName == "fEbx")
    {
        return this->mEbx;
    }
    else if (regName == "fEcx")
    {
        return this->mEcx;
    }
    else if (regName == "fEdx")
    {
        return this->mEdx;
    }
    else if (regName == "fEsi")
    {
        return this->mEsi;
    }
    else if (regName == "fCmpFlag")
    {
        return this->cmpFlag;
    }
    else if (regName == "fOffsetJmp")
    {
        return this->offsetJmp;
    }
    else 
    {
        throw std::invalid_argument("Invalid register name in getRegister()!");
    }
}

void CPU::setRegister(const std::string& regName, int value)
{
    if (regName == "fEax")
    {
        this->mEax = value;
    }
    else if (regName == "fEbx")
    {
        this->mEbx = value;
    }
    else if (regName == "fEcx")
    {
        this->mEcx = value;
    }
    else if (regName == "fEdx")
    {
        this->mEdx = value;
    }
    else if (regName == "fEsi")
    {
        this->mEsi = value;
    }
    else if (regName == "fCmpFlag")
    {
        this->cmpFlag = value;
    }
    else if (regName == "fOffsetJmp")
    {
        this->offsetJmp = value;
    }
    else 
    {
        throw std::invalid_argument("Invalid register name in setRegister()!");
    }
}

void CPU::setRegister(const std::string& reg1, const std::string& reg2)
{
    if (reg1 == "fEax")
    {
        this->mEax = this->getRegister(reg2);
    }
    else if (reg1 == "fEbx")
    {
        this->mEbx = this->getRegister(reg2);
    }
    else if (reg1 == "fEcx")
    {
        this->mEcx = this->getRegister(reg2);
    }
    else if (reg1 == "fEdx")
    {
        this->mEdx = this->getRegister(reg2);
    }
    else if (reg1 == "fEsi")
    {
        this->mEsi = this->getRegister(reg2);
    }
    else if (reg1 == "fCmpFlag")
    {
        this->cmpFlag = this->getRegister(reg2);
    }
    else if (reg1 == "fOffsetJmp")
    {
        this->offsetJmp = this->getRegister(reg2);
    }
    else 
    {
        throw std::invalid_argument("Invalid register name in setRegister()!");
    }
}

void CPU::printRegister(const std::string& regName)
{
    std::ofstream hardFile("hardDisk", std::ofstream::app);
    if (regName == "fEax")
    {
        std::cout << this->mEax << std::endl;
        hardFile << mEax << std::endl;
    }
    else if (regName == "fEbx")
    {
        std::cout << this->mEbx << std::endl;
        hardFile << mEbx << std::endl;
    }
    else if (regName == "fEcx")
    {
        std::cout << this->mEcx << std::endl;
        hardFile << mEcx << std::endl;

    }
    else if (regName == "fEdx")
    {
        std::cout << this->mEdx << std::endl;
        hardFile << mEdx << std::endl;
    }
    else if (regName == "fEsi")
    {
        std::cout << this->mEsi << std::endl;
        hardFile << mEsi << std::endl;
    }
    else if (regName == "fCmpFlag")
    {
        std::cout << this->cmpFlag << std::endl;
        hardFile << cmpFlag << std::endl;
    }
    else if (regName == "fOffsetJmp")
    {
        std::cout << this->offsetJmp << std::endl;
        hardFile << offsetJmp << std::endl;
    }
    else 
    {
        throw std::invalid_argument("Invalid register name in printRegister()!");
    }
    hardFile.close();
}

int CPU::ALU::add(const std::string& reg1, const std::string& reg2, CPU& obj)
{
    int tmp = obj.getRegister(reg1) + obj.getRegister(reg2);
    obj.setRegister(reg1, tmp);
    return tmp;
}

int CPU::ALU::sub(const std::string& reg1, const std::string& reg2, CPU& obj)
{
    int tmp = obj.getRegister(reg1) - obj.getRegister(reg2);
    obj.setRegister(reg1, tmp);
    return tmp;
}

int CPU::ALU::mul(const std::string& reg1, const std::string& reg2, CPU& obj)
{
    int tmp = obj.getRegister(reg1) * obj.getRegister(reg2);
    obj.setRegister(reg1, tmp);
    return tmp;
}

int CPU::ALU::div(const std::string& reg1, const std::string& reg2, CPU& obj)
{
    int tmp = obj.getRegister(reg1) / obj.getRegister(reg2);
    obj.setRegister(reg1, tmp);
    return tmp;
}

int CPU::ALU::modul(const std::string& reg1, const std::string& reg2, CPU& obj)
{
    int tmp = obj.getRegister(reg1) % obj.getRegister(reg2);
    obj.setRegister(reg1, tmp);
    return tmp;
}

bool CPU::ALU::fAnd(const std::string& reg1, const std::string& reg2, CPU& obj)
{
    int tmp = (obj.getRegister(reg1)) & (obj.getRegister(reg2));
    obj.setRegister(reg1, tmp);
    return tmp;
}

bool CPU::ALU::fOr(const std::string& reg1, const std::string& reg2, CPU& obj)
{
    int tmp = (obj.getRegister(reg1)) | (obj.getRegister(reg2));
    obj.setRegister(reg1, tmp);
    return tmp;
}

bool CPU::ALU::fXor(const std::string& reg1, const std::string& reg2, CPU& obj)
{
    int tmp = (obj.getRegister(reg1)) ^ (obj.getRegister(reg2));
    obj.setRegister(reg1, tmp);
    return tmp;
}

bool CPU::ALU::fNot(const std::string& reg1, CPU& obj)
{
    int tmp = ~(obj.getRegister(reg1));
    obj.setRegister(reg1, tmp);
    return tmp;
}

void CPU::ALU::fCmp(const std::string& reg1, const std::string& reg2, CPU& obj)
{
    int tmp1 = obj.getRegister(reg1);
    int tmp2 = obj.getRegister(reg2);
    obj.cmpFlag = tmp1 - tmp2;
}

bool CPU::ALU::fJmp(CPU& obj)
{
    return true;
}

bool CPU::ALU::fJmpLE(CPU& obj)
{
    return obj.cmpFlag <= 0;
}

bool CPU::ALU::fJmpE(CPU& obj)
{
    return obj.cmpFlag == 0;
}

bool CPU::ALU::fJmpL(CPU& obj)
{
    return obj.cmpFlag < 0;
}

bool CPU::ALU::fJmpG(CPU& obj)
{
    return obj.cmpFlag > 0;
}

int CPU::ALU::fInc(const std::string& reg1, CPU& obj)
{
    int tmp = obj.getRegister(reg1) + 1;
    obj.setRegister(reg1, tmp);
    return tmp;
}

int CPU::ALU::fDec(const std::string& reg1, CPU& obj)
{
    int tmp = obj.getRegister(reg1) - 1;
    obj.setRegister(reg1, tmp);
    return tmp;
}

void CPU::CU::analyze(RAM& objRAM, CPU& objCPU)
{
    int end = (--objRAM.memory.end())->first;
    for(; IP <= end; ++IP)
    {
        if (objRAM.memory[IP][0] == "fAdd")
        {
            objCPU.alu.add(objRAM.memory[IP][1], objRAM.memory[IP][2], objCPU);
        }
        else if (objRAM.memory[IP][0] == "fMov")
        {
            int value;
            bool isInt = true;
            try 
            {
                value = std::stoi(objRAM.memory[IP][2]);
            } 
            catch (const std::invalid_argument&) 
            {
                isInt = false;
            } 
            catch (const std::out_of_range&) 
            {
                isInt = false;
            }
            if (isInt) 
            {
                objCPU.setRegister(objRAM.memory[IP][1], value);
            } 
            else 
            {
                objCPU.setRegister(objRAM.memory[IP][1], objRAM.memory[IP][2]);
            }
        }
        else if (objRAM.memory[IP][0] == "fMul")
        {
            objCPU.alu.mul(objRAM.memory[IP][1], objRAM.memory[IP][2], objCPU);
        }
        else if (objRAM.memory[IP][0] == "fDiv")
        {
            objCPU.alu.div(objRAM.memory[IP][1], objRAM.memory[IP][2], objCPU);
        }
        else if (objRAM.memory[IP][0] == "fSub")
        {
            objCPU.alu.sub(objRAM.memory[IP][1], objRAM.memory[IP][2], objCPU);
        }
        else if (objRAM.memory[IP][0] == "fModul")
        {
            objCPU.alu.modul(objRAM.memory[IP][1], objRAM.memory[IP][2], objCPU);
        }
        else if (objRAM.memory[IP][0] == "fAnd")
        {
            objCPU.alu.fAnd(objRAM.memory[IP][1], objRAM.memory[IP][2], objCPU);
        }
        else if (objRAM.memory[IP][0] == "fOr")
        {
            objCPU.alu.fOr(objRAM.memory[IP][1], objRAM.memory[IP][2], objCPU);
        }
        else if (objRAM.memory[IP][0] == "fXor")
        {
            objCPU.alu.fXor(objRAM.memory[IP][1], objRAM.memory[IP][2], objCPU);
        }
        else if (objRAM.memory[IP][0] == "fNot")
        {
            objCPU.alu.fNot(objRAM.memory[IP][1], objCPU);
        }
        else if (objRAM.memory[IP][0] == "fCmp")
        {
            objCPU.alu.fCmp(objRAM.memory[IP][1], objRAM.memory[IP][2], objCPU);
        }
        else if (objRAM.memory[IP][0] == "fJmp")
        {
            if (objCPU.alu.fJmp(objCPU)) 
            {
                IP = (objCPU.getRegister("fOffsetJmp") - 2);
            }
        }
        else if (objRAM.memory[IP][0] == "fJmpG")
        {
            if (objCPU.alu.fJmpG(objCPU)) 
            {
                IP = (objCPU.getRegister("fOffsetJmp") - 2);
            }
        }
        else if (objRAM.memory[IP][0] == "fJmpE")
        {
            if (objCPU.alu.fJmpE(objCPU)) 
            {
                IP = (objCPU.getRegister("fOffsetJmp") - 2);
            }
        }
        else if (objRAM.memory[IP][0] == "fJmpL")
        {
            if (objCPU.alu.fJmpL(objCPU)) 
            {
                IP = (objCPU.getRegister("fOffsetJmp") - 2);
            }
        }
        else if (objRAM.memory[IP][0] == "fJmpLE")
        {
            if (objCPU.alu.fJmpLE(objCPU)) 
            {
                IP = (objCPU.getRegister("fOffsetJmp") - 2);
            }
        }
        else if (objRAM.memory[IP][0] == "fPrint")
        {
            objCPU.printRegister(objRAM.memory[IP][1]);
        }
        else if (objRAM.memory[IP][0] == "fInc")
        {
            objCPU.alu.fInc(objRAM.memory[IP][1], objCPU);
        }
        else if (objRAM.memory[IP][0] == "fDec")
        {
            objCPU.alu.fDec(objRAM.memory[IP][1], objCPU);
        }
    }
}

void CPU::start(const std::string& fName)
{
    RAM mem;
    mem.translate(fName);
    std::cout << "----- Program loaded -----\n" << std::endl;
    std::map<std::string, int> files = {
        {"fibonacci.txt", 1},
        {"factorial.txt", 2},
        {"oddsSum.txt", 3}
    };
    auto it = files.find(fName);
    if (it != files.end())
    {
        int variant = it->second;
        switch (variant)
        {
            case 1:
                std::cout << "This program calculates the nth Fibonacci number." << std::endl; 
                std::cout << "The Fibonacci sequence is a series of numbers in which each number is the sum of the two preceding ones.\n" << std::endl;
                std::cout << "The imported number is 6. The 6th Fibonacci number is ";
               break;
            case 2:
                std::cout << "This program calculates the factorial of a given number." << std::endl; 
                std::cout << "The factorial of a non-negative integer is the product of all positive integers less than or equal to that number.\n" << std::endl;
                std::cout << "The imported number is 5, the factorial of which is ";
                break;
            case 3:
                std::cout << "This program calculates the sum of odd numbers from 0 to a given positive integer." << std::endl;
                std::cout << "The imported number is 10, the sum of odd numbers from 0 to 10 is ";
                break;
        }
    }
    else
    {
        std::cout << "Unknown file name: " << fName << std::endl;
    }
    cu.analyze(mem, *this);
    std::cout << "\n----- CPU execution completed -----" << std::endl;

}

