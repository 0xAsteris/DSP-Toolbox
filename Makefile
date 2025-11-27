CC = gcc
CFLAGS = -O3 -Iinclude -Wall -Wextra
AR = ar
ARFLAGS = rcs

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, build/%.o, $(SRC))

lib: build/libdsp.a

build/libdsp.a: $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

examples/ex_complex: examples/ex_complex.c build/libdsp.a
	$(CC) $(CFLAGS) -o $@ $< -Lbuild -ldsp

clean:
	rm -f build/*.o build/libdsp.a examples/ex_complex

