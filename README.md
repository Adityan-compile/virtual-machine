# Simple CPU Emulator

## A Simple CPU Emulator Built Using C++.

### Instruction Set:

```
    LDA     [Load Accumlator AX]
    LDB     [Load Register BX]
    MOV     [Move to Register]
    CLR_A   [Clear Register AX]
    CLR_B   [Clear Register BX]
    CLR_F   [Clear Flags]
    CLR     [Clear all Registers]
    INC_AX  [Increment value in AX]
    DEC_AX  [Decrement value in AX]
    INC_BX  [Increment value in BX]
    DEC_BX  [Decrement value in BX]
    P_AX    [Print AX Register]
    P_BX    [Print BX Register]

    ADD  [Add AX & BX]
    SUB  [Subtract BX from AX]
    MUL  [Multiply AX & BX]
    DIV  [Divide  AX by BX]
    AVG  [Store Average of AX AND BX in AX]

    AND   [Perform Logical AND on AX AND BX]
    OR    [Perform Logical OR on AX AND BX]
    NOT_A [Perform Logical NOT on AX]
    NOT_B [Perform Logical NOT on BX]


    NOP,  [Do Nothing]
    JMP,  [Set Program Counter to Specified Value]
    HLT,  [Stop Program]

    ;  [Comment]

```
