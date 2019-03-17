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
//Punteros a lista y cola
//Variable global
TCOLA Q_;
TLISTA L_;

int main(int argc, char** argv) {
    //variables
    char opcion;
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
                    plus = m * PLUS
                            printf("pluses a anotar %.2f\n", plus);
                    inserta(&L_, fin(L_), plus);
                    printf("insertado\n");

                    imprimirListaPluses(L_);

                    EliminarCola(&Q_);
                    printf("Y ha sido atendido\n");
                    respuesta = EsColaVacia(Q_);
                    if (respuesta == 0) {
                        PrimeroCola(Q_, &m);
                        printf("El proximo cliente tiene %d productos para pasar\n", m);
                    } else printf("hemos terminado la cola");


                } else printf("ahora mismo no hay clientes\n");


                break;

            case 'c':
                printf("Cobrando pluses\n");
                TIPOELEMENTOLISTA DineroARecaudar, acum;
                
                printf("dinero que quiere extraer:\n");
                scanf(" %d", &DineroARecaudar);
                if (ComprobarValoresAReacudar(DineroARecaudar)) {
                    totalPluses(L_);
                    acum = totalPluses(L_);
                    printf("pluses acumulados:%.2f",acum);
                    
                            
                } else printf("El numero no es mayor que cero \n");

                break;

            case 'd':
                printf("Obteniendo estadisticas\n");
                
                break;

            case 'e':
                printf("librerando memoria");
                break;
            default: printf("Opcion incorrecta\n");
        }
    } while (opcion != 'e');
    return (EXIT_SUCCESS);

    //fin del programa
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
    printf("imprimiendo\n");
    TNODOLISTA s = 0;
    TIPOELEMENTOLISTA siguiente_;

    s = primero(L_);
    for (i = 0; i < longitud(listaPluses); i++) {
        recupera(L_, s, &siguiente_);
        printf("los pluses son: %.2f\n", siguiente_);
        s = siguiente(L_, s);

    }
}

int ComprobarValoresAReacudar(TIPOELEMENTOLISTA v) {
    if (v > 0) return 1;
    else return 0;
}

void recaudarPluses(TLISTA*listaPluses, TIPOELEMENTOLISTA dineroARecaudar) {
}

TIPOELEMENTOLISTA totalPluses(TLISTA listaPluses) {
    int i;
    printf("acumulando\n");
    TNODOLISTA s = 0;
    TIPOELEMENTOLISTA siguiente_, acum = 0;

    s = primero(L_);
    for (i = 0; i < longitud(listaPluses); i++) {
        recupera(L_, s, &siguiente_);
        s = siguiente(L_, s);
        acum += siguiente_;
    }
    return acum;
}

/*void LiberarListaPluses(TCOLA *listapluses) {
    if (listapluses = NULL) {
        destruye(*listapluses);
        listapluses = NULL;
    }
}

void LiberarColaEspera(TCOLA *colaespera) {
    if (colaespera = NULL && !EsColaVacia(colaespera)) {
        EliminarCola(colaespera);
    }
    free(*colaespera);
 *colaespera = NULL;
}*/
