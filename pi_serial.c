//Varun Ramani, this program estimates pi using a for loop that estimates and sums up pi for an inputted number of points and comapres error to actual pi.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//called from command line with 2 arguments one being a num 1-10. Returns 1 if error, 0 is success.
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
  int areaCounter = 0;
  double sum = 0;
  //define amount x should increment by dividing 1 by area
  double xIncrement = 1.0/areas;
  double currentx = 0;
  sum += (double) 4.0/(1.0 + pow(currentx, 2));
  currentx += xIncrement;
  //simpson's rule iterations
  while (areaCounter < areas) {
    
    sum += ((double) 4.0/(1.0 + pow(currentx, 2)) * 4);
    areaCounter++;
    currentx += xIncrement;
    //break to not exceed
    if (!(areaCounter < areas)) {
      break;
    }
  
    sum += ((double) 4.0/(1.0 + pow(currentx, 2)) * 2);
    areaCounter++;
    currentx += xIncrement;
      
  }

  sum += (double) 4.0/(1.0 + pow(currentx, 2));
  sum = sum * (xIncrement/3.0);
  //calculate error using M_Pi
  double error = M_PI - sum;
  //print results
  printf("Estimated value of Pi for %d points using Simpson's rule = %f\n", areas, sum);
  printf("Computation error = Exact value - Estimated value = %f\n", error);
  return 0;
}
  
	
	
	

