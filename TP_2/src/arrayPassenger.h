/*
 * arrayPassenger.h
 *
 *  Created on: 24 abr. 2022
 *      Author: barba
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn_miBiblioteca.h"
#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#define TRUE 1
#define FALSE 0
#define FORCED_CHARGE 5



struct {
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
	} typedef Passenger;

int initPassengers(Passenger* list, int len);

int addPassenger(Passenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[], int statusFlight);

int findPassengerById(Passenger* list, int len,int id);

int removePassenger(Passenger* list, int len, int id);

int sortPassengersByName(Passenger* list, int len, int order);

int printPassengers(Passenger* list, int length);

int sortPassengersByCode(Passenger* list, int len, int order);

int buscarIndexPorIsEmpty(Passenger* list, int len);

int modificarNombre(Passenger* list, int indice);

int modificarApellido(Passenger* list, int indice);

int modificarPrecio(Passenger* list, int indice);

int modificarTipoPasajero(Passenger* list, int indice);

int modificarCodigoVuelo(Passenger* list, int indice);

int totalYPromedioVuelos(Passenger* list, float* precioTotal, float* precioPromedio, int len);

int cantidadSuperaPromedio(Passenger* list, int* cantidadPasajeros, float promedio, int len);

void printPassenger(Passenger pasajero);

void printHeader();

int forcedCharge(Passenger *list, int len);

int muestraTotalPromedioPrecioyPasajeros(float total, float promedio, int cantidadPasajeros);

int isPassenger(Passenger *list, int len);

#endif /* ARRAYPASSENGER_H_ */
