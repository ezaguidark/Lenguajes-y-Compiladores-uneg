#!/bin/bash
echo "=== Instalando dependencias para el Ejercicio 3 (C) ==="
sudo apt update
sudo apt install -y build-essential

echo "Compilando el traductor dinámico..."
gcc main.c -o traductor

echo "Instalacion y compilacion completadas."
echo "Puedes ejecutar el programa con: ./traductor"