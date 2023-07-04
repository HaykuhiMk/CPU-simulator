# CPU-simulator

Abstract machine architecture and specifications including CPU, ALU, RAM and CU are defined. A set of instructions have been created that can be used to perform various operations on an abstract machine, including arithmetic and logical operations, data transfers, condition checks, and jump operations. Procedures for appropriate execution of instructions have been developed. The program is designed to handle errors and exceptions properly. The main functionality is implemented in the translate() member function of the RAM class. This is where the input file written in assembly language is read, parsed, and rendered understandable by the analyze() member function of the CU class. The analyze() member function of the CU class checks which of the existing instructions should be executed and how.

The result of the problem solved by the code written in pseudo-assembly language is not only printed on the screen, but also stored in a hardDisk text file.

 ## How to Run the Program
 
To execute the CPU-simulator program and view the results, follow the steps below:
Prerequisites: Ensure that you have CMake and a compatible C++ compiler installed on your system.

### Option 1: Running with CMake
1.Open a terminal or command prompt.

2.Navigate to the directory where you have downloaded or cloned the CPU-simulator repository.

3.Create a new directory called "build" for out-of-source builds:


mkdir build

4.Move into the "build" directory:


cd build

5.Generate the build files using CMake:


cmake ..

6.Build the project using the following command:


cmake --build . --config Release

7.Once the build process is complete, you can run the program by entering the following command:


./cpu

### Option 2: Running with Manual Compilation
1.Open a terminal or command prompt.

2.Navigate to the directory where you have downloaded or cloned the CPU-simulator repository.

3.Compile the source code files using the following command:

g++ -std=c++2a main.cpp ram.cpp cpu.cpp

Run the program by entering the following command:

./a.out

