CC=gcc
CFLAGS=-I.
DEPS = parser.h
OBJ = hex64.o parser.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o hex64 $^ $(CFLAGS)
