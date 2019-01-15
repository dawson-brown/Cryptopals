CC=gcc
CFLAGS=-I. -lm
DEPS = ../../crypto_handler/XOR/xor.h ../../number_handler/number_handler.h ../../file_handler/file_handler.h
OBJ = main.o ../../crypto_handler/XOR/xor.o ../../number_handler/number_handler.o ../../file_handler/file_handler.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o xor $^ $(CFLAGS)
