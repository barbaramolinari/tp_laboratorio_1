/*
 * arrayPassenger.c
 *
 *  Created on: 24 abr. 2022
 *      Author: barba
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrayPassenger.h"
#ifndef ARRAYPASSENGER_C_
#define ARRAYPASSENGER_C_

static const char VUELO_PASAJERO[23][51] = {" "," "," "," "," "," "," "," "," "," ", "Activo", "Demorado", "Suspendido",
												" "," "," "," "," "," "," ","First Class", "Business", "Economy"};


//Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
//(isEmpty) en TRUE en todas las posiciones del array. ej uso: r = initPassengers(arrayPassengers, ELEMENTS);
/** \brief Indica que todas las posiciones del array estan vacias. Pone la bandera isempty
* en true en todas las posiciones del array
* \param list Passenger* puntero al array de pasajeros
* \param len int longitud del array
* \return int Devuelve -1 si hay error o 0 si el resultado fue correcto.
*
*/

int initPassengers(Passenger* list, int len) {
	int retorno = -1;
	if (list != NULL && len > 0) {
		for(int i = 0; i < len ; i++){
			list[i].isEmpty = TRUE;
		}
		retorno = 0;
	}

	return retorno;
}


/** \brief agrega en un array de pasajeros existente los valores recibidos como parametro
* en la primer posicion libre.
* \param list passenger* puntero al array de pasajeros
* \param len int longitud máxima del array de pasajeros
* \param id int id de pasajero
* \param name[] char nombre de pasajero
* \param lastName[] char apellido de pasajero
* \param price float precio de vuelo
* \param typePassenger int tipo de pasajero
* \param flycode[] char codigo de reserva de vuelo
* \param statusFlight estado del vuelo
* \return int  devuelve -1 en caso de error o 0 en caso de resultado correcto.
*/


int addPassenger(Passenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[], int statusFlight)
{
	int retorno = -1;
	int posicionLibre;
	if (list != NULL && len > 0) {
		posicionLibre = buscarIndexPorIsEmpty(list, len);
		if (posicionLibre != -1) {
			list[posicionLibre].id = id;
			strcpy(list[posicionLibre].name,name);
			strcpy(list[posicionLibre].lastName,lastName);
			list[posicionLibre].price = price;
			list[posicionLibre].typePassenger = typePassenger;
			strcpy(list[posicionLibre].flycode,flycode);
			list[posicionLibre].statusFlight = statusFlight;
			list[posicionLibre].isEmpty = FALSE;
			retorno = 0;
		}
	}
	return retorno;
}


/** \brief Busca un pasajero recibiendo como parámetro de búsqueda su id
*
* \param list Passenger* puntero al array de pasajeros
* \param len int longitud máxima del array
* \param id int id del pasajero
* \return Devuelve el pasajero en la posicion indicada o -1 en caso de error.
*
*/

