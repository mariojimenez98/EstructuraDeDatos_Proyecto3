#ifndef SECONDARYMENUS_H_INCLUDED
#define SECONDARYMENUS_H_INCLUDED

#include "AuxiliaryFunctions.h"

int takeoffMenu()
{
    int opc;

    printf("\n\t------- Control de Despegues -------\n"
           "\n\t1 - Agregar Vuelo"
           "\n\t2 - Consultar Vuelo"
           "\n\t3 - Despegar Vuelo"
           "\n\n\tIntroduce una opci%cn: ", 162);
    scanf("%i", &opc);
    verifyRange(&opc, 3, 1);
    return opc;
}

int departureMenu()
{
    int opc;

    printf("\n\t------- Control de Salidas -------\n"
           "\n\t1 - Consultar Vuelo"
           "\n\t2 - Pasar Vuelo a Centro"
           "\n\t3 - Regreso de Emergencia"
           "\n\n\tIntroduce una opci%cn: ", 162);
    scanf("%i", &opc);
    verifyRange(&opc, 3, 1);
    return opc;
}

int skywayMenu()
{
    int opc;

    printf("\n\t------- Control de Ruta A%crea -------\n"
           "\n\t1 - Agregar Vuelo"
           "\n\t2 - Consultar Vuelo"
           "\n\t3 - Pasar Vuelo a Aproximaci%cn"
           "\n\n\tIntroduce una opci%cn: ", 130, 162, 162);
    scanf("%i", &opc);
    verifyRange(&opc, 3, 1);
    return opc;
}

int approachingMenu()
{
    int opc;
    printf("\n\t------- Control de Aproximaci%cn -------\n"
           "\n\t1 - Consultar Vuelo"
           "\n\t2 - Aterrizar Vuelo"
           "\n\n\tIntroduce una opci%cn: ", 162, 162);
    scanf("%i", &opc);
    verifyRange(&opc, 2, 1);
    return opc;
}

int landingMenu()
{
    int opc;
    printf("\n\t------- Control de Aterrizajes -------\n"
           "\n\t1 - Consultar Vuelo"
           "\n\t2 - En Terminal"
           "\n\t3 - Por Despegar"
           "\n\t4 - Eliminar"
           "\n\n\tIntroduce una opci%cn: ", 162);
    scanf("%i", &opc);
    verifyRange(&opc, 4, 1);
    return opc;
}

#endif
