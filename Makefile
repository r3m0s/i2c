CC=gcc
CFLAGS=-O2 -Wall -g

SOURCES=main.c draw.c checker.c
OBJECTS=$(SOURCES:.c=.o)

TARGET=connect4

.PHONY: clean mrproper

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $^

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o

mrproper: clean
	rm -f $(TARGET)
