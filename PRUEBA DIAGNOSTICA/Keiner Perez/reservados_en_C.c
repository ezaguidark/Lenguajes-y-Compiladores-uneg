#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    const char *ingles;
    const char *espanol;
} TradccionReservada;

TradccionReservada reservadas[] = {
    {"auto", "automático"},
    {"break", "romper"},
    {"case", "caso"},
    {"char", "carácter"},
    {"const", "constante"},
    {"continue", "continuar"},
    {"default", "predeterminado"},
    {"do", "hacer"},
    {"double", "doble_precisión"},
    {"else", "sino"},
    {"enum", "enumeración"},
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
    {"sizeof", "tamaño de"},
    {"static", "estático"},
    {"struct", "estructura"},
    {"switch", "cambiar"},
    {"typedef", "definición de tipo"},
    {"union", "unión"},
    {"unsigned", "sin signo"},
    {"void", "vacío"},
    {"volatile", "volátil"},
    {"while", "mientras"}
};

int total_palabras = sizeof(reservadas) / sizeof(TradccionReservada);

const char* buscar_traduccion(const char *palabra) {
    for (int i = 0; i < total_palabras; i++) {
        if (strcmp(reservadas[i].ingles, palabra) == 0) {
            return reservadas[i].espanol;
        }
    }
    return NULL; // Retorna NULL si no se encuentra la palabra
}

void analizar_codigo_dinamico(const char *codigo) {
    
    char *buffer = (char*)malloc(strlen(codigo) + 1);
    strcpy(buffer, codigo);

    printf("---ANALISIS DE PALABRAS RESERVADAS---\n");
    char *token = strtok(buffer, " \t\n\r(){}[];,");
    while (token != NULL) {
        const char *traduccion = buscar_traduccion(token);
        if (traduccion != NULL) {
            printf("Palabra reservada: %s -> Traduccion: %s\n", token, traduccion);
        }
        token = strtok(NULL, " \t\n\r(){}[];,");
    }

    free (buffer);
}

int main() {
    const char *codigo = 
        "int main() {\n" 
        "   int a = 10;\n"
        "   if (a > 5) {\n" 
        "       return 1;\n" 
        "   } else {\n"
        "       return 0;\n"
        "   }\n"
        "}";
        
    analizar_codigo_dinamico(codigo);
    return 0;
}