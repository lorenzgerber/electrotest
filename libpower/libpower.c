/**
 * libpower.c
 *
 * dynamic library for calculating power from
 * resistance or current
 *
 * Lorenz Gerber, 24.10.2016
 *
 */


#include <stdio.h>


float calc_power_r(float volt, float resistance)
{
  float power;
  power = (volt * volt) / resistance;
  return power;
}


float clac_power_i(float volt, float current)
{
  float power;
  power = volt * current;
  return power;

}
