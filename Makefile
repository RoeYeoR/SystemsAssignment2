CC = gcc

AR = ar

CFLAGS = -Wall -g

.PHONY: all clean

all: my_graph my_Knapsack

my_graph: my_graph.o libmymath.a

	$(CC) $(CFLAGS) $^ -o $@

my_Knapsack: my_Knapsack.o libmymath.a

	$(CC) $(CFLAGS) $^ -o $@


my_mat.o: my_mat.c my_mat.h

	$(CC) $(CFLAGS) -c $<

	
my_graph.o: my_graph.c my_mat.h

	$(CC) $(CFLAGS) -c $<


my_Knapsack.o: my_Knapsack.c

	$(CC) $(CFLAGS) -c $<


libmymath.a: my_mat.o

	$(AR) rcs $@ $<


clean:

	rm -f *.o *.a my_graph my_Knapsack



