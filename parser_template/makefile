CC=gcc
CFLAGS=-I.
DEPS = parser.h
OBJ = main.o parser.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o parser $^ $(CFLAGS)
