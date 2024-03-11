#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

    /**< Colores para Windows
        (La letra "L" al inicio, indica que es un color más claro que su antecesor).
     */
    enum Colors { //
        BLACK = 0,
        BLUE = 1,
        GREEN = 2,
        CYAN = 3,
        RED = 4,
        MAGENTA = 5,
        BROWN = 6,
        LGREY = 7,
        DGREY = 8,
        LBLUE = 9,
        LGREEN = 10,
        LCYAN = 11,
        LRED = 12,
        LMAGENTA = 13,
        YELLOW = 14,
        WHITE = 15
    };

    /**< Colores para terminales Linux */
    #define ANSI_COLOR_RED     "\x1b[31m"
    #define ANSI_COLOR_GREEN   "\x1b[32m"
    #define ANSI_COLOR_YELLOW  "\x1b[33m"
    #define ANSI_COLOR_BLUE    "\x1b[34m"
    #define ANSI_COLOR_MAGENTA "\x1b[35m"
    #define ANSI_COLOR_CYAN    "\x1b[36m"
    #define ANSI_COLOR_RESET   "\x1b[0m"

    /**<  Prototipo de funciones */
    void quitar_saltos( char * );
    char* leer_campo( int, char * );
    int leer_numero( char * ); // añadido
    void Color(int Background, int Text);

#endif // FUNCIONES_H_INCLUDED
