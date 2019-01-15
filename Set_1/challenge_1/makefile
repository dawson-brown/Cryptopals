CC=gcc
CFLAGS=-I. -lm
DEPS = ch1.h
OBJ = main.o ch1.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -g -o main $^ $(CFLAGS)
