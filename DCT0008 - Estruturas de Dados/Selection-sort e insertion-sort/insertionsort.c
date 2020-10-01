/*INSERTION-SORT*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

void insertionsort(int*, int);
void preenche(int*, int);

int main(void) {
  FILE* fp;
  fp = fopen("output.txt","w");
  long unsigned int t;
  long unsigned int media = 0;
  unsigned int n;
  unsigned int i;
  struct timeval a, b;

  for(n = 100; n < 5000; n = n + 100){
    srand(time(NULL));
    for(i = 0; i < 100; i++){
      int vec[n];
      preenche(vec, n);

      gettimeofday(&b, NULL);
      insertionsort(vec, n);
      gettimeofday(&a, NULL);

      t = (a.tv_sec * 1e6 + a.tv_usec) - (b.tv_sec * 1e6 + b.tv_usec);
      media += t;
    }
    printf("\nAnalisados %i de 5000",n);
    fprintf(fp, "%u %lu\n", n, media/100);
  }

  fclose(fp);
  system("gnuplot");
  
  return 0;
}

void insertionsort(int* vec, int n){
  int aux, j;
  for(int i = 1; i < n; i++){
    j = i;
    while(j > 0 && vec[j - 1] > vec[j]){
      aux = vec[j];
      vec[j] = vec[j - 1];
      vec[j - 1] = aux;
      j--;
    }
  }
}

void preenche(int* vec, int n){
  for(int i = 0; i < n; i++){
    vec[i] = rand() % 100;
  }
}
