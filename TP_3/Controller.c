#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int devuelve 0 en caso de exito o -1 en caso de error.
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	FILE* pFileText;

	if (pArrayListPassenger != NULL && path != NULL) {
		pFileText = fopen(path, "r");

		if (pFileText != NULL) {
			parser_PassengerFromText(pFileText, pArrayListPassenger);
			printf("Su lista ha sido cargada correctamente.\n ");
			retorno = 0;
		} else {
			printf("Archivo inexistente.\n ");
		}
	} else {
		printf("parámetros inválidos. \n");
	}
	fclose(pFileText);
	return retorno;
}


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int devuelve 0 en caso de exito o -1 en caso de error.
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	FILE* pFileBin;

	if (pArrayListPassenger != NULL && path != NULL) {
		pFileBin = fopen(path, "rb");

		if (pFileBin != NULL) {
			parser_PassengerFromBinary(pFileBin, pArrayListPassenger);
			printf("Su lista ha sido cargada correctamente.\n ");
			fclose(pFileBin);
			retorno = 0;

		} else {
			printf("Archivo inexistente.\n ");
		}
	} else {
		printf("parámetros inválidos. \n");
	}

	return retorno;
}


/** \brief Alta de pasajero
 *
 * \param pArrayListPassenger LinkedList*
 * \return int devuelve 0 en caso de exito o -1 en caso de error.
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* pPassenger = NULL;
	char auxNombre[50];
	char auxApellido[50];
	float auxPrecio;
	int auxTipoPasajero;
	char auxCodigoVuelo[50];
	int auxEstadoVuelo;
	int siguienteId;


	if(pArrayListPassenger != NULL){
		siguienteId = Passenger_getMaxIdtxt() +1;
		if (siguienteId > 0 && !utn_getNombre(auxNombre, 50, "\nIngrese el nombre: ", "\nNombre invalido. Reingrese.", 2) &&
			!utn_getNombre(auxApellido, 50, "\nIngrese el apellido: ", "\nApellido invalido. Reingrese.", 2) &&
			!utn_getNumeroFlotante(&auxPrecio, "\nIngrese el precio: $", "\nImporte invalido. Reingrese", 0, 3000000, 2) &&
			!utn_getNumero(&auxTipoPasajero, "\n1- FirstClass.\n2- ExecutiveClass.\n3- EconomyClass.\nIngrese clase de vuelo: ", "\nClase erronea. Reingrese.", 1, 3, 2) &&
			!utn_getDescripcion(auxCodigoVuelo, 50, "\nIngrese codigo de vuelo. (Hasta 8 caracteres): ", "Codigo erroneo. Reingrese.\n", 2) &&
			!utn_getNumero(&auxEstadoVuelo, "\n1- En Horario.\n2- En Vuelo.\n3- Aterrizado.\n4- Demorado.\nIngrese estado de vuelo: ", "Estado erroneo. Reingrese.\n", 1, 4, 2)) {

			pPassenger = Passenger_newParamTipo(siguienteId, auxNombre, auxApellido, auxPrecio,
					auxCodigoVuelo, auxTipoPasajero, auxEstadoVuelo);

			if (pPassenger != NULL) {
				ll_add(pArrayListPassenger, pPassenger);
				Passenger_writeMaxIdtxt(siguienteId);
				printf("\nPasajero dado de alta exitosamente.\n");
				retorno = 0;
			}

		} else {
			printf("\nNo se pudieron cargar los datos.\n");
		}
	}
    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param pArrayListPassenger LinkedList*
 * \return int devuelve 0 en caso de exito o -1 en caso de error.
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	if (pArrayListPassenger != NULL) {
		Passenger_editarPasajero (pArrayListPassenger);
		retorno = 0;
	}
    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param pArrayListPassenger LinkedList*
 * \return int devuelve 0 en caso de exito o -1 en caso de error.
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int opcion = 0;
	int maxValue = 2147483647;
	int idEliminar;
	int indice;
	Passenger* pPassenger = NULL;

	if (pArrayListPassenger != NULL) {

		utn_getNumero(&idEliminar, "\nIngrese el numero de id a eliminar: ", "\nId inexistente. Reingrese: ", 1, maxValue, 2);
		indice = Passenger_findById(pArrayListPassenger, idEliminar);

		if (indice != -1) {
			printf("\nEl pasajero seleccionado es el siguiente:\n");
			Passenger_printPassenger(pArrayListPassenger, indice);
			pPassenger = (Passenger*) ll_get(pArrayListPassenger, indice);

			utn_getNumero(&opcion, "\n Esta seguro que desea eliminar este pasajero?\n Ingrese 1 si desea borrarlo o 2 para cancelar:  ",
					"\nOpcion erronea. Reingrese: ", 1, 2, 2);

			if (opcion == 1) {

				ll_remove(pArrayListPassenger, indice);
				printf("Pasajero eliminado correctamente.\n");
				retorno = 0;
			} else {
				printf("Operación cancelada.\n");
			}
		}
	}
    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param pArrayListPassenger LinkedList*
 * \return int devuelve 0 en caso de exito o -1 en caso de error.
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	if(pArrayListPassenger != NULL){
		Passenger_Encabezado();
		for(int i = 0; i < ll_len(pArrayListPassenger); i++){
			Passenger_printPassenger(pArrayListPassenger, i);
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param pArrayListPassenger LinkedList*
 * \return int devuelve 0 en caso de exito o -1 en caso de error.
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{

	int retorno = -1;

	if (pArrayListPassenger != NULL) {
		Passenger_ordenamiento(pArrayListPassenger);
		retorno = 0;
	}
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int devuelve 0 en caso de exito o -1 en caso de error.
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int i;
	int largo = 0;
	int auxId;
	char auxNombre[50];
	char auxApellido[50];
	float auxPrecio;
	int auxTipoPasajero;
	char auxCodigoVuelo[50];
	int auxEstadoVuelo;
	char auxIdStr[50];
	char auxTipoPasajeroStr[50];
	char auxEstadoVueloStr[50];
	char auxPrecioStr[50];


	FILE* pFileText;
	pFileText = fopen (path, "w");

	Passenger* pPassenger = NULL;

	if (path != NULL && pArrayListPassenger != NULL){
		largo = ll_len(pArrayListPassenger);

		if (pFileText != NULL){
			fprintf(pFileText, "id,name,lastname,price,flycode,typePassenger,statusFlight \n");
			for (i = 0; i < largo; i++){
				pPassenger = ll_get(pArrayListPassenger, i);
				Passenger_getId(pPassenger, &auxId);
				Passenger_getNombre(pPassenger, auxNombre);
				Passenger_getApellido(pPassenger, auxApellido);
				Passenger_getPrecio(pPassenger, &auxPrecio);
				Passenger_getCodigoVuelo(pPassenger, auxCodigoVuelo);
				Passenger_getTipoPasajero(pPassenger, &auxTipoPasajero);
				Passenger_getEstadoVuelo(pPassenger, &auxEstadoVuelo);


				Passenger_convierteTipoVueloEnChar(auxTipoPasajero, auxTipoPasajeroStr);
				Passenger_convierteEstadoVueloEnChar(auxEstadoVuelo, auxEstadoVueloStr);


				fprintf(pFileText,"%d,%s,%s,%.2f,%s,%s,%s\n",auxId,auxNombre,auxApellido,auxPrecio,auxCodigoVuelo,
						auxTipoPasajeroStr,auxEstadoVueloStr);
			}
		retorno = 0;
		fclose(pFileText);
		}

	}
	if (retorno == 0) {
		printf("Lista modo texto guardada correctamente. \n");
	}
    return retorno;
}


/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int devuelve 0 en caso de exito o -1 en caso de error.
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFileBin = NULL;
	Passenger* pPassenger = NULL;
	int retorno = -1;

	int len = ll_len(pArrayListPassenger);

	pFileBin = fopen(path, "wb");

	if (pFileBin != NULL) {


		for (int i = 0; i < len; i++) {

			pPassenger = (Passenger*)ll_get(pArrayListPassenger, i);

			if (pPassenger != NULL) {

				fwrite (pPassenger, sizeof(Passenger), 1, pFileBin);
				retorno = 0;
			}
		}
		fclose(pFileBin);
	}
	if (retorno == 0) {
		printf("Lista modo binario guardada correctamente. \n");
	}
    return retorno;
}
