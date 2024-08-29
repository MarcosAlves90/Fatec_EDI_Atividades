numeros = []
crescente = []
valorEncontrado = False
posicaoValorEncontrado = None

for i in range(20):
  num = int(input(f'Digite o {i + 1}º número: '))
  numeros.append(num)

for i in numeros:
  for j in range(len(crescente)):
    if i < crescente[j]:
      crescente.insert(j, i)
      break
    if j == len(crescente):
      crescente.insert(0, i)
  else:
    crescente.append(i)

print(f"\nOs números digitados são: {numeros}")
print(f"Em ordem crescente é: {crescente}\n")

valorRequisitado = int(input("Digite um valor para pesquisar: "))

aux = 0
while aux < len(crescente) and crescente[aux] != valorRequisitado :
  aux += 1
else:
  if aux != len(crescente):
    valorEncontrado = True
    posicaoValorEncontrado = aux

print(f'\nO valor {"" if valorEncontrado else "não "}foi encontrado{f" no índice {[aux]}." if valorEncontrado else "."}')
