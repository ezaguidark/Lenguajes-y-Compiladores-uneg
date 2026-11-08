import os

script_dir = os.path.dirname(os.path.abspath(__file__))
ruta_archivo = os.path.join(script_dir, "resultado_ejercicio1_python.txt")

def evaluar_y_registrar(pos_inicial, n, C, archivo_txt):
    if len(pos_inicial) != 2:
        archivo_txt.write("Para Ak={} n={} y C=... salida: INCORRECTO posicion inicial invalida\n".format(pos_inicial, n))
        return

    col_actual = ord(pos_inicial[0]) - ord('a') + 1
    fil_actual = int(pos_inicial[1])

    if not (1 <= col_actual <= 8 and 1 <= fil_actual <= 8):
        archivo_txt.write("Para Ak={} n={} y C=... salida: INCORRECTO posicion inicial fuera de tablero\n".format(pos_inicial, n))
        return

    for i in range(min(n, len(C))):
        mov = C[i]

   
        if not mov.startswith('K') or len(mov) != 3:
            archivo_txt.write("Para Ak={} n={} y C=... salida: INCORRECTO falla letra {} no pertenece a un caballo.\n".format(pos_inicial, n, mov[0]))
            return

        col_nueva = ord(mov[1]) - ord('a') + 1
        fil_nueva = int(mov[2])

        
        if not (1 <= col_nueva <= 8 and 1 <= fil_nueva <= 8):
            archivo_txt.write("Para Ak={} n={} y C=... salida: INCORRECTO falla en el movimiento {}\n".format(pos_inicial, n, i + 1))
            return

        d_col = abs(col_nueva - col_actual)
        d_fil = abs(fil_nueva - fil_actual)

        if not ((d_col == 2 and d_fil == 1) or (d_col == 1 and d_fil == 2)):
            archivo_txt.write("Para Ak={} n={} y C=... salida: INCORRECTO falla en el movimiento {}\n".format(pos_inicial, n, i + 1))
            return

        archivo_txt.write("Comprobacion mov {} ({}): Correcto\n".format(i + 1, mov))

        col_actual = col_nueva
        fil_actual = fil_nueva

    archivo_txt.write("Para Ak={} n={} y C=... salida: movimiento CORRECTO\n".format(pos_inicial, n))

movimientos_500 = [
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
]

n = len(movimientos_500)
pos_inicial = "a2"

with open(ruta_archivo, "w") as archivo:
    archivo.write("=== REGISTRO DE TRAZA DE COMPROBACIONES ===\n\n")
    
    for iteracion in range(1, 11):
        archivo.write("--- Iteracion {} ---\n".format(iteracion))
        evaluar_y_registrar(pos_inicial, n, movimientos_500, archivo)
        archivo.write("\n")
    

print("Ejecucion completada con exito")
print("Los registros paso a paso y el tiempo total se han guardado en: {}".format(ruta_archivo))