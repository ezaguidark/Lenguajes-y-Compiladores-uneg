import time

def generar_pascal_en_python(n):

    fila = [0] * (n + 1)
    fila[0] = 1

    for i in range(1, n + 1):
        for j in range(i, 0, -1):
            fila[j] += fila[j - 1]
    return fila

n = 100
inicio = time.time()
resultado = generar_pascal_en_python(n)
fin = time.time()

tiempo_python = fin - inicio

with open("resultado_pascal_python.txt", "w") as archivo:
    archivo.write("Generacion de coeficientes del triangulo de Pascal para n = {}:\n".format(n))
    archivo.write("Tiempo de ejecucion en Python: {:.6f} segundos\n".format(tiempo_python))

print("Ejercicio 2 en Python completado en {:.6f} segundos.".format(tiempo_python))