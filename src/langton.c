#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "parameterValidation.h"
#include "print.h"

int main(int argc, char* argv[]) {
   World world;
   handleParameters(argc, argv, &world);
   int validParams = validate(&world);
   
   if(validParams == FALSE) {
      return EXIT_FAILURE;
   }
   printGrid(&world);
   return EXIT_SUCCESS;
}

