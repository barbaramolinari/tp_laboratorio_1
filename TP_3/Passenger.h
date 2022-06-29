/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn_miBiblioteca.h"
#include "LinkedList.h"
#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[50];
	int tipoPasajero;
	int estadoVuelo;

}Passenger;

Passenger* Passenger_new();

Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* precioStr,
		char* codigoVueloStr, char* tipoPasajeroStr,  char* estadoVueloStr);

Passenger* Passenger_newParamTipo(int id,char* nombreStr, char* apellidoStr, float precio,
		char* codigoVueloStr, int tipoPasajero,  int estadoVuelo);

void Passenger_delete();

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo);

int Passenger_printPassenger(LinkedList* pArrayListPassenger, int index);
void Passenger_Encabezado();
void Passenger_MenuPrincipal();
void Passenger_SubMenu();
void Passenger_MenuOrdenamiento();
int Passenger_getMaxIdtxt();
int Passenger_writeMaxIdtxt(int id);
int Passenger_convierteTipoVueloEnInt(char* tipoPasajero);
int Passenger_convierteEstadoVueloEnInt(char* estadoVuelo);
int Passenger_convierteTipoVueloEnChar(int tipoPasajero, char* auxTipoPasajero);
int Passenger_convierteEstadoVueloEnChar(int estadoVuelo, char* auxEstadoVuelo);
int Passenger_editarPasajero (LinkedList* pArrayListPassenger);
int Passenger_findById(LinkedList* pArrayListPassenger, int id);
int Passenger_ordenamiento(LinkedList* pArrayListPassenger);
int Passenger_OrdernarPorId(void* primerPasajero, void* segundoPasajero);
int Passenger_ordenarPorNombre(void* primerPasajero, void* segundoPasajero);
int Passenger_ordenarPorApellido(void* primerPasajero, void* segundoPasajero);
int Passenger_ordenarPorPrecio(void* primerPasajero, void* segundoPasajero);
int Passenger_ordenarPorCodigoVuelo(void* primerPasajero, void* segundoPasajero);
int Passenger_ordenarPorTipoPasajero(void* primerPasajero, void* segundoPasajero);
int Passenger_ordenarPorEstadoVuelo(void* primerPasajero, void* segundoPasajero);
int Passenger_ListPassenger(LinkedList* pArrayListPassenger);



#endif /* PASSENGER_H_ */
