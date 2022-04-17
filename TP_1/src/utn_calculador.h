#include <stdio.h>
#include <stdlib.h>

/// @brief Le aplica a un importe un descuento del 10%
///
/// @param pImporteConDesc puntero a la dirección de memoria de una variable donde se va a guardar el importe con el descuento aplicado
/// @param importe recibe el importe al que se le va a realizar la operación
/// @return devuelve 0 en caso de que haya salido bien la operación.
int descuentoDiez (float *pImporteConDesc, int importe);

/// @brief Le aplica a un importe un aumento del 25%
///
/// @param pImporteConAumento puntero a la dirección de memoria de una variable donde se va a guardar el importe con el aumento aplicado.
/// @param importe recibe el importe al que se le va a realizar la operación.
/// @return devuelve 0 en caso de que haya salido bien la operación.
int aumentoVeinticinco (float *pImporteConAumento, int importe);

/// @brief Convierte un importe de pesos a bitcoin.
///
/// @param pImporteBtc puntero a la dirección de memoria de una variable donde se va a guardar el importe con la conversión realizada.
/// @param importe recibe el importe a convertir en bitcoin.
/// @return devuelve 0 en caso de que haya salido bien la operación.
int conversionBtc (float *pImporteBtc, int importe);

/// @brief Calcula el precio unitario de cada kilómetro
///
/// @param pImportePorKm puntero a la dirección de memoria de una variable donde se va a guardar el importe por kilómetro.
/// @param importe recibe el importe para realizar la operación.
/// @param kilometros recibe la cantidad de kilómetros para realizar la operación.
/// @return devuelve 0 en caso de que haya salido bien la operación.
int precioUnit (float *pImportePorKm, int importe, int kilometros);

/// @brief realiza un calculo de diferencia de precio entre dos importes
///
/// @param pDiferenciaPrecio puntero a la dirección de memoria de una variable donde se va a guardar el importe de diferencia de precio entre ambos importes
/// @param importe recibe el primer importe para realizar la operación
/// @param importeDos recibe el segundo importe para realizar la operación.
/// @return devuelve 0 en caso de que haya salido bien la operación.
int diferenciaDePrecio (float *pDiferenciaPrecio, int importe, int importeDos);
