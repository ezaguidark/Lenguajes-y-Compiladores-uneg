#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

bool es_movimiento_valido(char col_actual, int fila_actual, char col_dest, int fila_dest) {
    int dc = abs(col_dest - col_actual);
    int df = abs(fila_dest - fila_actual);
    return (dc == 2 && df == 1) || (dc == 1 && df == 2);
}

int validar_secuencia(const char* pos_inicial, int n, const char* movimientos[], int *falla_en) {
    if (strlen(pos_inicial) != 2) return 0;
    char col_act = pos_inicial[0];
    int fila_act = pos_inicial[1] - '0';

    if (col_act < 'a' || col_act > 'h' || fila_act < 1 || fila_act > 8) return 0;

    for (int i = 0; i < n; i++) {
        const char* mov = movimientos[i];
        if (strlen(mov) != 3 || mov[0] != 'K') {
            *falla_en = i + 1;
            return -1;
        }
        char col_dest = mov[1];
        int fila_dest = mov[2] - '0';

        if (col_dest < 'a' || col_dest > 'h' || fila_dest < 1 || fila_dest > 8) {
            *falla_en = i + 1;
            return -1;
        }

        if (!es_movimiento_valido(col_act, fila_act, col_dest, fila_dest)) {
            *falla_en = i + 1;
            return 0;
        }

        col_act = col_dest;
        fila_act = fila_dest;
    }
    return 1;
}

int main() {
    const char* lista_500[] = {
        "Kb4", "Ka6", "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2", "Kg1", "Kh3", "Kg5", "Ke6", "Kc7", "Ka8", "Kc7", "Kb5", "Kd6", "Kb7", "Ka5", "Kc4", "Ka3", "Kc2", "Kc1",
        "Kc2", "Kb4", "Ka6", "Kb8", "Kd7", "Kb6", "Ka8", "Kc7", "Ka6", "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2", "Kg3", "Kh5", "Kg7", "Ke8", "Kc7", "Ka8", "Kc7", "Kb5",
        "Kd4", "Kb3", "Kc1", "Kc2", "Ka3", "Kc4", "Ka5", "Kc6", "Ka7", "Kc8", "Ka7", "Kc6", "Ka5", "Kc4", "Ka3", "Kc2", "Kc1", "Kc2", "Kb4", "Kd5", "Kb6", "Ka8", "Kc7",
        "Ka6", "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2", "Kg1", "Kh3", "Kg5", "Ke6", "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2", "Kg3", "Kh5", "Kg7", "Ke8", "Kc7", "Ka8",
        "Kc7", "Kb5", "Kd6", "Kb7", "Ka5", "Kc4", "Ka3", "Kc2", "Kc1", "Kc2", "Kb4", "Ka6", "Kb8", "Kd7", "Kb6", "Ka8", "Kc7", "Ka6", "Kc5", "Ka4", "Kc3", "Ka2", "Kc1",
        "Ke2", "Kg3", "Kh5", "Kg7", "Ke8", "Kc7", "Ka8", "Kc7", "Kb5", "Kd4", "Kb3", "Kc1", "Kc2", "Ka3", "Kc4", "Ka5", "Kc6", "Ka7", "Kc8", "Ka7", "Kc6", "Ka5", "Kc4",
        "Ka3", "Kc2", "Kc1", "Kc2", "Kb4", "Kd5", "Kb6", "Ka8", "Kc7", "Ka6", "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2", "Kg1", "Kh3", "Kg5", "Ke6", "Kc5", "Ka4", "Kc3",
        "Ka2", "Kc1", "Ke2", "Kg3", "Kh5", "Kg7", "Ke8", "Kc7", "Ka8", "Kc7", "Kb5", "Kd6", "Kb7", "Ka5", "Kc4", "Ka3", "Kc2", "Kc1", "Kc2", "Kb4", "Ka6", "Kb8", "Kd7",
        "Kb6", "Ka8", "Kc7", "Ka6", "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2", "Kg3", "Kh5", "Kg7", "Ke8", "Kc7", "Ka8", "Kc7", "Kb5", "Kd4", "Kb3", "Kc1", "Kc2", "Ka3",
        "Kc4", "Ka5", "Kc6", "Ka7", "Kc8", "Ka7", "Kc6", "Ka5", "Kc4", "Ka3", "Kc2", "Kc1", "Kc2", "Kb4", "Kd5", "Kb6", "Ka8"
    };
    int total_movs = sizeof(lista_500) / sizeof(lista_500[0]);
    int falla = 0;

    // Aumentamos a 100,000 iteraciones para medir un tiempo perceptible
    int iteraciones = 100000;

    clock_t inicio = clock();
    for (int iter = 0; iter < iteraciones; iter++) {
        validar_secuencia("b4", total_movs, lista_500, &falla);
    }
    clock_t fin = clock();

    double tiempo_c = ((double)(fin - inicio)) / CLOCKS_PER_SEC;

    // Guardar en el archivo txt exigido
    FILE *archivo = fopen("resultados_tiempo.txt", "w");
    if (archivo != NULL) {
        fprintf(archivo, "Tiempo de ejecucion en C (%d iteraciones de los 500 movimientos): %.6f segundos\n", iteraciones, tiempo_c);
        fclose(archivo);
    }

    printf("Prueba finalizada. Tiempo registrado: %.6f segundos.\n", tiempo_c);
    return 0;
}