#include <stdio.h>
#include <stdlib.h>

/// @brief Recibe un número de tipo entero.
///
/// @param pNumeroIngresado puntero a la dirección de memoria de una variable donde se va a guardar el número entero ingresado
/// @param mensaje contiene un mensaje de solicitud de número para el usuario
/// @param mensajeError contiene un mensaje de error en caso de que el número no cumpla con los parámetros necesarios
/// @param maximo número máximo a recibir
/// @param minimo número mínimo a recibir
/// @param maximoDeReintentos cantidad de reintentos permitidos para ingresar el número
/// @return
int getInt(int *pNumeroIngresado, char *mensaje, char *mensajeError,
			int maximo, int minimo, int maximoDeReintentos);

/// @brief Recibe un número de tipo flotante.
///
/// @param pNumeroIngresado puntero a la dirección de memoria de una variable donde se va a guardar el número flotante ingresado
/// @param mensaje mensaje contiene un mensaje de solicitud de número para el usuario
/// @param maximoDeReintentos cantidad de reintentos permitidos para ingresar el número
/// @return
int getFloat (float *pNumeroIngresado, char *mensaje, int maximoDeReintentos);
