#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <vector>

#define MAX_MEMORY 128 * 2
using std::vector;

struct Memory {
    int data[MAX_MEMORY];
    int prog_size = 0;

    void init() {
        std::cout << "Initializing Memory" << std::endl;
        for (int i = 0; i < MAX_MEMORY; i++) {
            data[i] = 0;
        }
    }

    void load_program(int *prog, int size) {
        prog_size = size;
        for (int i = 0; i < prog_size; i++) {
            data[i] = prog[i];
        }
    }

    void get_program() {
        for (int i = 0; i < prog_size; i++) {
            std::cout << data[i] << std::endl;
        }
    }

    int read_byte(int addr) {
        return data[addr];
    }
    int write_byte(int addr, int value) {
        return data[addr] = value;
    }
};

#endif