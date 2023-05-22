#ifndef RAM_H
#define RAM_H
#include <iostream>
#include <string>
#include <vector>
#include <map>

class RAM
{
public:
    void translate();
    std::map<int, std::vector<std::string> > memory;

private:
    std::vector<std::string> keywordsInstructions = {"fInc", "fDec", "fJmpLE", "fJmp", "fCmp", "fMov", "fAdd", "fSub", "fMul", "fDiv", "fAnd", "fOr", "fXor", "fNot", "fPrint", "fJmpG", "fJmpL", "fJmpE"};
    std::vector<std::string>  keywordsRegisters = {"fEax", "fEbx", "fEcx", "fEdx", "fEsi", "fCmpFlag", "fOffsetJmp"};
};

#endif  //RAM_H





