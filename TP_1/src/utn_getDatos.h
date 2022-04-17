#include <stdio.h>
#include <stdlib.h>

/// @brief Recibe un n�mero de tipo entero.
///
/// @param pNumeroIngresado puntero a la direcci�n de memoria de una variable donde se va a guardar el n�mero entero ingresado
/// @param mensaje contiene un mensaje de solicitud de n�mero para el usuario
/// @param mensajeError contiene un mensaje de error en caso de que el n�mero no cumpla con los par�metros necesarios
/// @param maximo n�mero m�ximo a recibir
/// @param minimo n�mero m�nimo a recibir
/// @param maximoDeReintentos cantidad de reintentos permitidos para ingresar el n�mero
/// @return
int getInt(int *pNumeroIngresado, char *mensaje, char *mensajeError,
			int maximo, int minimo, int maximoDeReintentos);

/// @brief Recibe un n�mero de tipo flotante.
///
/// @param pNumeroIngresado puntero a la direcci�n de memoria de una variable donde se va a guardar el n�mero flotante ingresado
/// @param mensaje mensaje contiene un mensaje de solicitud de n�mero para el usuario
/// @param maximoDeReintentos cantidad de reintentos permitidos para ingresar el n�mero
/// @return
int getFloat (float *pNumeroIngresado, char *mensaje, int maximoDeReintentos);
