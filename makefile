CC = g++
CFLAGS = -g -Wall
EXC = submission
SRC = main.cpp
OBJ = $(SRC:.cpp = .o)
IN = input.txt
OUT = output.txt

all: $(OBJ)
	$(CC) $(CFLAGS) -o $(EXC) $(OBJ)

run: all
	./$(EXC)

clean:
	rm -f *.o $(EXC)
