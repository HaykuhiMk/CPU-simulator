# CPU-simulator

Abstract machine architecture and specifications including CPU, ALU, RAM and CU are defined. A set of instructions have been created that can be used to perform various operations on an abstract machine, including arithmetic and logical operations, data transfers, condition checks, and jump operations. Procedures for appropriate execution of instructions have been developed. The program is designed to handle errors and exceptions properly. The main functionality is implemented in the translate() member function of the RAM class. This is where the input file written in assembly language is read, parsed, and rendered understandable by the analyze() member function of the CU class. The analyze() member function of the CU class checks which of the existing instructions should be executed and how.

The result of the problem solved by the code written in pseudo-assembly language is not only printed on the screen, but also stored in a hardDisk text file.

It is necessary to run the program in terminal or Visual Studio Code IDE with the command g++ -std=c++2a main.cpp ram.cpp cpu.cpp. Then to see the result, you need to compile the ./a.out command.
