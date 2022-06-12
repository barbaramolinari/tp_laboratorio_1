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
 * @brief
 *
 * @return
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
 * @brief
 *
 * @param idStr
 * @param nombreStr
 * @param tipoPasajeroStr
 * @return
 */
Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* precioStr,
		char* codigoVueloStr, char* tipoPasajeroStr,  char* estadoVueloStr) {
	Passenger* pPassenger;
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
		Passenger_delete(pPassenger);
	}
	return pPassenger;
}

/**
 * @brief
 *
 * @param this
 */
void Passenger_delete(Passenger* this){
	if (this != NULL){
			free(this);
		}
}

/**
 * @brief
 *
 * @param this
 * @param id
 * @return
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
 * @brief
 *
 * @param this
 * @param id
 * @return
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
 * @brief
 *
 * @param this
 * @param nombre
 * @return
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
 * @brief
 *
 * @param this
 * @param nombre
 * @return
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
 * @brief
 *
 * @param this
 * @param apellido
 * @return
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
 * @brief
 *
 * @param this
 * @param apellido
 * @return
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
 * @brief
 *
 * @param this
 * @param codigoVuelo
 * @return
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
 * @brief
 *
 * @param this
 * @param codigoVuelo
 * @return
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
 * @brief
 *
 * @param this
 * @param tipoPasajero
 * @return
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
 * @brief
 *
 * @param this
 * @param tipoPasajero
 * @return
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
 * @brief
 *
 * @param this
 * @param precio
 * @return
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
 * @brief
 *
 * @param this
 * @param precio
 * @return
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
 * @brief
 *
 * @param pArrayListPassenger
 * @param index
 * @return
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
	char auxIdStr[50];
	char auxPrecioStr[50];
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

		//casteo
		sprintf(auxIdStr,"%d", id);
		sprintf(auxPrecioStr,"%2.0f", precio);
		Passenger_convierteTipoVueloEnChar(&tipoPasajero, auxTipoPasajeroStr);
		Passenger_convierteEstadoVueloEnChar(&estadoVuelo, auxEstadoVueloStr);

		printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n", -13, auxIdStr, -20, nombre, -20, apellido, -13, auxPrecioStr, -13, codigoVuelo, -20, auxTipoPasajeroStr, -20, auxEstadoVueloStr);

		retorno = 0;
	}
	return retorno;
}


/**
 * @brief
 *
 */
void Passenger_Encabezado(){

	printf("\n|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",-13,"ID",-20, "Nombre", -20, "Apellido", -13, "Precio", -13, "FlyCode", -20, "Clase", -20, "Estado \n\n");
}

/***
 * @brief Muestra por pantalla el men de opciones
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
 * @brief Muestra por pantalla el menu de opciones
 *
 */
void Passenger_SubMenu(){
	printf("********** Menu de Modificación ********** \n\n");
		printf("1- Modificar nombre: \n");
		printf("2- Modificar apellido: \n");
		printf("3- Modificar precio: \n");
		printf("4- Modificar tipo pasajero: \n");
		printf("5- Modificar codigo de vuelo: \n");
		printf("6- Modificar estado de vuelo: \n");
		printf("7- Regresar al menu principal. \n");
}

/***
 * @brief Muestra por pantalla el menu de opciones
 *
 */
void Passenger_MenuOrdenamiento(){
	printf("********** Menu de Ordenamiento ********** \n\n");
		printf("1- Ordenar por nombre: \n");
		printf("2- Ordenar por apellido: \n");
		printf("3- Ordenar por  precio: \n");
		printf("4- Ordenar por tipo pasajero: \n");
		printf("5- Ordenar por codigo de vuelo: \n");
		printf("6- Ordenar por estado de vuelo: \n");
		printf("7- Regresar al menu principal. \n");
}

