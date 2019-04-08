CC=gcc
CFLAGS=-I. -lm
DEPS = modes.h
OBJ = main.o modes.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o main $^ $(CFLAGS)