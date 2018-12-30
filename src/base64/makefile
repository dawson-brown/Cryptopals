CC=gcc
CFLAGS=-I. -lm
DEPS = parser.h ../../number_handler/number_handler.h
OBJ = main.o parser.o ../../number_handler/number_handler.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -g -o hex64 $^ $(CFLAGS)
