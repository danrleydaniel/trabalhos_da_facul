float* preenchePolinomio(float* vetor){
    for(int i = 0; i <= 10; i++){
      printf("\nInsira o valor de grau %d: ",i);
      scanf("%f",&vetor[i]);
  }
  return vetor;
}

float avaliaPolinomio(float* vetor, int x){
  float soma = 0;
  for(int i = 0; i <= 10; i++){
    soma += (pow(vetor[i],i));
  }
  return soma;
}

int igualdadePolinomios(float* vet1, float* vet2){
  int cont = 0;
  for(int i = 0; i <= 10; i++){
    if(vet1[i] == vet2[i])
      cont++;
  }
  if(cont == 0)
    return 1;
  else
    return 0;
}

void escrevePolinomio(float * vetor){
  for(int i = 0; i <= 10; i++){
    if(vetor[i] == 0)
      continue;
    else if(i < 10)
      printf("(%.1f)X^%d + ",vetor[i],i);
    else
       printf("(%.1f)^%d",vetor[i],i);
  }
}

void somaPolinomio(float* vet1, float* vet2){
  float* vet3;
  for(int i = 0; i <= 10; i++){
    vet3[i] = vet1[i] + vet2[i]; 
  }
  escrevePolinomio(vet3);
}

void subtraiPolinomio(float* vet1, float* vet2){
  float* vet3;
  for(int i = 0; i <= 10; i++){
    vet3[i] = vet1[i] - vet2[i];
  }
  escrevePolinomio(vet3);
}

void derivadaPolinomio(float* vet){
  for(int i = 0; i < 10; i++){
    if(vet[i] == 0)
      continue;
    else if(i < 10)
      printf("%d(%.1f) ^ %d +",i, vet[i],i-1);
    else
      printf("%d(%.1f) ^ %d",i, vet[i],i-1);
  }
}

void opcaoSoma(void){
  float poli[10];
  float poli2[10];
  printf("\nPrimeiro, digite os valores do primeiro polinômio: ");
  preenchePolinomio(poli);
  printf("\n\nAgora, os valores do segundo polinômio: ");
  preenchePolinomio(poli2);

  printf("\n\nPolinômio 1: \n");
  escrevePolinomio(poli);
  printf("\n\nPolinômio 2: \n");
  escrevePolinomio(poli2);
  printf("\n\nSoma dos dois polinômios: ");
  somaPolinomio(poli, poli2);
}

void opcaoSubtracao(void){
  float poli[10];
  float poli2[10];
  printf("\nPrimeiro, digite os valores do primeiro polinômio: ");
  preenchePolinomio(poli);
  printf("\n\nAgora, os valores do segundo polinômio: ");
  preenchePolinomio(poli2);

  printf("\n\nPolinômio 1: \n");
  escrevePolinomio(poli);
  printf("\n\nPolinômio 2: \n");
  escrevePolinomio(poli2);
  printf("\n\nSubtração dos dois polinômios: ");
  subtraiPolinomio(poli, poli2);
}

void opcaoDerivada(void){
  float poli[10];
  printf("\n\nDê os valores para o polinômio: ");
  preenchePolinomio(poli);
  printf("\n\nA derivada desse polinômio é... \n");
  derivadaPolinomio(poli);
}

void opcaoAvalia(void){
  int x;
  float avaliacao;
  float poli[10];
  printf("\nPrimeiro, digite os valores do polinômio: ");
  preenchePolinomio(poli);
  printf("\n\nAgora, diga um valor para X: ");
  scanf("%d",&x);
  avaliacao = avaliaPolinomio(poli, x);
  printf("\n\nResultado final: %.2f",avaliacao);
}

void opcaoIgualdade(void){
  float poli[10];
  float poli2[10];
  printf("\nPrimeiro, digite os valores do primeiro polinômio: ");
  preenchePolinomio(poli);
  printf("\n\nAgora, dê os valores do segundo polinômio: ");
  preenchePolinomio(poli2);

  if(igualdadePolinomios(poli, poli2))
    printf("\nOs polinômios são iguais");
  else
    printf("\nOs polinômios não são iguais...");

}
