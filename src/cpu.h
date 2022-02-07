#ifndef CPU_H
#define CPU_H

#include<iostream>
#include "memory.h"
#include "instructionSet.h"
#include "flags.h"
#include "registers.h"

struct CPU {

    int PC, SP, running = 0; //Program Counter and Stack Pointer

    Registers registers;

    Flags flags;

    void reset(Memory& memory){
        std::cout<<"Resetting CPU"<<std::endl;
        PC = 0;
        SP = 0;
        registers.init();
        memory.init();
        flags.init();
    }

    int fetch_instruction( Memory& mem){
        int data = mem.read_byte(PC);
        PC++;
        return data;
    }

    void exec(Memory& memory){
        running = 1;
        while(running){
            int ins = fetch_instruction(memory);
            switch(ins){
                case LDA:{
                    int value = fetch_instruction(memory);
                    registers.AX = value;
                    if(registers.AX == 0){
                        flags.Z = 0;
                    }
                    break;
                }
                case P_AX:{
                    std::cout<<registers.AX<<std::endl;
                    break;
                }
                case MOV:{
                    int reg = fetch_instruction(memory);
                    int b = fetch_instruction(memory);
                    if(reg == registers.AX){
                        registers.AX = b;
                    }else if(reg == registers.BX){
                        registers.BX = b;
                    }else if(reg == registers.CX){
                        registers.CX = b;
                    }else if(reg == registers.DX){
                        registers.DX = b;
                    }else{
                        std::cout<<"Unknown Register"<<std::endl;
                    }
                    break;
                }
                case HLT:{
                    running = 0;
                    break;
                }
                default: {
                    std::cout<<"Unrecognised Instruction"<<std::endl;
                    break;
                }
            };
        }
    }

};


#endif