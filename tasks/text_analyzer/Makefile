CC = gcc

CFLAGS = -Wall -Wextra -g

TARGET = analyzer

OBJs = main.o file_exec.o

all: $(TARGET)

$(TARGET): $(OBJs)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJs)

main.o: main.c file_exec.h
	$(CC) $(CFLAGS) -c main.c

file_exec.o: file_exec.c file_exec.h
	$(CC) $(CFLAGS) -c file_exec.c

clean:
	rm -f $(TARGET) $(OBJs)

.PHONY: all clean