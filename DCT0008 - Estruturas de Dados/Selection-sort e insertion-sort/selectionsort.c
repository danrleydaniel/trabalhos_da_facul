/*SELECTION-SORT*\
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

void selectionsort(int*, int);
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
      selectionsort(vec, n);
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

void selectionsort(int* vec, int n){
  int aux, min;
  for(int i = 0; i < (n - 1); i++){
    min = i;
    for(int j = i+1; j < n; j++){
      if(vec[j] < vec[min]){
        min = j;
      }
    }
    if(i != min){
      aux = vec[i];
      vec[i] = vec[min];
      vec[min] = aux;
    }
  }
}

void preenche(int* vec, int n){
  for(int i = 0; i < n; i++){
    vec[i] = rand() % 100;
  }
}
