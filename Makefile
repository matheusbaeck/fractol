CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LIBS = -lpng

SRC = get_colour_set.c
TARGET = get_colour_set

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LIBS)

clean:
	rm -f $(TARGET)

.PHONY: all clean
