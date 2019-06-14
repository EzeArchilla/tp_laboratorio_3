/**
 * \brief Busca un puntero en la linkedList por id
 * \param pArrayListEmployee es la linkedList
 * \return -1 en caso de no encontrarlo o el la posicion donde se encuentra un puntero con el id buscado
 */
int controller_findId(LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 1 si cargo los datos de manera exitosa, 0 si hubo error al abrir archivo
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 1 si cargo los datos de manera exitosa, 0 si hubo error al abrir archivo
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \param lastId id autogenerado para que no se repita
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* lastId);

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
void controller_sortEmployee(LinkedList* pArrayListEmployee);


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


/**
 * \brief obtiene el maximo id
 * \param pArrayListEmploye LinkedList*
 * \return retorna el maximo id utilizado o -1 en caso de error
 */
int controller_getLastId(LinkedList* pArrayListEmployee);

/**
 * \brief Ordena la LinkedList por ID
 * \param pArrayListEmployee LinkedList*
 * \param order ascendente o descendente
 */
void orderById(LinkedList* pArrayListEmployee, int order);

/**
 * \brief Ordena la LinkedList por salario
 * \param pArrayListEmployee LinkedList*
 * \param order ascendente o descendente
 */
void orderBySalary(LinkedList* pArrayListEmployee, int order);

/**
 * \brief Ordena la LinkedList por tiempo trabajado
 * \param pArrayListEmployee LinkedList*
 * \param order ascendente o descendente
 */
void orderByWorkedTime(LinkedList* pArrayListEmployee, int order);

/**
 * \brief Ordena la LinkedList por nombre
 * \param pArrayListEmployee LinkedList*
 * \param order ascendente o descendente
 */
void orderByName(LinkedList* pArrayListEmployee, int order);


void mainMenu(void);
