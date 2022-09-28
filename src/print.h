void printGrid(int* size, int* position, int direction);
void printLineOfLength(int length);
void printLineWithAnt(int length, int ant, int direction);
void printAnt(int direction);
int relativeZero(int size);
int relativePosition(int size, int position);

void printGrid(int* size, int* position, int direction) {
   int x_pos = relativePosition(size[0], position[0]);
   int y_pos = relativePosition(size[1], position[1]);
   for(int i = 0; i < size[1]; i++) {
      if(i == y_pos) {
         printLineWithAnt(size[0], x_pos, direction);
      } else {
         printLineOfLength(size[0]);
      }
   }
}

int relativePosition(int size, int position) {
   return position + relativeZero(size);
}

int relativeZero(int size) {
   return floor((size-1)/2);
}

void printLineOfLength(int length) {
   for(int i = 0; i < length; i++) {
      printf(".");
   }
   printf("\n");

}

void printLineWithAnt(int length, int ant, int direction) {
   for(int i = 0; i < length; i++) {
      if(i == ant) {
         printAnt(direction);
      } else {
         printf(".");
      }
   }
   printf("\n");
}

void printAnt(int direction) {
   switch (direction) {
      case NORTH:
         printf("^");
         break;
      case EAST:
         printf(">");
         break;
      case SOUTH:
         printf("v");
         break;
      case WEST:
         printf("<");
         break;
   }
}

