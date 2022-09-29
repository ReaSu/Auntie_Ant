
enum dir {NORTH, EAST, SOUTH, WEST};

#define TRUE 1
#define FALSE 0
#define DEFAULT_SIZE 1
#define DEFAULT_POSITION 0
#define DEFAULT_DIRECTION 0

typedef struct {
   int x;
   int y;
} Size;

typedef struct {
   Size size;
   int position[2];
   int direction;
} World;

int validate(World* world);
int handleParameters(int argc, char* argv[], World* world);
void getSize(int argc, char* argv[], World* world);
void getPosition(int argc, char* argv[], World* world);
void getDirection(int argc, char* argv[], World* world);
int convertToInt(char* string);
int convertDirection(char direction[]);


int validate(World* world) {
   if(world->size.x < 1 || world->size.y < 1) {
      printf("invalid size: %d, %d\n", world->size.x, world->size.y);
      return FALSE;
   }
   
   int leftBoundary = ((world->size.x-1)/2) * -1;
   int rightBoundary = world->size.x/2;
   int upperBoundary = ((world->size.y-1)/2) * -1;
   int lowerBoundary = world->size.y/2;
   
   if(world->position[0] < leftBoundary || rightBoundary < world->position[0]
   || world->position[1] < upperBoundary || lowerBoundary < world->position[1]) {
      printf("invalid position: %d, %d\n", world->position[0], world->position[1]);
      return FALSE;
   }
      
   if(world->direction < 0) {
      printf("invalid direction: %d\n", world->direction);
      return FALSE;
   }
   return TRUE;
}

int handleParameters(int argc, char* argv[], World* world) {

   getSize(argc, argv, world);
   getPosition(argc, argv, world);
   getDirection(argc, argv, world);
   return 0;
}

void getSize(int argc, char* argv[], World* world) {
   if(argc>=2) {
      world->size.x = convertToInt(argv[1]);
   } else {
      world->size.x = DEFAULT_SIZE;
   }
   if(argc >= 3) {
      world->size.y = convertToInt(argv[2]);
   } else {
      world->size.y = DEFAULT_SIZE;
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

void getDirection(int argc, char* argv[], World* world) {
   if(argc >= 6) {
      world->direction = convertDirection(argv[5]);
   } else {
      world->direction = DEFAULT_DIRECTION;
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

