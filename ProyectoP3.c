/********************************************
    Nombre de Alumnos: Mario Ivan Jimenez Alfaro    #727740
                       Benjamin Gil Flores          #727211
                       Juan Enrique Cibrián Loera   #725290
                       Alejandro Sada Prendes       #725958
                       Carlos Manuel Alanis Peña    #732158
    Fecha: 11/12/2020
    Materia: Estructura de Datos
    Programa: Proyecto 3
    Descripcion: Control de trafico aéreo
********************************************/
#include <stdio.h>
#include <stdlib.h>

#include "AuxiliaryFunctions.h"
#include "SecondaryMenus.h"

typedef struct
{
    char flightCode[7];
    char airlineName[31];
    char planeModel[11];
    char origin[4];
    char destination[4];
    char state[31];
    struct node *next;
} M;

typedef node *pointer;
int size = 0;


void takeoffControls()
{
    printf("\n\tDo something");
}

void departureControls()
{
    printf("\n\tDo something");
}

void skywayControls()
{
    printf("\n\tDo something");
}

void approachingControls()
{
    printf("\n\tDo something");
}

void landingControls()
{
    printf("\n\tDo something");
}

void menu()
{
    int subOpc;
    M MiMs[50];

    do
    {
        printf("\n\t--------- Bienvenido al control de trafico a%creo ---------\n"
               "\n\t1 - Control de Despegues (GNDD)"
               "\n\t2 - Control de Salidas (DEP)"
               "\n\t3 - Control de Ruta A%crea (ACC)"
               "\n\t4 - Control de Aproximaci%cn (APP)"
               "\n\t5 - Control de Aterrizajes (GNDL)"
               "\n\t6 - Salir"
               "\n\n\tIntroduce una opci%cn: ", 130, 130, 162, 162);
        scanf("%i", &opc);
        verifyRange(&opc, 6, 1);

        system("cls");
        switch(opc)
        {
            case 1:
                do{
                     printf("\n\t------- Control de Despegues -------\n"
                            "\n\t1 - Agregar Vuelo"
                            "\n\t2 - Consultar Vuelo"
                            "\n\t3 - Despegar Vuelo"
                            "\n\t4 - Regresar"
                            "\n\n\tIntroduce una opci%cn: ", 162);
                            scanf("%d", &opc);

                            switch(opc)
                            {
                              case 1:
                                    registrar_trafico(MiMs, r);
                                    break;
                              case 2:
                                    busqueda_vuelo(MiMs, r);
                                    break;
                              case 3:

                                    break;
                             case 4:
                                   system("cls");
                                   break;
                            }
                            system("cls");
                 }while(opc!=4);
                //subOpc = takeoffMenu();
                //takeoffControls();
                break;
            case 2:
                subOpc = departureMenu();
                departureControls();
                break;
            case 3:
                subOpc = skywayMenu();
                skywayControls();
                break;
            case 4:
                do{
                    printf("\n\t------- Control de Aproximaci%cn -------\n"
                           "\n\t1 - Consultar Vuelo"
                           "\n\t2 - Aterrizar Vuelo"
                           "\n\t3 - Regresar"
                           "\n\n\tIntroduce una opci%cn: ", 162, 162);
                      scanf("%d", &opc);

                      switch(opc)
                      {
                        case 1:
                            busqueda_vuelo(MiMs, r);
                            break;
                        case 2:
                            autorizacion_aterrizar();
                            break;
                        case 3:
                            system("cls");
                            break;
                      }
                  system("cls");
                }while(opc!=3);

                //subOpc = approachingMenu();
                //approachingControls();
                break;
            case 5:
                subOpc = landingMenu();
                landingControls();
                break;
            case 6:
                printf("\n\tTerminando el programa...");
                break;
        }

        pauseAndWipe();
    } while(opc != 6);
}

void main()
{
    menu();
}
