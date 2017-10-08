.PHONY: all folder clean run unit_test
CC := gcc
CFLAGS := -Wall -Wextra -std=c99 -pedantic -Werror -pipe -fPIC -D_DEFAULT_SOURCE -I../../unit_test -O0 -g
LDFLAGS := -g -fPIC -lm -lpthread

OBJS += obj/main.o
OBJS += ../../unit_test/unit_test.a
OBJS += obj/prime_singlethreaded.o
OBJS += obj/prime_multithreaded.o

all: folder prime run

folder:
	mkdir -p obj 

clean:
	rm -f prime 
	rm -rf obj

run: prime
	./prime

../../unit_test/unit_test.a:
	make -C ../../unit_test

obj/main.o: src/main.c src/prime.h ../../unit_test/unit_test.h
	$(CC) $(CFLAGS) -c -o $@ $<

obj/%.o: src/%.c src/prime.h
	$(CC) $(CFLAGS) -c -o $@ $<

prime: $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)
