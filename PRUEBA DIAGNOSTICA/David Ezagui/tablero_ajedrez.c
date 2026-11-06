#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void verificar_mov(const char* ak, int n, char movimientos[][10]) {
    // Obtener la fila y la columna
    int col_actual = ak[0] - 'a';
    int fila_actual = ak[1] - '1';

    for (int i = 0; i < n; i++) {
        char* destino = movimientos[i];
        
        // Remover la letra K
        if (destino[0] == 'K' || destino[0] == 'k') {
            destino++;
        }

        int col_dest = destino[0] - 'a';
        int fila_dest = destino[1] - '1';

        // Validar límites del tablero (0 a 7)
        if (col_dest < 0 || col_dest >= 8 || fila_dest < 0 || fila_dest >= 8) {
            printf("INCORRECTO falla en el movimiento %d\n", i + 1);
            return;
        }

        // Se verifica si hay una diferencia de 2 en una coordenada entre dos filas o columnas y una diferencia de 1 en la otra coordenada.
        int dif_col = abs(col_dest - col_actual);
        int dif_fila = abs(fila_dest - fila_actual);

        // Validar movimiento en L del caballo
        if (!((dif_col == 2 && dif_fila == 1) || (dif_col == 1 && dif_fila == 2))) {
            printf("INCORRECTO falla en el movimiento %d\n", i + 1);
            return;
        }

        // Actualizar posición
        col_actual = col_dest;
        fila_actual = fila_dest;
    }

    printf("CORRECTO\n");
}

int main() {
    // Iniciar medición de tiempo
    clock_t inicio = clock();

    
    // Texto copiado del archivo pdf
    char ak[] = "a2";
    
    char C[][10] = {
        "Kb4", "Ka6", "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2", "Kg1", "Kh3", "Kg5", "Ke6", "Kc7", "Ka8", "Kc7", "Kb5", "Kd6", "Kb7", "Ka5", "Kc4", "Ka3", "Kc2",
        "Ka1", "Kc2", "Kb4", "Ka6", "Kb8", "Kd7", "Kb6", "Ka8", "Kc7", "Ka6", "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2", "Kg3", "Kh5", "Kg7", "Ke8", "Kc7", "Ka8",
        "Kc7", "Kb5", "Kd4", "Kb3", "Ka1", "Kc2", "Ka3", "Kc4", "Ka5", "Kc6", "Ka7", "Kc8", "Ka7", "Kc6", "Ka5", "Kc4", "Ka3", "Kc2", "Ka1", "Kc2", "Kb4", "Kd5",
        "Kb6", "Ka8", "Kc7", "Ka6", "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2", "Kg1", "Kh3", "Kg5", "Ke6", "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2", "Kg3", "Kh5",
        "Kg7", "Ke8", "Kc7", "Ka8", "Kc7", "Kb5", "Kd6", "Kb7", "Ka5", "Kc4", "Ka3", "Kc2", "Ka1", "Kc2", "Kb4", "Ka6", "Kb8", "Kd7", "Kb6", "Ka8", "Kc7", "Ka6",
        "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2", "Kg3", "Kh5", "Kg7", "Ke8", "Kc7", "Ka8", "Kc7", "Kb5", "Kd4", "Kb3", "Ka1", "Kc2", "Ka3", "Kc4", "Ka5", "Kc6",
        "Ka7", "Kc8", "Ka7", "Kc6", "Ka5", "Kc4", "Ka3", "Kc2", "Ka1", "Kc2", "Kb4", "Kd5", "Kb6", "Ka8", "Kc7", "Ka6", "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2",
        "Kg1", "Kh3", "Kg5", "Ke6", "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2", "Kg3", "Kh5", "Kg7", "Ke8", "Kc7", "Ka8", "Kc7", "Kb5", "Kd6", "Kb7", "Ka5", "Kc4",
        "Ka3", "Kc2", "Ka1", "Kc2", "Kb4", "Ka6", "Kb8", "Kd7", "Kb6", "Ka8", "Kc7", "Ka6", "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2", "Kg3", "Kh5", "Kg7", "Ke8",
        "Kc7", "Ka8", "Kc7", "Kb5", "Kd4", "Kb3", "Ka1", "Kc2", "Ka3", "Kc4", "Ka5", "Kc6", "Ka7", "Kc8", "Ka7", "Kc6", "Ka5", "Kc4", "Ka3", "Kc2", "Ka1", "Kc2",
        "Kb4", "Kd5", "Kb6", "Ka8", "Kc7", "Ka6", "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2", "Kg3", "Kh5", "Kg7", "Ke8", "Kc7", "Ka8", "Kc7", "Kb5", "Kd4", "Kb3",
        "Ka1", "Kc2", "Ka3", "Kc4", "Ka5", "Kc6", "Ka7", "Kc8", "Ka7", "Kc6", "Ka5", "Kc4", "Ka3", "Kc2", "Ka1", "Kc2", "Kb4", "Kd5", "Kb6", "Ka8", "Kc7", "Ka6",
        "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2", "Kg1", "Kh3", "Kg5", "Ke6", "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2", "Kg3", "Kh5", "Kg7", "Ke8", "Kc7", "Ka8",
        "Kc7", "Kb5", "Kd6", "Kb7", "Ka5", "Kc4", "Ka3", "Kc2", "Ka1", "Kc2", "Kb4", "Ka6", "Kb8", "Kd7", "Kb6", "Ka8", "Kc7", "Ka6", "Kc5", "Ka4", "Kc3", "Ka2",
        "Kc1", "Ke2", "Kg3", "Kh5", "Kg7", "Ke8", "Kc7", "Ka8", "Kc7", "Kb5", "Kd4", "Kb3", "Ka1", "Kc2", "Ka3", "Kc4", "Ka5", "Kc6", "Ka7", "Kc8", "Ka7", "Kc6",
        "Ka5", "Kc4", "Ka3", "Kc2", "Ka1", "Kc2", "Kb4", "Kd5", "Kb6", "Ka8", "Kc7", "Ka6", "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2", "Kg1", "Kh3", "Kg5", "Ke6",
        "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2", "Kg3", "Kh5", "Kg7", "Ke8", "Kc7", "Ka8", "Kc7", "Kb5", "Kd6", "Kb7", "Ka5", "Kc4", "Ka3", "Kc2", "Ka1", "Kc2",
        "Kb4", "Ka6", "Kb8", "Kd7", "Kb6", "Ka8", "Kc7", "Ka6", "Kc5", "Ka4", "Kc3", "Ka2", "Kc1", "Ke2", "Kg3", "Kh5", "Kg7", "Ke8", "Kc7", "Ka8", "Kc7", "Kb5",
        "Kd4", "Kb3", "Ka1", "Kc2", "Ka3", "Kc4", "Ka5", "Kc6", "Ka7", "Kc8", "Ka7", "Kc6", "Ka5", "Kc4", "Ka3", "Kc2", "Ka1", "Kc2", "Kb4", "Kd5", "Kb6", "Ka8",
        "Kc7", "Ka6", "Kc5", "Ka4"
    };


    int n = sizeof(C) / sizeof(C[0]);  // verificar el numero de movimientos


    // Ejecutar la prueba 10 veces
    for (int i = 0; i < 10; i++) {
        printf("Ejecutando Prueba %d: ", i + 1);
        verificar_mov(ak, n, C);
    }


    // Finalizar medición de tiempo
    clock_t fin = clock();
    double tiempo_cpu = ((double)(fin - inicio)) / CLOCKS_PER_SEC;

    printf("Tiempo de ejecucion (C): %.8f segundos\n", tiempo_cpu);

    return 0;
}