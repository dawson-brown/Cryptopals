CC=gcc
CFLAGS=-I.
DEPS = ch3.h
OBJ = main.o ch3.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o main $^ $(CFLAGS)
