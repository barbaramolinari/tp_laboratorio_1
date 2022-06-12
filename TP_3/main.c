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

    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    	Passenger_MenuPrincipal();
    	utn_getNumero(&option, "\nIngrese un numero de operacion: ", "\nOpcion incorrecta. reingrese: ", 1, 10, 3);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv", listaPasajeros);
                break;

            case 2:
            	controller_loadFromBinary("data.bin", listaPasajeros);
                break;

            case 3:
            	controller_addPassenger(listaPasajeros);
                break;

            case 4:
            	controller_editPassenger(listaPasajeros);
                break;

            case 5:
            	controller_removePassenger(listaPasajeros);
                break;

            case 6:
            	controller_ListPassenger(listaPasajeros);
                break;

            case 7:
            	controller_sortPassenger(listaPasajeros);
                break;

            case 8:
            	controller_saveAsText("data.csv", listaPasajeros);
                break;

            case 9:
            	controller_saveAsBinary("data.bin", listaPasajeros);
                break;

            case 10:
            	printf("�Hasta Luego! \n");
                break;
        }

    }while(option != 10);
    return 0;
}

