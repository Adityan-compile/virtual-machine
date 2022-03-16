#ifndef FILE_H
#define FILE_H

#include <fstream>

void read_hex_file(std::string filename, int *program) {
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Cannot Read Program File" << std::endl;
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

    int i = 0, line;

    while (file >> line) {
        program[i++] = line;
    }

    file.close();
}

void write_hex_file(std::string filename, int *compiled, int compiled_size) {
    std::ofstream outstream(filename, std::fstream::app);

    if (!outstream) {
        std::cerr << "Cannot Write to Output file" << std::endl;
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i<compiled_size; i++){
        outstream << std::hex << compiled[i]<<std::endl;
    }
    outstream.close();
}

#endif