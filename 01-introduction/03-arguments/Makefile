.PHONY: all clean

CC = gcc
CFLAGS = -Wall -Wextra -pedantic -Werror -std=c99 -g -O0

all: knights

knights: knights.o
	$(CC) -o $@ $<

knights.o: knights.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f knights.o knights
