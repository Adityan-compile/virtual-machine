#include <iostream>

#include "cpu.h"
#include "instructionSet.h"
#include "memory.h"

int main(void) {
    std::cout << "Starting Virtual Machine" << std::endl;

    CPU cpu;

    Memory mem;

    cpu.reset(mem);

    // Define a Simple Test Program
    int program[] = {
        LDA, 1,
        LDB, 1,
        ADD,
        P_AX,
        CLR,
        LDA, 3,
        LDB, 1,
        SUB,
        P_AX,
        CLR,
        LDA, 3,
        LDB, 3,
        MUL,
        P_AX,
        DIV,
        P_AX,
        HLT
    };

    // Calculate program Size and load into memory for Execution
    int prog_size = sizeof(program) / sizeof(program[0]);

    mem.load_program(program, prog_size);

    cpu.exec(mem);

    return 0;
}