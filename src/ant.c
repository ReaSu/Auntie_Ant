#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

enum dir {NORTH, EAST, SOUTH, WEST};

#define BLACK '#'
#define WHITE '_'

void getParams(int* width, int* height, int* steps);
void initialise(char** grid, int width, int height);
int centre(int width);
int newX(int x, int direction);
int newY(int y, int direction);
void print(char** grid, int width, int height);
char antHead(int dir);
void deallocate(char** grid, int width);


int main(int argc, char* argv[]) {
   int width, height, steps;
   getParams(&width, &height, &steps);
   int direction = NORTH;
   
   char** grid;
   grid = malloc(height * sizeof(*grid));
   for(int i = 0; i < width; i++) {
      grid[i] = malloc(width * sizeof(*grid[i]));
   }
   
   initialise(grid, width, height);
   
   int y0 = centre(height);
   int x0 = centre(width);
   
   for(int i = 0; i < steps; i++) {
      int old_x = x0;
      int old_y = y0;
      direction += 1;
      x0 = newX(x0, direction);
      y0 = newY(y0, direction);
      grid[y0][x0] = antHead(direction);
      grid[old_y][old_x] = BLACK;
   }
   
   print(grid, width, height);
   deallocate(grid, width);
}

int newX(int x, int direction) {
   switch(direction) {
      case 1:
         return x+1;
      case 3:
         return x-1;
      default:
         return x;
   }
}
int newY(int y, int direction) {
   switch(direction) {
      case 0:
         return y-1;
      case 2:
         return y+1;
      default:
         return y;
   }
}

int centre(int width) {
   return (width-1)/2;
}

void getParams(int* width, int* height, int* steps) {
   printf("width: ");
   scanf("%d", width);
   printf("\nheight: ");
   scanf("%d", height);
   printf("\nsteps: ");
   scanf("%d", steps);
   printf("\n");
   
}

void initialise(char** grid, int width, int height) {
   for(int i = 0; i < height; i++) {
      for(int j = 0; j < width; j++) {
         grid[i][j] = '.';
      }
   }
   int y0 = centre(height);
   int x0 = centre(width);
   
   grid[y0][x0] = antHead(NORTH);
}

void print(char** grid, int width, int height) {
   for(int i = 0; i < height; i++) {
      for(int j = 0; j < width; j++) {
         printf("%c", grid[i][j]);
      }
      printf("\n");
   }
}

char antHead(int dir){
   switch (dir) {
      case 0:
         return '^';
      case 1:
         return '>';
      case 2:
         return 'v';
      case 3:
         return '<';
   }
   return 'x';
}

void deallocate(char** grid, int width) {
   for(int i = 0; i < width; i++) {
      free(grid[i]);
   }
   free(grid);
}
