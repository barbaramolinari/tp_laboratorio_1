#include "utn_calculador.h"

#include <stdio.h>
#include <stdlib.h>

#define BTC 4606954.55

int descuentoDiez (float *pImporteConDesc, int importe) {
	*pImporteConDesc = (float)importe * 0.9;
	return 0;
}

int aumentoVeinticinco (float *pImporteConAumento, int importe) {
	*pImporteConAumento = (float)importe * 1.25;
	return 0;
}

int conversionBtc (float *pImporteBtc, int importe) {
	*pImporteBtc = (float)importe / BTC;
	return 0;
}

int precioUnit (float *pImportePorKm, int importe, int kilometros) {
	*pImportePorKm = (float)importe / kilometros;
	return 0;
}

int diferenciaDePrecio (float *pDiferenciaPrecio, int importe, int importeDos) {
	if (importe > importeDos) {
		*pDiferenciaPrecio = (float)importe - importeDos;
	} else {
		*pDiferenciaPrecio = (float)importeDos - importe;
	}
	return 0;
}
