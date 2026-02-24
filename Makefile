CFLAGS = -g -Wall -fdiagnostics-color=always -Iinlude -O3 -march=native

test: test.o sha256.o
	cc $(CFLAGS) -o test test.o sha256.o
	
test.o: tests/test.c include/sha.h
	cc $(CFLAGS) -c tests/test.c -o test.o

sha256.o: src/sha256.c include/sha.h
	cc $(CFLAGS) -c src/sha256.c -o sha256.o

clean:
	rm -f test *.o