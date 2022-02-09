#ifndef REGISTERS_H
#define REGISTERS_H

#include<iostream>

struct Registers {
    int AX, BX;  // Registers
    void init() {
        std::cout<<"Initializing Registers"<<std::endl;
        AX = BX = 0;
    }
};

#endif