#ifndef AUXILIARYFUNCTIONS_H_INCLUDED
#define AUXILIARYFUNCTIONS_H_INCLUDED

#define true 1
#define false 0

typedef struct
{
    char flightCode[7];
    char airlineName[31];
    char planeModel[11];
    char origin[4];
    char destination[4];
    char state[31];
    struct node *next;
} node;

typedef node *GNDD;
typedef node *DEP;
typedef node *ACC;
typedef node *APP;
typedef node *GNDL;

// -------- GNDD Functions -------- //
void printTakeOff(GNDD P)
{
    if(P != NULL)
    {
        printf("\n\t----------\n");
        printf("\tClave: %s\n\tDestino: %s\n", P->flightCode, P->destination);
        printf("\t----------\n\n");
        printTakeOff(P->next);
    }
}

void addFlight(GNDD *P)
{
    char flightCode[7];
    char airlineName[31];
    char planeModel[11];
    char origin[4];
    char destination[4];
    char state[31];

    printf("\n\t -------- Agregar Vuelo --------");
    clearBuffer();
    printf("\n\tClave de vuelo (2 letras y 4 d%cgitos): ", 161);
    fgets(flightCode, 7, stdin);

    clearBuffer();
    printf("\n\tNombre de la aerol%cnea: ", 161);
    fgets(airlineName, 31, stdin);

    clearBuffer();
    printf("\n\tModelo de la aerol%cnea: ", 161);
    fgets(planeModel, 11, stdin);

    clearBuffer();
    printf("\n\tOrigen (3 letras): ");
    fgets(origin, 4, stdin);

    clearBuffer();
    printf("\n\tDestino (3 letras): ");
    fgets(destination, 4, stdin);

    GNDD newNode = NULL;
    newNode = (node*) malloc(sizeof(node));

    strcpy(newNode->flightCode, flightCode);
    strcpy(newNode->airlineName, airlineName);
    strcpy(newNode->planeModel, planeModel);
    strcpy(newNode->origin, origin);
    strcpy(newNode->destination, destination);
    strcpy(newNode->state, "Por Despegar");
    newNode->next = *P;

    *P = newNode;
}

void searchTakeOff(GNDD P)
{
    if(P != NULL)
    {
        GNDD refTakeOff = NULL;
        int isFound = true;
        char flightCode[7];

        clearBuffer();
        printf("\n\tIntroduce la clave del vuelo a consultar: ");
        fgets(flightCode, 7, stdin);

        refTakeOff = P;
        while((strcmp(refTakeOff->flightCode, flightCode) != 0) && isFound)
        {
            if(refTakeOff->next != NULL)
                refTakeOff = refTakeOff->next;
            else
                isFound = false;
        }
        if(isFound) {
            printf("\n\t----------\n");
            printf("\tVuelo: %s \n\t Transporte: %s \n\t Equipamiento: %s \n\t Origen: %s \n\n\t Destino: %s \n\n\t Estado: %s\n",
                   refTakeOff->flightCode, refTakeOff->airlineName, refTakeOff->planeModel,
                   refTakeOff->origin, refTakeOff->destination, refTakeOff->state);
            printf("\t----------\n\n");
        } else {
            printf("\n\tERROR: No se encontro el vuelo");
        }
    } else
        printf("\n\tERROR: No hay vuelos registrados");
}

void flightTakeOff(GNDD *P, DEP *F)
{
    if(*P != NULL)
    {
        GNDD auxTakeOff = *P, temp = NULL;

        DEP newNode = NULL;
        newNode = (node*) malloc(sizeof(node));
        strcpy(newNode->flightCode, auxTakeOff->flightCode);
        strcpy(newNode->airlineName, auxTakeOff->airlineName);
        strcpy(newNode->planeModel, auxTakeOff->planeModel);
        strcpy(newNode->origin, auxTakeOff->origin);
        strcpy(newNode->destination, auxTakeOff->destination);
        strcpy(newNode->state, "En Ruta");
        newNode->next = *F;
        *F = newNode;

        *P = auxTakeOff->next;
        free(auxTakeOff);
        printf("\n\tEl vuelo despeg%c con %cxito", 162, 130);
    }
    else
        printf("\n\tERROR: No hay vuelos para despegar");
}

// -------- DEP Functions -------- //
void printDeparture(DEP P)
{
    if(P != NULL)
    {
        printf("\n\t----------\n");
        printf("\tClave: %s\n\tDestino: %s\n", P->flightCode, P->destination);
        printf("\t----------\n\n");
        printDeparture(P->next);
    }
}

