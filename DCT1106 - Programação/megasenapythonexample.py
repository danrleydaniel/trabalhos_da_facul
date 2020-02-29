import random

cartao = []

def gerarCartao():
  while(len(cartao) < 6):
    num = random.randint(1,100)
    if num not in cartao:
      cartao.append(num)
  cartao.sort()

def exibirCartao():
  print("[", end = " ")
  tamanho = len(cartao)
  for i in range(0, tamanho):
    print(cartao[i], end = " ")
  print("]")

def adicionarAoCartao():
  num = int(input("Digite o número que deseja adicionar ao cartão: "))
  if num not in cartao:
    cartao.append(num)
    cartao.sort()
    print("Número adicionado.")
  else:
    print("O número digitado já consta no cartão.")

def deletar():
  num = int(input("Digite o número que deseja excluir do cartão: "))
  tamanho = len(cartao)
  if num not in cartao:
    print("O número informado não consta no cartão.")
  else:
    for i in range(0, tamanho):
      if cartao[i] == num:
        del cartao[i]
  print("Número deletado.")
  cartao.sort()

print("CARTÃO DA MEGA-SENA")
print("Escolha uma opção: ")
print("""
1 - Gerar cartão
2 - Exibir cartão
3 - Adicionar número ao cartão
4 - Deletar número do cartão
0 - Fechar programa
""")
op = input()
while op != "0":
  if op == "1":
    gerarCartao()
    print()
  elif op == "2":
    exibirCartao()
    print()
  elif op == "3":
    adicionarAoCartao()
    print()
  elif op == "4":
    deletar()
    print()
  else:
    print("Opção inválida")
    print()
  op = input("O que deseja fazer agora? ")
print("Programa encerrado.")
