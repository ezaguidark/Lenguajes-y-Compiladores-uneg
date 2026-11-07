#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    const char* c_kw;
    const char* es_kw;
} Traduccion;

Traduccion diccionario[] = {
    {"int", "entero"},
    {"char", "caracter"},
    {"float", "flotante"},
    {"double", "doble"},
    {"void", "vacio"},
    {"if", "si"},
    {"else", "sino"},
    {"for", "para"},
    {"while", "mientras"},
    {"return", "retornar"},
    {"struct", "estructura"},
    {"break", "interrumpir"},
    {"include", "incluir"},
    {"printf", "imprimirf"},
    {"scanf", "leerf"},
    {"main", "principal"}
};
int num_palabras = sizeof(diccionario) / sizeof(diccionario[0]);

char* cargar_programa_en_memoria(const char* nombre_archivo) {
    FILE* archivo = fopen(nombre_archivo, "r");
    if (!archivo) {
        printf("\n[Error]: No se pudo abrir el archivo en la ruta especificada:\n-> %s\n", nombre_archivo);
        printf("Verifique que la ruta sea correcta y que el archivo exista.\n");
        return NULL;
    }

    fseek(archivo, 0, SEEK_END);
    long tamano_archivo = ftell(archivo);
    rewind(archivo);

    char* memoria_buffer = (char*)malloc(tamano_archivo + 1);
    if (!memoria_buffer) {
        printf("[Error]: No hay suficiente memoria RAM disponible.\n");
        fclose(archivo);
        return NULL;
    }

    long bytes_leidos = fread(memoria_buffer, 1, tamano_archivo, archivo);
    memoria_buffer[bytes_leidos] = '\0';

    fclose(archivo);
    return memoria_buffer; 
}

const char* buscar_traduccion(const char* token) {
    for (int i = 0; i < num_palabras; i++) {
        if (strcmp(diccionario[i].c_kw, token) == 0) {
            return diccionario[i].es_kw;
        }
    }
    return NULL;
}

int main() {
    char ruta_archivo[512];

    printf("=========================================\n");
    printf("   TRADUCTOR DINAMICO DE PALABRAS C\n");
    printf("=========================================\n");
    printf("Ingrese la ruta completa del archivo C a traducir\n");
    printf("(Ej: C:\\Users\\usuario\\Documents\\...\\main.c):\n> ");

    if (fgets(ruta_archivo, sizeof(ruta_archivo), stdin) != NULL) {
        size_t len = strlen(ruta_archivo);
        if (len > 0 && ruta_archivo[len - 1] == '\n') {
            ruta_archivo[len - 1] = '\0';
        }
    }

    char* codigo_dinamico = cargar_programa_en_memoria(ruta_archivo);
    if (!codigo_dinamico) {
        return 1;
    }

    printf("\n=== ARCHIVO CARGADO EXITOSAMENTE EN MEMORIA DINAMICA ===\n\n");

    int len = strlen(codigo_dinamico);
    char* resultado = (char*)malloc(len * 2 + 1);
    int p_out = 0, i = 0;

    while (i < len) {
        if (isalpha(codigo_dinamico[i]) || codigo_dinamico[i] == '_') {
            char token[64];
            int p_tok = 0;
            while (i < len && (isalnum(codigo_dinamico[i]) || codigo_dinamico[i] == '_')) {
                token[p_tok++] = codigo_dinamico[i++];
            }
            token[p_tok] = '\0';

            const char* trad = buscar_traduccion(token);
            if (trad) {
                strcpy(resultado + p_out, trad);
                p_out += strlen(trad);
            } else {
                strcpy(resultado + p_out, token);
                p_out += strlen(token);
            }
        } else {
            resultado[p_out++] = codigo_dinamico[i++];
        }
    }
    resultado[p_out] = '\0';

    printf("--- CODIGO TRADUCIDO AL ESPANOL ---\n%s\n", resultado);

    free(codigo_dinamico);
    free(resultado);

    return 0;
}