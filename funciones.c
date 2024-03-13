#include "funciones.h"

/** \brief Elimina '\n' del string, sustituyendo por '\0'
 *
 * \param cadena char*
 * \return void
 *
 */
void quitar_saltos( char *cadena ) {
     char *p;
     p = strchr(cadena, '\n');
     if (p) *p = '\0';
}

/** \brief Lee una cadena desde stdin, antepone un título o descripción
 *
 * \param largo int
 * \param titulo char*
 * \return char*
 *
 */
char* leer_campo( int largo, char *titulo ) {
//  Seria incorrecto leer string mediante un puntero al que no se le ha reservado memoria
//  scanf toma una palabra como cadena y usa los espacios para separar variables.
     char *campo;
     campo = (char *) malloc( (largo+1)*sizeof(char) );
     printf("%s (%d):", titulo, largo);
     fgets(campo, largo+1, stdin);
     quitar_saltos( campo );
     fflush( stdin );
     return campo;
}

/** \brief
 *
 * \param titulo char*
 * \return int
 *
 */
int leer_numero( char *titulo ) {
     int num;
     printf("%s (integer):", titulo);
     scanf("%d", &num);
     fflush( stdin );
     return num;
}

/** \brief
 *
 * \return bool
 *
 */
bool mas() {
    char ret[] = "N";
    strcpy(ret ,leer_campo(1,"Más(S/...)"));
    return (strstr("Ss", ret) != 0);
}


/** \brief Cambia el color del texto en Windows.
 *
 * \param Background int
 * \param Text int
 * \return void
 *
 */
void Color(int Background, int Text){ // Función para cambiar el color del fondo y/o pantalla

	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.

	// Para cambiar el color, se utilizan números desde el 0 hasta el 255.
	// Pero, para convertir los colores a un valor adecuado, se realiza el siguiente cálculo.
	int    New_Color= Text + (Background * 16);

	SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola.
}

/******************** Control cursor *********************/

COORD GetCursorPosition() {
   HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
   GetConsoleScreenBufferInfo(h, &bufferInfo);
   return bufferInfo.dwCursorPosition;
}

void SetCursorPosition(int XPos, int YPos) {
   COORD coord;
   coord.X = XPos; coord.Y = YPos;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void gotoxy(int x,int y){ SetCursorPosition(x, y); }
void gotoxy_printf(int x,int y, char *txt){
    SetCursorPosition(x, y);
    printf("%s",txt);
}

/******************** Control pantalla *********************/

void pausa() {
    Color(BLACK, BLUE);
    printf("Pulse <ENTER> para continuar.");
    fflush( stdin );
    getchar();
    fflush( stdin );
    Color(BLACK, WHITE);
}

void limpiar_pantalla() {
    // printf("\033[2J\033[1;1H"); // Linux
    // system("CLEAR"); // Linux
    Color(BLACK, WHITE);
    system("CLS");// Windows
    Color(BLACK, WHITE);
}
