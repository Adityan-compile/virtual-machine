#ifndef CPU_H
#define CPU_H

#include <iostream>
#include <string>

#include "instructionSet.h"
#include "memory.h"
#include "registers.h"

struct CPU {
    int running = 0;  //CPU Running Status

    Registers registers;  // Create Registers Object

    /*
      Reset CPU to Clean State before Startup
    */
    void reset(Memory& memory) {
        std::cout << "Resetting CPU" << std::endl;
        registers.init();
        memory.init();
    }

    /*
      Fetch and Instruction and Increment Program Counter
    */
    int fetch_instruction(Memory& mem) {
        int data = mem.read_byte(registers.PC);
        registers.PC++;
        return data;
    }

    /*
       Functions for Performing Arithmetic Operations on Registers(AX & BX)
    */
    void add() {
        int result = registers.AX + registers.BX;
        registers.AX = result;
    }

    void sub() {
        int result = registers.AX - registers.BX;
        registers.AX = result;
    }

    void multiply() {
        int result = registers.AX * registers.BX;
        registers.AX = result;
    }

    void divide() {
        if (registers.BX == 0) {
            std::cout << "Cannot Divide by Zero" << std::endl;
            registers.dump();
            running = 0;
            return;
        }
        int result = registers.AX / registers.BX;
        registers.AX = result;
    }

    void average() {
        int result = (registers.AX + registers.BX) / 2;
        registers.AX = result;
    }

    /*
      Functions for Performing Logical Operations on Registers(AX & BX)
    */
    void logic_and() {
        int result = registers.AX && registers.BX;
        registers.AX = result;
    }
    void logic_or() {
        int result = registers.AX || registers.BX;
        registers.AX = result;
    }
    void logic_not_ax() {
        int result = !registers.AX;
        registers.AX = result;
    }
    void logic_not_bx() {
        int result = !registers.BX;
        registers.AX = result;
    }

    /*
     Load Value to AX Register
    */
    void load_ax(Memory& memory) {
        int value = fetch_instruction(memory);
        registers.AX = value;
        if (registers.AX == 0) {
            registers.Z = 0;
        }
    }

    /*
     Load Value to AX Register
    */
    void load_bx(Memory& memory) {
        int value = fetch_instruction(memory);
        registers.BX = value;
    }

    /*
      Functions for Clearing Individual Registers
    */
    void clear_ax() {
        registers.AX = 0;
    }
    void clear_bx() {
        registers.BX = 0;
    }
    void clear_flags() {
        registers.S = registers.Z = 0;
    }

    /*
      Set Program Counter to Specified Value
    */
     void jump(Memory& memory){
         int value = fetch_instruction(memory);
         if(value >= MAX_MEMORY){
             std::cout<<"Memory Index Out of Bounds"<<std::endl;
             registers.dump();
             running = 0;
             return;
         }
         registers.PC = value;
     }

    /*
      Functions for Decrementing and Incrementing Values in Registers
    */
    void inc_ax() {
        registers.AX++;
    }
    void dec_ax() {
        registers.AX--;
    }
    void inc_bx() {
        registers.BX++;
    }
    void dec_bx() {
        registers.BX--;
    }

    /*
      Read Instructions from Memory and Execute
    */
    void exec(Memory& memory) {
        running = 1;
        while (running) {
            registers.IR = fetch_instruction(memory);
            switch (registers.IR) {
                case LDA: {
                    load_ax(memory);
                    break;
                }
                case LDB: {
                    load_bx(memory);
                    break;
                }
                case P_AX: {
                    std::cout << registers.AX << std::endl;
                    break;
                }
                case P_BX: {
                    std::cout << registers.BX << std::endl;
                    break;
                }
                case CLR: {
                    registers.clear();
                    break;
                }
                case CLR_A: {
                    clear_ax();
                    break;
                }
                case CLR_B: {
                    clear_bx();
                    break;
                }
                case CLR_F: {
                    clear_flags();
                    break;
                }
                case INC_AX: {
                    inc_ax();
                    break;
                }
                case DEC_AX: {
                    dec_ax();
                    break;
                }
                case INC_BX: {
                    inc_bx();
                    break;
                }
                case DEC_BX: {
                    dec_bx();
                    break;
                }
                case ADD: {
                    add();
                    break;
                }
                case SUB: {
                    sub();
                    break;
                }
                case MUL: {
                    multiply();
                    break;
                }
                case DIV: {
                    divide();
                    break;
                }
                case AVG: {
                    average();
                    break;
                }
                case AND:{
                    logic_and();
                    break;
                }
                case OR:{
                    logic_or();
                    break;
                }
                case NOT_A:{
                    logic_not_ax();
                    break;
                }
                case NOT_B:{
                    logic_not_bx();
                    break;
                }
                case JMP: {
                    jump(memory);
                    break;
                }
                case NOP: {
                    break;
                }
                case HLT: {
                    running = 0;
                    break;
                }
                default: {
                    std::cout << "Unrecognised Instruction: [" << registers.IR << "]" << std::endl;
                    registers.dump();
                    running = 0;
                    break;
                }
            };
        }
    }
};

#endif