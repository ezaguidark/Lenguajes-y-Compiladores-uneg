#!/bin/bash
echo "=== Instalando dependencias para el Ejercicio 2 (C y Python) ==="
sudo apt update
sudo apt install -y build-essential python3

echo "Compilando codigo en C..."
gcc main.c -o programa_pascal -lm

echo "Entorno y compilación listos."
echo "Para ejecutar C: ./programa_pascal"
echo "Para ejecutar Python: python3 main.py"