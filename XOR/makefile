CC=gcc
CFLAGS=-I.
DEPS = parser.h xor.h
OBJ = main.o xor.o parser.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o xor $^ $(CFLAGS)
