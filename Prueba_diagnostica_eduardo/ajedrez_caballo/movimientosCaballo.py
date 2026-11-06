import time
import os

def es_movimiento_valido(col_act, fila_act, col_dest, fila_dest):
    dc = abs(ord(col_dest) - ord(col_act))
    df = abs(fila_dest - fila_act)
    return (dc == 2 and df == 1) or (dc == 1 and df == 2)

def validar_secuencia(pos_inicial, movimientos):
    if len(pos_inicial) != 2:
        return False, 0
    col_act = pos_inicial[0]
    fila_act = int(pos_inicial[1])
    
    if not ('a' <= col_act <= 'h') or not (1 <= fila_act <= 8):
        return False, 0

    for i, mov in enumerate(movimientos):
        if len(mov) != 3 or mov[0] != 'K':
            return False, i + 1  # Falla por formato o letra incorrecta
        
        col_dest = mov[1]
        try:
            fila_dest = int(mov[2])
        except ValueError:
            return False, i + 1

        if not ('a' <= col_dest <= 'h') or not (1 <= fila_dest <= 8):
            return False, i + 1

        if not es_movimiento_valido(col_act, fila_act, col_dest, fila_dest):
            return False, i + 1

        col_act = col_dest
        fila_act = fila_dest

    return True, 0

# Bloque de medición de rendimiento exigido
movs_prueba = ["Kc2", "Kd4", "Kb3", "Kc5"]

inicio = time.perf_counter()
for _ in range(10):
    validar_secuencia("a2", movs_prueba)
fin = time.perf_counter()

tiempo_python = fin - inicio

# Guardar en archivo txt
with open("resultados_tiempo.txt", "a") as f:
    f.write(f"Tiempo de ejecucion en Python (10 iteraciones): {tiempo_python:.6f} segundos\n")

print(f"Ejecución en Python completada. Tiempo: {tiempo_python:.6f} segundos.")