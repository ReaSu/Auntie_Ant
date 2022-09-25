#include <stdlib.h>
#include <stdio.h>

int convertToInt(char* string);
void getSize(int argc, char* argv[], int size[]);
void printGrid(int* size);
void printLineOfLength(int length);

int main(int argc, char* argv[]) {
   if(2 > argc || argc > 5) {
      printf("Please specify size.\n");
      return 2;
   }   
   int size[2];
   getSize(argc, argv, size);

//   printf("x");

   printGrid(size);
   return 0;
}

void getSize(int argc, char* argv[], int size[]) {
   size[0] = convertToInt(argv[1]);
   size[1] = 1;
   if(argc == 3) {
      size[1] = convertToInt(argv[2]);
   }
}

int convertToInt(char* string) {
   char* endptr;
   int base = 10;
   return (int) strtol(string, &endptr, base);
}

void printGrid(int* size) {
   for(int i = 0; i < size[1]; i++) {
      printLineOfLength(size[0]);
   }
}

void printLineOfLength(int length) {
   for(int i = 0; i < length; i++) {
      printf(".");
   }
   printf("\n");

}
