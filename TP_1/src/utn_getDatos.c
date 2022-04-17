#include <stdio.h>
#include <stdlib.h>

#include "utn_getDatos.h"

int getInt(int *pNumeroIngresado, char *mensaje, char *mensajeError,
			int maximo, int minimo, int maximoDeReintentos) {

	int auxNumeroIngresado;
	int retorno;
	retorno = -1;

	if(pNumeroIngresado != NULL && maximo >= minimo && maximoDeReintentos>= 0){
		do{
			printf("%s", mensaje);
			scanf("%d", &auxNumeroIngresado);
			maximoDeReintentos--;

			if(auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo){
						*pNumeroIngresado = auxNumeroIngresado;
						retorno = 0;
						break;
			}else{
				printf("%s", mensajeError);
			}

		}while(maximoDeReintentos > 0);
	}

	return retorno;
}


int getFloat (float *pNumeroIngresado, char *mensaje, int maximoDeReintentos) {

	float auxNumeroIngresado;
	int retorno;
	retorno = -1;

	if(pNumeroIngresado != NULL && maximoDeReintentos>= 0){
		do{
			printf("%s", mensaje);
			scanf("%f", &auxNumeroIngresado);
			maximoDeReintentos--;
			*pNumeroIngresado = auxNumeroIngresado;
			retorno = 0;
			break;

		}while(maximoDeReintentos > 0);
	}

	return retorno;
}
