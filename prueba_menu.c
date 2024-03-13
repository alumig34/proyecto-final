#include "Menu.h"

int main() {

    int opcion;

    COORD c;
    gotoxy_printf(40,0,"EMPEZAMOS ...");
    c = GetCursorPosition();
    printf("x=%d, y=%d\n", c.X, c.Y);

    char *aMenu[] = {"uno","dos","tres","Salir"};
    opcion = menu((COORD){10,1}, aMenu, sizeof(aMenu)/sizeof(aMenu[0]));
    gotoxy(40,1);  printf("OPCION=====>%d\n", opcion);


    gotoxy_printf(40,2,"TERMINAMOS...");
    c = GetCursorPosition();
    printf("x=%d, y=%d\n", c.X, c.Y);

    gotoxy(0,10);
    //system("PAUSE");

    return 0;
}
