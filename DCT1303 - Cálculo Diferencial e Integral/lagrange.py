from math import*


VERDE = "\033[1;32m"
NORMAL = "\033[0;0m"


xo = 1

def mostraformula():
  print()
  print("""
  f(Xo + h) - f(Xo)
  __________________
           h
           """)

def mostraformula2():
  print()
  print("""
         f(b) - f(a)
  f(φ) = ___________
            b - a
            """)



def ajuda():
  print()
  print("Este programa verifica se o valor de uma derivada no ponto Xo, dado pela fórmula: ")
  mostraformula()
  print("é igual ao valor da função no teorema de Lagrange, dado pela fórmula: ")
  mostraformula2()
  print("O programa calcula as duas fórmulas, onde 'h', na fórmula da derivada recebe um valor de 0,0001 até -0,1099. Se o valor de ambas as equações forem iguais ou aproximados, o programa mostrará o resultado em",VERDE,"verde",NORMAL, "e em seguida, estará pronto para testar outra função.")
  print()
  print("Vale lembrar que o programa lê as funções de acordo com a semântica no Python, ou seja, se sua função é algo como: 'f(X) = 2X', você deve escrevê-la como '2*x',","\033[4m","sem escrever o 'f(x)'",NORMAL)
  print()
  print("Lembre-se, toda função que você escrever deverá conter um 'x' na fórmula")
  print()
  print("Se precisar escrever alguma função que envolva raiz quadrada, trigonometria, etc., use a semântica das funções da biblioteca math.")
  print()
  print("Escrever '-ajuda' mostra essa mensagem novamente.")
  print()

def validaExpressao(x):
  cont = 0
  for i in x:
    if i == "x":
      cont += 1
  if cont == 0:
    return False
  else:
    return True


def verifLagrange(f, a, b):
  x = a
  valorA = 
  x = b
  valorB = 

  fl = ((valorB - valorA) / (b - a))
  print("Valor encontrado pela fórmula da derivada: ")
  print(fl)
  input("Aperte ENTER para continuar")
  h = 0.0001
  while(h < -0,1099):
    print()
    print("h = ",h)
    print()
    aux = xo + h
    x = aux
    f1 = 
    x = xo
    f2 = 
    derivada = ((f1 - f2) / h)
    derivadaAux = (str(derivada))
    derivada = derivadaAux[0:3]
    fl = str(fl)
    fl = fl[0:3]
    if(derivada == fl):
      print(VERDE)
      print(derivada)
      print(NORMAL)
      input("ENCONTRADO!")
      break
    else:
      print(derivada)
    h -= 0.01

print("=================")
print("PROGRAMA LAGRANGE")
print("=================")
print("Se precisar de alguma instrução, escreva '-ajuda' no lugar de uma função.")


while True:


  f = input("Digite uma função: ")

  if f == "-ajuda":
    ajuda()
  elif not validaExpressao(f):
    print()
    print("Função inválida. Valor X não encontrado.")
    print()
  else: 
    verifLagrange(f, 1, 2)
