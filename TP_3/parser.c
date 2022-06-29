#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int devuelve 0 en caso de exito o -1 en caso de error.
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int cantidad = 0;
	char auxId[50];
	char auxNombre[50];
	char auxApellido[50];
	char auxPrecio[50];
	char auxTipoPasajero[50];
	char auxCodigoVuelo[50];
	char auxEstadoVuelo[50];
	Passenger* pPassenger;

	if (pFile != NULL && pArrayListPassenger != NULL) {
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
							auxId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxTipoPasajero, auxEstadoVuelo);
		do {
			 cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
									auxId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxTipoPasajero, auxEstadoVuelo);
			 if (cantidad == 7) {
				pPassenger = Passenger_newParametros(auxId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo,
						auxTipoPasajero, auxEstadoVuelo);

				ll_add(pArrayListPassenger, pPassenger);
				retorno = 0;
			 }

		} while (!feof(pFile));
	}

    return retorno;
}


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int devuelve 0 en caso de exito o -1 en caso de error.
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int cantidad = 0;
	Passenger* pPassenger;

	if(pFile != NULL && pArrayListPassenger != NULL) {
		do {
			pPassenger = Passenger_new();
			cantidad = fread(pPassenger,sizeof(Passenger),1,pFile);
			if (cantidad == 1) {
					ll_add(pArrayListPassenger,pPassenger);
					retorno = 0;
			}
		} while (feof(pFile) == 0);
	}
    return retorno;
}
