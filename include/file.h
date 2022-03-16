#ifndef FILE_H
#define FILE_H

#include<fstream>

 void read_program_file(std::string filename, int *program){

     std::ifstream file(filename);

    if (!file) {
        std::cerr << "Cannot Read Program File" << std::endl;
        exit(EXIT_FAILURE);
    }

    int i = 0,line;

    while (file >> std::hex >> line) {
        program[i++] = line;
    }

    file.close();

 }

#endif