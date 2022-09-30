#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "parameterValidation.h"
#include "print.h"

void tic(World* world);

int main(int argc, char* argv[]) {
   World world;
   handleParameters(argc, argv, &world);
   int isValid = validate(&world);
   if(isValid == FALSE) {
      return EXIT_FAILURE;
   }
   
   char grid[world.size.y][world.size.x];
   for(int i = 0; i < world.size.y; i++) {
      for(int j = 0; j < world.size.x; j++) {
         grid[i][j] = '.';
      }
   }
   //TODO wie komm ich hier an die richtige Repräsentation der Ameise?
   grid[world.position.x][world.position.y] = '^';
   if(argc == 7) {
      tic(&world);
   }
   print(&world);
   return EXIT_SUCCESS;
}

void tic(World* world) {
   world->pos.x += 1;
   world->direction += 1;
}
