
/*

To compiler
gcc example1.c
This will create a.out (an executable)

Compile and ask compiler to tell you about potentially unsafe code
gcc -Wall example1.c


*/


#include <stdio.h>
#include <stdlib.h>


void velocity_update(int npoints, double v[])
{
  int i;

  for (i=0; i<npoints; i++) {
    //v[i] = v[i] + 0.1;
    v[i] += 0.1; // c incrementor
  }

  npoints = 2 * npoints;
  printf("velocity_update: npoints %d\n", npoints);
}



/*
This is a function every c/c++ code needs to gave.
syntax

return_type FUNCTION_NAME (  ARGUMENTS )
{

 BODY OF FUNCTION GOES HERE

}
*/
int main(int nargs, char *args[])
{
    // Different ways to declare (and assign) intgers
    int a;
    int b = 3;
    int c, d = 10, e;
    float dx = 0.1;
    float dp; // single precision number
    double dx2 = 1.0e-6; // 10^{-6} // double precision number

    // static memory allocation = size of array is known at compiler time
    double position[128]; // allocate 128 doubles, which can be accessed / refereced with the name "position"

    int nparticles = 10; // imagine this number comes from an input file
    double *velocity; // pointer to doubles


    printf("hello world\n");
    printf("Value of a = %d \n", a); // C never ever initalzes values of any variable
    printf("Value of b = %d \n", b); // %d is the "format specifier" for int's

    printf("dx = %f, dx2 = %lf \n", dx, dx2);
    printf("<use engineering notation> dx = %1.4e, dx2 = %1.4e \n", dx, dx2);
    //dx = 4.001;
    dx2 = 300000000.33;
    //printf("dx = %f, dx2 = %lf \n", dx, dx2);
    printf("<use engineering notation> dx = %1.2e, dx2 = %1.2e \n", dx, dx2);

    dx2 = dx + 11;

    // conditional
    if (b > 2) {
      printf("b > 2\n");
    } else {
      printf("b is not greater than 2\n");
    }

    if (b > 2) {
      printf("b > 2\n");
    } else if (b < 0){
      printf("b is < 0\n");
    } else {
      printf("else got to line 62\n");
    }


    // && = logical "and"
    // || = logical "or"
    if ( (b > 2) && (a < 0) || dx2 > 0.0 ) {
      printf("b > 2\n");
    } else {
      printf("b is not greater than 2\n");
    }

    // c++ ---> c = c + 1
    for (c=0; c<10; c++) {
      printf("c = %d\n", c);
    }


    // iniitlize position (static allocated array)
    for (c=0; c<128; c++) {
      position[c] = 0.0;
    }


    // memory allocation
    velocity = malloc( nparticles * sizeof(double) );
    for (c=0; c<nparticles; c++) {
       velocity[c] = 0.0;
    }

    printf("main-1: npoints %d\n", nparticles);
    velocity_update(nparticles, velocity);
    printf("main-2: npoints %d\n", nparticles);

    for (c=0; c<nparticles; c++) {
      printf("velocity[%d] = %+1.6e\n", c, velocity[c]);
    }



    free(velocity);

    return 0;
}
