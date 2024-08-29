#include <stdio.h>
#include <string.h>

int main(void) {

    char codigo[10];
    int tipoSalario, numeroFilhos;
    double salarioBase;

    do {
        printf("Insira o código do funcionário: ");
        scanf("%s", codigo);

        if (strlen(codigo) < 2) {
            printf("\nCódigo inválido!\n");
        }
    } while (strlen(codigo) < 2);

    do {
        printf("Insira o tipo de salário: ");
        printf("\n[1 : Horista | 2 : Diarista | 3 : Mensalista] : ");
        scanf("%d", &tipoSalario);

        if (tipoSalario < 1 || tipoSalario > 3) {
            printf("\nTipo de salário inválido!\n");
        }
    } while (tipoSalario < 1 || tipoSalario > 3);

    printf("Insira o salário base: ");
    scanf("%lf", &salarioBase);
    printf("Insira o número de filhos: ");
    scanf("%d", &numeroFilhos);
    printf("\n");

    const int tipoSalarioTempo = tipoSalario == 1 ? 220 : tipoSalario == 2 ? 30 : tipoSalario == 3 ? 1 : 0;
    const double salarioBruto = salarioBase * tipoSalarioTempo;
    const double salarioBrutoPorcentagem = salarioBruto <= 3500 ? 0.08 : salarioBruto <= 5800 ? 0.09 : 0.1;
    const double inss = salarioBruto * salarioBrutoPorcentagem;
    const double salarioBrutoInss = salarioBruto - inss <= 6200 ? 0 : salarioBruto - inss <= 9400 ? 0.05 : 0.1;
    const double impostoRenda = (salarioBruto - inss) * salarioBrutoInss;
    const double salarioFamilia = numeroFilhos * 20;
    const double salarioLiquido = salarioBruto - inss - impostoRenda + salarioFamilia;

    printf("========================================\n");
    printf("Código do funcionário: %s\n", codigo);
    printf("Tipo de salário: %s\n", tipoSalario == 1 ? "Horista" : tipoSalario == 2 ? "Diarista" : "Mensalista");
    printf("Salário base: %.2lf\n", salarioBase);
    printf("Número de filhos: %d\n\n", numeroFilhos);
    printf("Salário bruto: %.2lf\n", salarioBruto);
    printf("INSS: %.2lf\n", inss);
    printf("Imposto de renda: %.2lf\n", impostoRenda);
    printf("Salário família: %.2lf\n", salarioFamilia);
    printf("Salário líquido: %.2lf\n", salarioLiquido);
    printf("========================================\n");

}