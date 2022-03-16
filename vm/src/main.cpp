#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>

#include "../../include/cpu.h"
#include "../../include/instructionSet.h"
#include "../../include/memory.h"
#include "../../include/file.h"


int main(int argc, char** argv) {
    std::cout << "Starting Virtual Machine" << std::endl;

    CPU cpu;

    Memory mem;

    cpu.reset(mem);

    int program[MAX_MEMORY];


    if (argc <= 1) {
        std::cerr << "No Filename Found" << std::endl;
    }

    read_hex_file(argv[1], program);

    // Calculate program Size and load into memory for Execution
    int prog_size = sizeof(program) / sizeof(program[0]);

    mem.load_program(program, prog_size);

    cpu.exec(mem);

    return EXIT_SUCCESS;
}