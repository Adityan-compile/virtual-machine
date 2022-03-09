#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>

#include "cpu.h"
#include "instructionSet.h"
#include "memory.h"
#include "file.h"


int main(int argc, char** argv) {
    std::cout << "Starting Virtual Machine" << std::endl;

    CPU cpu;

    Memory mem;

    cpu.reset(mem);

    int program[MAX_MEMORY];


    if (argc <= 1) {
        std::cerr << "No Filename Found" << std::endl;
    }


    // std::ifstream file(argv[1]);

    // if (!file) {
    //     std::cerr << "Cannot Read Program File" << std::endl;
    //     exit(EXIT_FAILURE);
    // }

    // int i = 0,line;

    // while (file >> std::hex >> line) {
    //     program[i++] = line;
    // }

    // file.close();

    read_program_file(argv[1], program);

    // Calculate program Size and load into memory for Execution
    int prog_size = sizeof(program) / sizeof(program[0]);

    mem.load_program(program, prog_size);

    cpu.exec(mem);

    return EXIT_SUCCESS;
}