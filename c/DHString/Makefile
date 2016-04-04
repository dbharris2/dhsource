CC = gcc
CFLAGS = -I.

DEPS = DHString.h
OBJ = DHString.o DHStringCopyTests.o DHStringReverseTests.o DHStringSizeTests.o AllTests.o CuTest.o CuTestTest.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

stringTests: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o *~ stringTests 

