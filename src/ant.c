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
int centre(int dimension);
void update(Field** grid, int current_x, int current_y, int* new_x, int* new_y, int direction, char colour);
int newX(int x, int direction);
int newY(int y, int direction);
void print(Field** grid, int width, int height);
char antHead(int dir);
void deallocate(Field** grid, int width);

int main(int argc, char* argv[]) {
   int direction = NORTH;
   int width, height, steps;
   getParams(&width, &height, &steps);
   
   Field** grid;
   grid = malloc(height * sizeof(*grid));
   for(int i = 0; i < width; i++) {
      grid[i] = malloc(width * sizeof(*grid[i]));
   }
   // TODO linked list anstatt 2d-array?
   initialise(grid, width, height);
   
   int new_y = centre(height);
   int new_x = centre(width);
   
   for(int i = 0; i < steps; i++) {
      int current_x = new_x;
      int current_y = new_y;
      char colour;
      if(grid[new_y][new_x].colour == EMPTY || grid[new_y][new_x].colour == WHITE) {
         direction = (direction + 1) % 4;
         colour = BLACK;
      } else {
         direction = (direction + 3) % 4;
         colour = WHITE;
      }
      update(grid, current_x, current_y, &new_x, &new_y, direction, colour);
   }
   
   print(grid, width, height);
   deallocate(grid, width);
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
   int new_y = centre(height);
   int new_x = centre(width);
   
   grid[new_y][new_x].direction = NORTH;
   grid[new_y][new_x].symbol = antHead(NORTH);
}

int centre(int dimension) {
   return (dimension-1)/2;
}

void update(Field** grid, int current_x, int current_y, int* new_x, int* new_y, int direction, char colour) {
   *new_x = newX(current_x, direction);
   *new_y = newY(current_y, direction);
   grid[current_y][current_x].colour = colour;
   grid[current_y][current_x].symbol = colour;
   grid[*new_y][*new_x].direction = direction;
   grid[*new_y][*new_x].symbol = antHead(direction);
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
