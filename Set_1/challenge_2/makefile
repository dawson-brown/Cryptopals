CC=gcc
CFLAGS=-I.
DEPS = ch2.h
OBJ = main.o ch2.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o main $^ $(CFLAGS)