/**
 * @brief
 *
 * @param this
 * @param estadoVuelo
 * @return
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
 * @brief
 *
 * @param this
 * @param estadoVuelo
 * @return
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
 * @brief
 *
 * @param tipoPasajero
 * @return
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
		auxTipoPasajero = -1; // si hay error devuelve -1
	}

	return auxTipoPasajero;
}


/**
 * @brief
 *
 * @param estadoVuelo
 * @return
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
		auxEstadoVuelo = -1; // si hay error devuelve -1
	}

	return auxEstadoVuelo;

}


/**
 * @brief
 *
 * @param pArrayListPassenger
 * @return
 */
int Passenger_getMaxId(LinkedList* pArrayListPassenger) {
	int retorno = -1;
	int i;
	int largo;
	int auxId;
	int maxId = 0;

	Passenger* pPassenger;

	if (pArrayListPassenger != NULL) {
		largo = ll_len(pArrayListPassenger);

		for (i = 0; i < largo; i++) {
			pPassenger = (Passenger*) ll_get (pArrayListPassenger, i);
			Passenger_getId(pPassenger, &auxId);

			if (maxId < auxId) {
				maxId = auxId;
			}
		}
		retorno = maxId;
	}

	return retorno;
}

/**
 * @brief
 *
 * @param tipoPasajero
 * @return
 */
int Passenger_convierteTipoVueloEnChar(int* tipoPasajero, char* auxTipoPasajero) {

	int retorno = -1;

	if(*tipoPasajero == 1){
		auxTipoPasajero = "FirstClass";
		retorno = 0;

	} else if(*tipoPasajero == 2){
		auxTipoPasajero = "ExecutiveClass";
		retorno = 0;

	} else if(*tipoPasajero == 3){
		auxTipoPasajero = "EconomyClass";
		retorno = 0;

	}

	return retorno;
}


/**
 * @brief
 *
 * @param estadoVuelo
 * @return
 */
int Passenger_convierteEstadoVueloEnChar(int* estadoVuelo, char* auxEstadoVuelo) {

	int retorno = -1;

	if(*estadoVuelo == 1){
		auxEstadoVuelo = "En Horario";
		retorno = 0;

	} else if(*estadoVuelo == 2){
		auxEstadoVuelo = "En Vuelo";
		retorno = 0;

	} else if(*estadoVuelo == 3){
		auxEstadoVuelo = "Aterrizado";
		retorno = 0;

	} else if(*estadoVuelo == 4){
		auxEstadoVuelo = "Demorado";
		retorno = 0;

	}

	return retorno;
}

/**
 * @brief
 *
 * @param pArrayListPassenger
 * @return
 */
