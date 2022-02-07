#ifndef REGISTERS_H
#define REGISTERS_H

#include<iostream>

struct Registers {
    int AX, BX, CX, DX;  // Registers
    void init() {
        std::cout<<"Initializing Registers"<<std::endl;
        AX = BX = CX = DX = 0;
    }
};

#endif