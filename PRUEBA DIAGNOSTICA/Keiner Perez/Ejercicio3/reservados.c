#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Estructura de diccionario para palabras reservadas y su traducción
typedef struct {
    const char *ingles;
    const char *espanol;
} TraduccionReservada;

TraduccionReservada diccionario[] = {
    {"auto", "automatico"},
    {"break", "romper/interrumpir"},
    {"case", "caso"},
    {"char", "caracter"},
    {"const", "constante"},
    {"continue", "continuar"},
    {"default", "predeterminado"},
    {"do", "hacer"},
    {"double", "doble_precision"},
    {"else", "sino"},
    {"enum", "enumeracion"},
    {"extern", "externo"},
    {"float", "flotante"},
    {"for", "para"},
    {"goto", "ir_a"},
    {"if", "si"},
    {"int", "entero"},
    {"long", "largo"},
    {"register", "registro"},
    {"return", "retornar"},
    {"short", "corto"},
    {"signed", "con_signo"},
    {"sizeof", "tamano_de"},
    {"static", "estatico"},
    {"struct", "estructura"},
    {"switch", "segun/conmutar"},
    {"typedef", "definir_tipo"},
    {"union", "union"},
    {"unsigned", "sin_signo"},
    {"void", "vacio"},
    {"volatile", "volatile"},
    {"while", "mientras"}
};

int total_palabras = sizeof(diccionario) / sizeof(TraduccionReservada);

const char* buscar_traduccion(const char *palabra) {
    for (int i = 0; i < total_palabras; i++) {
        if (strcmp(diccionario[i].ingles, palabra) == 0) {
            return diccionario[i].espanol;
        }
    }
    return NULL;
}

void analizar_codigo_dinamico(const char *codigo_fuente) {
    // Asignación dinámica para el análisis del texto fuente
    char *buffer = (char*)malloc(strlen(codigo_fuente) + 1);
    strcpy(buffer, codigo_fuente);

    printf("--- ANALISIS DE PALABRAS RESERVADAS EN C ---\n");
    char *token = strtok(buffer, " \t\n\r(){}[];,");
    while (token != NULL) {
        const char *trad = buscar_traduccion(token);
        if (trad != NULL) {
            printf("Palabra reservada encontrada: [%s] -> Traduccion: [%s]\n", token, trad);
        }
        token = strtok(NULL, " \t\n\r(){}[];,");
    }

    free(buffer);
}

int main() {
    // Ejemplo de un fragmento de código en C cargado en memoria
    char *codigo_ejemplo = 
        "int main() {\n"
        "    int a = 10;\n"
        "    if (a > 5) {\n"
        "        return 1;\n"
        "    } else {\n"
        "        return 0;\n"
        "    }\n"
        "}";

    analizar_codigo_dinamico(codigo_ejemplo);
    return 0;
}