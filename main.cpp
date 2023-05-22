#include <iostream>
#include "ram.h"
#include "cpu.h"

int main()
{
    std::cout << "========== CPU Simulator ==========\n" << std::endl;
    CPU cpu;
    cpu.start("oddsSum.txt");
}