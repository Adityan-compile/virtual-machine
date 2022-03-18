#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <iostream>
#include "instructionSet.h"

void read_hex_file(std::string filename, int *program) {
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Cannot Read HEX File" << std::endl;
        exit(EXIT_FAILURE);
    }

    int i = 0, line;

    while (file >> std::hex >> line) {
        program[i++] = line;
    }

    file.close();
}
void read_program_file(std::string filename, std::string *program) {
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Cannot Read Program File" << std::endl;
        exit(EXIT_FAILURE);
    }

    int i = 0;

    std::string line;

    while (file >> line) {
        program[i++] = line;
    }

    file.close();
}

void write_hex_file(std::string filename, int *compiled, int compiled_size) {
    std::ofstream outstream(filename, std::fstream::out | std::fstream::trunc);

    if (!outstream) {
        std::cerr << "Cannot Write to Output file" << std::endl;
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i<compiled_size; i++){
          outstream << std::hex << compiled[i]<<std::endl;
        if(compiled[i] == HLT){
            break;
        }
    }
    outstream.close();
}

#endif