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

typedef node *pointer;

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

        fflush(stdin);
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
            printf("\n\tVuelo: %s | Transporte: %s | Equipamiento: %s | Origen: %s | Destino: %s | Estado: %s",
                   refLanding->flightCode, refLanding->airlineName, refLanding->planeModel,
                   refLanding->origin, refLanding->destination, refLanding->state);
        else
            printf("\n\tERROR: No se encontro el vuelo");
    } else
        printf("\n\tERROR: No hay vuelos registrados");

}
void flightLanding(GNDL P)
{

    if(P != NULL)
    {
        GNDL refLanding = NULL;
        int isFound = true;
        char flightCode[7];

        fflush(stdin);
        printf("\n\tIntroduce la clave del vuelo por aterrizar: ");
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
        {
            printf("\n\t Vuelo: %s", P->flightCode);
            strcpy(refLanding->state, "Aterrizo");
            printf("\n\tAterrizando...");
            pauseAndWipe();
            printf("\n\tEl vuelo %s ha aterrizado con %cxito", P->flightCode, 130);
        }else
            printf("\n\tERROR: No se encontro el vuelo");
    } else
        printf("\n\tERROR: No hay vuelos registrados");

}
void flightToTakeOff(GNDL *P, GNDD *F)
{
    if(P != NULL)
    {
        GNDL refLanding = NULL, auxTakeOff = *P, temp = NULL;
        GNDD auxLanding = *F;
        int isFound = true;
        char flightCode[7];

        fflush(stdin);
        printf("\n\tIntroduce la clave del vuelo por despegar: ");
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
        {
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
            printf("\n\tEl vuelo ahora esta listo para partir");
        }else
                printf("\n\tERROR: No se encontro el vuelo");
    } else
        printf("\n\tERROR: No hay vuelos registrados");
}

void freeFlight(GNDL *P)
{
    if(P != NULL)
    {
        GNDL refLanding = NULL, auxTakeOff = *P, temp = NULL;
        int isFound = true;
        char flightCode[7];

        fflush(stdin);
        printf("\n\tIntroduce la clave del vuelo por eliminar: ");
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
        {
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
            printf("\n\tEl vuelo a salido de la terminal");
        }else
                printf("\n\tERROR: No se encontro el vuelo");
    } else
        printf("\n\tERROR: No hay vuelos registrados");
}

void insertHead(pointer *P, int num)
{
    pointer newNode = NULL;

    /*newNode = (node*) malloc(sizeof(node));

    newNode->num = num;
    newNode->sig = *P;

    *P = newNode;*/
}

void insertTail(pointer *P, int num)
{
    pointer newNode = NULL, aux = NULL;

    /*aux = *P;

    while(aux->sig != NULL)
        aux = aux->sig;

    newNode = (nodo*) malloc(sizeof(nodo));

    newNode->num = num;
    newNode->sig = NULL;

    aux->sig = newNode;*/
}

void removeHead(pointer *P)
{

    pointer ref = NULL;
/*
    ref = *P;

    *P = ref->sig;
    free(ref);*/
}

void removeTail(pointer *P)
{
    pointer ant = NULL, ref = NULL;
    /*ref = *P;

    if (ref->sig == NULL)
        *P = NULL;
    else {
        while(ref->sig != NULL) {
            ant = ref;
            ref = ref->sig;
        }
        ant->sig = NULL;
    }
    free(ref);*/
}

void printRecursive(pointer P)
{
    if(P != NULL)
    {
        //printf("\n  Direccion = %d | Numero = %d | Siguiente = %d |", P, P->num, P->sig);
        recorreRecursivo(P->next);
    }
}

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
