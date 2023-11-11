#include <stdio.h>

char validaSexo(char sexo);
float validaSalario(float salario);
void classificaSalario(float salario, char *classificacao);
void mostraClassifica(float salario, char sexo, char classificacao);
void contaClassificacao(float salario, int *abaixo, int *acima);

int main() {
    int numAssalariados, abaixoSalario = 0, acimaSalario = 0;

    // Solicitar o número de assalariados
    printf("Digite o numero de assalariados: ");
    scanf("%d", &numAssalariados);

    for (int i = 0; i < numAssalariados; i++) {
        char sexo;
        float salario;
        char classificacao;

        // Solicitar o sexo
        printf("\nDigite o sexo (M/F) do assalariado %d: ", i + 1);
        scanf(" %c", &sexo);

        // Validar o sexo
        sexo = validaSexo(sexo);

        // Solicitar o salário
        printf("Digite o salario do assalariado %d: R$ ", i + 1);
        scanf("%f", &salario);

        // Validar o salário
        salario = validaSalario(salario);

        // Classificar o salário
        classificaSalario(salario, &classificacao);

        // Mostrar os resultados
        mostraClassifica(salario, sexo, classificacao);

        // Contar a classificação
        contaClassificacao(salario, &abaixoSalario, &acimaSalario);
    }

    // Mostrar a quantidade de assalariados abaixo e acima do salário mínimo
    printf("\nQuantidade de assalariados abaixo do salario minimo: %d\n", abaixoSalario);
    printf("Quantidade de assalariados acima do salario minimo: %d\n", acimaSalario);

    return 0;
}

//  validar sexo
char validaSexo(char sexo) {
    while (sexo != 'M' && sexo != 'm' && sexo != 'F' && sexo != 'f') {
        printf("Sexo invalido. Digite novamente (M/F): ");
        scanf(" %c", &sexo);
    }
    return sexo;
}

// validar  salário
float validaSalario(float salario) {
    while (salario <= 1.0) {
        printf("Salario invalido. Digite novamente: R$ ");
        scanf("%f", &salario);
    }
    return salario;
}

//  salário
void classificaSalario(float salario, char *classificacao) {
    if (salario < 1400.0) {
        *classificacao = 'A';  // Abaixo do salário mínimo
    } else if (salario == 1400.0) {
        *classificacao = 'I';  // Igual ao salário mínimo
    } else {
        *classificacao = 'S';  // Acima do salário mínimo
    }
}

// resultados
void mostraClassifica(float salario, char sexo, char classificacao) {
    printf("\nSalario do assalariado: R$ %.2f\n", salario);
    printf("Sexo do assalariado: %s\n", (sexo == 'M' || sexo == 'm') ? "Masculino" : "Feminino");
    printf("Classificacao em relacao ao salario minimo: ");
    
    switch (classificacao) {
        case 'A':
            printf("Abaixo do salario minimo\n");
            break;
        case 'I':
            printf("Igual ao salario minimo\n");
            break;
        case 'S':
            printf("Acima do salario minimo\n");
            break;
    }
}

// class
void contaClassificacao(float salario, int *abaixo, int *acima) {
    if (salario < 1400.0) {
        (*abaixo)++;
    } else {
        (*acima)++;
    }
}
