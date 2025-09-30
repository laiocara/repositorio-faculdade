#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare_floats(const void *a, const void *b) {
    float fa = *(const float *)a;
    float fb = *(const float *)b;
    return (fa > fb) - (fa < fb);
}

int main() {
    int N;
    float *valores;
    float soma = 0.0, media = 0.0;
    float minimo, maximo;
    float mediana;
    float desvio = 0.0;

    printf("Quantos números na sua série (N): ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Número inválido de elementos.\n");
        return 1;
    }

    valores = (float *)malloc(N * sizeof(float));
    if (valores == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("Entre com números:\n");
    for (int i = 0; i < N; i++) {
        printf("> ");
        if (scanf("%f", &valores[i]) != 1) {
            printf("Entrada inválida.\n");
            free(valores);
            return 1;
        }
        soma += valores[i];
    }

    media = soma / N;
    minimo = maximo = valores[0];
    for (int i = 1; i < N; i++) {
        if (valores[i] < minimo) minimo = valores[i];
        if (valores[i] > maximo) maximo = valores[i];
    }

    qsort(valores, N, sizeof(float), compare_floats);
    if (N % 2 == 0)
        mediana = (valores[N / 2 - 1] + valores[N / 2]) / 2.0;
    else
        mediana = valores[N / 2];

    for (int i = 0; i < N; i++) {
        desvio += pow(valores[i] - media, 2);
    }
    desvio = sqrt(desvio / N);

    printf("Valor mínimo: %.2f\n", minimo);
    printf("Valor Máximo: %.2f\n", maximo);
    printf("Média: %.2f\n", media);
    printf("Mediana: %.2f\n", mediana);
    printf("Desvio padrão: %.13f\n", desvio);

    free(valores);
    return 0;
}
