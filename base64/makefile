CC=gcc
CFLAGS=-I. -lssl -lcrypto
DEPS = parser.h base64.h
OBJ = main.o parser.o base64.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -g -o hex64 $^ $(CFLAGS)
