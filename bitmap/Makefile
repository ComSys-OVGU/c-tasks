.PHONY: all folder clean run unit_test
CC := gcc
CFLAGS := -Wall -Wextra -std=c99 -pedantic -Werror -pipe -fPIC -D_DEFAULT_SOURCE -I../unit_test -O0 -g
LDFLAGS := -g -fPIC

OBJS += obj/compose-bmp.o

all: folder compose-bmp run

folder:
	mkdir -p obj 

clean:
	rm -f compose-bmp 
	rm -rf obj

run: compose-bmp
	./compose-bmp

obj/%.o: src/%.c 
	$(CC) $(CFLAGS) -c -o $@ $<

compose-bmp: $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)
