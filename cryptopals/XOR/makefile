CC=gcc
CFLAGS=-I. -lm
DEPS = parser.h xor.h ../base64/base64.h
OBJ = main.o xor.o parser.o ../base64/base64.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o xor $^ $(CFLAGS)
