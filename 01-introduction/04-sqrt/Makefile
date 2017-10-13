.PHONY: all folder clean
CC := gcc
CFLAGS := -Wall -Wextra -std=c99 -pedantic -Werror -pipe -fPIC -D_DEFAULT_SOURCE -O0 -g
LDFLAGS := -g -fPIC

OBJS += obj/main.o
OBJS += obj/heron_step.o
OBJS += obj/heron_sqrt.o
OBJS += obj/is_equal.o
OBJS += obj/parse_number.o
OBJS += obj/print_result.o

all: folder sqrt

folder:
	mkdir -p obj 

clean:
	rm -f sqrt
	rm -rf obj

obj/main.o: src/main.c src/sqrt.h
	$(CC) $(CFLAGS) -c -o $@ $<

obj/%.o: src/%.c src/sqrt.h
	$(CC) $(CFLAGS) -c -o $@ $<

sqrt: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^