void searchDeparture(DEP P)
{
    if(P != NULL)
    {
        DEP refDep = NULL;
        int isFound = true;
        char flightCode[7];

        clearBuffer();
        printf("\n\tIntroduce la clave del vuelo a consultar: ");
        fgets(flightCode, 7, stdin);

        refDep = P;
        while((strcmp(refDep->flightCode, flightCode) != 0) && isFound)
        {
            if(refDep->next != NULL)
                refDep = refDep->next;
            else
                isFound = false;
        }
        if(isFound) {
            printf("\n\t----------\n");
            printf("\tVuelo: %s \n\t Transporte: %s \n\t Equipamiento: %s \n\t Origen: %s \n\n\t Destino: %s \n\n\t Estado: %s\n",
                   refDep->flightCode, refDep->airlineName, refDep->planeModel,
                   refDep->origin, refDep->destination, refDep->state);
            printf("\t----------\n\n");
        } else {
            printf("\n\tERROR: No se encontro el vuelo");
        }
    } else
        printf("\n\tERROR: No hay vuelos registrados");
}

void flightToCenter(DEP *P, ACC *F)
{
    if(*P != NULL)
    {
        DEP auxDeparture = *P, temp = NULL;

        ACC newNode = NULL;
        newNode = (node*) malloc(sizeof(node));
        strcpy(newNode->flightCode, auxDeparture->flightCode);
        strcpy(newNode->airlineName, auxDeparture->airlineName);
        strcpy(newNode->planeModel, auxDeparture->planeModel);
        strcpy(newNode->origin, auxDeparture->origin);
        strcpy(newNode->destination, auxDeparture->destination);
        strcpy(newNode->state, "En Ruta");
        newNode->next = *F;
        *F = newNode;

        *P = auxDeparture->next;
        free(auxDeparture);
        printf("\n\tEl vuelo se movio al centro con %cxito", 130);
    }
    else
        printf("\n\tERROR: No hay vuelos para mover al centro");
}

void flightEmergency(DEP *P, APP *F)
{
    if(*P != NULL)
    {
        DEP auxDeparture = *P, temp = NULL;

        APP newNode = NULL;
        newNode = (node*) malloc(sizeof(node));
        strcpy(newNode->flightCode, auxDeparture->flightCode);
        strcpy(newNode->airlineName, auxDeparture->airlineName);
        strcpy(newNode->planeModel, auxDeparture->planeModel);
        strcpy(newNode->origin, auxDeparture->origin);
        strcpy(newNode->destination, auxDeparture->destination);
        strcpy(newNode->state, "Emergencia");
        newNode->next = *F;
        *F = newNode;

        *P = auxDeparture->next;
        free(auxDeparture);
        printf("\n\tEl vuelo se movio a emergencias con %cxito", 130);
    }
    else
        printf("\n\tERROR: No hay vuelos para indicar emergencia");
}

// -------- APP Functions -------- //
void printApproaching(APP P)
{
    if(P != NULL)
    {
        printf("\n\t Clave: %s\tOrigen: %s", P->flightCode, P->destination);
        printTakeOff(P->next);
    }
    printf("\n");
}

void searchApproaching(APP P)
{
    if(P != NULL)
    {
        APP refApproaching = NULL;
        int isFound = true;
        char flightCode[7];

        clearBuffer();
        printf("\n\tIntroduce la clave del vuelo a consultar: ");
        fgets(flightCode, 7, stdin);

        refApproaching = P;
        while((strcmp(refApproaching->flightCode, flightCode) != 0) && isFound)
        {
            if(refApproaching->next != NULL)
                refApproaching = refApproaching->next;
            else
                isFound = false;
        }
        if(isFound)
            printf("\tVuelo: %s \n\t Transporte: %s \n\t Equipamiento: %s \n\t Origen: %s \n\n\t Destino: %s \n\n\t Estado: %s\n",
                   refApproaching->flightCode, refApproaching->airlineName, refApproaching->planeModel,
                   refApproaching->origin, refApproaching->destination, refApproaching->state);
        else
            printf("\n\tERROR: No se encontro el vuelo");
    } else
        printf("\n\tERROR: No hay vuelos registrados");
}

