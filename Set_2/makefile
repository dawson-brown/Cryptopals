CC=gcc
CFLAGS=-I. -lm
DEPS = ch9.h
OBJ = main.o ch9.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o main $^ $(CFLAGS)