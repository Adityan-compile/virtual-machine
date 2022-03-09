#ifndef INSTRUCTION_SET_H
#define INSTRUCTION_SET_H

enum InstructionSet {

    // Register Manipulation
    LDA = 0x0A,    // Load Accumlator AX
    LDB = 0x0B,    // Load Register BX
    CLR_A = 0x0C,  // Clear Register AX
    CLR_B = 0x0D,  // Clear Register BX
    CLR_F = 0x0E,  // Clear Flags
    CLR = 0x0F,    // Clear all Registers
    INC_AX = 0x010,    // Increment value in AX
    DEC_AX = 0x011,    // Decrement value in AX
    INC_BX = 0x012,    // Increment value in BX
    DEC_BX = 0x013,    // Decrement value in BX
    P_AX = 0x014,   // Print AX Register
    P_BX = 0x015,   // Print BX Register

    // Arithmetic
    ADD = 0x016,  // Add
    SUB = 0x017,  // Subtract
    MUL = 0x018,  // Multiply
    DIV = 0x019,  // Divide
    AVG = 0x01A,  // Average

    // Logic
    AND = 0x01B,    // Perform Logical AND on AX AND BX
    OR = 0x01C,     // Perform Logical OR on AX AND BX
    NOT_A = 0x01D,  // Perform Logical NOT on AX
    NOT_B = 0x01E,  // Perform Logical NOT on BX

    // CPU/FLOW Control
    NOP = 0x01F,  // Do Nothing
    JMP = 0x020,  // Set Program Counter to Specified Value
    HLT = 0x021,  // Stop Program
};

#endif