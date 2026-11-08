import time

def generar_pascal_python(n):
    
    fila = [0] * (n + 1)
    fila[0] = 1
    
    for i in range(1, n + 1):
        for j in range(i, 0, -1):
            fila[j] = fila[j] + fila[j - 1]
    return fila


n = 100


inicio = time.time()
coeficientes = generar_pascal_python(n)
fin = time.time()

tiempo_python = fin - inicio

with open("resultado_ejercicio2_python.txt", "w") as f:
    f.write("=== COEFICIENTES DEL POLINOMIO (x+1)^{} (TRIANGULO DE PASCAL) ===\n".format(n))
    f.write("Total de coeficientes generados: {}\n\n".format(len(coeficientes)))
    
    
    for i, coef in enumerate(coeficientes):
        grado = n - i
        if grado > 1:
            f.write("Coeficiente de x^{}: {}\n".format(grado, coef))
        elif grado == 1:
            f.write("Coeficiente de x^1: {}\n".format(coef))
        else:
            f.write("Termino independiente (x^0): {}\n".format(coef))
            
    f.write("\n=================================================================\n")
    f.write("Tiempo de ejecucion en Python (n={}): {:.9f} segundos\n".format(n, tiempo_python))

print("Proceso completado")
print("Tiempo medido: {:.9f} segundos".format(tiempo_python))