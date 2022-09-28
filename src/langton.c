#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "parameterValidation.h"
#include "print.h"

int main(int argc, char* argv[]) {
   int size[2];
   int position[2];
   int direction;
   handleParameters(argc, argv, size, position, &direction);
   int validParams = validateParams(size, position, direction);
   
   if(validParams == FALSE) {
      return EXIT_FAILURE;
   }
   printGrid(size, position, direction);
   return EXIT_SUCCESS;
}

