#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long* generar_pascal_c(int n) {
    long long* fila = (long long*)malloc(1 * sizeof(long long));
    fila[0] = 1;

    for (int i = 1; i <= n; i++) {
        long long* nueva_fila = (long long*)malloc((i + 1) * sizeof(long long));
        nueva_fila[0] = 1;
        nueva_fila[i] = 1;

        for (int j = 1; j < i; j++) {
            nueva_fila[j] = fila[j - 1] + fila[j];
        }

        free(fila);
        fila = nueva_fila;
    }
    return fila;
}

int main() {
    int n = 100;
    clock_t inicio = clock();
    long long* coeficientes = generar_pascal_c(n);
    clock_t fin = clock();

    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecucion en C para n=%d: %f segundos\n", n, tiempo);

    FILE* archivo = fopen("tiempos_n100.txt", "w");
    if (archivo != NULL) {
        fprintf(archivo, "Resultados de medicion para n=100:\n");
        fprintf(archivo, "-----------------------------------\n");
        fprintf(archivo, "Tiempo de ejecucion en C: %f segundos\n", tiempo);
        fclose(archivo);
    }

    free(coeficientes);
    return 0;
}