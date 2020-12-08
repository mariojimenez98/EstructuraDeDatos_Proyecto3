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
} M;

typedef node *pointer;

char clave_vuelo[7];
int a, r, k, i, traficos_almacenados, opc;
k=0;
traficos_almacenados=0;

void registrar_trafico(M Ms[], int r)
{
    do
      {
         printf("\n        Ingrese la cantidad de vuelos que se van a registrar: ");
         scanf("%d", &r);
      } while(r<0&&r>51);

    int a=k;
    for(i=k; i<a+r; i++)
    {
        k++;
        printf("\n\t ---------------");
        printf("\n\t     Vuelo %i", k);
        printf("\n\t ---------------");
        fflush(stdin);
        printf("\n    Clave Vuelo: ");
        gets(Ms[i].flightCode);
        fflush(stdin);
        printf("    Transporte: ");
        gets(Ms[i].airlineName);
        fflush(stdin);
        printf("    Equipamiento: ");
        gets(Ms[i].planeModel);
        fflush(stdin);
        printf ("    Origen: ");
        gets(Ms[i].origin);
        fflush(stdin);
        printf("    Destino: ");
        gets(Ms[i].destination);
        fflush(stdin);
        printf("    Estado: ");
        gets(Ms[i].state);
        fflush(stdin);

    }
     traficos_almacenados=traficos_almacenados+k;
     printf("\n\n");
     system("pause");
     system("cls");
}

void impresion_vuelos(M Ms[], int r)
{

     printf("\n  --------------------");
     printf("\n\t Vuelos");
     printf("\n  --------------------");

    for(i=0; i<k; i++)
    {
        printf("\n %c%d | Vuelo: %s | Transporte: %s | Equipamiento: %s | Origen: %s | Destino: %s | Estado: %s ", 35,
            i+1, Ms[i].flightCode, Ms[i].airlineName, Ms[i].planeModel, Ms[i].origin, Ms[i].destination, Ms[i].state);
    }

     printf("\n\n");
     system("pause");
     system("cls");
}


void busqueda_vuelo(M Ms[], int r)
{
    fflush(stdin);
    printf("\n Ingrese la clave de vuelo: ");
    gets(clave_vuelo);
    fflush(stdin);
    for(i=0; i<k; i++){
     if(strcmp(Ms[i].flightCode, clave_vuelo)){
     }else{
            printf("\n %c%d | Vuelo: %s | Transporte: %s | Equipamiento: %s | Origen: %s | Destino: %s | Estado: %s ", 35,
                i+1, Ms[i].flightCode, Ms[i].airlineName, Ms[i].planeModel, Ms[i].origin, Ms[i].destination, Ms[i].state);
          }
    }

    printf("\n\n");
    system("pause");
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
