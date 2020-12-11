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
#include <string.h>

static inline void clearBuffer() 
{ 
    char c = '0'; 
  
    while ((c = getchar()) != '\n' && c != EOF) { 
        // silence is golden
    } 
}

#include "AuxiliaryFunctions.h"
#include "SecondaryMenus.h"

GNDD takeOff = NULL;
DEP departure = NULL;
ACC skyway = NULL;
APP approaching = NULL;
GNDL landing = NULL;

void takeoffControls()
{
    int subOpc;

    do
    {
        printf("\n\t--------- Lista de Vuelos ---------\n");
        printTakeOff(takeOff);
        subOpc = takeoffMenu();
        switch(subOpc)
        {
            case 1:
                addFlight(&takeOff);
                break;
            case 2:
                searchTakeOff(takeOff);
                break;
            case 3:
                flightTakeOff(&takeOff, &departure);
                break;
            case 0:
                printf("\n\tVolviendo al men%c principal...", 163);
        }
        if(subOpc != 0)
            pauseAndWipe();
    } while(subOpc != 0);
}

void departureControls()
{
    int subOpc;

    do
    {
        printf("\n\t--------- Lista de Vuelos ---------\n");
        printDeparture(departure);
        subOpc = departureMenu();
        switch(subOpc)
        {
            case 1:
                searchDeparture(departure);
                break;
            case 2:
                flightToCenter(&departure, &skyway);
                break;
            case 3:
                flightEmergency(&departure, &approaching);
                break;
            case 0:
                printf("\n\tVolviendo al men%c principal...", 163);
        }
        if(subOpc != 0)
            pauseAndWipe();
    } while(subOpc != 0);
}

void skywayControls()
{
    printf("\n\tDo something");
}

void approachingControls()
{
    int subOpc;

    do
    {
        printf("\n\t--------- Lista de Vuelos ---------\n");
        printApproaching(approaching);
        subOpc = approachingMenu();
        switch(subOpc)
        {
            case 1:
                searchApproaching(approaching);
                break;
            case 2:
                flightApproaching(&approaching, &landing);
                break;
        }
        if(subOpc != 0)
            pauseAndWipe();
    } while(subOpc != 0);
}

void landingControls()
{
    int subOpc;

    do
    {
        printf("\n\t--------- Lista de Vuelos ---------\n");
        printLanding(landing);
        subOpc = landingMenu();
        switch(subOpc)
        {
            case 1:
                searchLanding(landing);
                break;
            case 2:
                flightLanding(&landing);
                break;
            case 3:
                flightToTakeOff(&landing, &takeOff);
                break;
            case 4:
                freeFlight(&landing);
                break;
            case 0:
                printf("\n\tVolviendo al men%c principal...", 163);
        }
        if(subOpc != 0)
            pauseAndWipe();
    } while(subOpc != 0);
}

void menu()
{
    int opc, subOpc;

    do
    {
        printf("\n\t--------- Bienvenido al control de trafico a%creo ---------\n"
               "\n\t1 - Control de Despegues (GNDD)"
               "\n\t2 - Control de Salidas (DEP)"
               "\n\t3 - Control de Ruta A%crea (ACC)"
               "\n\t4 - Control de Aproximaci%cn (APP)"
               "\n\t5 - Control de Aterrizajes (GNDL)"
               "\n\t0 - Salir"
               "\n\n\tIntroduce una opci%cn: ", 130, 130, 162, 162);
        scanf("%i", &opc);
        verifyRange(&opc, 5, 0);
        clear();
        switch(opc)
        {
            case 1:
                takeoffControls();
                break;
            case 2:
                departureControls();
                break;
            case 3:
                skywayControls();
                break;
            case 4:
                approachingControls();
                break;
            case 5:
                landingControls();
                break;
            case 0:
                printf("\n\tTerminando el programa...");
                break;
        }
        pauseAndWipe();
    } while(opc != 0);
}

void main()
{
    menu();
}
