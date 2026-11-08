#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DIGITOS 40

// Estructura BigInt para manejar enteros gigantes de hasta 40 dígitos
typedef struct {
    int digitos[MAX_DIGITOS];
    int len;
} BigInt;

// Inicializa un BigInt con un entero corto
void init_bigint(BigInt *n, int val) {
    memset(n->digitos, 0, sizeof(n->digitos));
    n->len = 0;
    if (val == 0) {
        n->digitos[0] = 0;
        n->len = 1;
        return;
    }
    while (val > 0) {
        n->digitos[n->len++] = val % 10;
        val /= 10;
    }
}

// Suma dos BigInt: res = a + b
void sumar_bigint(const BigInt *a, const BigInt *b, BigInt *res) {
    memset(res->digitos, 0, sizeof(res->digitos));
    int max_len = (a->len > b->len) ? a->len : b->len;
    int acarreo = 0;
    int i = 0;

    for (i = 0; i < max_len || acarreo; i++) {
        int suma = acarreo;
        if (i < a->len) suma += a->digitos[i];
        if (i < b->len) suma += b->digitos[i];

        res->digitos[i] = suma % 10;
        acarreo = suma / 10;
    }
    res->len = i;
}

// Escribe el BigInt en un archivo de texto
void fprint_bigint(FILE *f, const BigInt *n) {
    for (int i = n->len - 1; i >= 0; i--) {
        fprintf(f, "%d", n->digitos[i]);
    }
}

int main() {
    int n = 100;
    
    // Asignación dinámica del Triángulo de Pascal (Arreglo de BigInt)
    BigInt *fila = (BigInt *)malloc((n + 1) * sizeof(BigInt));
    BigInt *temp = (BigInt *)malloc((n + 1) * sizeof(BigInt));

    struct timespec inicio, fin;
    clock_gettime(CLOCK_MONOTONIC, &inicio);

    // Algoritmo del Triángulo de Pascal con BigInt
    init_bigint(&fila[0], 1);
    for (int i = 1; i <= n; i++) {
        init_bigint(&fila[i], 0);
    }

    for (int i = 1; i <= n; i++) {
        for (int k = 0; k <= i; k++) {
            temp[k] = fila[k];
        }

        init_bigint(&fila[0], 1);
        for (int j = 1; j < i; j++) {
            sumar_bigint(&temp[j], &temp[j - 1], &fila[j]);
        }
        init_bigint(&fila[i], 1);
    }

    clock_gettime(CLOCK_MONOTONIC, &fin);
    double tiempo = (fin.tv_sec - inicio.tv_sec) + (fin.tv_nsec - inicio.tv_nsec) / 1e9;

    // Guardar los 101 coeficientes completos en el archivo .txt
    FILE *archivo = fopen("resultado_ejercicio2_c.txt", "w");
    if (archivo != NULL) {
        fprintf(archivo, "=== COEFICIENTES COMPLETOS DEL POLINOMIO (x+1)^%d (C) ===\n", n);
        fprintf(archivo, "Total de coeficientes: %d\n\n", n + 1);

        for (int i = 0; i <= n; i++) {
            int grado = n - i;
            fprintf(archivo, "Coeficiente de x^%-3d : ", grado);
            fprint_bigint(archivo, &fila[i]);
            fprintf(archivo, "\n");
        }

        fprintf(archivo, "\n=========================================================\n");
        fprintf(archivo, "Tiempo de ejecucion C (n=%d): %.9f segundos\n", n, tiempo);
        fclose(archivo);
        printf("Se guardaron exitosamente los %d coeficientes completos en 'resultado_ejercicio2_c.txt'.\n", n + 1);
    } else {
        printf("Error al crear el archivo txt.\n");
    }

    free(fila);
    free(temp);
    return 0;
}