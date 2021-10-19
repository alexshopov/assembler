CC = gcc

CFLAGS=-Wall -pedantic -Werror

LDFLAGS = -L /local/lib -lcunit

default: assembler.o instructions.o
	$(CC) $(CFLAGS) -o assembler assembler.o instructions.o

assembler.o : assembler.c instructions.h
	gcc -c assembler.c

instructions.o : instructions.c instructions.h
	gcc -c instructions.c

testprogram.o : testprogram.c instructions.h
	gcc -c testprogram.c

test: testprogram.o instructions.o
	$(CC) $(CFLAGS) -o testprogram testprogram.o instructions.o -lcunit && ./testprogram

clean:
	rm *.o *.mif assembler testprogram