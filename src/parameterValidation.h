
enum dir {NORTH, EAST, SOUTH, WEST};

#define TRUE 1
#define FALSE 0
#define DEFAULT_SIZE 1
#define DEFAULT_POSITION 0
#define DEFAULT_DIRECTION 0

typedef struct {
   int size[2];
   int position[2];
   int direction;
} World;

int validateParams(int direction, World* world);
int handleParameters(int argc, char* argv[], int* direction, World* world);
void getSize(int argc, char* argv[], World* world);
void getPosition(int argc, char* argv[], World* world);
void getDirection(int argc, char* argv[], int* direction);
int convertToInt(char* string);
int convertDirection(char direction[]);


int validateParams(int direction, World* world) {
   if(world->size[0] < 1 || world->size[1] < 1) {
      printf("invalid size: %d, %d\n", world->size[0], world->size[1]);
      return FALSE;
   }
   
   int leftBoundary = ((world->size[0]-1)/2) * -1;
   int rightBoundary = world->size[0]/2;
   int upperBoundary = ((world->size[1]-1)/2) * -1;
   int lowerBoundary = world->size[1]/2;
   
   if(world->position[0] < leftBoundary || rightBoundary < world->position[0]
   || world->position[1] < upperBoundary || lowerBoundary < world->position[1]) {
      printf("invalid position: %d, %d\n", world->position[0], world->position[1]);
      return FALSE;
   }
      
   if(direction < 0) {
      printf("invalid direction: %d\n", direction);
      return FALSE;
   }
   return TRUE;
}

int handleParameters(int argc, char* argv[], int* direction, World* world) {

   getSize(argc, argv, world);
   getPosition(argc, argv, world);
   getDirection(argc, argv, direction);
   return 0;
}

void getSize(int argc, char* argv[], World* world) {
   if(argc>=2) {
      world->size[0] = convertToInt(argv[1]);
   } else {
      world->size[0] = DEFAULT_SIZE;
   }
   if(argc >= 3) {
      world->size[1] = convertToInt(argv[2]);
   } else {
      world->size[1] = DEFAULT_SIZE;
   }
}

void getPosition(int argc, char* argv[], World* world) {
   if(argc >= 4) {
      world->position[0] = convertToInt(argv[3]);
   } else {
      world->position[0] = DEFAULT_POSITION;
   }
   if(argc >= 5) {
      world->position[1] = convertToInt(argv[4]);
   } else {
      world->position[1] = DEFAULT_POSITION;
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

