#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

//Estructura para guardar resultado de validar movimientos
typedef struct {
    bool es_valido;
    int posicion_error;
    char mensaje[100];
} ResultadoValidacion;

ResultadoValidacion validar_movimiento(const char* posicion_inicial, const char* lista_movs[], int n) {
    ResultadoValidacion resultado = {true, 0, "Movimiento válido"};

    if (strlen(posicion_inicial) != 2){
        resultado.es_valido = false;
        resultado.posicion_error = 0;
        snprintf(resultado.mensaje, sizeof(resultado.mensaje), "Posición inicial inválida: %s", posicion_inicial);
        return resultado;
    }

    int columna_inicial = posicion_inicial[0] - 'a' + 1;
    int fila_inicial = posicion_inicial[1] - '0';
    
    if (columna_inicial < 1 || columna_inicial > 8 || fila_inicial < 1 || fila_inicial > 8) {
        resultado.es_valido = false;
        resultado.posicion_error = 0;
        snprintf(resultado.mensaje, sizeof(resultado.mensaje), "Posición inicial fuera del tablero: %s", posicion_inicial);
        return resultado;
    }

    for (int i = 0; i < n; i++) {
        const char* mov = lista_movs[i];

        if (mov[0] != 'K') {
            resultado.es_valido = false;
            resultado.posicion_error = i + 1;
            snprintf(resultado.mensaje, sizeof(resultado.mensaje), "Movimiento inválido en la posición %d: %s", i + 1, mov);
            return resultado;
        }

        if(strlen(mov) != 3) {
            resultado.es_valido = false;
            resultado.posicion_error = i + 1;
            snprintf(resultado.mensaje, sizeof(resultado.mensaje), "Formato de movimiento inválido en la posición %d: %s", i + 1, mov);
            return resultado;
        }

        int columna_nueva = mov[0] - 'a' + 1;
        int fila_nueva = mov[2] - '0';

        if (columna_nueva < 1 || columna_nueva > 8 || fila_nueva < 1 || fila_nueva > 8) {
            resultado.es_valido = false;
            resultado.posicion_error = i + 1;
            snprintf(resultado.mensaje, sizeof(resultado.mensaje), "Movimiento fuera del tablero en la posición %d: %s", i + 1, mov);
            return resultado;
        }

        // Validar movimiento de caballo
        int d_columna = abs(columna_nueva - columna_inicial);
        int d_fila = abs(fila_nueva - fila_inicial);

        if (!((d_columna == 2 && d_fila == 1) || (d_columna == 1 && d_fila == 2))) {
            resultado.es_valido = false;
            resultado.posicion_error = i + 1;
            snprintf(resultado.mensaje, sizeof(resultado.mensaje), "Movimiento no válido de caballo en la posición %d: %s", i + 1, mov);
            return resultado;
        }

        // Actualizar posición inicial para el siguiente movimiento
        columna_inicial = columna_nueva;
        fila_inicial = fila_nueva;
    }
    return resultado;
}

