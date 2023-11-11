#include <stdio.h>


int validaQuantidade(int quantidade);
float calculaSalario(int quantidade);
void mostraFinal(int quantidade, float salario);

int main() {
    int quantidade;
    char continuar;

    do {
        //quantidade de peças fabricadas
        printf("Digite a quantidade de pecas fabricadas: ");
        scanf("%d", &quantidade);

        // Validando a quantidade de peças
        while (validaQuantidade(quantidade) == 0) {
            printf("Quantidade invalida. Digite novamente: ");
            scanf("%d", &quantidade);
        }

        // Calcular e mostrar o salário
        mostraFinal(quantidade, calculaSalario(quantidade));

        // popup! deseja continuar?
        printf("\nDeseja calcular o salario para outro funcionario? (S/N): ");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');

    return 0;
}

// Função p validar a quantidade de peças
int validaQuantidade(int quantidade) {
    return quantidade >= 0;
}

// calculando o salário
float calculaSalario(int quantidade) {
    float salario_base = 600.0;
    float adicional = 0.0;

    if (quantidade > 50) {
        adicional += 0.50 * (quantidade - 50);

        if (quantidade > 80) {
            adicional += 0.75 * (quantidade - 80);
        }
    }

    return salario_base + adicional;
}

// Procedimento para mostrar o resultado final
void mostraFinal(int quantidade, float salario) {
    printf("\nQuantidade de pecas fabricadas: %d\n", quantidade);
    printf("Salrio total: R$ %.2f\n", salario);
}
