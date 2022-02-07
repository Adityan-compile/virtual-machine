OBJS	= bin/main.o
SOURCE	= src/main.cpp
HEADER	= src/cpu.h src/memory.h src/instructionSet.h src/types.h src/registers.h src/flags.h
OUT	= bin/build.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 


all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)



bin/main.o: src/main.cpp
	$(CC) $(FLAGS) src/main.cpp -o bin/main.o



clean:
	rm -f $(OBJS) $(OUT)


run: $(OUT)
	./$(OUT)