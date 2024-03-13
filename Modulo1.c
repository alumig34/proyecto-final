#include "Modulo1.h"

/*
tipo_reg *fichero_a_vector(int *n) {
    tipo_reg *temp = NULL;
    *n = 0;

    FILE *fich;
    fich = fopen("datos.txt", "r");
    if (fich == NULL) {
        printf("EROOR al abrir el fichero de lectura ...\n");
        exit(1);
    }

    while(!feof(fich)) {
        temp = (tipo_reg *) realloc(temp, ((*n)+1) * sizeof(tipo_reg));
        fscanf(fich, "%[^-]-%[^-]-%d\n", temp[*n].nombre, temp[*n].direccion, &temp[*n].edad);
        (*n)++;
    }

    fclose(fich);

    return temp;
}
*/

void fichero_a_vector2(tipo_reg **v, int *n) {
    *v = NULL;
    *n = 0;

    FILE *fich;
    fich = fopen("datos.txt", "r");
    if (fich == NULL) {
        printf("EROOR al abrir el fichero de lectura ...\n");
        exit(1);
    }

    while (!feof(fich)) {
        *v = (tipo_reg *) realloc(*v, ((*n)+1) * sizeof(tipo_reg));
        fscanf(fich, "%[^-]-%[^-]-%d\n", (*v)[*n].nombre, (*v)[*n].direccion, &(*v)[*n].edad);
        (*n)++;
    }

    fclose(fich);

}

void mostrar_vector(tipo_reg *v, int n) {
    Color(YELLOW, BLACK);
    printf("\nMostrando vector:\n");
    Color(BLACK, WHITE);
    for (int i=0; i<n; i++)
        printf("%d => [ %-*s - %-*s - %2d ]\n", i,
               MAX_NOMBRE   , v[i].nombre,
               MAX_DIRECCION, v[i].direccion,
               v[i].edad);
}

void inserta_reg(tipo_reg **v, int *n) {

    // reservamos memoria
    *v = (tipo_reg *) realloc(*v, ((*n)+1) * sizeof(tipo_reg));

    // leemos valores
    // insertamos en el vector
    strcpy((*v)[*n].nombre   , leer_campo(MAX_NOMBRE   , "Nombre?"));
    strcpy((*v)[*n].direccion, leer_campo(MAX_DIRECCION, "Direccion?"));
    (*v)[*n].edad = leer_numero("Edad?");

    (*n)++;
}

void vector_a_fichero(tipo_reg *v, int n) {

    FILE *fich;
    fich = fopen("datos.txt", "w");
    if (fich == NULL) {
        printf("EROOR al abrir el fichero de escritura ...\n");
        exit(2);
    }

    for (int i=0; i<n; i++) {
        fprintf(fich, "%s-%s-%d\n", v[i].nombre, v[i].direccion, v[i].edad);
    }

    fclose(fich);
}
