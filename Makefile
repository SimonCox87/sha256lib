CFLAGS = -g -Wall -fdiagnostics-color=always -Iinclude -O3 -march=native

test: test.o sha256.o sha1.o sha512.o sha384.o internal.o
	cc $(CFLAGS) -o test test.o sha256.o sha1.o sha512.o sha384.o internal.o
	
test.o: tests/test.c include/sha.h 
	cc $(CFLAGS) -c tests/test.c -o test.o

sha384.o: src/sha384.c include/sha.h src/internal.h
	cc $(CFLAGS) -c src/sha384.c -o sha384.o

sha512.o: src/sha512.c include/sha.h src/internal.h
	cc $(CFLAGS) -c src/sha512.c -o sha512.o

sha256.o: src/sha256.c include/sha.h src/internal.h
	cc $(CFLAGS) -c src/sha256.c -o sha256.o

sha1.o: src/sha1.c include/sha.h src/internal.h
	cc $(CFLAGS) -c src/sha1.c -o sha1.o

internal.o: src/internal.c src/internal.h
	cc $(CFLAGS) -c src/internal.c -o internal.o

clean:
	rm -f test *.o