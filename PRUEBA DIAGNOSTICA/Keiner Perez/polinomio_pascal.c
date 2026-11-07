#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//Funcion para calcular el coeficiente binomial C(n, k)
long long* gen_pascal(int n) {
    long long *fila = (long long*)malloc((n + 1) * sizeof(long long));
    if (fila == NULL) {
        printf("Error al asignar memoria\n");
        exit(1);
    }

    fila[0] = 1;
    for (int i = 1; i <= n; i++) {
        fila[i] = 0; 
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = i; j > 0; j--) {
            fila[j] += fila[j - 1];
        }
    }
    return fila;
}

int main() {
    int n = 100;
    double x = 2.0;

    clock_t inicio = clock();
    long long *coeficientes = gen_pascal(n);
    clock_t fin = clock();

    double tiempo = ((double)(fin - inicio)) / CLOCKS_PER_SEC;

    FILE *archivo = fopen("resultados_ejercicio2_c.txt", "w");
    if (archivo != NULL) {
        fprintf(archivo, "Generacion de coeficientes (n=%d) en C:\n", n);
        for (int i = 0; i <= 5; i++) {
            fprintf(archivo, "Coeficiente x^%d: %lld\n", n-i, coeficientes[i]);
        }
        fprintf(archivo, "Tiempo de ejecución: %.6f segundos\n", tiempo);
        fclose(archivo);
    }

    free(coeficientes);
    printf("Ejercicio 2 en C completado en %.6f segundos)\n", tiempo);
    return 0;
}