void flightApproaching(APP *P, GNDL *F)
{
    if(*P != NULL)
    {
        APP auxApproaching = *P, temp = NULL;

        GNDL newNode = NULL;
        newNode = (node*) malloc(sizeof(node));
        strcpy(newNode->flightCode, auxApproaching->flightCode);
        strcpy(newNode->airlineName, auxApproaching->airlineName);
        strcpy(newNode->planeModel, auxApproaching->planeModel);
        strcpy(newNode->origin, auxApproaching->origin);
        strcpy(newNode->destination, auxApproaching->destination);
        strcpy(newNode->state, "Aterrizando");
        newNode->next = *F;
        *F = newNode;

        *P = auxApproaching->next;
        free(auxApproaching);
        printf("\n\tEl vuelo esta aterrizando con %cxito", 130);
    }
    else
        printf("\n\tERROR: No hay vuelos para despegar");
}
// -------- GNDL Functions -------- //

void printLanding(GNDL P)
{
    if(P != NULL)
    {
        printf("\n\t Clave: %s\tOrigen: %s\tDestino: %s\tEstatus: %s", P->flightCode, P->origin, P->destination, P->state);
        printLanding(P->next);
    }
    printf("\n");
}

void searchLanding(GNDL P)
{
    if(P != NULL)
    {
        GNDL refLanding = NULL;
        int isFound = true;
        char flightCode[7];

        clearBuffer();
        printf("\n\tIntroduce la clave del vuelo en terminal: ");
        gets(flightCode);

        refLanding = P;
        while((strcmp(refLanding->flightCode, flightCode) != 0) && isFound)
        {
            if(refLanding->next != NULL)
                refLanding = refLanding->next;
            else
                isFound = false;
        }
        if(isFound)
            printf("\tVuelo: %s \n\t Transporte: %s \n\t Equipamiento: %s \n\t Origen: %s \n\n\t Destino: %s \n\n\t Estado: %s\n",
                   refLanding->flightCode, refLanding->airlineName, refLanding->planeModel,
                   refLanding->origin, refLanding->destination, refLanding->state);
        else
            printf("\n\tERROR: No se encontro el vuelo");
    } else
        printf("\n\tERROR: No hay vuelos registrados");

}

void flightLanding(GNDL *P)
{
    if(*P != NULL)
    {
        GNDL refLanding = NULL;
        int isFound = true;
        char flightCode[7];

        clearBuffer();
        printf("\n\tIntroduce la clave del vuelo por aterrizar: ");
        gets(flightCode);

        refLanding = *P;
        while((strcmp(refLanding->flightCode, flightCode) != 0) && isFound)
        {
            if(refLanding->next != NULL)
                refLanding = refLanding->next;
            else
                isFound = false;
        }
        if(isFound)
        {
            printf("\n\t Vuelo: %s", refLanding->flightCode);
            strcpy(refLanding->state, "Aterrizo");
            printf("\n\tAterrizando...");
            pauseAndWipe();
            printf("\n\tEl vuelo %s ha aterrizado con %cxito", refLanding->flightCode, 130);
        }else
            printf("\n\tERROR: No se encontro el vuelo");
    } else
        printf("\n\tERROR: No hay vuelos registrados");

}
void flightToTakeOff(GNDL *P, GNDD *F)
{
    if(*P != NULL)
    {
        GNDL auxTakeOff = *P, temp = NULL;

        GNDD newNode = NULL;
        newNode = (node*) malloc(sizeof(node));
        strcpy(newNode->flightCode, auxTakeOff->flightCode);
        strcpy(newNode->airlineName, auxTakeOff->airlineName);
        strcpy(newNode->planeModel, auxTakeOff->planeModel);
        strcpy(newNode->origin, auxTakeOff->origin);
        strcpy(newNode->destination, auxTakeOff->destination);
        strcpy(newNode->state, "Por Despegar");
        newNode->next = *F;
        *F = newNode;

        *P = auxTakeOff->next;
        free(auxTakeOff);
        printf("\n\tEl vuelo se mueve a control de despegues");
    }
    else
        printf("\n\tERROR: No hay vuelos para despegar");
}

void freeFlight(GNDL *P)
{
    if(*P != NULL)
    {
        GNDL auxLanding = *P;

        *P = auxLanding->next;
        free(auxLanding);
        printf("\n\tEl vuelo esta en mantenimiento");
    } else
        printf("\n\tERROR: No hay vuelos registrados");
}

