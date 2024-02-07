CC = gcc
AR = ar
CFLAGS = -Wall -g


.PHONY: all clean

all: connections

connections: main.o libmymath.a
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c my_mat.h
	$(CC) $(CFLAGS) -c $<

my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c $<	

libmymath.a: my_mat.o
	$(AR) rcs $@ $<


clean:
	rm -f *.o *.a connections
