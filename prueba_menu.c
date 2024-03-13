#include "Menu.h"
#include "Modulo1.h"

int main() {

    tipo_reg *vector = NULL;
    int tam_vector = 0;

    COORD c;
    gotoxy_printf(40,0,"EMPEZAMOS ...");
    c = GetCursorPosition();
    printf("x=%d, y=%d\n", c.X, c.Y);

    char *aMenu[] = {"FICHERO a VECTOR","Insertar registro",
                     "Mostrar VECTOR","VECTOR a FICHERO", "Salir"};

    int opcion = -1;
    while(opcion != 4){

        opcion = menu((COORD){10,1}, aMenu, sizeof(aMenu)/sizeof(aMenu[0]));
        gotoxy(40,1);  printf("OPCION=====>%d\n", opcion);

        switch (opcion) {
        case 0: // FICHERO a VECTOR"
            fichero_a_vector2(&vector, &tam_vector);
            break;
        case 1: // Insertar registro
            inserta_reg(&vector, &tam_vector);
            break;
        case 2: // Mostrar VECTOR
            mostrar_vector(vector, tam_vector);
            break;
        case 3: // VECTOR a FICHERO"
            //vector_a_fichero(vector, tam_vector);
            break;
        }

    }

    gotoxy_printf(40,2,"TERMINAMOS...");
    c = GetCursorPosition();
    printf("x=%d, y=%d\n", c.X, c.Y);

    gotoxy(0,10);
    //system("PAUSE");

    return 0;
}
