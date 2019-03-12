#include <stdlib.h>
#include <stdio.h>

#include "TAD\cola.h"
#include "TAD\pila.h"
#include "TAD\listas.h"


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
void anotando_en_cola(){
	int n;
	printf("Introduce el numero de productos que lleva:");
	scanf(" %d",&n);
	if(comprobarNumeroProductos(n)){
		//Añadimos elemento a cola
		AnadirCola(&Q_, n);
		printf("Productos aniadidos a la cola\n");
		imprimirPrimeroCola(Q_);
		}
	else printf("El numero no es mayor que cero \n");
	}
	
int comprobarNumeroProductos(TIPOELEMENTOCOLA n){
	if(n > 0) return 1;
	else return 0;
	}

void imprimirPrimeroCola(TCOLA colaEspera){
	int n;
	PrimeroCola(colaEspera, &n);
	printf("El primer cliente tiene %d productos para pasar\n",n);
	}

void atender_cliente(){
	int n;
	PrimeroCola(Q_, &n);	
	printf("El cliente a atender tiene %d productos para pasar\n",n);
	EliminarCola(&Q_);
	//Añadir pluses
	
	//
	printf("Y ha sido atendido\n");
	PrimeroCola(Q_, &n);	
	printf("El proximo cliente tiene %d productos para pasar\n",n);
	}
	
void
imprimirListaPluses(TLISTA listaPluses){
	
	}
