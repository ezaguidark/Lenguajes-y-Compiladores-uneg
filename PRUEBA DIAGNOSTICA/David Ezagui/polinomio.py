import time

def nueva_fila(n):
    fila = [1]
    for i in range(n):
        fila = [1] + [fila[j] + fila[j+1] for j in range(len(fila)-1)] + [1]
        # print(f"Nivel n={i}: {fila}")  # Se torna muy largo
    return fila

def resolver_pascal(n, x=None):
    # Genera coeficientes por cada fila del triangulo de pascal
    coefs = nueva_fila(n)
    
    print(f"\n- Polinomio resultante para (x + 1)^{n}: ")
    terminos = []
    for i, c in enumerate(coefs):
        grado = n - i
        if grado > 1:
            terminos.append(f"{c}x^{grado}")
        elif grado == 1:
            terminos.append(f"{c}x")
        else:
            terminos.append(f"{c}")
    print("F(x) = " + " + ".join(terminos))
    
    # Si no hay valor de X, no se puede calcular un resultado
    if x is None:
        print("\nNo se ingreso un valor para X.")
        return
    
    # Si se tiene un valor de X, se calcula el valor final del polinomio
    print(f"\nCalculo paso a paso evaluando en x = {x}:")
    total = 0
    pasos = []
    
    for i, c in enumerate(coefs):
        grado = n - i
        pot = x ** grado
        parcial = c * pot
        total += parcial
        pasos.append(f"Paso {i}: ({c} * {x}^{grado} = {parcial})")
        
    print(" \n".join(pasos))
    print(f"Resultado final f({x}) = {total}")

inicio = time.perf_counter()

print("Prueba con n = 100: ")  # Ejemplo, valor de X = 1
resolver_pascal(100, 1)

fin = time.perf_counter()
print(f"Tiempo de ejecucion (Python): {fin - inicio:.8f} segundos")