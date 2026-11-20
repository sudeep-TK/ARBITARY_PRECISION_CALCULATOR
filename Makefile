
CC = gcc
TARGET = apc

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c,%.o,$(SRC))

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
