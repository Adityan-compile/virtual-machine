#ifndef ASSEMBLER_H
#define ASSEMBLER_H
#include "memory.h"

struct Assembler {
    std::string raw_prog[MAX_MEMORY];
    int compiled[MAX_MEMORY];
};

#endif