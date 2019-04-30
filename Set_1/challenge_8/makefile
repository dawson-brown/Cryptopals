CC=gcc
CFLAGS=-I. -lm
DEPS = ch8.h
OBJ = main.o ch8.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o main $^ $(CFLAGS)