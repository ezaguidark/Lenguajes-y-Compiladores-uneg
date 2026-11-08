import time

def generar_pascal(n):
    # Genera la fila n del Triángulo de Pascal
    fila = [1] + [0] * n
    for i in range(1, n + 1):
        for j in range(i, 0, -1):
            fila[j] = fila[j] + fila[j - 1]
    return fila

def evaluar_polinomio(n, coefs, x):
    print(f"\n--- Evaluando f(x) = (x + 1)^{n} para x = {x} ---")
    resultado_total = 0
    for i, coef in enumerate(coefs):
        potencia = n - i
        termino = coef * (x ** potencia)
        resultado_total += termino
        print(f"Paso {i + 1}: Coeficiente {coef} * ({x}^{potencia}) = {termino}")
    print(f"Resultado Final f({x}) = {resultado_total}\n")

# Medición de rendimiento para n = 100
n = 100
inicio = time.perf_counter()
for _ in range(50000):
    coefs_n = generar_pascal(n)
fin = time.perf_counter()

tiempo_python = fin - inicio

# Guardar en el archivo txt compartido
with open("resultados_tiempo.txt", "a") as f:
    f.write(f"Ejercicio 2 - Tiempo Python (n=100, 50k iteraciones): {tiempo_python:.6f} segundos\n")

print(f"Generación en Python para n={n} completada. Tiempo: {tiempo_python:.6f} segundos.")

# Demostración paso a paso con n = 4
coefs_demo = generar_pascal(4)
evaluar_polinomio(4, coefs_demo, 2.0)