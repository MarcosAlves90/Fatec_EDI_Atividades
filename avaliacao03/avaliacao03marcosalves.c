#include <stdbool.h>
#include <stdio.h>

typedef struct {
    int codigo;
    int tipoSalario;
    double salarioBase;
    int numeroFilhos;
    double salarioBruto;
    double inss;
    double salarioBrutoInss;
    double impostoRenda;
    double salarioFamilia;
    double salarioLiquido;
} Funcionarios;

void Funcionarios_init(Funcionarios *self, int codigo, int tipoSalario, double salarioBase, int numeroFilhos) {
    self->codigo = codigo;
    self->tipoSalario = tipoSalario;
    self->salarioBase = salarioBase;
    self->numeroFilhos = numeroFilhos;

    const int tipoSalarioTempo = tipoSalario == 1 ? 220.0 : tipoSalario == 2 ? 30.0 : tipoSalario == 3 ? 1.0 : 0.0;
    self->salarioBruto = salarioBase * tipoSalarioTempo;

    const double salarioBrutoPorcentagem = self->salarioBruto <= 3500 ? 0.08 : self->salarioBruto <= 5800 ? 0.09 : 0.1;
    self->inss = self->salarioBruto * salarioBrutoPorcentagem;

    const double salarioBrutoInss = self->salarioBruto - self->inss <= 6200 ? 0 : self->salarioBruto - self->inss <= 9400 ? 0.05 : 0.1;
    self->impostoRenda = (self->salarioBruto - self->inss) * salarioBrutoInss;

    self->salarioFamilia = self->numeroFilhos * 20.45;
    self->salarioLiquido = self->salarioBruto - self->inss - self->impostoRenda + self->salarioFamilia;
}

bool isNumberInArray(int arr[], const int size, const int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return true;
        }
    }
    return false;
}

int main(void) {
    Funcionarios funcionario[10];
    int codigos[10];

    double totalSalarioBruto = 0.0;
    double totalInss = 0.0;
    double totalImpostoRenda = 0.0;
    double totalSalarioFamilia = 0.0;
    double totalSalarioLiquido = 0.0;

    for (int i = 0; i < 10; i++) {
        int codigo;
        int tipoSalario, numeroFilhos;
        double salarioBase;

        do {
            printf("Insira o código do funcionário: ");
            scanf("%d", &codigo);
            if (codigo < 1 || codigo > 1000 || isNumberInArray(codigos, 10, codigo)) {
                printf("\nCódigo precisa ser numérico e estar entre 1 e 1000\n");
            }
        } while (codigo < 1 || codigo > 1000 || isNumberInArray(codigos, 10, codigo));

        do {
            printf("Insira o tipo de salário: ");
            printf("\n[1 : Horista | 2 : Diarista | 3 : Mensalista] : ");
            scanf("%d", &tipoSalario);
            if (tipoSalario < 1 || tipoSalario > 3) {
                printf("\nTipo de salário inválido. Escolha um número!\n");
            }
        } while (tipoSalario < 1 || tipoSalario > 3);

        bool salarioInvalido = false;
        do {
            salarioInvalido = false;
            printf("Insira o salário base: ");
            scanf("%lf", &salarioBase);
            if (tipoSalario == 1 && (salarioBase < 6 || salarioBase > 100)) {
                salarioInvalido = true;
                printf("\nSalário base precisa estar entre 6 e 100\n");
            } else if (tipoSalario == 2 && (salarioBase < 150 || salarioBase > 400)) {
                printf("\nSalário base precisa estar entre 150 e 400\n");
                salarioInvalido = true;
            } else if (tipoSalario == 3 && (salarioBase < 1400 || salarioBase > 40000)) {
                printf("\nSalário base precisa estar entre 1400 e 40000\n");
                salarioInvalido = true;
            }
        } while (salarioInvalido == true);

        do {
            printf("Insira o número de filhos: ");
            scanf("%d", &numeroFilhos);
            if (numeroFilhos < 0 || numeroFilhos > 20) {
                printf("\nNúmero de filhos inválido!\n");
            }
        } while (numeroFilhos < 0 || numeroFilhos > 20);

        printf("\n===================================================\n");
        Funcionarios_init(&funcionario[i], codigo, tipoSalario, salarioBase, numeroFilhos);
        codigos[i] = codigo;

        totalSalarioBruto += funcionario[i].salarioBruto;
        totalInss += funcionario[i].inss;
        totalImpostoRenda += funcionario[i].impostoRenda;
        totalSalarioFamilia += funcionario[i].salarioFamilia;
        totalSalarioLiquido += funcionario[i].salarioLiquido;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (codigos[i] > codigos[j]) {
                const int tempCodigo = codigos[i];
                codigos[i] = codigos[j];
                codigos[j] = tempCodigo;
            }
        }
    }

    printf("\n| Código | Tipo      | Salário Base | Filhos | Salário Bruto |   INSS   | Imposto Renda  | Salário Família | Salário Líquido |\n");
    printf("|--------|-----------|--------------|--------|---------------|----------|----------------|-----------------|-----------------|\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (funcionario[j].codigo == codigos[i]) {
                printf("| %6d | %-8s| %12.2lf | %6d | %13.2lf | %8.2lf | %14.2lf | %15.2lf | %15.2lf |\n",
                       funcionario[j].codigo,
                       funcionario[j].tipoSalario == 1 ? "Horista   " : funcionario[j].tipoSalario == 2 ? "Diarista  " : "Mensalista",
                       funcionario[j].salarioBase,
                       funcionario[j].numeroFilhos,
                       funcionario[j].salarioBruto,
                       funcionario[j].inss,
                       funcionario[j].impostoRenda,
                       funcionario[j].salarioFamilia,
                       funcionario[j].salarioLiquido);
            }
        }
    }

    printf("\n| Totais |           |              |        | %13.2lf | %8.2lf | %14.2lf | %15.2lf | %15.2lf |\n",
           totalSalarioBruto, totalInss, totalImpostoRenda, totalSalarioFamilia, totalSalarioLiquido);

    return 0;
}
