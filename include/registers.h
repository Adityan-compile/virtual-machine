#ifndef REGISTERS_H
#define REGISTERS_H

#include <iostream>

struct Registers {
    int AX, BX, PC, Z, S, IR;  // Registers
    void init() {
        std::cout << "Initializing Registers" << std::endl;
        AX = BX = PC = Z = S = IR = 0;
    }

    void clear() {
        std::cout << "Clearing Registers" << std::endl;
        AX = BX = Z = S = IR = 0;
    }

    void dump() {
        std::cout << "Dumping Registers" << std::endl;
        std::cout << "AX: [" << AX << "]" << std::endl;
        std::cout << "BX: [" << BX << "]" << std::endl;
        std::cout << "PC: [" << PC << "]" << std::endl;
        std::cout << "IR: [" << IR << "]" << std::endl;
        std::cout << "Z:  [" << Z << "]" << std::endl;
        std::cout << "S:  [" << S << "]" << std::endl;
    }
};

#endif