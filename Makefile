CC = gcc
AR = ar
CFLAGS = -Wall -g


.PHONY: all clean

all: my_graph my_Knapsack

my_graph: main.o libmymath.a
	$(CC) $(CFLAGS) $^ -o $@

my_Knapsack: knapsack.o libmymath.a
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c my_mat.h
	$(CC) $(CFLAGS) -c $<

my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c $<

knapsack.o: knapsack.c
	$(CC) $(CFLAGS) -c $<

libmymath.a: my_mat.o
	$(AR) rcs $@ $<


clean:
	rm -f *.o *.a my_graph my_Knapsack

