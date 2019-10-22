#include "grid.h"

int main(int argc, char **argv) {

  int grid[5][5];

  if(argc != 3) {
    printf("Please enter grid_instance.txt and output.txt files\n");
    exit(EXIT_FAILURE);
  }

  printf("------------------\n");
  parse_grid(argv[1], grid);
  printf("Input grid:\n");
  print_grid(grid);
  
  solve_grid(grid);
  printf("Your output grid:\n");
  print_grid(grid);
  printf("------------------\n");

  write_grid(argv[2], grid);

  return 0;
}
