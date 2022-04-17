/*
 ============================================================================
 Name        : trabajoPracticoUno.c
 Author      : Molinari Bárbara
 Version     :
 Copyright   : Your copyright notice
 Description : Trabajo practico n° 1 -
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_calculador.h"
#include "utn_getDatos.h"

int main(void) {
	setbuf(stdout, NULL);

	int kilometros;
	int opcionDelMenu;
	int validacionRetorno;
	int opcionSubMenu;
	float precioAerolineas;
	float precioLatam;
	float precioDebitoAero;
	float precioDebitoLatam;
	float precioCreditoAero;
	float precioCreditoLatam;
	float precioBtcAero;
	float precioBtcLatam;
	float precioKilometroAero;
	float precioKilometroLatam;
	float diferenciaPrecio;

	int pasoTres;

	kilometros = 0;
	precioAerolineas = 0;
	precioLatam = 0;
	pasoTres = 0;

	do{
		printf("1) Ingresar Kilómetros:");
		if (kilometros > 0 ) {
			printf(" %d KMs \n", kilometros);
		} else {
			printf("\n");
		}
		printf("2) Ingresar Precio de Vuelos:");
		if (precioLatam > 0 || precioAerolineas > 0) {
			printf(" (Aerolineas = $%.2f, Latam = $%.2f) \n", precioAerolineas, precioLatam);
		} else {
			printf("\n");
		}
		printf("3) Calcular Costos\n");
		printf("4) Informar resultados\n");
		printf("5) Carga forzada de datos\n");
		printf("6) Salir\n");


		validacionRetorno = getInt(&opcionDelMenu,"Ingrese la opcion seleccionada:\n"
									,"La opcion es incorrecta.\n",7,1,1);
		if(validacionRetorno == 0){
			switch(opcionDelMenu){

				case 1:

					pasoTres = 0;
					validacionRetorno = getInt(&kilometros,"Ingrese la cantidad de kilometros:\n"
												,"Kilometraje mal ingresado.\n",1000000,100,2);
					if(validacionRetorno != 0){
						printf("Kilometraje mal ingresado, reintente por favor.\n");
					}
					break;

				case 2:
					pasoTres = 0;
					do {
						printf("1) Ingresar precio Aerolineas: \n");
						printf("2) Ingresar precio Latam: \n");
						printf("3) Regresar al menú principal. \n");

						validacionRetorno = getInt(&opcionSubMenu,"Ingrese la opcion seleccionada:\n"
															,"La opcion es incorrecta. \n",3,1,1);


						if(validacionRetorno == 0){
							switch(opcionSubMenu){

							case 1:
								validacionRetorno = getFloat(&precioAerolineas, "Ingrese precio Aerolineas: \n", 1);
								break;

							case 2:
								validacionRetorno = getFloat(&precioLatam, "Ingrese precio Latam: \n", 1);
								break;

							case 3:
								break;
							}
						}
					} while(opcionSubMenu != 3);

					break;

				case 3:

					if (kilometros > 0 && precioLatam > 0 && precioAerolineas > 0) {
						descuentoDiez (&precioDebitoLatam, precioLatam);
						aumentoVeinticinco (&precioCreditoLatam, precioLatam);
						conversionBtc (&precioBtcLatam, precioLatam);
						precioUnit (&precioKilometroLatam, precioLatam, kilometros);

						descuentoDiez (&precioDebitoAero, precioAerolineas);
						aumentoVeinticinco (&precioCreditoAero, precioAerolineas);
						conversionBtc (&precioBtcAero, precioAerolineas);
						precioUnit (&precioKilometroAero, precioAerolineas, kilometros);

						diferenciaDePrecio (&diferenciaPrecio, precioLatam, precioAerolineas);

						pasoTres = 1;

					} else {
						printf("No puede realizar cálculos sin kilómetros y precios ingresados. \n");
					}


					break;

				case 4:

					printf("KMs Ingresados: %d km \n\n", kilometros);

					if (pasoTres == 1) {

						printf("Precio Aerolineas: $ %.2f \n", precioAerolineas);
						printf("a) Precio con tarjeta de debito: $ %.2f \n", precioDebitoAero);
						printf("b) Precio con tarjeta de crédito: $ %.2f \n", precioCreditoAero);
						printf("c) Precio pagando con bitcoin: %.4f BTC \n", precioBtcAero);
						printf("d) Precio unitario: $ %.2f \n", precioKilometroAero);

						printf("Precio Latam: $ %.2f \n", precioLatam);
						printf("a) Precio con tarjeta de debito: $ %.2f \n", precioDebitoLatam);
						printf("b) Precio con tarjeta de crédito: $ %.2f \n", precioCreditoLatam);
						printf("c) Precio pagando con bitcoin: %.4f BTC\n", precioBtcLatam);
						printf("d) Precio unitario: $ %.2f \n\n", precioKilometroLatam);

						printf("La diferencia de precio es: $ %.2f \n\n", diferenciaPrecio);
					} else {
						printf("No se registran cálculos realizados. \n");
					}
					break;

				case 5:

					kilometros = 7090;
					precioAerolineas = 162965;
					precioLatam = 159339;

					descuentoDiez (&precioDebitoLatam, precioLatam);
					aumentoVeinticinco (&precioCreditoLatam, precioLatam);
					conversionBtc (&precioBtcLatam, precioLatam);
					precioUnit (&precioKilometroLatam, precioLatam, kilometros);

					descuentoDiez (&precioDebitoAero, precioAerolineas);
					aumentoVeinticinco (&precioCreditoAero, precioAerolineas);
					conversionBtc (&precioBtcAero, precioAerolineas);
					precioUnit (&precioKilometroAero, precioAerolineas, kilometros);

					diferenciaDePrecio (&diferenciaPrecio, precioLatam, precioAerolineas);

					printf("KMS Ingresados: %d km \n\n", kilometros);

					printf("Precio Aerolineas: $ %.2f \n", precioAerolineas);
					printf("a) Precio con tarjeta de debito: $ %.2f \n", precioDebitoAero);
					printf("b) Precio con tarjeta de crédito: $ %.2f \n", precioCreditoAero);
					printf("c) Precio pagando con bitcoin: %.4f BTC \n", precioBtcAero);
					printf("d) Precio unitario: $ %.2f \n", precioKilometroAero);

					printf("Precio Latam: $ %.2f \n", precioLatam);
					printf("a) Precio con tarjeta de debito: $ %.2f \n", precioDebitoLatam);
					printf("b) Precio con tarjeta de crédito: $ %.2f \n", precioCreditoLatam);
					printf("c) Precio pagando con bitcoin: %.4f BTC\n", precioBtcLatam);
					printf("d) Precio unitario: $ %.2f \n\n", precioKilometroLatam);

					printf("La diferencia de precio es: $ %.2f \n\n", diferenciaPrecio);

					system("pause");
					break;

				case 6:
					printf("Gracias por consultar los precios. \n");
					break;
			}

		}
	}while(opcionDelMenu != 6);
	return 0;
}




