#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

int pow2r(int);

int main(void) {
  FILE* fp;
  fp = fopen("output.txt","w");
  long unsigned int t;
  long unsigned int media = 0;
  unsigned int n;
  unsigned int i;
  struct timeval a, b;

  for(n = 100; n < 10000; n = n + 100){
    for(i = 0; i < 100; i++){
      gettimeofday(&b, NULL);
      pow2r(n);
      gettimeofday(&a, NULL);
      t = (a.tv_sec * 1e6 + a.tv_usec) - (b.tv_sec * 1e6 + b.tv_usec);
      media += t;
    }
    fprintf(fp, "%u %lu\n", n, media/100);
  }

  fclose(fp);
  system("gnuplot");
  
  return 0;
}

int pow2r(int n){
  if(n < 2){
    return (n+1);
  }
  if(n % 2 == 0){
    int r = pow2r(n/2);
    return (r * r);
  }
  int r =  pow2r((n - 1)/2);
  return (2 * r * r);
}
