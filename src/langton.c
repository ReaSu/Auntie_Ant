#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int convertToInt(char* string);
void getSize(int argc, char* argv[], int size[]);
int getdirection(char direction[]);
void printGrid(int* size, int* position, int direction);
void printLineOfLength(int length);
void printLineWithAnt(int length, int ant);

int main(int argc, char* argv[]) {
   if(2 > argc || argc > 6) {
      printf("Please specify size.\n");
      return 2;
   }   
   int size[2];
   getSize(argc, argv, size);
   int position[2] = {0, 0};
   int direction = 1;
   if(argc > 3) {
      position[0] = convertToInt(argv[3]);
      position[1] = convertToInt(argv[4]);
      direction = getdirection(argv[5]);
   }

   printGrid(size, position, direction);
   return 0;
}

void getSize(int argc, char* argv[], int size[]) {
   size[0] = convertToInt(argv[1]);
   size[1] = 1;
   if(argc >= 3) {
      size[1] = convertToInt(argv[2]);
   }
}

int convertToInt(char* string) {
   char* endptr;
   int base = 10;
   return (int) strtol(string, &endptr, base);
}

int getdirection(char direction[]) {
   return 1;
}

void printGrid(int* size, int* position, int direction) {
   int y_0 = floor((size[1]-1)/2);
   int x_0 = floor((size[0]-1)/2);
   int x_pos = x_0 + position[0];
   int y_pos = y_0 + position[1];
   for(int i = 0; i < size[1]; i++) {
      if(i == y_pos) {
         printLineWithAnt(size[0], x_pos);
      } else {
         printLineOfLength(size[0]);
      }
   }
}

void printLineOfLength(int length) {
   for(int i = 0; i < length; i++) {
      printf(".");
   }
   printf("\n");

}

void printLineWithAnt(int length, int ant) {
   for(int i = 0; i < length; i++) {
      if(i == ant) {
         printf("^");
      } else {
         printf(".");
      }
   }
   printf("\n");

}
