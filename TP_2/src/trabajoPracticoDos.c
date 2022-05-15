/*
 ============================================================================
 Name        : trabajopractico2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 param order int [1] indicate UP - [0] indicate DOWN
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "arrayPassenger.h"
#include "utn_miBiblioteca.h"
#define LEN_PASSENGERS 2000
#define ACTIVO 10 //VUELOS
#define DEMORADO 11
#define SUSPENDIDO 12
#define FIRSTCLASS 20 //pasajeros
#define BUSINESS 21
#define ECONOMY 22

int main(void) {
	setbuf (stdout,NULL);
	char seguir = 's';
	int opcion = 0;


    Passenger list[LEN_PASSENGERS];
    char auxName[51];
	char auxLastName[51];
	float auxPrice = 0;
	char auxFlycode[10];
	int auxTypePassenger;
	int auxStatusFlight;
	int opcionSubMenu = 0;
	char seguirSubMenu ='s';
	int idSubMenu;
	int auxId = 0;
	float precioTotal;
	float precioPromedio = 0;
	int cantidadPasajeros;

    if(!initPassengers(list, LEN_PASSENGERS)){

    	do {
    		printf("Ingrese un numero de operacion\n");
    		printf("1- Alta de pasajero: \n");
    		printf("2- Modificacion de pasajero: \n");
    		printf("3- Baja de pasajero:\n");
    		printf("4- Informar: \n");
    		printf("5- Carga forzada de datos: \n");
    		printf("6- Salir\n");

    		utn_getNumero(&opcion, "Ingrese un numero de operacion: ", "Opcion incorrecta. reingrese. \n: ", 1, 6, 3);


    		switch(opcion){
				case 1:

					if (
						!utn_getNombre(auxName, 51, "Ingrese un nombre:", "Nombre incorrecto. Reingrese.", 2) &&
						!utn_getNombre(auxLastName, 51, "Ingrese un apellido:", "Nombre incorrecto. Reingrese.", 2) &&
						!utn_getNumeroFlotante(&auxPrice, "Ingrese el precio: ", "Precio incorrecto. Reingrese.", 100.0, 2000000.00, 3) &&
						!utn_getDescripcion(auxFlycode, 10, "Ingrese la codificación de reserva: ","datos ingresados incorrectamente. Reingrese.", 3) &&
						!utn_getNumero(&auxTypePassenger, "Ingrese tipo de pasajero (20- First Class 21-Business 22-Economy): ", "Tipo de pasajero erroneo. Reingrese.", 20, 22, 3) &&
						!utn_getNumero(&auxStatusFlight, "Ingrese estado de vuelo (10- Activo 11-Demorado 12-Suspendido): ", "Estado de vuelo erróneo. Reingrese.", 10, 12, 3))
					{

						int id = incrementarId();
						if(!addPassenger(list, LEN_PASSENGERS, id, auxName, auxLastName, auxPrice, auxTypePassenger, auxFlycode, auxStatusFlight)) {
							printf("Guardo correctamente \n");
						} else {
							printf("No se pudo guardar \n");
						}

					} else {
						printf("Los datos no han sido cargados correctamente. \n");
					}



					break;

				case 2:

					if (!isPassenger(list, LEN_PASSENGERS)) {


						if (!utn_getNumero(&idSubMenu, "Ingrese el id a modificar: ", "Opcion incorrecta. reingrese. \n ", 1000, 9999, 3)){

							int indice = findPassengerById(list, LEN_PASSENGERS, idSubMenu);

							if (indice != -1) {
								printHeader();
								printPassenger(list[indice]);

								do {
									printf("Ingrese el número de lo que desea modificar. \n");
									printf("1- Nombre \n");
									printf("2- Apellido: \n");
									printf("3- Precio:\n");
									printf("4- Tipo de pasajero (20- First Class 21-Business 22-Economy): \n");
									printf("5- Codigo de vuelo: \n");
									printf("6- Salir\n");

									utn_getNumero(&opcionSubMenu, "Ingrese un numero de operacion: ", "Opcion incorrecta. reingrese. \n ", 1, 6, 3);

									switch(opcionSubMenu) {

										case 1:
											if (!modificarNombre(list, indice)){
												printf("Operación realizada correctamente. \n");
											} else {
												printf("No se ha podido efectuar el cambio. Reintente. \n");
											}

											break;

										case 2:
											if (!modificarApellido(list, indice)){
												printf("Operación realizada correctamente.\n");
											} else {
												printf("No se ha podido efectuar el cambio. Reintente.\n");
											}

											break;

										case 3:
											if (!modificarPrecio(list, indice)){
												printf("Operación realizada correctamente.\n");
											} else {
												printf("No se ha podido efectuar el cambio. Reintente.\n");
											}
											break;

										case 4:
											if (!modificarTipoPasajero(list, indice)){
												printf("Operación realizada correctamente. \n");
											} else {
												printf("No se ha podido efectuar el cambio. Reintente. \n");
											}
											break;

										case 5:
											if (!modificarCodigoVuelo(list, indice)){
												printf("Operación realizada correctamente.\n");
											} else {
												printf("No se ha podido efectuar el cambio. Reintente. \n");
											}
											break;

										case 6:
											break;
									}


									printf("Desea seguir modificando? Ingrese s / n: \n");
									fflush(stdin);
									scanf("%c", &seguirSubMenu);
								} while(seguirSubMenu=='s');
							} else {
								printf("pasajero inexistente.\n");
								}
					} else {
						printf("Reintentos agotados.\n");
					}
				} else {
					printf("No existen pasajeros cargados.\n");
				}
					break;

				case 3:
					if (!isPassenger(list, LEN_PASSENGERS)) {

						if (!utn_getNumero(&auxId, "Ingrese el id a dar de baja: \n", "El ID ingresado no es correcto. Reintente por favor. \n", 1000, 9999, 3)) {
							if(!removePassenger(list, LEN_PASSENGERS, auxId)) {
								printf("Pasajero eliminado exitosamente.\n");
							} else {
								printf("No se pudo realizar la baja correctamente.\n");
							}
						} else {
							printf("pasajero inexistente.\n");
						}
					} else {
						printf("No existen pasajeros cargados.\n");
					}

					break;

				case 4:

					if (!isPassenger(list, LEN_PASSENGERS)) {


						do {
							printf("Ingrese el número de lo que desea informar. \n");
							printf("1- Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero. \n");
							printf("2- Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.  \n");
							printf("3- Listado de los pasajeros por Código de vuelo y estados de vuelos ACTIVO: \n");
							printf("4- Salir\n");

							utn_getNumero(&opcionSubMenu, "Ingrese un numero de operacion: ", "Opcion incorrecta. reingrese. \n ", 1, 6, 3);

							switch(opcionSubMenu) {

								case 1:

									if (!sortPassengersByName(list, LEN_PASSENGERS, 1)) {
										if (printPassengers(list, LEN_PASSENGERS)){
											printf("no se pudo imprimir la lista. \n");
										}
									} else {
										printf("no se pudo ordenar la lista. \n");
									}

									break;

								case 2:


									totalYPromedioVuelos(list, &precioTotal, &precioPromedio, LEN_PASSENGERS);
									cantidadSuperaPromedio(list, &cantidadPasajeros, precioPromedio, LEN_PASSENGERS);

									muestraTotalPromedioPrecioyPasajeros(precioTotal, precioPromedio, cantidadPasajeros);

									break;

								case 3:
									if (!sortPassengersByCode(list, LEN_PASSENGERS, 1)) {
										printHeader();
										for (int i = 0; i < LEN_PASSENGERS; i++) {
											if (list[i].statusFlight == ACTIVO && list[i].isEmpty == FALSE) {
												printPassenger(list[i]);
											}
										}
									} else {
										printf("no se pudo ordenar la lista. \n");
									}
									break;

								case 4:
									break;
							}


							printf("Desea seguir mostrando? Ingrese s / n: \n");
							fflush(stdin);
							scanf("%c", &seguirSubMenu);
						} while(seguirSubMenu=='s');
					} else {
						printf("No existen pasajeros cargados. \n");
					}
					break;

				case 5:
					forcedCharge(list, LEN_PASSENGERS);
					break;

				case 6:
					printf("Gracias por cargar los datos solicitados. \n");
					break;

    		}

			printf("Desea seguir operando? Ingrese s / n: \n");
				fflush(stdin);
				scanf("%c", &seguir);
			} while(seguir=='s');
	} else {
		printf("No se pudo iniciar la lista de pasajeros. \n");
	}
	return 0;
}
