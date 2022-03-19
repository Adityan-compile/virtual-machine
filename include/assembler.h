#ifndef ASSEMBLER_H
#define ASSEMBLER_H
#include <cstdlib>
#include <iostream>
#include <string>

#include "file.h"
#include "instructionSet.h"
#include "memory.h"

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

    bool starts_with(std::string toMatch) {
        // std::string::find returns 0 if toMatch is found at starting
        if (toMatch.find(';') == 0)
            return true;
        else
            return false;
    }

    void parse_instr(std::string curr_inst, int i) {
        if (curr_inst == "LDA") {
            compiled[i] = LDA;
            return;
        } else if (curr_inst == "LDB") {
            compiled[i] = LDB;
            return;
        } else if (curr_inst == "CLR_A") {
            compiled[i] = CLR_A;
            return;
        } else if (curr_inst == "CLR_B") {
            compiled[i] = CLR_B;
            return;
        } else if (curr_inst == "CLR_F") {
            compiled[i] = CLR_F;
            return;
        } else if (curr_inst == "CLR") {
            compiled[i] = CLR;
            return;
        } else if (curr_inst == "INC_AX") {
            compiled[i] = INC_AX;
            return;
        } else if (curr_inst == "INC_BX") {
            compiled[i] = INC_BX;
            return;
        } else if (curr_inst == "DEC_AX") {
            compiled[i] = DEC_AX;
            return;
        } else if (curr_inst == "DEC_BX") {
            compiled[i] = DEC_BX;
            return;
        } else if (curr_inst == "P_AX") {
            compiled[i] = P_AX;
            return;
        } else if (curr_inst == "P_BX") {
            compiled[i] = P_BX;
            return;
        } else if (curr_inst == "ADD") {
            compiled[i] = ADD;
            return;
        } else if (curr_inst == "SUB") {
            compiled[i] = SUB;
            return;
        } else if (curr_inst == "MUL") {
            compiled[i] = MUL;
            return;
        } else if (curr_inst == "DIV") {
            compiled[i] = DIV;
            return;
        } else if (curr_inst == "AVG") {
            compiled[i] = AVG;
            return;
        } else if (curr_inst == "AND") {
            compiled[i] = AND;
            return;
        } else if (curr_inst == "OR") {
            compiled[i] = OR;
            return;
        } else if (curr_inst == "NOT_A") {
            compiled[i] = NOT_A;
            return;
        } else if (curr_inst == "NOT_B") {
            compiled[i] = NOT_B;
            return;
        } else if (curr_inst == "NOP") {
            compiled[i] = NOP;
            return;
        } else if (curr_inst == "JMP") {
            compiled[i] = JMP;
            return;
        } else if (curr_inst == "HLT") {
            compiled[i] = HLT;
            return;
        } else if (curr_inst == "MOV") {
            compiled[i] = MOV;
            return;
        } else if (curr_inst == "AX") {
            compiled[i] = AX;
            return;
        } else if (curr_inst == "BX") {
            compiled[i] = BX;
            return;
        } else if (starts_with(curr_inst)) {
            return;
        } else if (contains_num(curr_inst)) {
            std::cout << contains_num(curr_inst) << std::endl;
            compiled[i] = std::atoi(curr_inst.c_str());
            return;
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

    void save_compiled_file(std::string filename) {
        int compiled_size = sizeof(compiled) / sizeof(compiled[0]);
        write_hex_file(filename, compiled, compiled_size);
    }
};

#endif