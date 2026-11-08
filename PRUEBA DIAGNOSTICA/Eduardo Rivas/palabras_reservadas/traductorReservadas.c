#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Estructura para asociar la palabra reservada en C con su traducción al español
typedef struct {
    const char *palabra_c;
    const char *traduccion_es;
} PalabraReservada;

// Lista de palabras reservadas estándar de C y su traducción
PalabraReservada diccionario[] = {
    {"auto", "automatico"},
    {"break", "romper / detener"},
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
    {"switch", "interruptor / selector"},
    {"typedef", "definir_tipo"},
    {"union", "union"},
    {"unsigned", "sin_signo"},
    {"void", "vacio"},
    {"volatile", "volatile / volatil"},
    {"while", "mientras"}
};

int total_reservadas = sizeof(diccionario) / sizeof(diccionario[0]);

// Función para buscar si una palabra es reservada
const char* buscar_traduccion(const char *palabra) {
    for (int i = 0; i < total_reservadas; i++) {
        if (strcmp(diccionario[i].palabra_c, palabra) == 0) {
            return diccionario[i].traduccion_es;
        }
    }
    return NULL;
}

// Función para cargar y analizar un archivo de código fuente C usando memoria dinámica
void analizar_codigo_c(const char *nombre_archivo) {
    FILE *file = fopen(nombre_archivo, "r");
    if (!file) {
        printf("No se pudo abrir el archivo de codigo fuente: %s\n", nombre_archivo);
        return;
    }

    // Obtener el tamaño del archivo para reservar memoria dinámica exacta
    fseek(file, 0, SEEK_END);
    long tamano = ftell(file);
    rewind(file);

    // Asignación de memoria dinámica para el contenido completo del archivo
    char *buffer = (char*) malloc((tamano + 1) * sizeof(char));
    if (!buffer) {
        printf("Error de asignacion de memoria dinamica.\n");
        fclose(file);
        return;
    }

    long leidos = fread(buffer, sizeof(char), tamano, file);
    buffer[leidos] = '\0';
    fclose(file);

    printf("\n--- ANALISIS DE PALABRAS RESERVADAS EN: %s ---\n", nombre_archivo);
    
    // Extracción dinámica de palabras (tokens) del código fuente
    char *token = malloc(256 * sizeof(char));
    int idx = 0;
    
    for (int i = 0; i <= leidos; i++) {
        char c = buffer[i];
        if (isalnum(c) || c == '_') {
            if (idx < 255) token[idx++] = c;
        } else {
            if (idx > 0) {
                token[idx] = '\0';
                const char *trad = buscar_traduccion(token);
                if (trad != NULL) {
                    printf("[Encontrada] Palabra C: '%s' --> Traduccion al espanol: '%s'\n", token, trad);
                }
                idx = 0;
            }
        }
    }

    // Liberar memoria dinámica utilizada
    free(token);
    free(buffer);
    printf("--------------------------------------------------\n\n");
}

int main() {
    // Retrocedemos una carpeta (..) y entramos a ejercicio1
    analizar_codigo_c("../ajedrez_caballo/movimientosCaballo.c");
    return 0;
}