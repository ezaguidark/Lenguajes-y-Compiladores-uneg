def es_movimiento_valido(c1, f1, c2, f2):
    dc = abs(ord(c1) - ord(c2))
    df = abs(int(f1) - int(f2))
    return (dc == 1 and df == 2) or (dc == 2 and df == 1)

def verificar_secuencia_caballo(pos_inicial, secuencia_str):
    col_actual, fila_actual = pos_inicial[0], pos_inicial[1]
    movimientos = secuencia_str.split()

    print(f"Iniciando verificación desde la posición: {pos_inicial}")
    for i, mov in enumerate(movimientos, start=1):
        if not mov.startswith('K') or len(mov) < 3:
            print(f"INCORRECTO: El movimiento '{mov}' no cumple con la notación de caballo en el paso {i}.")
            return False

        col_dest, fila_dest = mov[1], mov[2]

        if not ('a' <= col_dest <= 'h' and '1' <= fila_dest <= '8'):
            print(f"INCORRECTO: Coordenadas fuera del tablero en el movimiento {i} ({mov}).")
            return False

        if not es_movimiento_valido(col_actual, fila_actual, col_dest, fila_dest):
            print(f"INCORRECTO falla en el movimiento {i} ({mov}).")
            return False

        col_actual, fila_actual = col_dest, fila_dest

    print("movimiento CORRECTO para toda la secuencia.")
    return True

if __name__ == "__main__":
    secuencia_500 = (
        "Kb4 Ka6 Kc5 Ka4 Kc3 Ka2 Kc1 Ke2 Kg1 Kh3 Kg5 Ke6 Kc7 Ka8 Kc7 Kb5 "
        "Kd6 Kb7 Ka5 Kc4 Ka3 Kc2 Ka1 Kc2 Kb4 Ka6 Kb8 Kd7 Kb6 Ka8 Kc7 Ka6 "
        "Kc5 Ka4 Kc3 Ka2 Kc1 Ke2 Kg3 Kh5 Kg7 Ke8 Kc7 Ka8 Kc7 Kb5 Kd4 Kb3 "
        "Ka1 Kc2 Ka3 Kc4 Ka5 Kc6 Ka7 Kc8 Ka7 Kc6 Ka5 Kc4 Ka3 Kc2 Ka1 Kc2 "
        "Kb4 Kd5 Kb6 Ka8 Kc7 Ka6 Kc5 Ka4 Kc3 Ka2 Kc1 Ke2 Kg1 Kh3 Kg5 Ke6 "
        "Kc5 Ka4 Kc3 Ka2 Kc1 Ke2 Kg3 Kh5 Kg7 Ke8 Kc7 Ka8 Kc7 Kb5 Kd6 Kb7 "
        "Ka5 Kc4 Ka3 Kc2 Ka1 Kc2 Kb4 Ka6 Kb8 Kd7 Kb6 Ka8 Kc7 Ka6 Kc5 Ka4 "
        "Kc3 Ka2 Kc1 Ke2 Kg3 Kh5 Kg7 Ke8 Kc7 Ka8 Kc7 Kb5 Kd4 Kb3 Ka1 Kc2 "
        "Ka3 Kc4 Ka5 Kc6 Ka7 Kc8 Ka7 Kc6 Ka5 Kc4 Ka3 Kc2 Ka1 Kc2 Kb4 Kd5 "
        "Kb6 Ka8 Kc7 Ka6 Kc5 Ka4 Kc3 Ka2 Kc1 Ke2 Kg1 Kh3 Kg5 Ke6 Kc5 Ka4 "
        "Kc3 Ka2 Kc1 Ke2 Kg3 Kh5 Kg7 Ke8 Kc7 Ka8 Kc7 Kb5 Kd6 Kb7 Ka5 Kc4 "
        "Ka3 Kc2 Ka1 Kc2 Kb4 Ka6 Kb8 Kd7 Kb6 Ka8 Kc7 Ka6 Kc5 Ka4 Kc3 Ka2 "
        "Kc1 Ke2 Kg3 Kh5 Kg7 Ke8 Kc7 Ka8 Kc7 Kb5 Kd4 Kb3 Ka1 Kc2 Ka3 Kc4 "
        "Ka5 Kc6 Ka7 Kc8 Ka7 Kc6 Ka5 Kc4 Ka3 Kc2 Ka1 Kc2 Kb4 Kd5 Kb6 Ka8"
    )
    
    verificar_secuencia_caballo("a2", secuencia_500)