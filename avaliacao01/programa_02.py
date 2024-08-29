data = input('Digite uma data no modelo dd/mm/aaaa: ')

try:
    dia = int(data[0:2])
    mes = int(data[3:5])
    ano = int(data[6:])
    numerosValido = '+' not in data and '-' not in data

except ValueError:
    dia, mes, ano = 0, 0, 0
    numerosValido = False

formatoValido = data[2:3] == '/' and data[5:6] == '/'
bissexto = ano % 400 == 0 or ano % 100 != 0 and ano % 4 == 0
diaLimite = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
diaValido = dia >= 1 and ((dia <= diaLimite[mes-1]) or (dia <= diaLimite[mes-1] + 1 and mes == 2 and bissexto))
mesValido = 1 <= mes <= 12
anoValido = ano >= 0

if formatoValido and diaValido and mesValido and anoValido and numerosValido:
    print('Data Válida')
    diaMes = [0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334]

    aux = int((ano - 1) * 365.25 + diaMes[mes - 1] + dia)
    if mes > 2 and bissexto:
        aux = aux + 1
    aux1 = int(aux / 7)
    aux1 = aux1 * 7
    aux1 = aux - aux1
    diaNome = ['Sábado', 'Domingo', 'Segunda-Feira', 'Terça-Feira', 'Quarta-Feira', 'Quinta-Feira', 'Sexta-Feira']
    print(f'O dia da semana de {data} é {diaNome[aux1]}')
else:
    print('Data Inválida')