int main() {
    const char* movimientos_500[] = {
        "Kb4", "Ka6", "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2", "Kg1", "Kh3",
        "Kg5", "Ke6", "Kc7", "Ka8", "Kc7", "Kb5", "Kd6", "Kb7", "Ka5", "Kc4",
        "Ka3", "Kc2", "Ka1", "Kc2", "Kb4", "Ka6", "Kb8", "Kd7", "Kb6", "Ka8",
        "Kc7", "Ka6", "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2", "Kg3", "Kh5",
        "Kg7", "Ke8", "Kc7", "Ka8", "Kc7", "Kb5", "Kd4", "Kb3", "Ka1", "Kc2",
        "Ka3", "Kc4", "Ka5", "Kc6", "Ka7", "Kc8", "Ka7", "Kc6", "Ka5", "Kc4",
        "Ka3", "Kc2", "Ka1", "Kc2", "Kb4", "Kd5", "Kb6", "Ka8", "Kc7", "Ka6",
        "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2", "Kg1", "Kh3", "Kg5", "Ke6",
        "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2", "Kg3", "Kh5", "Kg7", "Ke8",
        "Kc7", "Ka8", "Kc7", "Kb5", "Kd6", "Kb7", "Ka5", "Kc4", "Ka3", "Kc2",
        "Ka1", "Kc2", "Kb4", "Ka6", "Kb8", "Kd7", "Kb6", "Ka8", "Kc7", "Ka6",
        "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2", "Kg3", "Kh5", "Kg7", "Ke8",
        "Kc7", "Ka8", "Kc7", "Kb5", "Kd4", "Kb3", "Ka1", "Kc2", "Ka3", "Kc4",
        "Ka5", "Kc6", "Ka7", "Kc8", "Ka7", "Kc6", "Ka5", "Kc4", "Ka3", "Kc2",
        "Ka1", "Kc2", "Kb4", "Kd5", "Kb6", "Ka8", "Kc7", "Ka6", "Kc5", "Ka4",
        "Kc3", "Ka2", "Kc1", "Ke2", "Kg1", "Kh3", "Kg5", "Ke6", "Kc5", "Ka4",
        "Kc3", "Ka2", "Kc1", "Ke2", "Kg3", "Kh5", "Kg7", "Ke8", "Kc7", "Ka8",
        "Kc7", "Kb5", "Kd6", "Kb7", "Ka5", "Kc4", "Ka3", "Kc2", "Ka1", "Kc2",
        "Kb4", "Ka6", "Kb8", "Kd7", "Kb6", "Ka8", "Kc7", "Ka6", "Kc5", "Ka4",
        "Kc3", "Ka2", "Kc1", "Ke2", "Kg3", "Kh5", "Kg7", "Ke8", "Kc7", "Ka8",
        "Kc7", "Kb5", "Kd4", "Kb3", "Ka1", "Kc2", "Ka3", "Kc4", "Ka5", "Kc6",
        "Ka7", "Kc8", "Ka7", "Kc6", "Ka5", "Kc4", "Ka3", "Kc2", "Ka1", "Kc2",
        "Kb4", "Kd5", "Kb6", "Ka8", "Kc7", "Ka6", "Kc5", "Ka4", "Kc3", "Ka2",
        "Kc1", "Ke2", "Kg1", "Kh3", "Kg5", "Ke6", "Kc5", "Ka4", "Kc3", "Ka2",
        "Kc1", "Ke2", "Kg3", "Kh5", "Kg7", "Ke8", "Kc7", "Ka8", "Kc7", "Kb5",
        "Kd6", "Kb7", "Ka5", "Kc4", "Ka3", "Kc2", "Ka1", "Kc2", "Kb4", "Ka6",
        "Kb8", "Kd7", "Kb6", "Ka8", "Kc7", "Ka6", "Kc5", "Ka4", "Kc3", "Ka2",
        "Kc1", "Ke2", "Kg3", "Kh5", "Kg7", "Ke8", "Kc7", "Ka8", "Kc7", "Kb5",
        "Kd4", "Kb3", "Ka1", "Kc2", "Ka3", "Kc4", "Ka5", "Kc6", "Ka7", "Kc8",
        "Ka7", "Kc6", "Ka5", "Kc4", "Ka3", "Kc2", "Ka1", "Kc2", "Kb4", "Kd5",
        "Kb6", "Ka8", "Kc7", "Ka6", "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2",
        "Kg1", "Kh3", "Kg5", "Ke6", "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2",
        "Kg3", "Kh5", "Kg7", "Ke8", "Kc7", "Ka8", "Kc7", "Kb5", "Kd6", "Kb7",
        "Ka5", "Kc4", "Ka3", "Kc2", "Ka1", "Kc2", "Kb4", "Ka6", "Kb8", "Kd7",
        "Kb6", "Ka8", "Kc7", "Ka6", "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2",
        "Kg3", "Kh5", "Kg7", "Ke8", "Kc7", "Ka8", "Kc7", "Kb5", "Kd4", "Kb3",
        "Ka1", "Kc2", "Ka3", "Kc4", "Ka5", "Kc6", "Ka7", "Kc8", "Ka7", "Kc6",
        "Ka5", "Kc4", "Ka3", "Kc2", "Ka1", "Kc2", "Kb4", "Kd5", "Kb6", "Ka8",
        "Kc7", "Ka6", "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2", "Kg1", "Kh3",
        "Kg5", "Ke6", "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2", "Kg3", "Kh5",
        "Kg7", "Ke8", "Kc7", "Ka8", "Kc7", "Kb5", "Kd6", "Kb7", "Ka5", "Kc4",
        "Ka3", "Kc2", "Ka1", "Kc2", "Kb4", "Ka6", "Kb8", "Kd7", "Kb6", "Ka8",
        "Kc7", "Ka6", "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2", "Kg3", "Kh5",
        "Kg7", "Ke8", "Kc7", "Ka8", "Kc7", "Kb5", "Kd4", "Kb3", "Ka1", "Kc2",
        "Ka3", "Kc4", "Ka5", "Kc6", "Ka7", "Kc8", "Ka7", "Kc6", "Ka5", "Kc4",
        "Ka3", "Kc2", "Ka1", "Kc2", "Kb4", "Kd5", "Kb6", "Ka8", "Kc7", "Ka6",
        "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2", "Kg1", "Kh3", "Kg5", "Ke6",
        "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2", "Kg3", "Kh5", "Kg7", "Ke8",
        "Kc7", "Ka8", "Kc7", "Kb5", "Kd6", "Kb7", "Ka5", "Kc4", "Ka3", "Kc2",
        "Ka1", "Kc2", "Kb4", "Ka6", "Kb8", "Kd7", "Kb6", "Ka8"
    };

    int num_movs = 500;

    struct timespec inicio, fin;
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    for (int inter = 0; inter < 10; inter++) {
        validar_movimiento("a1", movimientos_500, num_movs);
    }
    clock_gettime(CLOCK_MONOTONIC, &fin);

    double tiempo_total = (double)(fin.tv_sec - inicio.tv_sec) + (double)(fin.tv_nsec - inicio.tv_nsec) / 1000000000.0;

    FILE *archivo = fopen("ejercicio1_C.txt", "w");
    if (archivo != NULL) {
        fprintf(archivo, "Tiempo para validar 500 movimientos en 10 iteraciones:%.6f segundos\n", tiempo_total);
        fclose(archivo);
    }

    printf("Tiempo para validar 500 movimientos en 10 iteraciones: %.6f segundos\n", tiempo_total);
    return 0;
}
    