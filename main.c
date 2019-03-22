//prueba
#include <stdlib.h>
#include <stdio.h>

#include "TAD/cola.h"
#include "TAD/pila.h"
#include "TAD/listas.h"

#define PLUS 0.5;


//enumeramos funciones
int comprobarNumeroProductos(TIPOELEMENTOCOLA n);
void imprimirPrimeroCola(TCOLA colaEspera);
//
void imprimirListaPluses(TLISTA *listaPluses);
//
int ComprobarValoresAReacudar(TIPOELEMENTOLISTA v);
TIPOELEMENTOLISTA totalPluses(TLISTA listaPluses);
void recaudarPluses(TLISTA *listaPluses, TIPOELEMENTOLISTA dineroARecaudar, TIPOELEMENTOLISTA *totalPlusesRecaudados);
//
void LiberarColaEspera(TCOLA *colaespera);
void LiberarListaPluses(TCOLA *listapluses);
//Punteros a lista y cola
//Variable global
TCOLA Q_;
TLISTA L_;

int main(int argc, char** argv) {
    //variables
    char opcion;
    float PlusesDisponibles = 0.0;
    int clientesAtendidos = 0, clientesEnEspera = 0;
    //Inicializamos la cola
    ColaVacia(&Q_);
    crea(&L_);

    //menu
    do {
        printf("\n--------------------\n");
        printf("\na) Anotarse a la cola");
        printf("\nb) Atender cliente");
        printf("\nc) Cobrar pluses");
        printf("\nd) Obtener estadisticas");
        printf("\ne) Salir");
        printf("\n--------------------\n");
        printf("\nOpcion: ");
        scanf(" %c", &opcion);
        switch (opcion) {
            case 'a':
                printf("Anotando en la cola\n");
                int n;
                printf("Introduce el numero de productos que lleva:");
                scanf(" %d", &n);
                if (comprobarNumeroProductos(n)) {
                    //Añadimos elemento a cola
                    AnadirCola(&Q_, n);
                    printf("Productos aniadidos a la cola\n");
                    imprimirPrimeroCola(Q_);
                    //solo contamos clientes en espera si lo añadimos a la cola
                    clientesEnEspera += 1;
                } else printf("El numero no es mayor que cero \n");
                
                
                break;

            case 'b':
                printf("Atendendiendo cliente\n");
                int m; //tipoelemento
                int aux;
                int respuesta;
                TIPOELEMENTOLISTA plus;
                respuesta = EsColaVacia(Q_);
                if (respuesta == 0) {
                    PrimeroCola(Q_, &m);
                    printf("El cliente a atender tiene %d productos para pasar\n", m);
                    plus = m * PLUS;
                    printf("pluses a anotar %.2f\n", plus);
                    inserta(&L_, fin(L_), plus);
                    printf("insertado\n");
                    imprimirListaPluses(L_);
                    EliminarCola(&Q_);
                    printf("Y ha sido atendido\n");
                    //aumentamos cliente atendidos y reducimos clientes en espera
                    clientesAtendidos +=1;
                    clientesEnEspera -=1;
                    respuesta = EsColaVacia(Q_);
                    if (respuesta == 0) {
                        PrimeroCola(Q_, &m);
                        printf("El proximo cliente tiene %d productos para pasar\n", m);
                    } else printf("hemos terminado la cola\n");


                } else printf("ahora mismo no hay clientes\n");
                //imprimimos clientes en espera y atendidos siempre que intentemos atender
                printf("Clientes atendidos %d\n",clientesAtendidos);
                printf("Clientes en espera %d\n",clientesEnEspera);
                break;

            case 'c':
                printf("Cobrando pluses\n");
                TIPOELEMENTOLISTA DineroARecaudar, acum;
                printf("dinero que quiere extraer:\n");
                scanf(" %d", &DineroARecaudar);
                if (ComprobarValoresAReacudar(DineroARecaudar)) {
                    acum = totalPluses(L_);
                    printf("pluses acumulados:%.2f",acum);
                } else printf("El numero no es mayor que cero \n");

                break;

            case 'd':
                printf("Obteniendo estadisticas\n");
                printf("el numero de clientes atendidos es: %f",clientesAtendidos);
                printf("el numero de clientes en espera es: %f",clientesEnEspera);
                printf("numero de pluses recuadados");
                printf("numero de pluses disponibles");
                break;

            case 'e':
                printf("librerando memoria");
                printf("desea salir del programa? -------> e(exit)/n(no)");
                scanf(" %c", &opcion);
                switch (opcion) {
                    case 'e':
                        printf("librerando memoria");
                        LiberarListaPluses(&L_);
                        LiberarColaEspera(&Q_);
                        break;
                    case 'n':
                        break;
                }      
                break;
            default: printf("Opcion incorrecta\n");
        }
    } while (opcion != 'e');
    return (EXIT_SUCCESS);

    exit(0);
}

int comprobarNumeroProductos(TIPOELEMENTOCOLA n) {
    if (n > 0) return 1;
    else return 0;
}

void imprimirPrimeroCola(TCOLA colaEspera) {
    int n;
    PrimeroCola(colaEspera, &n);
    printf("El primer cliente tiene %d productos para pasar\n", n);
}

void imprimirListaPluses(TLISTA *listaPluses) {
    int i;
    printf("imprimiendo lista de pluses\n");
    TNODOLISTA p = 0;
    TIPOELEMENTOLISTA SigElem;
    p = primero(L_);
    for (i = 0; i < longitud(listaPluses); i++) {
        recupera(L_, p, &SigElem);
        printf("los pluses son: %.2f\n", SigElem);
        p = siguiente(L_, p);
    }
}

int ComprobarValoresAReacudar(TIPOELEMENTOLISTA v) {
    if (v > 0) return 1;
    else return 0;
}

void recaudarPluses(TLISTA *listaPluses, TIPOELEMENTOLISTA dineroARecaudar, TIPOELEMENTOLISTA *totalPlusesRecaudados) {
    TIPOELEMENTOLISTA valor, valormin, total = 0, diferencia;
    int i, lon;
    TNODOLISTA tnodo, tnodomin;
    while (total < dineroARecaudar) {
        lon = longitud(*listaPluses);
        tnodo = primero(*listaPluses);
    }}


TIPOELEMENTOLISTA totalPluses(TLISTA listaPluses) {
    int i;
    TNODOLISTA s = 0;
    TIPOELEMENTOLISTA SigElem, acum = 0;
    
    s = primero(L_);
    for (i = 0; i < longitud(listaPluses); i++) {
        recupera(L_, s, &SigElem);
        s = siguiente(L_, s);
        acum += SigElem;
        
    }
    return acum;
}

void LiberarListaPluses(TLISTA *listapluses) {
    if (*listapluses = NULL) {
        destruye(listapluses);
        *listapluses = NULL;
    }
}

void LiberarColaEspera(TCOLA *colaespera) {
    if(*colaespera == NULL && !EsColaVacia(*colaespera)) {
        do{
            EliminarCola(colaespera);
        }while (!EsColaVacia (*colaespera));
    }
    
    free(*colaespera);
 *colaespera = NULL;
}
