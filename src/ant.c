#include <stdio.h>
#include <stdlib.h>

void getParams(int* width, int* height, int* steps);
void initialise(char** grid, int width, int height);
void print(char** grid, int width, int height);

int main(int argc, char* argv[]) {
   int width, height, steps;
   getParams(&width, &height, &steps);
   
   char** grid;
   grid = malloc(height * sizeof(*grid));
   for(int i = 0; i < width; i++) {
      grid[i] = malloc(width * sizeof(*grid[i]));
   }
   
   initialise(grid, width, height);
   
   grid[1][1] = '#';
   grid[1][2] = '>';
   
   print(grid, width, height);
   
   for(int i = 0; i < width; i++) {
      free(grid[i]);
   }
   free(grid);
}

void getParams(int* width, int* height, int* steps) {
   printf("width: \n");
   scanf("%d", width);
   printf("height: \n");
   scanf("%d", height);
   printf("steps: \n");
   scanf("%d", steps);
   
}

void initialise(char** grid, int width, int height) {
   for(int i = 0; i < height; i++) {
      for(int j = 0; j < width; j++) {
         grid[i][j] = '.';
      }
   }
}

void print(char** grid, int width, int height) {
   for(int i = 0; i < height; i++) {
      for(int j = 0; j < width; j++) {
         printf("%c", grid[i][j]);
      }
      printf("\n");
   }
}


