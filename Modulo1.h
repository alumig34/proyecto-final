#ifndef MODULO1_H_INCLUDED
#define MODULO1_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"

#define MAX_NOMBRE 10
#define MAX_DIRECCION 20

typedef struct {
    char nombre[MAX_NOMBRE+1];
    char direccion[MAX_DIRECCION+1];
    int edad;
} tipo_reg;

//tipo_reg *fichero_a_vector(int *);
void fichero_a_vector2(tipo_reg **, int *);
void mostrar_vector(tipo_reg *, int);
void inserta_reg(tipo_reg **, int *);

#endif // MODULO1_H_INCLUDED
