#ifndef CPU_H
#define CPU_H

#include <iostream>
#include <string>

#include "instructionSet.h"
#include "memory.h"
#include "registers.h"

struct CPU {
    int running = 0;  // Program Counter and CPU Running Status

    Registers registers;  // Create Registers Object

    /*
      Reset CPU to Clean State
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
       Add AX & BX Registers and Store Results into AX
    */
    void add() {
        int result = registers.AX + registers.BX;
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
      Read Instructions from Memory and Execute
    */
    void exec(Memory& memory) {
        running = 1;
        while (running) {
            int instr = fetch_instruction(memory);
            switch (instr) {
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
                case ADD: {
                    add();
                    break;
                }
                case HLT: {
                    running = 0;
                    break;
                }
                default: {
                    std::cout << "Unrecognised Instruction: [" << instr << "]" << std::endl;
                    registers.dump();
                    running = 0;
                    break;
                }
            };
        }
    }
};

#endif