import time

def generar_pascal_python(n):
    fila = [1]
    for i in range(1, n + 1):
        nueva_fila = [1] * (i + 1)
        for j in range(1, i):
            nueva_fila[j] = fila[j - 1] + fila[j]
        fila = nueva_fila
    return fila

if __name__ == "__main__":
    n = 100
    inicio = time.time()
    coeficientes = generar_pascal_python(n)
    fin = time.time()

    tiempo_total = fin - inicio
    print(f"Tiempo de ejecucion en Python para n={n}: {tiempo_total:.6f} segundos")

    with open("tiempos_n100.txt", "a") as f:
        f.write(f"Tiempo de ejecucion en Python: {tiempo_total:.6f} segundos\n")