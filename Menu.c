#include "Menu.h"

static int lenMenu(char *arreglo[], int n) {
    int max=0;
    for (int i=0; i<n; i++)
        if (strlen(arreglo[i]) > max) max = strlen(arreglo[i]);
    return max;
}

static void print_linea_menu(COORD c, int posiAnterior, int posiActual, char *arreglo[], int max) {
    SetCursorPosition(c.X, c.Y + posiAnterior);
    printf("%d - %-*s   ", posiAnterior+1, max, arreglo[posiAnterior]);
    SetCursorPosition(c.X, c.Y + posiActual);
    Color(WHITE, BLACK);
    printf("%d - %-*s <<", posiActual+1, max, arreglo[posiActual]);
    Color(BLACK,WHITE);
}

int menu(char titulo[], COORD c, char *arreglo[], int n, int posIni) {

    int posiActual = posIni;
    int posiAnterior = posiActual;
    int max;
    char cTecla;
    COORD coord_espera;

    max = lenMenu(arreglo, n);

    gotoxy_printf(c.X, c.Y, titulo);
    c.Y += 2;

    for(int i=0; i<n; i++) {
        SetCursorPosition(c.X, c.Y + i);
        printf("%d - %-*s   ", i+1, max, arreglo[i]);
    }

    gotoxy_printf(c.X, c.Y + n+1, "Presione un Tecla ...");
    coord_espera = GetCursorPosition();

    int devolver = -1;
    while(devolver == -1) {

        print_linea_menu(c, posiAnterior, posiActual, arreglo, max);
        SetCursorPosition(coord_espera.X, coord_espera.Y);

        cTecla = getch();
        if(cTecla == 0)
           cTecla = getch();

        else
           switch(cTecla) {
            case 27: // ESC
                print_linea_menu(c, posiActual, n-1, arreglo, max);
                devolver = n-1;
                break;

            case 13: // ENTER
                devolver = posiActual;
                break;

            case 9: // TAB
            case 80: // Flecha ABAJO
                posiAnterior = posiActual++;
                if (posiActual >= n) posiActual = 0;
                break;

            case 72: // Flecha ARRIBA
                posiAnterior = posiActual--;
                if (posiActual < 0) posiActual = n-1;
                break;

            default:
                //printf("tecla=>%d\n", cTecla);
                if (cTecla>=1+(int)'0' && cTecla<=n+(int)'0') {
                    posiAnterior = posiActual;
                    posiActual   = (cTecla-1) - (int)'0';
                    print_linea_menu(c, posiAnterior, posiActual, arreglo, max);
                    devolver = posiActual;
                }
            }
    }

    return devolver;

}