int Passenger_editarPasajero (LinkedList* pArrayListPassenger) {
	int retorno = -1;
	int opcion = 0;
	int idMaximo;
	int idModificar;
	int indice;
	char auxNombre[50];
	char auxApellido[50];
	float auxPrecio;
	char auxCodigoVuelo[8];
	int auxTipoPasajero;
	int auxEstadoVuelo;
	Passenger *pPassenger = NULL;

	if (pArrayListPassenger != NULL) {

		idMaximo = Passenger_getMaxId(pArrayListPassenger);
		utn_getNumero(&idModificar, "\n Ingrese el numero de id a modificar: ", "\nId inexistente. Reingrese: ", 1, idMaximo, 2);
		indice = Passenger_findById(pArrayListPassenger, idModificar);

		if (indice != -1) {
			printf("\nEl pasajero seleccionado es el siguiente:\n");
			Passenger_printPassenger(pArrayListPassenger, indice);
			pPassenger = (Passenger*) ll_get(pArrayListPassenger, indice);

			do {
				Passenger_SubMenu();
				utn_getNumero(&opcion, "\n Ingrese un numero de operacion: ", "\nOpcion incorrecta. reingrese: ", 1, 7, 3);

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
						if (!utn_getNumero(&auxTipoPasajero, "\n1- FirstClass.\n2- ExecutiveClass.\n3- EconomyClass.\nIngrese clase de vuelo: ",
								"\nClase erronea. Reingrese.", 1, 3, 2)) {
							Passenger_setTipoPasajero(pPassenger, auxTipoPasajero);
							printf("\nTipo de pasajero modificado correctamente.\n");
						}
						break;

					case 5:
						if (!utn_getDescripcion(auxCodigoVuelo, 50, "\nIngrese codigo de vuelo. (Hasta 8 caracteres): ", "Codigo erroneo. Reingrese.\n", 2)) {
							Passenger_setCodigoVuelo(pPassenger, auxCodigoVuelo);
							printf("\nCodigo de vuelo modificado correctamente.\n");
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
			} while (opcion != 7);

		}
	}
	return retorno;
}

/**
 * @brief
 *
 * @param pArrayListPassenger
 * @param id
 * @return
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
 * @brief
 *
 * @param primerPasajero
 * @param segundoPasajero
 * @return
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
 * @brief
 *
 * @param primerPasajero
 * @param segundoPasajero
 * @return
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
 * @brief
 *
 * @param primerPasajero
 * @param segundoPasajero
 * @return
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
 * @brief
 *
 * @param primerPasajero
 * @param segundoPasajero
 * @return
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
 * @brief
 *
 * @param pArrayListPassenger
 * @return
 */
int Passenger_ordenamiento(LinkedList* pArrayListPassenger){

	int retorno = -1;
	int opcion;
	int orden;

	if(pArrayListPassenger != NULL){
		do{
			Passenger_MenuOrdenamiento();
			utn_getNumero(&opcion, "Ingrese la opcion seleccionada: \n", "opcion inexistente. Reintente", 1, 7, 2);

			switch(opcion){
				case 1:
					if(!utn_getNumero(&orden, "\n0- Ascendente.\n1- Descendente.\nIndique el tipo de ordenamiento deseado: ",
							"\nOpcion incorrecta\n", 0, 1, 2)){
						ll_sort(pArrayListPassenger, Passenger_OrdernarPorId, orden);
						controller_ListPassenger(pArrayListPassenger);
					}
					break;

				case 2:
					if(!utn_getNumero(&orden, "\n0- Ascendente.\n1- Descendente.\nIndique el tipo de ordenamiento deseado: ",
							"\nOpcion incorrecta\n", 0, 1, 2)){
						ll_sort(pArrayListPassenger, Passenger_ordenarPorNombre, orden);
						controller_ListPassenger(pArrayListPassenger);
					}
					break;

				case 3:
					if(!utn_getNumero(&orden, "\n0- Ascendente.\n1- Descendente.\nIndique el tipo de ordenamiento deseado: ",
							"\nOpcion incorrecta\n", 0, 1, 2)){
						ll_sort(pArrayListPassenger, Passenger_ordenarPorApellido, orden);
						controller_ListPassenger(pArrayListPassenger);
					}
					break;

				case 4:
					if(!utn_getNumero(&orden, "\n0- Ascendente.\n1- Descendente.\nIndique el tipo de ordenamiento deseado: ",
							"\nOpcion incorrecta\n", 0, 1, 2)){
						ll_sort(pArrayListPassenger, Passenger_ordenarPorPrecio, orden);
						controller_ListPassenger(pArrayListPassenger);
					}
					break;

				case 5:
					if(!utn_getNumero(&orden, "\n0- Ascendente.\n1- Descendente.\nIndique el tipo de ordenamiento deseado: ",
							"\nOpcion incorrecta\n", 0, 1, 2)){
						//falta hacer - printf para prueba
						printf("funcion sin realizar.");
					}
					break;

				case 6:
					if(!utn_getNumero(&orden, "\n0- Ascendente.\n1- Descendente.\nIndique el tipo de ordenamiento deseado: ",
							"\nOpcion incorrecta\n", 0, 1, 2)){
						//falta hacer - printf para prueba
						printf("funcion sin realizar.");
					}
					break;

				case 7:
					if(!utn_getNumero(&orden, "\n0- Ascendente.\n1- Descendente.\nIndique el tipo de ordenamiento deseado: ",
							"\nOpcion incorrecta\n", 0, 1, 2)){
						//falta hacer - printf para prueba
						printf("funcion sin realizar.");

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
