CC = gcc
AR = ar
CFLAGS = -Wall -g

all: main.c

libStrList.a: my_mat.o
	$(AR) rcs libmy_mat.a my_mat.o

StrList.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c my_mat.c

main: main.o libStrList.a
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c StrList.h
	$(CC) $(CFLAGS) -c main.c


.PHONY: clean all

clean:
	rm -f *.o *.a main.c
