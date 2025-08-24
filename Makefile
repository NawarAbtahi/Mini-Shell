# Compiler
CC = gcc

# Source and output
SRC = src/main.c src/cd.c src/getdir.c src/lsf.c src/quit.c src/clearscr.c
OUT = main

# Build rule
all: $(OUT)

$(OUT): $(SRC)
	$(CC) -o $(OUT) $(SRC)

# Run the compiled program
run: $(OUT)
	./$(OUT)

# Clean up
clean:
	rm -f $(OUT)

