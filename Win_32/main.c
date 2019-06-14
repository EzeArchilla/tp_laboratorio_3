#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "input.h"

#define PATHTXT "data.csv"
#define PATHBIN "data.bin"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option;
    int dataLoaded = 0;
    int lastId;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        mainMenu();
        option = getIntLimitado("\nIngrese una opcion del menu: ", "Opcion incorrecta, ingrese nuevamente: ", 1, 10);
        switch(option)
        {
        case 1:
            dataLoaded = controller_loadFromText(PATHTXT,listaEmpleados);
            break;
        case 2:
            dataLoaded = controller_loadFromBinary(PATHBIN,listaEmpleados);
            break;
        case 3:
            if(dataLoaded)
            {
                lastId = controller_getLastId(listaEmpleados);
                controller_addEmployee(listaEmpleados, &lastId);
            }
            else
            {
                printf("\nPrimero debe cargar datos!\n");
            }
            break;
        case 4:
            if(dataLoaded)
            {
                controller_editEmployee(listaEmpleados);
            }
            else
            {
                printf("\nPrimero debe cargar datos!\n");
            }
            break;
        case 5:
            if(dataLoaded)
            {
                controller_removeEmployee(listaEmpleados);
            }
            else
            {
                printf("\nPrimero debe cargar datos!\n");
            }
            break;
        case 6:
            if(dataLoaded)
            {
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("\nPrimero debe cargar datos!\n");
            }
            break;
        case 7:
            if(dataLoaded)
            {
                controller_sortEmployee(listaEmpleados);
            }
            else
            {
                printf("\nPrimero debe cargar datos!\n");
            }
            break;
        case 8:
            if(dataLoaded)
            {
                dataLoaded = controller_saveAsText(PATHTXT, listaEmpleados);
            }
            else
            {
                printf("\nPrimero debe cargar datos!\n");
            }
            break;
        case 9:
            if(dataLoaded)
            {
                dataLoaded = controller_saveAsBinary(PATHBIN, listaEmpleados);
            }
            else
            {
                printf("\nPrimero debe cargar datos!\n");
            }
            break;

        }
    }
    while(option != 10);
    ll_deleteLinkedList(listaEmpleados);
    return 0;
}
