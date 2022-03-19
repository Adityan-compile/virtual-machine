#include <cstdlib>
#include <iostream>

#include "../../include/assembler.h"
#include "../../include/memory.h"
#include "../../include/file.h"

int main(int argc, char** argv) {
    
    Assembler assembler;

    if (argc < 3) {
        std::cerr << "Cannot Find Filename" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string program[MAX_MEMORY];

    read_program_file(argv[1], program);

    assembler.load_raw_prog(program,MAX_MEMORY);

    assembler.assemble();
    assembler.save_compiled_file(argv[2]);
    
    return EXIT_SUCCESS;
}