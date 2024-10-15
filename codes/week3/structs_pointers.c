
#include "stdio.h"

struct DEM {
  int    npoints; // number of DEM particles
  double radius;
  double *position;
  double *velocity;
  double *acceleration;
  double *velocity_angular;
  double *mass;
};

typedef long int t_idx_; // alias "long int" to "t_idx_"
typedef struct DEM MyDEM; // alias "struct DEM" to "MyDEM"

/*
Set the number of particles, and their radii,
Allocate memory for position, vel, accel, velocity_angular, mass

This function is not working because d is copied and only the copy is modified.
After function call is finished the copy iis destroyed and we are left with the original again.
*/
void initialize_points_pass_by_value(int np, struct DEM d)
{
  t_idx_ points;

  d.npoints = np;  // assign npoints to be equal to np
}

void initialize_points(int np, struct DEM *d)
{
  //d->npoints = np;  // assign npoints to be equal to np
  (*d).npoints = np;  // assign npoints to be equal to np
}

void dem_get_npoints(struct DEM d, int *np)
{
  (*np) = d.npoints;
}


int main(int nargs, char *args[])
{
  //struct DEM grain_properties;
  MyDEM grain_properties;
  int n;

  printf("<before> number of particles: %d\n", grain_properties.npoints);
  //initialize_points_pass_by_value(10, grain_properties);
  initialize_points(10, &grain_properties);
  printf("<after> number of particles: %d\n", grain_properties.npoints);

  n = 0;
  dem_get_npoints(grain_properties, &n);

  return 0;
}
