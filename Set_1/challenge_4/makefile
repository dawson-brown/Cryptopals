CC=gcc
CFLAGS=-I.
DEPS = ch4.h
OBJ = main.o ch4.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o main $^ $(CFLAGS)