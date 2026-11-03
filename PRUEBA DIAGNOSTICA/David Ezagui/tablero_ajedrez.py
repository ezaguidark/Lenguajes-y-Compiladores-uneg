import time

# ak es la posicion inicial, n el numero de movimientos y C la lista de movimientos
def verificar_mov(ak, n, C):
  # Separar el valor de la fila y columna.
  col_actual = ord(ak[0].lower()) - ord("a")
  fila_actual = int(ak[1]) - 1

  for i in range(n):
    mov = C[i]
    # Por cada movimento, se elimina la letra K para obtener solo la posicion.
    destino = mov.lstrip("kK")

    # Si uno de los movimientos no tiene 2 coordenadas es incorrecta.
    if len(destino) != 2:
      return f"INCORRECTO falla en el movimiento {i+1}"

    col_dest = ord(destino[0].lower()) - ord("a")
    fila_dest = int(destino[1]) - 1

    # Verificar si esta dentro del tablero
    if not (0 <= col_dest < 8 and 0 <= fila_dest < 8):
      return f"INCORRECTO falla en el movimiento {i+1}"

    # Se verifica si hay una diferencia de 2 en una coordenada entre dos filas o columnas y una diferencia de 1 en la otra coordenada.
    # De esa manera, se verifica la tipica forma de L del movimiento del caballo.
    # Por ejemplo, de a a b hay 1 columna, de 1 a 3 hay 2 filas.
    dif_col = abs(col_dest - col_actual)
    dif_fila = abs(fila_dest - fila_actual)

    if not ((dif_col == 2 and dif_fila == 1) or (dif_col == 1 and dif_fila == 2)):
      return f"INCORRECTO falla en el movimiento {i+1}"

    # Actualizar la posición actual del caballo luego de moverse
    col_actual = col_dest
    fila_actual = fila_dest

  return "CORRECTO"

# Iniciar Counter
inicio = time.perf_counter()

# Probando con el ejemplo del PDF copiado y pegado
ak = "a2"  # como el primero elemento de la lista es kb4, el punto de origen es a2
n = 224  # verificado con len(C)
C = [
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
    "Kb4", "Kd5", "Kb6", "Ka8"
]

# Verificar la prueba 10 veces:
for i in range(10):
    print(f"Ejecutando Prueba {i + 1}:", verificar_mov(ak, n, C))

fin = time.perf_counter()
print(f"Tiempo de ejecucion (Python): {fin - inicio:.8f} segundos")