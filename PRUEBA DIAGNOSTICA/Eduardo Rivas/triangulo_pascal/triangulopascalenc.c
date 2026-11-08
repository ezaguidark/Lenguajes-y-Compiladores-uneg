#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función que genera los coeficientes de la fila n usando memoria dinámica
long long* generar_pascal_dinamico(int n) {
    // Reserva de memoria dinámica para n + 1 coeficientes
    long long *fila = (long long*) malloc((n + 1) * sizeof(long long));
    if (fila == NULL) {
        printf("Error: No se pudo asignar memoria dinámica.\n");
        exit(1);
    }

    fila[0] = 1;
    for (int i = 1; i <= n; i++) {
        fila[i] = 0;
    }

    // Construcción iterativa del Triángulo de Pascal
    for (int i = 1; i <= n; i++) {
        for (int j = i; j > 0; j--) {
            fila[j] = fila[j] + fila[j - 1];
        }
    }

    return fila;
}

// Función para evaluar y mostrar el cálculo paso a paso para un x dado
void evaluar_polinomio(int n, long long *coefs, double x) {
    printf("\n--- Evaluando f(x) = (x + 1)^%d para x = %.2f ---\n", n, x);
    double resultado_total = 0;

    for (int i = 0; i <= n; i++) {
        int potencia = n - i;
        double termino = coefs[i];
        for (int p = 0; p < potencia; p++) {
            termino *= x;
        }
        resultado_total += termino;
        
        printf("Paso %d: Coeficiente %lld * (%.2f^%d) = %.4f\n", i + 1, coefs[i], x, potencia, termino);
    }
    printf("Resultado Final f(%.2f) = %.4f\n\n", x, resultado_total);
}

int main() {
    int n = 100; // Caso exigido para la medición de rendimiento
    
    // Medición de tiempo en C para n = 100 (50,000 iteraciones para alta precisión)
    clock_t inicio = clock();
    long long *coefs_n = NULL;
    for (int iter = 0; iter < 50000; iter++) {
        if (coefs_n != NULL) free(coefs_n);
        coefs_n = generar_pascal_dinamico(n);
    }
    clock_t fin = clock();

    double tiempo_c = (double)(fin - inicio) / CLOCKS_PER_SEC;

    // Guardar el resultado en el archivo txt requerido
    FILE *archivo = fopen("resultados_tiempo.txt", "a");
    if (archivo != NULL) {
        fprintf(archivo, "Ejercicio 2 - Tiempo C (n=100, 50k iteraciones): %.6f segundos\n", tiempo_c);
        fclose(archivo);
    }

    printf("Generacion en C para n=%d completada. Tiempo: %.6f segundos.\n", n, tiempo_c);

    // Demostración paso a paso con un n pequeño (ej. n = 4)
    int n_demo = 4;
    long long *coefs_demo = generar_pascal_dinamico(n_demo);
    evaluar_polinomio(n_demo, coefs_demo, 2.0);

    // Liberación de memoria dinámica
    free(coefs_n);
    free(coefs_demo);

    return 0;
}