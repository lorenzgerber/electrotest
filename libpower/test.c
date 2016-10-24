#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libpower.h"


int main(int argc, char *argv[]){

  if (argc < 3){
    fprintf(stderr, "Usage: test volt resistance\n");
    exit(EXIT_FAILURE);
  }

  float result;
  float volt = atof(argv[1]);
  float resistance = atof(argv[2]);
  
  result = calc_power_r(volt, resistance);
  printf(" %f^2 / %f = %f \n", volt, resistance, result);

  return 0;
}
