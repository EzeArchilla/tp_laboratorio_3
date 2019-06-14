#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char* mensaje);


/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char* mensaje);


/**
 * \brief Solicita un número positivo al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param eMensaje Es el mensaje en caso de error
 * \return El número ingresado por el usuario
 *
 */
int getIntPositivo(char* mensaje, char* eMensaje);


/**
 * \brief Solicita un número positivo al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param eMensaje Es el mensaje en caso de error
 * \return El número ingresado por el usuario
 *
 */
int getIntLimitado(char* mensaje, char* eMensaje, int lowLimit, int highLimit);


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char* mensaje);


/**
 * \brief Genera un número aleatorio
 * \param desde Número aleatorio mínimo
 * \param hasta Número aleatorio máximo
 * \param iniciar Indica si se trata del primer número solicitado 1 indica que si
 * \return retorna el número aleatorio generado
 *
 */
char getNumeroAleatorio(int desde, int hasta, int iniciar);


/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumerico(char str[]);


/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[]);


/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[]);


/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[]);


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char* mensaje,char input[]);


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char* mensaje,char input[]);


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char* mensaje,char input[]);

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getCharSexo(void);


/**
 * \brief Evalua la longitud de un array
 * \param str es el array a evaluar
 * \param length es la longitud esperada del array
 * \return 1 si el texto es mayor a lo solicitado
 */
int lengthString(char str[],int length);


/**
 * \brief Verifica si el valor recibido es una direccion de correo electronico
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene 1 arroba y 1 o 2 puntos.
 *
 */
int esMail(char str[]);


/**
 * \brief Solicita un caracter al usuario [s/n], se utiliza para confirmaciones
 * \param mensaje Es el mensaje a ser mostrado
 * \param eMensaje Es el mensaje a ser mostrado en caso de error
 * \return El caracter ingresado por el usuario [s/n]
 *
 */
char getCharConfirm(char* mensaje, char* eMensaje);


#endif // INPUT_H_INCLUDED
