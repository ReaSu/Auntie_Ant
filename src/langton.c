#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "parameterValidation.h"
#include "print.h"

int main(int argc, char* argv[]) {
   World world;
   int position[2];
   int direction;
   handleParameters(argc, argv, position, &direction, &world);
   int validParams = validateParams(position, direction, &world);
   
   if(validParams == FALSE) {
      return EXIT_FAILURE;
   }
   printGrid(position, direction, &world);
   return EXIT_SUCCESS;
}

