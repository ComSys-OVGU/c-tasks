.PHONY: all folder clean run
CC := gcc
CFLAGS := -Wall -Wextra -std=c99 -pedantic -Werror -pipe -fPIC -D_DEFAULT_SOURCE -O0 -g
AR := ar
ARFLAGS := rcs

OBJS += obj/critical_fail.o
OBJS += obj/did_no_test_fail.o
OBJS += obj/globals.o
OBJS += obj/test.o
OBJS += obj/test_init.o
OBJS += obj/test_results.o

all: folder unit_test.a

folder:
	mkdir -p obj 

clean:
	rm -f unit_test.a 
	rm -rf obj

obj/%.o: src/%.c unit_test.h
	$(CC) $(CFLAGS) -c -o $@ $<

unit_test.a: $(OBJS)
	$(AR) $(ARFLAGS) -o $@ $^
