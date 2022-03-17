#ifndef ASSEMBLER_H
#define ASSEMBLER_H
#include <cstdlib>
#include <iostream>
#include <string>

#include "instructionSet.h"
#include "memory.h"
#include "file.h"

struct Assembler {
    std::string raw_prog[MAX_MEMORY];
    int compiled[MAX_MEMORY];

    void load_raw_prog(std::string* prog, int size) {
        for (int i = 0; i < size; i++) {
            raw_prog[i] = prog[i];
        }
    }

    bool contains_num(std::string input_str) {
        char* p;
        strtol(input_str.c_str(), &p, 0);
        return *p == 0;
    }

    void parse_instr(std::string curr_inst, int i) {
        if (curr_inst == "LDA") {
            compiled[i] = LDA;
        } else if (curr_inst == "LDB") {
            compiled[i] = LDB;
        } else if (curr_inst == "CLR_A") {
            compiled[i] = CLR_A;
        } else if (curr_inst == "CLR_B") {
            compiled[i] = CLR_B;
        } else if (curr_inst == "CLR_F") {
            compiled[i] = CLR_F;
        } else if (curr_inst == "CLR") {
            compiled[i] = CLR;
        } else if (curr_inst == "INC_AX") {
            compiled[i] = INC_AX;
        } else if (curr_inst == "INC_BX") {
            compiled[i] = INC_BX;
        } else if (curr_inst == "DEC_AX") {
            compiled[i] = DEC_AX;
        } else if (curr_inst == "DEC_BX") {
            compiled[i] = DEC_BX;
        } else if (curr_inst == "P_AX") {
            compiled[i] = P_AX;
        } else if (curr_inst == "P_BX") {
            compiled[i] = P_BX;
        } else if (curr_inst == "ADD") {
            compiled[i] = ADD;
        } else if (curr_inst == "SUB") {
            compiled[i] = SUB;
        } else if (curr_inst == "MUL") {
            compiled[i] = MUL;
        } else if (curr_inst == "DIV") {
            compiled[i] = DIV;
        } else if (curr_inst == "AVG") {
            compiled[i] = AVG;
        } else if (curr_inst == "AND") {
            compiled[i] = AND;
        } else if (curr_inst == "OR") {
            compiled[i] = OR;
        } else if (curr_inst == "NOT_A") {
            compiled[i] = NOT_A;
        } else if (curr_inst == "NOT_B") {
            compiled[i] = NOT_B;
        } else if (curr_inst == "NOP") {
            compiled[i] = NOP;
        } else if (curr_inst == "JMP") {
            compiled[i] = JMP;
        } else if (curr_inst == "HLT") {
            compiled[i] = HLT;
        }else if (curr_inst == "MOV") {
            return;
        } else if (contains_num(curr_inst)) {
            compiled[i] = std::stoi(curr_inst);
        } else {
            std::cerr << "Error: Unknown Instruction [" << curr_inst << "]" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    void assemble() {
        for (size_t i = 0; i < MAX_MEMORY; i++) {
            std::string curr_inst = raw_prog[i];
            parse_instr(curr_inst, i);
        }
    }

    void save_compiled_file(std::string filename){
        int compiled_size = sizeof(compiled)/ sizeof(compiled[0]);
    }

};

#endif