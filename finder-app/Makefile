.SILENT:

CROSS_COMPILE = ''
CC = gcc

all: writer

writer: writer.o
	$(CROSS_COMPILE)$(CC) -o writer writer.o

writer.o: writer.c
	$(CROSS_COMPILE)$(CC) -c writer.c

.PHONY: clean

clean: 
	rm -f writer writer.o


