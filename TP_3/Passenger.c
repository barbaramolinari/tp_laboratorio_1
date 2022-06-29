/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include <stdio.h>
#include <stdlib.h>
#include "Passenger.h"

/**
 * @brief crea espacio en memoria para un nuevo pasajero
 *
 * @return devuelve el espacio en memoria reservado o NULL en caso de no haber podido reservarlo
 */
Passenger* Passenger_new() {
	Passenger* pPassenger = NULL;
	pPassenger = (Passenger*) malloc(sizeof(Passenger));
	if (pPassenger != NULL) {
		Passenger_setId(pPassenger, 0);
		Passenger_setNombre(pPassenger, " ");
		Passenger_setApellido(pPassenger, " ");
		Passenger_setPrecio(pPassenger, 0);
		Passenger_setTipoPasajero(pPassenger, 0);
		Passenger_setCodigoVuelo(pPassenger, " ");
		Passenger_setEstadoVuelo(pPassenger, 0);
	}
	return pPassenger;
}

/**
 * @brief Constructor de parámetros en modo texto. Setea todos los datos del pasajero.
 *
 * @param idStr
 * @param nombreStr
 * @param apellidoStr
 * @param precioStr
 * @param codigoVueloStr
 * @param tipoPasajeroStr
 * @param estadoVueloStr
 * @return retorna NULL si no hay espacio o un puntero al espacio de memoria
 */
Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* precioStr,
		char* codigoVueloStr, char* tipoPasajeroStr,  char* estadoVueloStr) {
	Passenger* pPassenger = NULL;
	pPassenger = Passenger_new();
	int idStrAux;
	float precioStrAux;
	int tipoPasajeroStrAux;
	int estadoVueloStrAux;

	if (pPassenger != NULL) {

		idStrAux = atoi(idStr);
		tipoPasajeroStrAux = Passenger_convierteTipoVueloEnInt(tipoPasajeroStr);
		precioStrAux = atof(precioStr);
		estadoVueloStrAux = Passenger_convierteEstadoVueloEnInt(estadoVueloStr);
		Passenger_setId(pPassenger, idStrAux);
		Passenger_setNombre(pPassenger, nombreStr);
		Passenger_setApellido(pPassenger, apellidoStr);
		Passenger_setPrecio(pPassenger, precioStrAux);
		Passenger_setTipoPasajero(pPassenger, tipoPasajeroStrAux);
		Passenger_setCodigoVuelo(pPassenger, codigoVueloStr);
		Passenger_setEstadoVuelo(pPassenger, estadoVueloStrAux);
	}
	return pPassenger;
}


/**
 * @brief Constructor de parámetros en los tipos que trae la estructura. Setea todos los datos del pasajero.
 *
 * @param id
 * @param nombreStr
 * @param apellidoStr
 * @param precio
 * @param codigoVueloStr
 * @param tipoPasajero
 * @param estadoVuelo
 * @return retorna NULL si no hay espacio o un puntero al espacio de memoria
 */
Passenger* Passenger_newParamTipo(int id,char* nombreStr, char* apellidoStr, float precio,
		char* codigoVueloStr, int tipoPasajero,  int estadoVuelo) {
	Passenger* pPassenger = NULL;
	pPassenger = Passenger_new();

	if (pPassenger != NULL) {


		Passenger_setId(pPassenger, id);
		Passenger_setNombre(pPassenger, nombreStr);
		Passenger_setApellido(pPassenger, apellidoStr);
		Passenger_setPrecio(pPassenger, precio);
		Passenger_setTipoPasajero(pPassenger, tipoPasajero);
		Passenger_setCodigoVuelo(pPassenger, codigoVueloStr);
		Passenger_setEstadoVuelo(pPassenger, estadoVuelo);
	}
	return pPassenger;
}


/**
 * @brief elimina un pasajero para liberar el espacio en memoria
 *
 * @param this
 */
void Passenger_delete(Passenger* this){
	if (this != NULL){
			free(this);
		}
}

/**
 * @brief setea el id en el campo del pasajero
 *
 * @param this
 * @param id
 * @return devuelve 0 en caso de exito o -1 en caso de error.
 */
