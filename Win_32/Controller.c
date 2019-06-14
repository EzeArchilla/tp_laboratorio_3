#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "input.h"
#include "Controller.h"


void mainMenu(void)
{
    printf("\n===============Menu==================");
    printf("\n1. Cargar datos desde csv (texto)    ");
    printf("\n2. Cargar datos desde csv (binario)  ");
    printf("\n3. Agregar empleado                  ");
    printf("\n4. Modificar empleado                ");
    printf("\n5. Eliminar empleado                 ");
    printf("\n6. Listar empleados                  ");
    printf("\n7. Ordenar empleados                 ");
    printf("\n8. Guardar datos en csv (texto)      ");
    printf("\n9. Guardar datos en csv (binario)    ");
    printf("\n10. Salir                            ");
    printf("\n=====================================");
}

void menuMod(void)
{
    printf("\n=========Menu modificacion===========");
    printf("\n1. Horas trabajadas                  ");
    printf("\n2. Sueldo                            ");
    printf("\n3. Nombre                            ");
    printf("\n0. Salir                             ");
    printf("\n=====================================");
}

void menuSort(void)
{
    printf("\n========Menu de ordenamiento=========");
    printf("\n1. Id                                ");
    printf("\n2. Sueldo                            ");
    printf("\n3. Horas trabajadas                  ");
    printf("\n4. Nombre                            ");
    printf("\n=====================================");
}


int controller_findId(LinkedList* pArrayListEmployee)
{
    int i;
    int idMod = getIntPositivo("Ingrese el id que desea editar: ", "Id incorrecto, ingreselo nuevamente: ");
    int longitud = ll_len(pArrayListEmployee);
    int idEmp;
    Employee* emp = employee_new();
    int retorno = -1;

    for( i=0 ; i<longitud ; i++ )
    {
        emp = ll_get(pArrayListEmployee, i);
        employee_getId(emp, &idEmp);
        if(idMod == idEmp)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}




int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* archivo;
    int retorno=0;

    if((archivo=fopen(path, "r"))!=NULL && pArrayListEmployee != NULL)
    {
        ll_clear(pArrayListEmployee);
        parser_EmployeeFromText(archivo, pArrayListEmployee);
        retorno = 1;
        fclose(archivo);
    }
    else
    {
        printf("\nError al leer archivo.\n");
    }
    fclose(archivo);

    return retorno;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* archivo;
    int retorno=0;


    if((archivo=fopen(path, "rb"))!=NULL && pArrayListEmployee != NULL)
    {
        ll_clear(pArrayListEmployee);
        parser_EmployeeFromBinary(archivo, pArrayListEmployee);
        retorno = 1;
        fclose(archivo);
    }
    else
    {
        printf("\nError al leer archivo.\n");
    }
    fclose(archivo);

    return retorno;
}


int controller_addEmployee(LinkedList* pArrayListEmployee, int* lastId)
{
    Employee empAux;
    char nombreAux[256];

    printf("\n===ALTA DE EMPLEADO===\n");

    (*lastId)++;

    empAux.id = *lastId;
    empAux.horasTrabajadas = getIntPositivo("Ingrese la cantidad de horas trabajadas: ", "Valor incorrecto, ingrese nuevamente: ");
    empAux.sueldo = getIntPositivo("Ingrese el sueldo: ", "Valor incorrecto, ingrese nuevamente: ");
    getStringLetras("Ingrese el nombre: ", nombreAux);
    nombreAux[0] = toupper(nombreAux[0]);
    strncpy(empAux.nombre, nombreAux, 128);

    Employee* emp = employee_newParametros(empAux.id, empAux.nombre, empAux.horasTrabajadas, empAux.sueldo);
    ll_add(pArrayListEmployee, emp);

    return 1;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* emp = employee_new();
    Employee* empAux = employee_new();
    int opcion;
    int posicionMod = controller_findId(pArrayListEmployee);

    if(posicionMod != -1)
    {
        emp = ll_get(pArrayListEmployee, posicionMod);
        do
        {
            menuMod();
            opcion = getIntLimitado("\nIngrese una opcion del menu: ", "Opcion incorrecta, ingrese nuevamente: ", 0, 4);
            switch(opcion)
            {
            case 1:
                empAux->horasTrabajadas = getIntPositivo("Ingrese la cantidad de horas trabajadas: ", "Valor incorrecto, ingrese nuevamente: ");
                employee_setHorasTrabajadas(emp, empAux->horasTrabajadas);
                break;
            case 2:
                empAux->sueldo = getIntPositivo("Ingrese el sueldo: ", "Valor incorrecto, ingrese nuevamente: ");
                employee_setSueldo(emp, empAux->sueldo);
                break;
            case 3:
                getString("Ingrese el nombre: ", empAux->nombre);
                employee_setNombre(emp, empAux->nombre);
                break;
            }

        }
        while(opcion!=0);


    }

    return 1;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int posicionMod = controller_findId(pArrayListEmployee);

    if(posicionMod != -1)
    {
        ll_remove(pArrayListEmployee, posicionMod);
        printf("\nSe ha eliminado correctamente el registro.\n");
    }
    else
    {
        printf("\nNo se ha encontrado el id que busca.\n");
    }

    return 1;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* emp = employee_new();

    int i;
    int longitud = ll_len(pArrayListEmployee);
    for(i=0; i<longitud; i++)
    {
        emp = ll_get(pArrayListEmployee, i);
        employee_mostrarUno(emp);
    }
    return 1;
}


void controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    menuSort();
    int opcion = getIntLimitado("\nIngrese una opcion del menu: ", "Opcion incorrecta, ingrese nuevamente: ", 0, 4);
    printf("\n1-Ascendent\n2-Descendent\n");
    int order = getIntLimitado("Ingrese el ordenamiento: ", "Opcion incorrecta, ingresse nuevamente: ", 1, 2);

    switch(opcion)
    {
    case 1:
        orderById(pArrayListEmployee, order);
        break;
    case 2:
        orderBySalary(pArrayListEmployee, order);
        break;
    case 3:
        orderByWorkedTime(pArrayListEmployee, order);
        break;
    case 4:
        orderByName(pArrayListEmployee, order);
        break;
    }
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile= fopen(path,"w");
    int estado= -1;
    int i;

    char confirm = getCharConfirm("Esta seguro que desea guardar el archivo? [s/n] ", "Ingreso incorrecto, intente nuevamente [s/n] ");

    if(pFile!= NULL && pArrayListEmployee != NULL && confirm == 'S')
    {
        Employee* this;
        fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            this= ll_get(pArrayListEmployee, i);
            fprintf(pFile,"%d,%s,%d,%d\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
        }
        fclose(pFile);
        estado= 0;
    }
    return estado;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile= fopen(path,"wb");
    int estado= -1;
    int i;

    char confirm = getCharConfirm("Esta seguro que desea guardar el archivo? [s/n] ", "Ingreso incorrecto, intente nuevamente [s/n] ");

    if(pFile!= NULL && pArrayListEmployee!= NULL && confirm == 'S')
    {
        Employee* this;
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            this= ll_get(pArrayListEmployee, i);
            fwrite(this, sizeof(Employee),1,pFile);
        }
        fclose(pFile);
        estado= 0;
    }
    return estado;
}



int controller_getLastId(LinkedList* pArrayListEmployee)
{
    int longitud = (ll_len(pArrayListEmployee));
    int i, idMayor, flag=0;
    Employee* emp;

    if(!ll_isEmpty(pArrayListEmployee))
    {
        for( i=0; i<longitud; i++)
        {
            emp=ll_get(pArrayListEmployee, i);
            if(emp->id > idMayor || flag == 0)
            {
                idMayor = emp->id;
                flag=1;
            }
        }
    }
    else
    {
        idMayor = -1;
    }

    return idMayor;
}



