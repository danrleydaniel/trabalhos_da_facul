#include <stdio.h>
#include <stdlib.h>

//0 1 . 2 3 4 . 5 6 7 / 8 9 10 11 - 12 13

int chartoint(char);
char inttochar(int);
int validaCNPJ(char [16]);


int main(void) {
  char cnpj[16];
  printf("\nDigite um CNPJ: ");
  scanf("%s", cnpj);
  if(validaCNPJ(cnpj)){
    printf("\nCNPJ válido!");
  } else{
    printf("\nCNPJ inválido!");
  }
}

int chartoint(char c){
    return c - '0';
}

char inttochar(int n){
  return n + 48;
}

int validaCNPJ(char cnpj[16]){
  int soma = 0;
  int num;
  int j = 0;
  char digito1;
  for(int i = 5; i >= 2; i--){
    num = chartoint(cnpj[j]);
    num *= i;
    soma += num;
    j++;
  }
  for(int i = 9; i >= 2; i--){
    num = chartoint(cnpj[j]);
    num *= i;
    soma += num;
    j++;
  }
  soma = soma % 11;
  if(soma < 2){
    soma = 0;
  } else{
    soma = 11 - soma;
  }
  digito1 = inttochar(soma);
  if(digito1 != cnpj[12]){
    return 0;
  } else{
    j = 0;
    soma = 0;
    for(int i = 6; i >= 2; i--){
      num = chartoint(cnpj[j]);
      num *= i;
      soma += num;
      j++;
    }
    for(int i = 9; i >= 2; i--){
      num = chartoint(cnpj[j]);
      num *= i;
      soma += num;
      j++;
    }
    soma = soma % 11;
    if(soma < 2){
      soma = 0;
    } else{
      soma = 11 - soma;
    }
    digito1 = inttochar(soma);
    if(digito1 != cnpj[13]){
      return 0;
    } else{
      return 1;
    }
  }
}
