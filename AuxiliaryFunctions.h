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
void addFlight(GNDD *P)
{
    char flightCode[7];
    char airlineName[31];
    char planeModel[11];
    char origin[4];
    char destination[4];
    char state[31];

    printf("\n\t -------- Agregar Vuelo --------");
    fflush(stdin);

    printf("\n\tClave de vuelo (2 letras y 4 d%cgitos): ", 161);
    gets(flightCode);
    fflush(stdin);

    printf("\n\tNombre de la aerol%cnea: ", 161);
    gets(airlineName);
    fflush(stdin);

    printf("\n\tModelo de la aerol%cnea: ", 161);
    gets(planeModel);
    fflush(stdin);

    printf("\n\tOrigen (3 letras): ");
    gets(origin);
    fflush(stdin);

    printf("\n\tDestino (3 letras): ");
    gets(destination);

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

void searchTakeOff(GNDD P, char flightCode[])
{
    if(P != NULL)
    {
        int isFound = true;
        GNDD refTakeOff = P;
        while(strcmp(refTakeOff->flightCode, flightCode) != 0 && isFound)
        {
            if(refTakeOff->next != NULL)
                refTakeOff = refTakeOff->next;
            else
                isFound = false;
        }
        if(!isFound)
            printf("\n\tNo se encontro el vuelo\n\n");
        else
            printf("\n\tVuelo: %s | Transporte: %s | Equipamiento: %s | Origen: %s | Destino: %s | Estado: %s"
                , P->flightCode, P->airlineName, P->planeModel, P->origin, P->destination, P->state);
    }
    else
        printf("\n\tERROR: No hay vuelos registrados");

}

void printTakeOff(GNDD P)
{
    if(P != NULL)
    {
        printf("\n\t Clave: %s\tDestino: %s", P->flightCode, P->destination);
        printTakeOff(P->next);
    }
    printf("\n\n");
}

void flightTakeOff(GNDD *P, DEP *F)
{
    if(*P != NULL)
    {
        GNDD auxTakeOff = *P, temp = NULL;
        DEP auxDeparture = *F;

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
    system("pause");
    system("cls");
}

#endif
