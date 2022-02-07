#include<iostream>
#include"cpu.h"
#include "memory.h"
#include "instructionSet.h"

int main(void){
    
    std::cout<<"Starting Virtual Machine"<<std::endl;

    CPU cpu;
    
    Memory mem;
    
    cpu.reset(mem);
  
    //Calculate program Size and load into memory
    int program[] = {
        LDA,
        1,
        P_AX,
        HLT
    };


    int prog_size = sizeof(program)/sizeof(program[0]);

    mem.load_program(program, prog_size);

    cpu.exec(mem);

    return 0;
}