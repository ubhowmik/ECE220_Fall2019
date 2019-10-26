
grid_test: grid.c main.c
	g++ -c grid.c -o grid.o
	g++ -c main.c -o main.o
	g++ main.o grid.o -o grid

clean:
	rm *.o

grid1: grid_test
	./grid grid1.txt sol_grid1.txt

grid2: grid_test
	./grid grid2.txt sol_grid2.txt

grid3: grid_test
	./grid grid3.txt sol_grid3.txt

all: 
	$(MAKE) main.c
