#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct usuario Usuario;

Usuario* cadastraUsuario();
void mostraDadosUsuario(const Usuario*);
int menuPrincipal(void);

struct usuario{
  char nome[50];
  char dataDeNascimento[20];
  char email[40];
  char signo[15];
  char horoscopoChines[15];
  int numerologia;
};


int main(void) {
  Usuario* novoUsuario;
  int opcao;
  printf("Protótipo C-Ganinha com Estruturas\n\n");
  opcao = menuPrincipal();
  while(opcao != 0){
    switch(opcao){
      case 1: novoUsuario = cadastraUsuario();
              break;
      case 2: mostraDadosUsuario(novoUsuario);
              break;
    }
    opcao = menuPrincipal();
  }
  return 0;
}

Usuario* cadastraUsuario(){
  Usuario* usu;
  usu = (Usuario*) malloc(sizeof(Usuario));
  printf("\nDigite o nome: ");
  scanf(" %80[^\n]", usu->nome);
  printf("\nDigite a data de nascimento: ");
  scanf(" %20[^\n]", usu->dataDeNascimento);
  printf("\nDigite o email: ");
  scanf(" %40[^\n]", usu->email);
  printf("\nDigite o signo: ");
  scanf(" %15[^\n]", usu->signo);
  printf("\nDigite o número nativo: ");
  scanf("%d", &usu->numerologia);
  return usu;
}

void mostraDadosUsuario(const Usuario* usu){
  printf("USUÁRIO CADASTRADO: ");
  printf("Nome: %s \n",usu->nome);
  printf("Data de nascimento: %s \n", usu->dataDeNascimento);
  printf("Email: %s \n",usu->email);
  printf("Signo: %s \n", usu->signo);
  printf("Número nativo: %d \n",usu->numerologia);
}

int menuPrincipal(void){
  int op;
  printf("\n[1] - Cadastrar Usuário");
  printf("\n[2] - Exibir Usuário");
  printf("\n[0] - Encerrar Programa");
  printf("\n");
  scanf("%d",&op);
  return op;
}
