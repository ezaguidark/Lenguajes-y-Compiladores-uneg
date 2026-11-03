#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long potencia(long long base, int exp) {
    long long res = 1;
    for (int i = 0; i < exp; i++) {
        res *= base;
    }
    return res;
}

void resolver_pascal(int n, int *x) {
    // Memoria dinamica para los coeficientes 
    int *coefs = (int *)malloc((n + 1) * sizeof(int));
    if (coefs == NULL) {
        printf("Error al asignar memoria.\n");
        return;
    }

    coefs[0] = 1;
    for (int i = 1; i <= n; i++) {
        coefs[i] = 0;
    }

    // Triangulo de Pascal:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j > 0; j--) {
            coefs[j] += coefs[j - 1];
        }
    }

    // Polinomio generado:
    printf("\n- Polinomio para (x + 1)^%d: \nF(x) = ", n);
    for (int i = 0; i <= n; i++) {
        int grado = n - i;
        if (coefs[i] != 0) {
            if (grado > 1) {
                printf("%d*x^%d ", coefs[i], grado);
            } else if (grado == 1) {
                printf("%d*x ", coefs[i]);
            } else {
                printf("%d", coefs[i]);
            }
            if (i < n) printf("+ ");
        }
    }
    printf("\n");

    // Si no hay valor de X, no se evalua el resultado final
    if (x == NULL) {
        printf("\nNo se proporciono valor para x.\n");
        free(coefs);
        return;
    }

    // Mostrar los pasos para x
    printf("\nCalculo paso a paso evaluando en x = %d:\n", *x);
    long long total = 0;

    for (int i = 0; i <= n; i++) {
        int grado = n - i;
        long long val_potencia = potencia(*x, grado);
        long long parcial = (long long)coefs[i] * val_potencia;
        total += parcial;

        printf("Paso %d: Coeficiente %d * (%d^%d = %lld) = %lld\n", 
               i, coefs[i], *x, grado, val_potencia, parcial);
    }

    printf("Resultado final f(%d) = %lld\n", *x, total);

    free(coefs);
}

int main() {

    // Iniciar medición de tiempo

    // Ejemplo asignandole un valor a X = 1
    clock_t inicio = clock();
    int n = 100;
    int valor_x = 1;

 
    printf("Prueba con X = 5 y n = 100\n");
    resolver_pascal(n, &valor_x);

    // Finalizar medición de tiempo
    clock_t fin = clock();
    double tiempo_cpu = ((double)(fin - inicio)) / CLOCKS_PER_SEC;

    printf("Tiempo de ejecucion (C): %.8f segundos\n", tiempo_cpu);

    return 0;
}