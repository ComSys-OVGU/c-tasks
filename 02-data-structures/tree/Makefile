.PHONY: all folder clean run unit_test
CC := gcc
CFLAGS := -Wall -Wextra -std=c99 -pedantic -Werror -pipe -fPIC -D_DEFAULT_SOURCE -I../../unit_test -O0 -g
LDFLAGS := -g -fPIC

OBJS += obj/main.o
OBJS += ../../unit_test/unit_test.a
OBJS += obj/create_student.o
OBJS += obj/init_tree.o
OBJS += obj/insert_student.o
OBJS += obj/search_student.o
OBJS += obj/foreach_student.o
OBJS += obj/delete_students.o

all: folder tree run

folder:
	mkdir -p obj 

clean:
	rm -f tree
	rm -rf obj

run: tree
	./tree

../../unit_test/unit_test.a:
	make -C ../../unit_test

obj/main.o: src/main.c src/tree.h ../../unit_test/unit_test.h
	$(CC) $(CFLAGS) -c -o $@ $<

obj/%.o: src/%.c src/tree.h
	$(CC) $(CFLAGS) -c -o $@ $<

tree: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^
