#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;


/**
 * \brief Crea un puntero de tipo Employee
 * \return puntero con memoria asignada de tipo Employee
 */
Employee* employee_new();

/**
 * \brief Asigna parametros a puntero de tipo Employee
 * \param id, nombre, horasTrabajadas y sueldo son los parametros del Employee
 * \return puntero a Employee con los datos cargados
 */
Employee* employee_newParametros(int id, char* nombre, int horasTrabajadas, int sueldo);

 /**
 * \brief Pasa un valor al campo Id del puntero Employee
 * \param this es el puntero
 * \param id es el valor a ingresar
 * \return retorna 0 si esta correcto, -1 si this es NULL
 */
int employee_setId(Employee* this,int id);

/**
 * \brief Busca el campo id del puntero que se le pasa
 * \param this es el puntero
 * \param id es el valor a retornar
 * \return el valor id encontrado o -1 si no encuentra
 */
int employee_getId(Employee* this,int* id);

 /**
 * \brief Pasa un valor al campo nombre del puntero Employee
 * \param this es el puntero
 * \param nombre es el valor a ingresar
 * \return retorna 0 si esta correcto, -1 si this es NULL
 */
int employee_setNombre(Employee* this,char* nombre);

/**
 * \brief Busca el campo nombre del puntero que se le pasa
 * \param this es el puntero
 * \param nombre es el valor a retornar
 * \return el valor id encontrado o -1 si no encuentra
 */
int employee_getNombre(Employee* this,char* nombre);

 /**
 * \brief Pasa un valor al campo horasTrabajadas del puntero Employee
 * \param this es el puntero
 * \param horasTrabajadas es el valor a ingresar
 * \return retorna 0 si esta correcto, -1 si this es NULL
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/**
 * \brief Busca el campo horasTrabajadas del puntero que se le pasa
 * \param this es el puntero
 * \param horasTrabajadas es el valor a retornar
 * \return el valor id encontrado o -1 si no encuentra
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

 /**
 * \brief Pasa un valor al campo sueldo del puntero Employee
 * \param this es el puntero
 * \param sueldo es el valor a ingresar
 * \return retorna 0 si esta correcto, -1 si this es NULL
 */
int employee_setSueldo(Employee* this,int sueldo);


/**
 * \brief Busca el campo sueldo del puntero que se le pasa
 * \param this es el puntero
 * \param sueldo es el valor a retornar
 * \return el valor id encontrado o -1 si no encuentra
 */
int employee_getSueldo(Employee* this,int* sueldo);

/**
 * \brief Imprime por pantalla los datos del puntero
 * \param this es el puntero
 */
void employee_mostrarUno(Employee* this);
#endif // employee_H_INCLUDED