int findPassengerById(Passenger* list, int len,int id) {
	int retorno = -1;
	if (list != NULL && len > 0 && id > 0) {
		for (int i =0; i < len; i++) {
			if (list[i].id == id && list[i].isEmpty == 0) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


/** \brief Elimina de manera logica colocando isempty flang en 1 a un pasajero recibiendo como parametro su id.
*
* \param list Passenger* puntero al array de pasajeros
* \param len int longitud maxima del array de pasajeros
* \param id int id de pasajero
* \return int  Devuelve 0 si sale ok o -1 en caso de error
*
*/

int removePassenger(Passenger* list, int len, int id) {
	int retorno = -1;
	int indice;
	if (list != NULL && len > 0 && id > 0) {
		indice = findPassengerById(list, len, id);
		if (indice != -1) {
			list[indice].isEmpty = TRUE;
			retorno = 0;
		}
	}
	return retorno;
}

/**
 */


//Ordena el array de pasajeros por apellido y tipo de pasajero de manera ascendente o
//descendente. ej uso: r = sortPassengersByName(arrayPassengers, ELEMENTS, 1);
/** \brief Ordena el array de pasajeros por apellido y tipo de pasajeros de manera
 * ascendente o descendente (1 - ascendente - 0 - descendente)
*
* \param list Passenger* puntero al array de pasajeros
* \param len int longitud maxima del array de pasajeros
* \param order 1 ascendente - 2 descendente
* \return int Devuelve -1 si hubo error o 0 si funciono bien.
*
*/

int sortPassengersByName (Passenger* list, int len, int order)
{
	int retorno = -1;
	int i;
	Passenger aux;
	int isOrder;

	if (list != NULL && len > 0) {
			do {
				isOrder = 1;
				len--;
				if (order == 0) {
					for (i = 0; i < len; i++) {
						if (stricmp(list[i].lastName, list[i + 1].lastName) < 0) {
							aux = list[i];
							list[i] = list[i + 1];
							list[i + 1] = aux;
							isOrder = 0;
						} else if (stricmp(list[i].lastName, list[i + 1].lastName) == 0
								&& list[i].typePassenger < list[i + 1].typePassenger) {
							aux = list[i];
							list[i] = list[i + 1];
							list[i + 1] = aux;
							isOrder = 0;
						}
					}
				} else {
					for (i = 0; i < len; i++) {
						if (stricmp(list[i].lastName, list[i + 1].lastName) > 0) {
							aux = list[i];
							list[i] = list[i + 1];
							list[i + 1] = aux;
							isOrder = 0;
						} else if (stricmp(list[i].lastName, list[i + 1].lastName) == 0
								&& list[i].typePassenger > list[i + 1].typePassenger) {
							aux = list[i];
							list[i] = list[i + 1];
							list[i + 1] = aux;
							isOrder = 0;
						}
					}
				}
			} while (isOrder == 0);

			retorno = 0;
	}
	return retorno;
}



/** \brief Imprime el array de pasajeros de forma encolumnada
*
* \param list Passenger* puntero al array de pasajeros
* \param len int longitud maxima del array de pasajeros
* \return int devuelve 0 si pudo ejecutarse o -1 en caso de error
*
*/

int printPassengers(Passenger* list, int len) {
	int retorno = -1;
	if (list != NULL && len > 0) {
		printHeader();
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == FALSE) {
				printPassenger(list[i]);
				retorno = 0;
			}
		}
	}
	return retorno;
}

/** \brief Ordena el array de pasajeros por codigo de vuelo y estado de vuelo de manera ascendente o descendente.
*
* \param list Passenger* puntero al array de pasajeros
* \param len int longitud del array de pasajeros
* \param order 1 ascendente - 0 descendente
* \return int devuelve -1 en caso de error o 0 en caso de correcto funcionamiento
*
*
*/


int sortPassengersByCode (Passenger* list, int len, int order)
{
	int retorno = -1;
	int i;
	Passenger aux;
	int isOrder;

	if (list != NULL && len > 0) {
			do {
				isOrder = 1;
				len--;
				if (order == 0) {
					for (i = 0; i < len; i++) {
						if (stricmp(list[i].flycode, list[i + 1].flycode) < 0) {
							aux = list[i];
							list[i] = list[i + 1];
							list[i + 1] = aux;
							isOrder = 0;
						} else if (stricmp(list[i].flycode, list[i + 1].flycode) == 0
								&& list[i].statusFlight < list[i + 1].statusFlight) {
							aux = list[i];
							list[i] = list[i + 1];
							list[i + 1] = aux;
							isOrder = 0;
						}
					}
				} else {
					for (i = 0; i < len; i++) {
						if (stricmp(list[i].flycode, list[i + 1].flycode) > 0) {
							aux = list[i];
							list[i] = list[i + 1];
							list[i + 1] = aux;
							isOrder = 0;
						} else if (stricmp(list[i].flycode, list[i + 1].flycode) == 0
								&& list[i].statusFlight > list[i + 1].statusFlight) {
							aux = list[i];
							list[i] = list[i + 1];
							list[i + 1] = aux;
							isOrder = 0;
						}
					}
				}
			} while (isOrder == 0);

			retorno = 0;
	}
	return retorno;
}


/**
 * @brief busca la primer posicion vacia del array
 *
 * @param list puntero al array de pasajeros
 * @param len longitud maxima del array de pasajeros
 * @return devuelve -1 en caso de error o la posicion en caso de correcto funcionamiento.
 */

int buscarIndexPorIsEmpty(Passenger* list, int len)
{
	int retorno = -1;

		if(list != NULL && len > 0)
		{
			for(int i = 0; i < len; i++)
			{
				if(list[i].isEmpty == 1)
				{
					retorno = i;
					break;
				}
			}
		}

	return retorno;
}

/**
 * @brief modifica el nombre del pasajero
 *
 * @param list puntero al array de pasajeros
 * @param indice recibe la posicion en la que se encuentra el pasajero
 * @return devuelve 0 en caso de correcto funcionamiento o -1 en caso de error
 */


int modificarNombre(Passenger* list, int indice)
{
	int retorno = -1;
	char auxName[51];

	if (!utn_getNombre(auxName, 51, "Ingrese un nombre:", "Nombre incorrecto. Reingrese.", 2)){
		strcpy(list[indice].name, auxName);

		retorno = 0;
	}

	return retorno;
}

/**
 * @brief modifica el apellido del pasajero
 *
 * @param list puntero al array de pasajeros
 * @param indice recibe la posicion en la que se encuentra el pasajero
 * @return devuelve 0 en caso de correcto funcionamiento o -1 en caso de error
 */

int modificarApellido(Passenger* list, int indice)
{
	int retorno = -1;
	char auxApellido[51];


	if (!utn_getNombre(auxApellido, 51, "Ingrese un apellido:", "Apellido incorrecto. Reingrese.", 2)){
		strcpy(list[indice].lastName, auxApellido);

		retorno = 0;
	}


	return retorno;
}

/**
 * @brief modifica el precio de vuelo del pasajero
 *
 * @param list puntero al array de pasajeros
 * @param indice recibe la posicion en la que se encuentra el pasajero
 * @return devuelve 0 en caso de correcto funcionamiento o -1 en caso de error
 */
int modificarPrecio(Passenger* list, int indice)
{
	int retorno = -1;
	float auxPrecio = 0;


	if (!utn_getNumeroFlotante(&auxPrecio, "Ingrese un Precio:", "Precio incorrecto. Reingrese.", 100.0, 2000000.00, 3)){
		list[indice].price = auxPrecio;

		retorno = 0;
	}


	return retorno;
}

/**
 * @brief modifica el tipo de pasajero
 *
 * @param list puntero al array de pasajeros
 * @param indice recibe la posicion en la que se encuentra el pasajero
 * @return devuelve 0 en caso de correcto funcionamiento o -1 en caso de error
 */

int modificarTipoPasajero(Passenger* list, int indice)
{
	int retorno = -1;
	int auxTypePassenger;


	if (!utn_getNumero(&auxTypePassenger, "Ingrese tipo de pasajero: ", "Tipo de pasajero erroneo. Reingrese.", 20, 22, 3)){
		list[indice].typePassenger = auxTypePassenger;

		retorno = 0;
	}


	return retorno;
}

/**
 * @brief modifica el codigo de reserva de vuelo del pasajero
 *
 * @param list puntero al array de pasajeros
 * @param indice recibe la posicion en la que se encuentra el pasajero
 * @return devuelve 0 en caso de correcto funcionamiento o -1 en caso de error
 */

int modificarCodigoVuelo(Passenger* list, int indice)
{
	int retorno = -1;
	char auxFlyCode[10];


	if (!utn_getDescripcion(auxFlyCode, 10, "Ingrese la codificación de reserva: ","datos ingresados incorrectamente. Reingrese.", 3)){
		strcpy(list[indice].flycode, auxFlyCode);

		retorno = 0;
	}


	return retorno;
}

/**
 * @brief  calcula el precio total de los vuelos y el promedio de los mismos
 *
 * @param list list puntero al array de pasajeros
 * @param precioTotal puntero al espacio de memoria donde se guardara el precio total resultante
 * @param precioPromedio puntero al espacio de memoria donde se guardara el precio promedio resultante
 * @param len longitud maxima del array de pasajeros
 * @return
 */
int totalYPromedioVuelos(Passenger* list, float* precioTotal, float* precioPromedio, int len) {
	int retorno= -1;
	float acumuladorPrecio = 0;
	float promedio = 0;
	int cantidad = 0;

	for (int i = 0; i<len; i++) {
		if (list[i].isEmpty == FALSE && list[i].price > 0) {
			acumuladorPrecio += list[i].price;
			cantidad++;
		}
	}

	promedio = (float)acumuladorPrecio / cantidad;
	*precioTotal = acumuladorPrecio;
	*precioPromedio = promedio;
	retorno = 0;

	return retorno;
}

/**
 * @brief calcula la cantidad de pasajeros que superan el precio promedio de vuelos
 *
 * @param list list puntero al array de pasajeros
 * @param cantidadPasajeros puntero al espacio de memoria de la cantidad de pasajeros
 * @param promedio promedio de precio de vuelos
 * @param len longitud maxima de array de pasajeros
 * @return
 */

int cantidadSuperaPromedio(Passenger* list, int* cantidadPasajeros, float promedio, int len){
	int retorno = -1;
	int acumuladorPasajeros =0;
	for (int i = 0; i<len; i++) {
		if (list[i].isEmpty == FALSE && list[i].price > promedio) {
			acumuladorPasajeros++;
		}
	}
	*cantidadPasajeros = acumuladorPasajeros;
	retorno = 0;
	return retorno;
}

/**
 * @brief imprime un pasajero con los datos ingresados
 *
 * @param pasajero pasajero a imprimir
 */
void printPassenger(Passenger pasajero) {

	if(pasajero.isEmpty == FALSE) {
		printf("|%*d|%*s|%*s|%*.2f|%*s|%*s|%*s|\n", -8, pasajero.id, -13, pasajero.name, -13, pasajero.lastName, -10, pasajero.price, -15, VUELO_PASAJERO[pasajero.typePassenger], -10, pasajero.flycode, -12, VUELO_PASAJERO[pasajero.statusFlight]);
	}
}


/**
 * @brief encabezado a mostrar junto con los pasajeros
 *
 */
void printHeader(){

	printf("\n|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n\n",-8,"Id",-13, "Nombre", -13, "Apellido", -10, "Precio", -15, "Clase", -10, "Reserva", -12, "Estado");
}

/**
 * @brief realiza la carga forzada de datos
 *
 * @param list puntero al array de pasajeros
 * @param len longitud maxima del array de pasajeros
 * @return devuelve 0 en caso de carga correcta o -1 en caso de error
 */
int forcedCharge(Passenger* list, int len){
	int retorno = -1;
	int i;
	Passenger passengers[FORCED_CHARGE] = {{0, "NEZUKO", "KAMADO", 250000.00, "T5F4HG", 20, 10, 0},
											{0, "TANJIRO", "KAMADO", 356000.95, "F5YJ68", 22, 11, 0},
											{0, "KIMETSU", "NOYAIBA", 450000.00, "ZG65RD", 21, 10, 0},
											{0, "TENTEN", "UZUI", 252000.79, "ASR12G", 22, 12, 0},
											{0, "MITSURI", "KANROJI", 175000.00, "TH1JU5", 21, 12, 0}};

	if(list != NULL){
		printHeader();
		for(i = 0; i < 5; i++){
			int id = incrementarId();
			if(!addPassenger(list, len, id, passengers[i].name, passengers[i].lastName, passengers[i].price, passengers[i].typePassenger, passengers[i].flycode, passengers[i].statusFlight)) {
				printPassenger(list[i]);
			}
		}
		retorno = 0;
	}
	return retorno;
}


/**
 * @brief muestra el precio total de vuelos, el precio promedio y la cantidad de pasajeros que
 * superan el precio promedio.
 *
 * @param total recibe el precio total de los pasajes
 * @param promedio recibe el precio promedio de los pasajes
 * @param cantidadPasajeros recibe la cantidad de pasajeros que superan el precio promedio
 * @return devuelve 0 en caso de ejecutarse correctamente
 */

int muestraTotalPromedioPrecioyPasajeros (float total, float promedio, int cantidadPasajeros) {
	printf("El precio total de los pasajes es de: %.2f \n", total);
	printf("El precio promedio de los pasajes es de: %.2f \n", promedio);
	printf("La cantidad de pasajeros que superan el precio promedio es de %d pasajeros. \n", cantidadPasajeros);
	return 0;
}

/**
 * @brief corrobora si hay un pasajero cargado
 *
 * @param list puntero al array de pasajeros
 * @param len longitud maxima del array de pasajeros
 * @return devuelve -1 en caso de error o 0 en caso de encontrar el pasajero
 */

int isPassenger(Passenger *list, int len) {
	int retorno = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == FALSE) {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

#endif /* ARRAYPASSENGER_C_ */
