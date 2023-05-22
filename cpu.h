#ifndef CPU_H
#define CPU_H
#include <string>
#include "ram.h"

class CPU
{
public:
    void start();
    void setRegister(const std::string&, int);
    void setRegister(const std::string& reg1, const std::string& reg2);
    int getRegister(const std::string&);
    void printRegister(const std::string&);
private:
    int mEax = 0;
    int mEbx = 0;
    int mEcx = 0;
    int mEdx = 0;
    int mEsi = 0;
    int cmpFlag = 0;
    int offsetJmp = 0;
    class CU
    {
    public:
        void analyze(RAM&, CPU&);
    private:
        int IP {};
    };
    class ALU 
    {
    public:
        int add(const std::string&, const std::string&, CPU&);
        int mul(const std::string&, const std::string&, CPU&);
        int div(const std::string&, const std::string&, CPU&);
        int sub(const std::string&, const std::string&, CPU&);
        int modul(const std::string&, const std::string&, CPU&);
        bool fAnd(const std::string&, const std::string&, CPU&);
        bool fOr(const std::string&, const std::string&, CPU&);
        bool fXor(const std::string&, const std::string&, CPU&);
        bool fNot(const std::string&, CPU&);
        void fCmp(const std::string&, const std::string&, CPU&);
        bool fJmp(CPU&);
        bool fJmpLE(CPU&);
        bool fJmpG(CPU&);
        bool fJmpL(CPU&);
        bool fJmpE(CPU&);
        int fInc(const std::string&, CPU&);
        int fDec(const std::string&, CPU&);
  
    };
    ALU alu;
    CU cu;

};

#endif  //CPU_H