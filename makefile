VM_OBJ = bin/vm_main.o
ASSEMBLER_OBJ = bin/assembler_main.o
VM_SOURCE = vm/src/main.cpp
ASSEMBLER_SOURCE = assembler/src/main.cpp
HEADER = include/cpu.h include/memory.h include/instructionSet.h include/registers.h include/file.h
VM_OUT = bin/vm.out
ASSEMBLER_OUT = bin/assembler.out
CC = g++
FLAGS = -g -c -Wall
LFLAGS = 


all: vm assembler

vm: $(VM_OBJ)
	$(CC) -g $(VM_OBJ) -o $(VM_OUT) $(LFLAGS)

assembler: $(ASSEMBLER_OBJ)
	$(CC) -g $(ASSEMBLER_OBJ) -o $(ASSEMBLER_OUT) $(LFLAGS)

bin/vm_main.o: vm/src/main.cpp
	$(CC) $(FLAGS) vm/src/main.cpp -o bin/vm_main.o


bin/assembler_main.o: assembler/src/main.cpp
	$(CC) $(FLAGS) assembler/src/main.cpp -o bin/assembler_main.o


clean:
	rm -f $(VM_OBJ) $(ASSEMBLER_OBJ) $(VM_OUT) $(ASSEMBLER_OUT)


run_vm: $(OUT)
	./$(VM_OUT) $(file)

run_assembler: $(OUT)
	./$(ASSEMBLER_OUT) $(file)