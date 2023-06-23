#include <stdio.h>
#include <stdlib.h>

int main() {
    int filas;
    int columnas;

    printf("Ingrese el numero de filas de la matriz: ");
    scanf("%d", &filas);

    printf("Ingrese el numero de columnas de la matriz: ");
    scanf("%d", &columnas);

    // Crear e inicializar la matriz con memoria dinamica
    int** matriz = (int**)malloc(filas * sizeof(int*));
    for (int i = 0; i < filas; i++) {
        matriz[i] = (int*)malloc(columnas * sizeof(int));
        for (int j = 0; j < columnas; j++) {
            // Durante la inicializacion se verifica si el elemento esta en la diagonal principal
            matriz[i][j] = i == j ? 1 : 0;
        }
    }

    // Imprimir la matriz
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Liberar la memoria asignada a la matriz
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}