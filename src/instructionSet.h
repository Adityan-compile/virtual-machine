#ifndef INSTRUCTION_SET_H
#define INSTRUCTION_SET_H

enum InstructionSet {

    // Register Manipulation
    LDA,    // Load Accumlator AX
    LDB,    // Load Register BX
    CLR_A,  // Clear Register AX
    CLR_B,  // Clear Register BX
    CLR_F,  // Clear Flags
    INC,    // Increment value in AX
    DEC,    // Decrement value in AX
    P_AX,   // Print AX Register
    P_BX,   // Print BX Register

    // Arithmetic
    ADD,  // Add
    SUB,  // Subtract
    MUL,  // Multiply
    DIV,  // Divide
    AVG,  // Average

    // Logic
    AND,    // Perform Logical AND on AX AND BX
    OR,     // Perform Logical OR on AX AND BX
    NOT_A,  // Perform Logical NOT on AX
    NOT_B,  // Perform Logical NOT on BX

    // CPU/FLOW Control
    NOP,  // Do Nothing
    JMP,  // Set Program Counter to Specified Address
    HLT,  // Stop Program
};

#endif