int Passenger_setId(Passenger* this,int id){
	int retorno = -1;
	if (this != NULL && id >= 0){
		this -> id = id;
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief obtiene el id del campo del pasajero
 *
 * @param this
 * @param id
 * @return devuelve 0 en caso de exito o -1 en caso de error.
 */
int Passenger_getId(Passenger* this,int* id){
	int retorno = -1;
	if (this != NULL && id != NULL){
		*id = this -> id;
		retorno = 0;
	}
	return retorno;
}


/**
 * @brief setea el nombre en el campo del pasajero
 *
 * @param this
 * @param nombre
 * @return devuelve 0 en caso de exito o -1 en caso de error.
 */
int Passenger_setNombre(Passenger* this,char* nombre){
	int retorno = -1;
	if (this != NULL){
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief obtiene el nombre del campo del pasajero
 *
 * @param this
 * @param nombre
 * @return devuelve 0 en caso de exito o -1 en caso de error.
 */
int Passenger_getNombre(Passenger* this,char* nombre){
	int retorno = -1;
	if (this != NULL && nombre != NULL) {
		strcpy (nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief setea el apellido en el campo del pasajero
 *
 * @param this
 * @param apellido
 * @return devuelve 0 en caso de exito o -1 en caso de error.
 */
int Passenger_setApellido(Passenger* this,char* apellido){
	int retorno = -1;
	if (this != NULL){
		strcpy(this->apellido, apellido);
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief obtiene el apellido del campo del pasajero
 *
 * @param this
 * @param apellido
 * @return devuelve 0 en caso de exito o -1 en caso de error.
 */
int Passenger_getApellido(Passenger* this,char* apellido){
	int retorno = -1;
	if (this != NULL && apellido != NULL) {
		strcpy (apellido, this->apellido);
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief setea el codigo de vuelo en el campo del pasajero
 *
 * @param this
 * @param codigoVuelo
 * @return devuelve 0 en caso de exito o -1 en caso de error.
 */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo){
	int retorno = -1;
	if (this != NULL){
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief obtiene el codigo de vuelo del campo del pasajero
 *
 * @param this
 * @param codigoVuelo
 * @return devuelve 0 en caso de exito o -1 en caso de error.
 */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo){
	int retorno = -1;
	if (this != NULL && codigoVuelo != NULL) {
		strcpy (codigoVuelo, this->codigoVuelo);
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief setea el tipo de pasajero en el campo del pasajero
 *
 * @param this
 * @param tipoPasajero
 * @return devuelve 0 en caso de exito o -1 en caso de error.
 */
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero){
	int retorno = -1;
	if(this != NULL){
		this->tipoPasajero = tipoPasajero;
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief obtiene el tipo de pasajero del campo del pasajero
 *
 * @param this
 * @param tipoPasajero
 * @return devuelve 0 en caso de exito o -1 en caso de error.
 */
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero){
	int retorno = -1;
		if(this != NULL && tipoPasajero != NULL){
			*tipoPasajero = this -> tipoPasajero;
			retorno = 0;
		}
		return retorno;
}

/**
 * @brief setea el precio en el campo del pasajero
 *
 * @param this
 * @param precio
 * @return devuelve 0 en caso de exito o -1 en caso de error.
 */
int Passenger_setPrecio(Passenger* this,float precio){
	int retorno = -1;
	if(this != NULL){
		this -> precio = precio;
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief obtiene el precio del campo del pasajero
 *
 * @param this
 * @param precio
 * @return devuelve 0 en caso de exito o -1 en caso de error.
 */
int Passenger_getPrecio(Passenger* this,float* precio){
	int retorno = -1;
		if(this != NULL && precio != NULL){
			*precio = this -> precio;
			retorno = 0;
		}
		return retorno;
}

/**
 * @brief imprime un pasajero que se encuentra en un indice puntual
 *
 * @param pArrayListPassenger
 * @param index
 * @return devuelve 0 en caso de exito o -1 en caso de error.
 */
int Passenger_printPassenger(LinkedList* pArrayListPassenger, int index){

	int retorno = -1;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[50];
	int tipoPasajero;
	int estadoVuelo;
	char auxTipoPasajeroStr[50];
	char auxEstadoVueloStr[50];



	Passenger* pPassenger = NULL;

	if(pArrayListPassenger != NULL){
		pPassenger = (Passenger*)ll_get(pArrayListPassenger, index);
		Passenger_getId(pPassenger, &id);
		Passenger_getNombre(pPassenger, nombre);
		Passenger_getApellido(pPassenger, apellido);
		Passenger_getPrecio(pPassenger, &precio);
		Passenger_getCodigoVuelo(pPassenger, codigoVuelo);
		Passenger_getTipoPasajero(pPassenger, &tipoPasajero);
		Passenger_getEstadoVuelo(pPassenger, &estadoVuelo);


		Passenger_convierteTipoVueloEnChar(tipoPasajero, auxTipoPasajeroStr);
		Passenger_convierteEstadoVueloEnChar(estadoVuelo, auxEstadoVueloStr);

		printf("|%*d|%*s|%*s|%*.2f|%*s|%*s|%*s|\n", -13, id, -20, nombre, -20, apellido, -13, precio, -13, codigoVuelo,
				-20, auxTipoPasajeroStr, -20, auxEstadoVueloStr);

		retorno = 0;
	}
	return retorno;
}


/**
 * @brief muestra por pantalla el encabezado de la lista
 *
 */
void Passenger_Encabezado(){

	printf("\n|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",-13,"ID",-20, "Nombre", -20, "Apellido", -13, "Precio", -13, "FlyCode", -20, "Clase", -20, "Estado");
}

/***
 * @brief Muestra por pantalla el menu principal de opciones
 *
 */
void Passenger_MenuPrincipal(){
	printf("********** Menu Principal ********** \n\n");
		printf("1- Cargar los datos de los pasajeros desde el archivo data.csv (modo texto). \n");
		printf("2- Cargar los datos de los pasajeros desde el archivo data.csv (modo binario). \n");
		printf("3- Alta de pasajero.\n");
		printf("4- Modificar datos de pasajero. \n");
		printf("5- Baja de pasajero. \n");
		printf("6- Listar pasajeros. \n");
		printf("7- Ordenar pasajeros. \n");
		printf("8- Guardar los datos de los pasajeros en el archivo data.csv (modo texto). \n");
		printf("9- Guardar los datos de los pasajeros en el archivo data.csv (modo binario). \n");
		printf("10- Salir. \n");
}

/***
 * @brief Muestra por pantalla el menu con opciones de modificacion
 *
 */
void Passenger_SubMenu(){
	printf("********** Menu de Modificación ********** \n\n");
		printf("1- Modificar nombre: \n");
		printf("2- Modificar apellido: \n");
		printf("3- Modificar precio: \n");
		printf("4- Modificar codigo de vuelo: \n");
		printf("5- Modificar tipo pasajero: \n");
		printf("6- Modificar estado de vuelo: \n");
		printf("7- Regresar al menu principal. \n");
}

/***
 * @brief Muestra por pantalla el menu con opciones de ordenamiento
 *
 */
void Passenger_MenuOrdenamiento(){
	printf("********** Menu de Ordenamiento ********** \n\n");
		printf("1- Ordenar por id: \n");
		printf("2- Ordenar por nombre: \n");
		printf("3- Ordenar por apellido: \n");
		printf("4- Ordenar por precio: \n");
		printf("5- Ordenar por codigo de vuelo: \n");
		printf("6- Ordenar por tipo pasajero: \n");
		printf("7- Ordenar por estado de vuelo: \n");
		printf("8- Regresar al menu principal. \n");
}

/**
 * @brief setea el estado de vuelo en el campo del pasajero
 *
 * @param this
 * @param estadoVuelo
 * @return devuelve 0 en caso de exito o -1 en caso de error.
 */
int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo){
	int retorno = -1;
	if(this != NULL){
		this->estadoVuelo = estadoVuelo;
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief obtiene el estado de vuelo del campo del pasajero
 *
 * @param this
 * @param estadoVuelo
 * @return devuelve 0 en caso de exito o -1 en caso de error.
 */
int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo){
	int retorno = -1;
		if(this != NULL && estadoVuelo != NULL){
			*estadoVuelo = this -> estadoVuelo;
			retorno = 0;
		}
		return retorno;
}

/**
 * @brief convierte el tipo de vuelo de texto a entero
 *
 * @param tipoPasajero
 * @return devuelve el tipo de pasajero como int en caso de exito, o -1 en caso de error
 */
int Passenger_convierteTipoVueloEnInt(char* tipoPasajero) {

	int auxTipoPasajero;

	if(! stricmp(tipoPasajero, "FirstClass")){
		auxTipoPasajero = 1;

	} else if(! stricmp(tipoPasajero, "ExecutiveClass")){
		auxTipoPasajero = 2;

	} else if(! stricmp(tipoPasajero, "EconomyClass")){
		auxTipoPasajero = 3;

	} else {
		auxTipoPasajero = -1;
	}

	return auxTipoPasajero;
}


/**
 * @brief convierte el estado de vuelo de texto a entero
 *
 * @param estadoVuelo
 * @return devuelve el estado de vuelo como int en caso de exito o -1 en caso de error.
 */
int Passenger_convierteEstadoVueloEnInt(char* estadoVuelo) {

	int auxEstadoVuelo;

	if(! stricmp(estadoVuelo, "En Horario")){
		auxEstadoVuelo = 1;

	} else if(! stricmp(estadoVuelo, "En Vuelo")){
		auxEstadoVuelo = 2;

	} else if(! stricmp(estadoVuelo, "Aterrizado")){
		auxEstadoVuelo = 3;

	} else if(! stricmp(estadoVuelo, "Demorado")){
		auxEstadoVuelo = 4;

	} else {
		auxEstadoVuelo = -1;
	}

	return auxEstadoVuelo;

}

/**
 * @brief convierte el tipo de pasajero de entero a texto
 *
 * @param tipoPasajero
 * @return devuelve 0 en caso de exito o -1 en caso de error.
 */
int Passenger_convierteTipoVueloEnChar(int tipoPasajero, char* auxTipoPasajero) {

	int retorno = -1;

	if(tipoPasajero == 1){
		strcpy (auxTipoPasajero, "FirstClass");
		retorno = 0;

	} else if(tipoPasajero == 2){
		strcpy (auxTipoPasajero, "ExecutiveClass");
		retorno = 0;

	} else if(tipoPasajero == 3){
		strcpy (auxTipoPasajero, "EconomyClass");
		retorno = 0;

	}

	return retorno;
}


/**
 * @brief convierte el estado de vuelo de entero a texto
 *
 * @param estadoVuelo
 * @return devuelve 0 en caso de exito o -1 en caso de error.
 */
int Passenger_convierteEstadoVueloEnChar(int estadoVuelo, char* auxEstadoVuelo) {

	int retorno = -1;

	if(estadoVuelo == 1){
		strcpy(auxEstadoVuelo, "En Horario");
		retorno = 0;

	} else if(estadoVuelo == 2){
		strcpy(auxEstadoVuelo, "En Vuelo");
		retorno = 0;

	} else if(estadoVuelo == 3){
		strcpy(auxEstadoVuelo, "Aterrizado");
		retorno = 0;

	} else if(estadoVuelo == 4){
		strcpy(auxEstadoVuelo, "Demorado");
		retorno = 0;

	}

	return retorno;
}


/**
 * @brief edita los campos del pasajero, permitiendole al usuario elegir que campo modificar
 *
 * @param pArrayListPassenger
 * @return devuelve 0 en caso de exito o -1 en caso de error.
 */
int Passenger_editarPasajero (LinkedList* pArrayListPassenger) {
	int retorno = -1;
	int opcion = 0;
	int idModificar;
	int indice;
	char auxNombre[50];
	char auxApellido[50];
	float auxPrecio;
	char auxCodigoVuelo[50];
	int auxTipoPasajero;
	int auxEstadoVuelo;
	int maxValue = 2147483647;
	Passenger *pPassenger = NULL;

	if (pArrayListPassenger != NULL) {

		utn_getNumero(&idModificar, "\nIngrese el numero de id a modificar: ", "\nId inexistente. Reingrese: ", 1, maxValue, 2);
		indice = Passenger_findById(pArrayListPassenger, idModificar);

		if (indice != -1) {
			printf("\nEl pasajero seleccionado es el siguiente:\n");
			Passenger_printPassenger(pArrayListPassenger, indice);
			pPassenger = (Passenger*) ll_get(pArrayListPassenger, indice);

			do {
				Passenger_SubMenu();
				utn_getNumero(&opcion, "\nIngrese un numero de operacion: ", "\nOpcion incorrecta. reingrese: ", 1, 7, 3);

				switch (opcion) {
					case 1:
						if (!utn_getNombre(auxNombre, 50, "\nIngrese el nombre: ", "\nNombre invalido. Reingrese.", 2)) {
							Passenger_setNombre(pPassenger, auxNombre);
							printf("\nNombre modificado correctamente.\n");					}
						break;

					case 2:
						if (!utn_getNombre(auxApellido, 50, "\nIngrese el apellido: ", "\nApellido invalido. Reingrese.", 2)) {
							Passenger_setApellido(pPassenger, auxApellido);
							printf("\nApellido modificado correctamente.\n");
						}
						break;

					case 3:
						if (!utn_getNumeroFlotante(&auxPrecio, "\nIngrese el precio: $", "\nImporte invalido. Reingrese", 0, 3000000, 2)) {
							Passenger_setPrecio(pPassenger, auxPrecio);
							printf("\nPrecio modificado correctamente.\n");
						}
						break;

					case 4:
						if (!utn_getDescripcion(auxCodigoVuelo, 50, "\nIngrese codigo de vuelo. (Hasta 8 caracteres): ", "Codigo erroneo. Reingrese.\n", 2)) {
							Passenger_setCodigoVuelo(pPassenger, auxCodigoVuelo);
							printf("\nCodigo de vuelo modificado correctamente.\n");
						}
						break;

					case 5:
						if (!utn_getNumero(&auxTipoPasajero, "\n1- FirstClass.\n2- ExecutiveClass.\n3- EconomyClass.\nIngrese clase de vuelo: ",
								"\nClase erronea. Reingrese.", 1, 3, 2)) {
							Passenger_setTipoPasajero(pPassenger, auxTipoPasajero);
							printf("\nTipo de pasajero modificado correctamente.\n");
						}
						break;

					case 6:
						if (!utn_getNumero(&auxEstadoVuelo, "\n1- En Horario.\n2- En Vuelo.\n3- Aterrizado.\n4- Demorado."
								"\nIngrese estado de vuelo: ", "Estado erroneo. Reingrese.\n", 1, 4, 2)) {
							Passenger_setEstadoVuelo(pPassenger, auxEstadoVuelo);
							printf("\nEstado de vuelo modificado correctamente.\n");
						}
						break;

					case 7:
						break;
				}
				retorno = 0;
			} while (opcion != 7);

		}
	}
	return retorno;
}

/**
 * @brief encuentra un pasajero por numero de id
 *
 * @param pArrayListPassenger
 * @param id
 * @return retorna la posicion de memoria del pasajero del id indicado o -1 en caso de error
 */
int Passenger_findById(LinkedList* pArrayListPassenger, int id){

	int retorno = -1;
	int auxId;
	int largo = ll_len(pArrayListPassenger);
	Passenger* pPassenger = NULL;

	if(pArrayListPassenger != NULL && id >= 0){
			for(int i = 0; i < largo; i++){
				pPassenger = (Passenger*)ll_get(pArrayListPassenger, i);
				if(!Passenger_getId(pPassenger, &auxId) && id == auxId){
					retorno = i;
					break;
				}
			}
		}
	return retorno;
}


/**
 * @brief comparacion de pasajeros por id
 *
 * @param primerPasajero
 * @param segundoPasajero
 * @return Retorna 1 si el id del primer pasajero es mayor, -1 si es menor o 0 si son iguales.
 */
int Passenger_OrdernarPorId(void* primerPasajero, void* segundoPasajero) {

	int retorno = 0;
	Passenger* pPrimerPass = NULL;
	Passenger* pSegundoPass = NULL;
	int idUno;
	int idDos;

	if(primerPasajero != NULL && segundoPasajero != NULL) {

		pPrimerPass = (Passenger*) primerPasajero;
		pSegundoPass = (Passenger*) segundoPasajero;
		Passenger_getId(pPrimerPass, &idUno);
		Passenger_getId(pSegundoPass, &idDos);

		if(idUno > idDos){
			retorno = 1;
		} else if(idUno < idDos){
			retorno = -1;
		}
	}

	return retorno;
}

/**
 * @brief comparacion de pasajeros por nombre
 *
 * @param primerPasajero
 * @param segundoPasajero
 * @return Retorna 1 si el nombre del primer pasajero es mayor, -1 si es menor o 0 si son iguales.
 */
int Passenger_ordenarPorNombre(void* primerPasajero, void* segundoPasajero) {

	int retorno = 0;
	Passenger* pPrimerPass = NULL;
	Passenger* pSegundoPass = NULL;
	char nombreUno[50];
	char nombreDos[50];

	if(primerPasajero != NULL && segundoPasajero != NULL) {

		pPrimerPass = (Passenger*) primerPasajero;
		pSegundoPass = (Passenger*) segundoPasajero;
		Passenger_getNombre(pPrimerPass, nombreUno);
		Passenger_getNombre(pSegundoPass, nombreDos);

		if(strcmp(nombreUno, nombreDos) > 0) {
			retorno = 1;
		} else if(strcmp(nombreUno, nombreDos) < 0) {
			retorno = -1;
		}
	}
	return retorno;
}

/**
 * @brief comparacion de psajeros por apellido
 *
 * @param primerPasajero
 * @param segundoPasajero
 * @return Retorna 1 si el apellido del primer pasajero es mayor, -1 si es menor o 0 si son iguales.
 */
int Passenger_ordenarPorApellido(void* primerPasajero, void* segundoPasajero) {

	int retorno = 0;
	Passenger* pPrimerPass = NULL;
	Passenger* pSegundoPass = NULL;
	char apellidoUno[50];
	char apellidoDos[50];

	if(primerPasajero != NULL && segundoPasajero != NULL) {

		pPrimerPass = (Passenger*) primerPasajero;
		pSegundoPass = (Passenger*) segundoPasajero;
		Passenger_getApellido(pPrimerPass, apellidoUno);
		Passenger_getApellido(pSegundoPass, apellidoDos);

		if(strcmp(apellidoUno, apellidoDos) > 0){
			retorno = 1;
		} else if(strcmp(apellidoUno, apellidoDos) < 0){
			retorno = -1;
		}
	}

	return retorno;
}

/**
 * @brief comparacion de pasajeros por precio
 *
 * @param primerPasajero
 * @param segundoPasajero
 * @return Retorna 1 si el precio del primer pasajero es mayor, -1 si es menor o 0 si son iguales.
 */
int Passenger_ordenarPorPrecio(void* primerPasajero, void* segundoPasajero) {

	int retorno = 0;
	Passenger* pPrimerPass = NULL;
	Passenger* pSegundoPass = NULL;
	float precioUno;
	float precioDos;

	if(primerPasajero != NULL && segundoPasajero != NULL) {

		pPrimerPass = (Passenger*) primerPasajero;
		pSegundoPass = (Passenger*) segundoPasajero;
		Passenger_getPrecio(pPrimerPass, &precioUno);
		Passenger_getPrecio(pSegundoPass, &precioDos);

		if(precioUno > precioDos){
			retorno = 1;
		} else if(precioUno < precioDos){
			retorno = -1;
		}
	}
	return retorno;
}


/**
 * @brief comparacion de pasajeros por codigo de vuelo
 *
 * @param primerPasajero
 * @param segundoPasajero
 * @return Retorna 1 si el codigo de vuelo del primer pasajero es mayor, -1 si es menor o 0 si son iguales.
 */
int Passenger_ordenarPorCodigoVuelo(void* primerPasajero, void* segundoPasajero){

	int retorno = 0;
	Passenger* pPrimerPass = NULL;
	Passenger* pSegundoPass = NULL;
	char codigoVueloUno[50];
	char codigoVueloDos[50];

	if(primerPasajero != NULL && segundoPasajero != NULL){
		pPrimerPass = (Passenger*) primerPasajero;
		pSegundoPass = (Passenger*) segundoPasajero;
		Passenger_getCodigoVuelo(pPrimerPass, codigoVueloUno);
		Passenger_getCodigoVuelo(pSegundoPass, codigoVueloDos);
		if(strcmp(codigoVueloUno, codigoVueloDos) > 0){
			retorno = 1;
		}
		else if(strcmp(codigoVueloUno, codigoVueloDos) < 0){
			retorno = -1;
		}
	}

	return retorno;
}

/**
 * @brief comparacioon de pasajeros por tipo de pasajero
 *
 * @param primerPasajero
 * @param segundoPasajero
 * @return Retorna 1 si el tipo de pasajero del primer pasajero es mayor, -1 si es menor o 0 si son iguales.
 */
int Passenger_ordenarPorTipoPasajero(void* primerPasajero, void* segundoPasajero){

	int retorno = 0;
	Passenger* pPrimerPass = NULL;
	Passenger* pSegundoPass = NULL;
	int tipoPasajeroUno;
	int tipoPasajeroDos;
	char tipoPasajeroUnoStr[50];
	char tipoPasajeroDosStr[50];

	if(primerPasajero != NULL && segundoPasajero != NULL){
		pPrimerPass = (Passenger*) primerPasajero;
		pSegundoPass = (Passenger*) segundoPasajero;
		Passenger_getTipoPasajero(pPrimerPass, &tipoPasajeroUno);
		Passenger_getTipoPasajero(pSegundoPass, &tipoPasajeroDos);

		Passenger_convierteTipoVueloEnChar(tipoPasajeroUno, tipoPasajeroUnoStr);
		Passenger_convierteTipoVueloEnChar(tipoPasajeroDos, tipoPasajeroDosStr);



		if(strcmp(tipoPasajeroUnoStr, tipoPasajeroDosStr) > 0){
			retorno = 1;
		}
		else if(strcmp(tipoPasajeroUnoStr, tipoPasajeroDosStr) < 0){
			retorno = -1;
		}
	}
	return retorno;
}

/**
 * @brief comparacion de pasajeros por estado de vuelo
 *
 * @param primerPasajero
 * @param segundoPasajero
 * @return Retorna 1 si el estado de vuelo del primer pasajero es mayor, -1 si es menor o 0 si son iguales.
 */
int Passenger_ordenarPorEstadoVuelo(void* primerPasajero, void* segundoPasajero){

	int retorno = 0;
	Passenger* pPrimerPass = NULL;
	Passenger* pSegundoPass = NULL;
	int estadoVueloUno;
	int estadoVueloDos;
	char estadoVueloUnoStr[50];
	char estadoVueloDosStr[50];

	if(primerPasajero != NULL && segundoPasajero != NULL){
		pPrimerPass = (Passenger*) primerPasajero;
		pSegundoPass = (Passenger*) segundoPasajero;
		Passenger_getEstadoVuelo(pPrimerPass, &estadoVueloUno);
		Passenger_getEstadoVuelo(pSegundoPass, &estadoVueloDos);

		Passenger_convierteEstadoVueloEnChar(estadoVueloUno, estadoVueloUnoStr);
		Passenger_convierteEstadoVueloEnChar(estadoVueloDos, estadoVueloDosStr);

		if(strcmp(estadoVueloUnoStr, estadoVueloDosStr) > 0){
			retorno = 1;
		}
		else if(strcmp(estadoVueloUnoStr, estadoVueloDosStr) < 0){
			retorno = -1;
		}

	}
	return retorno;
}

/**
 * @brief imprime la lista de pasajeros
 *
 * @param pArrayListPassenger
 * @return devuelve 0 en caso de exito o -1 en caso de error.
 */
int Passenger_ListPassenger(LinkedList* pArrayListPassenger)
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

/**
 * @brief ordena pasajeros segun el criterio seleccionado por el usuario y en orden ascendente o descendente
 *
 * @param pArrayListPassenger
 * @return devuelve 0 en caso de exito o -1 en caso de error.
 */
int Passenger_ordenamiento(LinkedList* pArrayListPassenger){

	int retorno = -1;
	int opcion;
	int orden;

	if(pArrayListPassenger != NULL){
		do{
			Passenger_MenuOrdenamiento();
			utn_getNumero(&opcion, "Ingrese la opcion seleccionada: \n", "opcion inexistente. Reintente", 1, 8, 2);

			switch(opcion){
				case 1:
					if(!utn_getNumero(&orden, "\n0- Descendente.\n1- Ascendente.\nIndique el tipo de ordenamiento deseado: ",
							"\nOpcion incorrecta\n", 0, 1, 2)){
						printf("Aguarde, ordenamiento en curso...\n");
						ll_sort(pArrayListPassenger, Passenger_OrdernarPorId, orden);
						Passenger_ListPassenger(pArrayListPassenger);
					}
					break;

				case 2:
					if(!utn_getNumero(&orden, "\n0- Descendente.\n1- Ascendente.\nIndique el tipo de ordenamiento deseado: ",
							"\nOpcion incorrecta\n", 0, 1, 2)){
						printf("Aguarde, ordenamiento en curso...\n");
						ll_sort(pArrayListPassenger, Passenger_ordenarPorNombre, orden);
						Passenger_ListPassenger(pArrayListPassenger);
					}
					break;

				case 3:
					if(!utn_getNumero(&orden, "\n0- Descendente.\n1- Ascendente.\nIndique el tipo de ordenamiento deseado: ",
							"\nOpcion incorrecta\n", 0, 1, 2)){
						printf("Aguarde, ordenamiento en curso...\n");
						ll_sort(pArrayListPassenger, Passenger_ordenarPorApellido, orden);
						Passenger_ListPassenger(pArrayListPassenger);
					}
					break;

				case 4:
					if(!utn_getNumero(&orden, "\n0- Descendente.\n1- Ascendente.\nIndique el tipo de ordenamiento deseado: ",
							"\nOpcion incorrecta\n", 0, 1, 2)){
						printf("Aguarde, ordenamiento en curso...\n");
						ll_sort(pArrayListPassenger, Passenger_ordenarPorPrecio, orden);
						Passenger_ListPassenger(pArrayListPassenger);
					}
					break;

				case 5:
					if(!utn_getNumero(&orden, "\n0- Descendente.\n1- Ascendente.\nIndique el tipo de ordenamiento deseado: ",
							"\nOpcion incorrecta\n", 0, 1, 2)){
						printf("Aguarde, ordenamiento en curso...\n");
						ll_sort(pArrayListPassenger, Passenger_ordenarPorCodigoVuelo, orden);
						Passenger_ListPassenger(pArrayListPassenger);
					}
					break;

				case 6:
					if(!utn_getNumero(&orden, "\n0- Descendente.\n1- Ascendente.\nIndique el tipo de ordenamiento deseado: ",
							"\nOpcion incorrecta\n", 0, 1, 2)){
						printf("Aguarde, ordenamiento en curso...\n");
						ll_sort(pArrayListPassenger, Passenger_ordenarPorTipoPasajero, orden);
						Passenger_ListPassenger(pArrayListPassenger);;
					}
					break;

				case 7:
					if(!utn_getNumero(&orden, "\n0- Descendente.\n1- Ascendente.\nIndique el tipo de ordenamiento deseado: ",
							"\nOpcion incorrecta\n", 0, 1, 2)){
						printf("Aguarde, ordenamiento en curso...\n");
						ll_sort(pArrayListPassenger, Passenger_ordenarPorEstadoVuelo, orden);
						Passenger_ListPassenger(pArrayListPassenger);

					}
					break;

				case 8:
					break;
				}
			retorno = 0;
			}while(opcion != 8);
		} else {
			printf("lista no valida.\n");
		}
	return retorno;
}

/**
 * @brief obtiene el id maximo del archivo auxiliar
 *
 * @return devuelve -1 en caso de error o el numero de id en caso de exito
 */
int Passenger_getMaxIdtxt() {
	int retorno = -1;
	char auxId [50];

	FILE* pFileTxt;

	pFileTxt = fopen("ultimoId.txt", "r");

	if (pFileTxt != NULL) {

		fscanf(pFileTxt, "%[^\n]\n", auxId);

		fclose(pFileTxt);

		retorno = atoi(auxId);
	}


	return retorno;
}

/**
 * @brief escribe el id en el archivo auxiliar
 *
 * @param id
 * @return devuelve 0 en caso de exito o -1 en caso de error.
 */
int Passenger_writeMaxIdtxt(int id) {
	int retorno = -1;

	FILE* pFileTxt;

	pFileTxt = fopen("ultimoId.txt", "w");

	if (pFileTxt != NULL) {

		fprintf(pFileTxt, "%d\n", id);

		fclose(pFileTxt);

		retorno = 0;
	}


	return retorno;

}
