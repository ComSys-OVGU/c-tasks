.PHONY: all folder clean run unit_test
CC := gcc
CFLAGS := -Wall -Wextra -std=c99 -pedantic -Werror -pipe -fPIC -D_DEFAULT_SOURCE -I../../unit_test -O0 -g
LDFLAGS := -g -fPIC

OBJS += obj/main.o
OBJS += ../../unit_test/unit_test.a
OBJS += obj/fib_slow.o
OBJS += obj/fib_fast.o

all: folder fib run

folder:
	mkdir -p obj 

clean:
	rm -f fib
	rm -rf obj

run: fib
	./fib

../../unit_test/unit_test.a:
	make -C ../../unit_test

obj/main.o: src/main.c src/fib.h ../../unit_test/unit_test.h
	$(CC) $(CFLAGS) -c -o $@ $<

obj/%.o: src/%.c src/fib.h
	$(CC) $(CFLAGS) -c -o $@ $<

fib: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^
