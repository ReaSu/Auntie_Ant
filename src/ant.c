#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

enum dir {NORTH, EAST, SOUTH, WEST};

#define BLACK '#'
#define WHITE '_'
#define EMPTY '.'

typedef struct {
   int direction;
   char colour;
   char symbol;
} Field;

void getParams(int* width, int* height, int* steps);
void initialise(Field** grid, int width, int height);
int centre(int width);
int newX(int x, int direction);
int newY(int y, int direction);
void print(Field** grid, int width, int height);
char antHead(int dir);
void deallocate(Field** grid, int width);

int main(int argc, char* argv[]) {
   int direction = WEST;
   int width, height, steps;
   getParams(&width, &height, &steps);
   
   Field** grid;
   grid = malloc(height * sizeof(*grid));
   for(int i = 0; i < width; i++) {
      grid[i] = malloc(width * sizeof(*grid[i]));
   }
   // TODO linked list anstatt 2d-array?
   initialise(grid, width, height);
   
   int y0 = centre(height);
   int x0 = centre(width);
   // TODO invert direction on black fields
   
   for(int i = 0; i < steps; i++) {
      int old_x = x0;
      int old_y = y0;
      if(grid[y0][x0].colour == EMPTY || grid[y0][x0].colour == WHITE) {
         direction = (direction + 1) % 4;
         x0 = newX(x0, direction);
         y0 = newY(y0, direction);
         grid[old_y][old_x].colour = BLACK;
         grid[old_y][old_x].symbol = BLACK;
         grid[y0][x0].direction = direction;
         grid[y0][x0].symbol = antHead(direction);
      } else {
         direction = (direction + 3) % 4;
         x0 = newX(x0, direction);
         y0 = newY(y0, direction);
         grid[old_y][old_x].colour = WHITE;
         grid[old_y][old_x].symbol = WHITE;
         grid[y0][x0].direction = direction;
         grid[y0][x0].symbol = antHead(direction);
      }
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
   printf("height: ");
   scanf("%d", height);
   printf("steps: ");
   scanf("%d", steps);
   printf("\n");
   
}

void initialise(Field** grid, int width, int height) {
   for(int i = 0; i < height; i++) {
      for(int j = 0; j < width; j++) {
         grid[i][j].colour = EMPTY;
         grid[i][j].symbol = EMPTY;
      }
   }
   int y0 = centre(height);
   int x0 = centre(width);
   
   grid[y0][x0].direction = NORTH;
   grid[y0][x0].symbol = antHead(NORTH);
}

void print(Field** grid, int width, int height) {
   for(int i = 0; i < height; i++) {
      for(int j = 0; j < width; j++) {
         printf("%c", grid[i][j].symbol);
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

void deallocate(Field** grid, int width) {
   for(int i = 0; i < width; i++) {
      free(grid[i]);
   }
   free(grid);
}
