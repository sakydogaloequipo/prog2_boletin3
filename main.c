#include <stdlib.h>
#include <stdio.h>

#include "TAD\cola.h"
#include "TAD\pila.h"
#include "TAD\listas.h"

int main(int argc, char** argv) {
	//variables
	char opcion;
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
                break;
            case 'b':
				printf("Atendendiendo cliente\n");
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