void orderById(LinkedList* pArrayListEmployee, int order)
{
    int longitud = ll_len(pArrayListEmployee);
    int i,j;

    Employee* emp1 = employee_new();
    Employee* emp2 = employee_new();
    Employee* empAux = employee_new();

    switch(order)
    {
    case 1:
        for(i=0; i<longitud; i++)
        {
            emp1 = ll_get(pArrayListEmployee, i);

            for(j=0; j<longitud; j++)
            {
                emp2 = ll_get(pArrayListEmployee, j);

                if(emp1->id > emp2->id)
                {
                    *empAux = *emp2;
                    *emp2 = *emp1;
                    *emp1 = *empAux;
                }
            }
        }
        break;
    case 2:
        for(i=0; i<longitud; i++)
        {
            emp1 = ll_get(pArrayListEmployee, i);

            for(j=0; j<longitud; j++)
            {
                emp2 = ll_get(pArrayListEmployee, j);

                if(emp1->id < emp2->id)
                {
                    *empAux = *emp2;
                    *emp2 = *emp1;
                    *emp1 = *empAux;
                }
            }
        }
    }

}


void orderBySalary(LinkedList* pArrayListEmployee, int order)
{
    int longitud = ll_len(pArrayListEmployee);
    int i,j;

    Employee* emp1 = employee_new();
    Employee* emp2 = employee_new();
    Employee* empAux = employee_new();

    switch(order)
    {
    case 1:
        for(i=0; i<longitud; i++)
        {
            emp1 = ll_get(pArrayListEmployee, i);

            for(j=0; j<longitud; j++)
            {
                emp2 = ll_get(pArrayListEmployee, j);

                if(emp1->sueldo > emp2->sueldo)
                {
                    *empAux = *emp2;
                    *emp2 = *emp1;
                    *emp1 = *empAux;
                }
            }
        }
        break;
    case 2:
        for(i=0; i<longitud; i++)
        {
            emp1 = ll_get(pArrayListEmployee, i);

            for(j=0; j<longitud; j++)
            {
                emp2 = ll_get(pArrayListEmployee, j);

                if(emp1->sueldo < emp2->sueldo)
                {
                    *empAux = *emp2;
                    *emp2 = *emp1;
                    *emp1 = *empAux;
                }
            }
        }
    }
}



void orderByWorkedTime(LinkedList* pArrayListEmployee, int order)
{
    int longitud = ll_len(pArrayListEmployee);
    int i,j;

    Employee* emp1 = employee_new();
    Employee* emp2 = employee_new();
    Employee* empAux = employee_new();

    switch(order)
    {
    case 1:
        for(i=0; i<longitud; i++)
        {
            emp1 = ll_get(pArrayListEmployee, i);

            for(j=0; j<longitud; j++)
            {
                emp2 = ll_get(pArrayListEmployee, j);

                if(emp1->horasTrabajadas > emp2->horasTrabajadas)
                {
                    *empAux = *emp2;
                    *emp2 = *emp1;
                    *emp1 = *empAux;
                }
            }
        }
        break;
    case 2:
        for(i=0; i<longitud; i++)
        {
            emp1 = ll_get(pArrayListEmployee, i);

            for(j=0; j<longitud; j++)
            {
                emp2 = ll_get(pArrayListEmployee, j);

                if(emp1->horasTrabajadas < emp2->horasTrabajadas)
                {
                    *empAux = *emp2;
                    *emp2 = *emp1;
                    *emp1 = *empAux;
                }
            }
        }
    }

}



void orderByName(LinkedList* pArrayListEmployee, int order)
{
    int longitud = ll_len(pArrayListEmployee);
    int i,j;

    Employee* emp1 = employee_new();
    Employee* emp2 = employee_new();
    Employee* empAux = employee_new();

    switch(order)
    {
    case 1:
        for(i=0; i<longitud; i++)
        {
            emp1 = ll_get(pArrayListEmployee, i);

            for(j=0; j<longitud; j++)
            {
                emp2 = ll_get(pArrayListEmployee, j);

                if(strcmp(emp1->nombre, emp2->nombre)>0)
                {
                    *empAux = *emp2;
                    *emp2 = *emp1;
                    *emp1 = *empAux;
                }
            }
        }
        break;
    case 2:
        for(i=0; i<longitud; i++)
        {
            emp1 = ll_get(pArrayListEmployee, i);

            for(j=0; j<longitud; j++)
            {
                emp2 = ll_get(pArrayListEmployee, j);

                if(strcmp(emp1->nombre, emp2->nombre)<0)
                {
                    *empAux = *emp2;
                    *emp2 = *emp1;
                    *emp1 = *empAux;
                }
            }
        }
    }

}
