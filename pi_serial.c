//Varun Ramani, this program estimates pi using a for loop that estimates and sums up pi for an inputted number of points and comapres error to actual pi.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
      printf("Usage: ./pi_serial num(1-10)\n");
      return 1;
  }
  int n = atoi(argv[1]);
  if (!(n > 0 && n < 11)) {
      printf("Usage: ./pi_serial num(1-10)\n");
      return 1;
  }
  //turn n into the correct areas
  int areas = pow(10, n);
  double sum = 0;
  //define amount x should increment by dividing 1 by area
  double xIncrement = 1/areas;
  
  for (double currentx = 0; currentx <= 1; currentx += xIncrement) {
      //equation to calculate pi using integral
      sum += (double) 4.0/(1.0 + pow(currentx, 2));
  }
  //calculate error using M_Pi
  double error = M_PI - sum;
  //print results
  printf("Estimated value of Pi for %d points using Simpson's rule = %f\n", areas, sum);
  printf("Computation error = Exact value - Estimated value = %f\n", error);
  return 0;
}
  
	
	
	
