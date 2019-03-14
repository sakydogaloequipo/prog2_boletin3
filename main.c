#include <stdlib.h>
#include <stdio.h>

#include "TAD\cola.h"
#include "TAD\pila.h"
#include "TAD\listas.h"

void LiberarListaPluses(TCOLA *listapluses) {
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
}
//enumeramos funciones
int comprobarNumeroProductos(TIPOELEMENTOCOLA n);
void imprimirPrimeroCola(TCOLA colaEspera);
//
void imprimirListaPluses(TLISTA listaPluses);
//
//funciones de menu
void anotando_en_cola();
void atender_cliente();
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
                anotando_en_cola();
                break;
            case 'b':
                printf("Atendendiendo cliente\n");
                atender_cliente();
                break;
            case 'c':
                printf("Cobrando pluses\n");
                break;
            case 'd':
                printf("Obteniendo estadisticas\n");
                break;
            case 'e':
                printf("Saliendo del programa\n");
                break;
            default: printf("Opcion incorrecta\n");
        }
    } while (opcion != 'e');
    return (EXIT_SUCCESS);

    //fin del programa
    exit(0);

}

void anotando_en_cola() {
    int n;
    printf("Introduce el numero de productos que lleva:");
    scanf(" %d", &n);
    if (comprobarNumeroProductos(n)) {
        //Añadimos elemento a cola
        AnadirCola(&Q_, n);
        printf("Productos aniadidos a la cola\n");
        imprimirPrimeroCola(Q_);
    } else printf("El numero no es mayor que cero \n");
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

void atender_cliente() {
    int n; //tipoelemento
    int aux;
    int respuesta;
    TNODOLISTA s = 0;
    //printf("%d\n--------",EsColaVacia(Q_));
    respuesta = EsColaVacia(Q_);
    if (respuesta == 0) {
        PrimeroCola(Q_, &n);
        printf("El cliente a atender tiene %d productos para pasar\n", n);
        printf("pluses a anotar %.2f\n", n * 0.5);
        inserta(L_, fin(L_), n * 0.5 );
        
        float valor;        
        recupera(L_,fin(L_) , &valor);

        printf("Plus insertado en la lista %.2f\n", valor );
        
        imprimirListaPluses(L_);
        
        EliminarCola(&Q_);
        printf("Y ha sido atendido\n");
        respuesta = EsColaVacia(Q_);
        if (respuesta == 0) {
            PrimeroCola(Q_, &n);
            printf("El proximo cliente tiene %d productos para pasar\n", n);
        }
        else printf("hemos terminado la cola");
        

    } else printf("ahora mismo no hay clientes\n");

    //Añadir pluses
    //ler o primeiro elemento da cola e *0.5 almaceno o resultado nunha variable que meto en lista
    /*PrimeroCola(Q_, &aux);
    aux += aux * 0.5;
    inserta(L_, s, aux);*/


}

void imprimirListaPluses(TLISTA listaPluses) {
    int i;
    printf("empezando\n");
    TNODOLISTA s = 0;
    TIPOELEMENTOLISTA siguiente_;
    
    s = primero(L_);
    
    for (i = 0; i < longitud(listaPluses); i++) {
        recupera(L_, s, &siguiente_);
        printf("los pluses son: %f", siguiente);
        s = siguiente(L_, s);

    }
}

int ComprobarValoresAReacudar(TIPOELEMENTOLISTA v) {
    do {
        printf("\n\nIntroduzca la cantidad a retirar: ");
        scanf("%f", v);
    } while (v <= 0);
}
