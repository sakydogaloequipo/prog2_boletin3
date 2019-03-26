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
int ComprobarValorAReacudar(TIPOELEMENTOLISTA v);
TIPOELEMENTOLISTA totalPluses(TLISTA *listaPluses);
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
    TIPOELEMENTOCOLA clientesAtendidos = 0, clientesEnEspera = 0;
    TIPOELEMENTOLISTA acum = 0.0,PlusesDisponibles = 0.0;
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
                TIPOELEMENTOLISTA DineroARecaudar;
                
                printf("Lista de pluses actual:\n");
                imprimirListaPluses(L_);
                printf("Total de pluses acumulados %.2f\n",totalPluses(L_));
                printf("Indica la cantidad que quiere retirar:");
                scanf(" %f", &DineroARecaudar);
                
                if (ComprobarValorAReacudar(DineroARecaudar)) {
					//
					if(totalPluses(L_)>=DineroARecaudar){
						printf("Recaudamos\n");
						recaudarPluses(L_,DineroARecaudar,&acum);
						}
					else printf("No se puede recaudar %.2f, solo hay %.2f\n", DineroARecaudar,totalPluses(L_));
                } else printf("El numero no es mayor que cero \n");


                break;

            case 'd':
                printf("Obteniendo estadisticas\n");
                printf("el numero de clientes atendidos es: %d\n",clientesAtendidos);
                printf("el numero de clientes en espera es: %d\n",clientesEnEspera);
                printf("numero de pluses recuadados hasta ahora %.2f\n", acum);
                printf("numero de pluses disponibles %.2f\n",totalPluses(L_));
                break;

            case 'e':
                printf("desea salir del programa? -------> e(exit)/n(no)");
                scanf(" %c", &opcion);
                switch (opcion) {
                    case 'e':
                        printf("librerando memoria\n");
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


int ComprobarValorAReacudar(TIPOELEMENTOLISTA v) {
    if (v > 0) return 1;
    else return 0;
}

TNODOLISTA minimo_lista(TLISTA *listaPluses){
    int i;
    TNODOLISTA s = 0;
    TIPOELEMENTOLISTA SigElem,minimo;
    TNODOLISTA MINIMO_;
    printf("buscando minimo\n");
    
    s = primero(listaPluses);
    recupera(listaPluses, s, &SigElem);
    //minimo inicial
    minimo = SigElem;
    MINIMO_ = s;
    for (i = 0; i < longitud(listaPluses); i++) {
        recupera(listaPluses, s, &SigElem);
        printf("->%.2f\n",SigElem);
        if (minimo > SigElem){
			//si encontramos uno mas pequenio guardamos puntero para devolver
			//y valor para visualizar
			MINIMO_ = s;
			minimo = SigElem;
			}
        s = siguiente(listaPluses, s);
    }
    printf("el mas pequenio.... %.2f\n",minimo);
    return MINIMO_;
	}


void recaudarPluses(TLISTA *listaPluses, TIPOELEMENTOLISTA dineroARecaudar, TIPOELEMENTOLISTA *totalPlusesRecaudados) {
    TIPOELEMENTOLISTA valor, valormin, total = 0, diferencia;
    int i, lon;
    TNODOLISTA tnodo, tnodomin;
    TIPOELEMENTOLISTA elmaspequenio, dineroRecaudado;
    dineroRecaudado = 0.0;
    imprimirListaPluses(listaPluses);
    printf("A recaudar: %.2f lo recaudado %.2f\n",dineroARecaudar,dineroRecaudado );
    i = 0;
    do{
		//buscamos el más pequeño
		i++;
		tnodomin = minimo_lista(listaPluses);	
		recupera(listaPluses,tnodomin,&elmaspequenio);	
		printf("(%d) Valor mas pequenio %.2f\n",i,elmaspequenio);
		if (elmaspequenio <= dineroARecaudar){
			dineroRecaudado += elmaspequenio;
			dineroARecaudar -= elmaspequenio;
			suprime(&listaPluses,tnodomin);
			//quitamos
			} else {
				//descontamos
				//modifica el valor del plus
				modifica(listaPluses, tnodomin, elmaspequenio-dineroARecaudar);
				dineroRecaudado += dineroARecaudar;
				dineroARecaudar -= dineroARecaudar;
				
				}
		imprimirListaPluses(L_);

        printf("A recaudar: %.2f lo recaudado %.2f\n",dineroARecaudar,dineroRecaudado );
		} while(dineroARecaudar!=0.0);
		
		printf("Hemos recaudado %.2f\n", dineroRecaudado );
		//Acumulamos pluses recaudados en contador
		*totalPlusesRecaudados += dineroRecaudado;
        printf("Lista de pluses queda de la siguiente forma:\n");
        imprimirListaPluses(L_);
        printf("Con un total de pluses pendiente de recaudar %.2f\n",totalPluses(L_));   

    }

TIPOELEMENTOLISTA totalPluses(TLISTA *listaPluses) {
    int i;
    TNODOLISTA s = 0;
    TIPOELEMENTOLISTA SigElem, acum = 0;
    s = primero(listaPluses);
    for (i = 0; i < longitud(listaPluses); i++) {
        recupera(listaPluses, s, &SigElem);
        s = siguiente(listaPluses, s);
        acum += SigElem;
    }
    return acum;
}

void imprimirListaPluses(TLISTA *listaPluses) {
    int i;
    printf("imprimiendo lista de pluses\n");
    TNODOLISTA p = 0;
    TIPOELEMENTOLISTA SigElem;
    p = primero(listaPluses);
    for (i = 0; i < longitud(listaPluses); i++) {
        recupera(listaPluses, p, &SigElem);
        printf("los pluses son: %.2f\n", SigElem);
        p = siguiente(listaPluses, p);
    }
}

void LiberarListaPluses(TLISTA *listapluses) {
    if (*listapluses != NULL) {
        destruye(listapluses);
        *listapluses = NULL;
    }
}

void LiberarColaEspera(TCOLA *colaespera) {
    if(*colaespera != NULL && !EsColaVacia(*colaespera)) {
        do{
            EliminarCola(colaespera);
        }while (!EsColaVacia (*colaespera));
    }
    
    free(*colaespera);
	*colaespera = NULL;
}
