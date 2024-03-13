#include "Modulo1.h"

int main() {
    tipo_reg* v;
    int n;

    fichero_a_vector2(&v, &n);
    mostrar_vector(v, n);

    inserta_reg(&v, &n);
    mostrar_vector(v, n);

    vector_a_fichero(v, n);

    return 0;
}
