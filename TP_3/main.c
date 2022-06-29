#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option = 0;
    int flagCarga = 0;
    int flagCargaUnitaria = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();

    do{
    	Passenger_MenuPrincipal();
    	utn_getNumero(&option, "\nIngrese un numero de operacion: ", "\nOpcion incorrecta. reingrese por favor. ", 1, 10, 3);
        switch(option)
        {
            case 1:
                if (flagCarga == 0) {
                	controller_loadFromText("data.csv", listaPasajeros);
                	flagCarga = 1;
                } else {
                	printf("La lista ya ha sido cargada previamente. \n");
                }
                break;

            case 2:
                if (flagCarga == 0) {
                	controller_loadFromBinary("data.bin", listaPasajeros);
                	flagCarga = 1;
                } else {
                	printf("La lista ya ha sido cargada previamente. \n");
                }
                break;

            case 3:
            	controller_addPassenger(listaPasajeros);
            	flagCargaUnitaria = 1;
                break;

            case 4:
            	if (flagCarga == 1 || flagCargaUnitaria == 1) {
            		controller_editPassenger(listaPasajeros);
            	} else {
            		printf("Primero debe cargar un pasajero para modificarlo. \n");
            	}

                break;

            case 5:
            	if (flagCarga == 1 || flagCargaUnitaria == 1) {
            	controller_removePassenger(listaPasajeros);
            	} else {
            		printf("Primero debe cargar un pasajero para eliminarlo. \n");
            	}
                break;

            case 6:
            	if (flagCarga == 1 || flagCargaUnitaria == 1) {
            	controller_ListPassenger(listaPasajeros);
            	} else {
            		printf("Primero debe cargar un pasajero para visualizarlo. \n");
            	}
                break;

            case 7:
            	if (flagCarga == 1 || flagCargaUnitaria == 1) {
            	controller_sortPassenger(listaPasajeros);
            	} else {
            		printf("Primero debe cargar pasajeros para ordenarlos. \n");
            	}
                break;

            case 8:
            	controller_saveAsText("data.csv", listaPasajeros);
                break;

            case 9:
            	controller_saveAsBinary("data.bin", listaPasajeros);
                break;

            case 10:
            	ll_deleteLinkedList(listaPasajeros);
            	printf("¡Hasta Luego! \n");
                break;
        }

    }while(option != 10);
    return 0;
}

