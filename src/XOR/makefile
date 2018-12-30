CC=gcc
CFLAGS=-I. -lm
DEPS = parser.h xor.h ../../number_handler/number_handler.h ../../file_handler/file_handler.h
OBJ = main.o xor.o parser.o ../../number_handler/number_handler.o ../../file_handler/file_handler.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o xor $^ $(CFLAGS)
