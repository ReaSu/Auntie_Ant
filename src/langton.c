#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "parameterValidation.h"
#include "print.h"

int main(int argc, char* argv[]) {
   World world;
   int direction;
   handleParameters(argc, argv, &direction, &world);
   int validParams = validateParams(direction, &world);
   
   if(validParams == FALSE) {
      return EXIT_FAILURE;
   }
   printGrid(direction, &world);
   return EXIT_SUCCESS;
}

