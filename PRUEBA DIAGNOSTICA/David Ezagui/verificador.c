#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Estructura para almacenar la palabra en C y su traducción
typedef struct {
    char *c_word;
    char *es_word;
} Traduccion;

// Diccionario de la mayoria de palabras reservadas en C
// Se usara para verificar si existe alguna de las palabras reservadas y
// Mostrar su equivalente en español

Traduccion diccionario[] = {
    {"auto", "automatico"},
    {"break", "romper"},
    {"case", "caso"},
    {"char", "caracter"},
    {"const", "constante"},
    {"continue", "continuar"},
    {"default", "por defecto"},
    {"do", "hacer"},
    {"double", "doble precision"},
    {"else", "si no"},
    {"enum", "enumeracion"},
    {"extern", "externo"},
    {"float", "flotante"},
    {"for", "para"},
    {"goto", "ir a"},
    {"if", "si"},
    {"int", "entero"},
    {"long", "largo"},
    {"register", "registro"},
    {"return", "retornar"},
    {"short", "corto"},
    {"signed", "con signo"},
    {"sizeof", "tamano de"},
    {"static", "estatico"},
    {"struct", "estructura"},
    {"switch", "interruptor"},
    {"typedef", "definir tipo"},
    {"union", "union"},
    {"unsigned", "sin signo"},
    {"void", "vacio"},
    {"volatile", "volatil"},
    {"while", "mientras"}
};

int total_palabras_clave = sizeof(diccionario) / sizeof(diccionario[0]);

// Función para buscar si una palabra es reservada
const char* buscar_traduccion(char *palabra) {
    for (int i = 0; i < total_palabras_clave; i++) {
        if (strcmp(palabra, diccionario[i].c_word) == 0) {
            return diccionario[i].es_word;
        }
    }
    return NULL; // No es palabra reservada
}

int main() {
    // por ejemplo el archivo del ejercicio 1
    char *nombre_archivo = "tablero_ajedrez.c"; 

    FILE *archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo '%s'. \n", nombre_archivo);
        return 1;
    }

    // 1. Calcular el tamaño exacto del archivo
    fseek(archivo, 0, SEEK_END);
    long tamano = ftell(archivo);
    rewind(archivo);

    // 2. Cargar el archivo en memoria dinámica usando malloc
    char *buffer = (char *)malloc((tamano + 1) * sizeof(char));
    if (buffer == NULL) {
        printf("Error: No se pudo asignar memoria dinámica con malloc.\n");
        fclose(archivo);
        return 1;
    }

    // Leer el contenido completo del archivo
    size_t bytes_leidos = fread(buffer, sizeof(char), tamano, archivo);
    buffer[bytes_leidos] = '\0'; 
    fclose(archivo);

    printf("ARCHIVO '%s' CARGADO: \n", nombre_archivo);
    printf("Palabras encontradas: \n\n");
    printf("%-15s | %-25s\n", "PALABRA EN C", "TRADUCCION");
    printf("-----------------------------------------\n");

    // 3. Analizar el texto palabra por palabra
    int i = 0;
    while (buffer[i] != '\0') {
        // Si encontramos una letra o guion bajo, empieza una palabra potencial
        if (isalpha(buffer[i]) || buffer[i] == '_') {
            int inicio = i;
            // Avanzar mientras sea parte de un identificador/palabra
            while (isalnum(buffer[i]) || buffer[i] == '_') {
                i++;
            }
            int longitud = i - inicio;

            // Extraer temporalmente la palabra
            char palabra_actual[50];
            if (longitud < 50) {
                strncpy(palabra_actual, &buffer[inicio], longitud);
                palabra_actual[longitud] = '\0';

                // Verificar si está en nuestro diccionario de palabras reservadas
                const char *traduccion = buscar_traduccion(palabra_actual);
                if (traduccion != NULL) {
                    printf("%-15s -> %-25s\n", palabra_actual, traduccion);
                }
            }
        } else {
            i++;
        }
    }

    free(buffer);

    return 0;
}