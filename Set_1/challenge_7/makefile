CC=gcc
CFLAGS=-I. -lm
DEPS = ch7.h ../../Block_Modes/modes.h ../../AES/aes.h
OBJ = main.o ch7.o ../../AES/aes.o ../../Block_Modes/modes.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o main $^ $(CFLAGS)