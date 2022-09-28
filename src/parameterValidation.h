
enum dir {NORTH, EAST, SOUTH, WEST};

#define TRUE 1
#define FALSE 0
#define DEFAULT_SIZE 1
#define DEFAULT_POSITION 0
#define DEFAULT_DIRECTION 0

int validateParams(int size[], int position[], int direction);
int handleParameters(int argc, char* argv[], int* size, int* position, int* direction);
void getSize(int argc, char* argv[], int size[]);
void getPosition(int argc, char* argv[], int position[]);
void getDirection(int argc, char* argv[], int* direction);
int convertToInt(char* string);
int convertDirection(char direction[]);


int validateParams(int size[], int position[], int direction) {
   if(size[0] < 1 || size[1] < 1) {
      printf("invalid size: %d, %d\n", size[0], size[1]);
      return FALSE;
   }
   
   int leftBoundary = ((size[0]-1)/2) * -1;
   int rightBoundary = size[0]/2;
   int upperBoundary = ((size[1]-1)/2) * -1;
   int lowerBoundary = size[1]/2;
   
   if(position[0] < leftBoundary || rightBoundary < position[0]
   || position[1] < upperBoundary || lowerBoundary < position[1]) {
      printf("invalid position: %d, %d\n", position[0], position[1]);
      return FALSE;
   }
      
   if(direction < 0) {
      printf("invalid direction: %d\n", direction);
      return FALSE;
   }
   return TRUE;
}

int handleParameters(int argc, char* argv[], int* size, int* position, int* direction) {

   getSize(argc, argv, size);
   getPosition(argc, argv, position);
   getDirection(argc, argv, direction);
   return 0;
}

void getSize(int argc, char* argv[], int size[]) {
   if(argc>=2) {
      size[0] = convertToInt(argv[1]);
   } else {
      size[0] = DEFAULT_SIZE;
   }
   if(argc >= 3) {
      size[1] = convertToInt(argv[2]);
   } else {
      size[1] = DEFAULT_SIZE;
   }
}

void getPosition(int argc, char* argv[], int position[]) {
   if(argc >= 4) {
      position[0] = convertToInt(argv[3]);
   } else {
      position[0] = DEFAULT_POSITION;
   }
   if(argc >= 5) {
      position[1] = convertToInt(argv[4]);
   } else {
      position[1] = DEFAULT_POSITION;
   }
}

void getDirection(int argc, char* argv[], int* direction) {
   if(argc >= 6) {
      *direction = convertDirection(argv[5]);
   } else {
      *direction = DEFAULT_DIRECTION;
   }
}

int convertToInt(char* string) {
   char* endptr;
   int base = 10;
   return (int) strtol(string, &endptr, base);
}

int convertDirection(char direction[]) {
   if(0 == strcmp(direction, "north")) {
      return NORTH;
   } else if (0 == strcmp(direction, "east")) {
      return EAST;
   } else if (0 == strcmp(direction, "south")) {
      return SOUTH;
   } else if (0 == strcmp(direction, "west")) {
      return WEST;
   } else {
      return -1;
   }
}

