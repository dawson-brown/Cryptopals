CC=gcc
CFLAGS=-I. -lm
DEPS = ch5.h
OBJ = main.o ch5.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o main $^ $(CFLAGS)