// -------- ACC Functions -------- //
void printSkyway(ACC P)
{
    if(P != NULL)
    {
        printf("\n\t----------\n");
        printf("\tClave: %s\n\tDestino: %s\n", P->flightCode, P->destination);
        printf("\t----------\n\n");
        printSkyway(P->next);
    }
}

void addFlightSkyway(ACC *P)
{
    char flightCode[7];
    char airlineName[31];
    char planeModel[11];
    char origin[4];
    char destination[4];
    char state[31];

    printf("\n\t -------- Agregar Vuelo --------");
    clearBuffer();
    printf("\n\tClave de vuelo (2 letras y 4 d%cgitos): ", 161);
    fgets(flightCode, 7, stdin);

    clearBuffer();
    printf("\n\tNombre de la aerol%cnea: ", 161);
    fgets(airlineName, 31, stdin);

    clearBuffer();
    printf("\n\tModelo de la aerol%cnea: ", 161);
    fgets(planeModel, 11, stdin);

    clearBuffer();
    printf("\n\tOrigen (3 letras): ");
    fgets(origin, 4, stdin);

    clearBuffer();
    printf("\n\tDestino (3 letras): ");
    fgets(destination, 4, stdin);

    ACC newNode = NULL;
    newNode = (node*) malloc(sizeof(node));

    strcpy(newNode->flightCode, flightCode);
    strcpy(newNode->airlineName, airlineName);
    strcpy(newNode->planeModel, planeModel);
    strcpy(newNode->origin, origin);
    strcpy(newNode->destination, destination);
    strcpy(newNode->state, "En Ruta");
    newNode->next = *P;

    *P = newNode;
}

void searchSkyway(ACC P)
{
    if(P != NULL)
    {
        ACC refSkyway = NULL;
        int isFound = true;
        char flightCode[7];

        clearBuffer();
        printf("\n\tIntroduce la clave del vuelo en terminal: ");
        gets(flightCode);

        refSkyway = P;
        while((strcmp(refSkyway->flightCode, flightCode) != 0) && isFound)
        {
            if(refSkyway->next != NULL)
                refSkyway = refSkyway->next;
            else
                isFound = false;
        }
        if(isFound)
            printf("\tVuelo: %s \n\t Transporte: %s \n\t Equipamiento: %s \n\t Origen: %s \n\n\t Destino: %s \n\n\t Estado: %s\n",
                   refSkyway->flightCode, refSkyway->airlineName, refSkyway->planeModel,
                   refSkyway->origin, refSkyway->destination, refSkyway->state);
        else
            printf("\n\tERROR: No se encontro el vuelo");
    } else
        printf("\n\tERROR: No hay vuelos registrados");
}

void flightSkyway(ACC *P, APP *F)
{
    if(*P != NULL)
    {
        ACC auxTakeOff = *P, temp = NULL;
        APP auxDeparture = *F;

        APP newNode = NULL;
        newNode = (node*) malloc(sizeof(node));
        strcpy(newNode->flightCode, auxTakeOff->flightCode);
        strcpy(newNode->airlineName, auxTakeOff->airlineName);
        strcpy(newNode->planeModel, auxTakeOff->planeModel);
        strcpy(newNode->origin, auxTakeOff->origin);
        strcpy(newNode->destination, auxTakeOff->destination);
        strcpy(newNode->state, "Por Aterrizar");
        newNode->next = *F;
        *F = newNode;

        if (auxTakeOff->next == NULL)
            *P = NULL;
        else
        {
            while(auxTakeOff->next != NULL)
            {
                temp = auxTakeOff;
                auxTakeOff = auxTakeOff->next;
            }
            temp->next = NULL;
        }
        free(auxTakeOff);
        printf("\n\tEl vuelo esta por aterrizar con %cxito", 130);
    }
    else
        printf("\n\tERROR: No hay vuelos para despegar");
}

// -------- Auxiliary Functions -------- //

void verifyRange(int *value, int max, int min)
{
    if(*value > max || *value < min)
    {
        do {
            printf("\tN%cmero no es valido, intente de nuevo: ", 163);
            scanf("%i", &*value);
        } while(*value > max || *value < min);
    }
}

void pauseAndWipe()
{
    printf("\n\n");

    #if __unix__
        printf("Pulse [Enter] para continuar");
        getchar();
        getchar();
        system("clear");
    #else
        system("pause");
        system("cls");
    #endif
}

void clear()
{
    #if __unix__
        system("clear");
    #else
        system("cls");
    #endif
} 

#endif
