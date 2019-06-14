#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"


int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int campos;

    if(pFile != NULL && pArrayListEmployee != NULL){

    char var1[50],var2[50],var3[50],var4[50];
    campos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
    do
    {
        campos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        if(campos==4)
        {
            Employee* emp = employee_new();
            employee_setId(emp, atoi(var1));
            employee_setHorasTrabajadas(emp, atoi(var3));
            employee_setSueldo(emp, atoi(var4));
            employee_setNombre(emp, var2);
            ll_add(pArrayListEmployee, emp);
        }
        else
            break;
    }
    while(!feof(pFile));
}
    return 1;
}


int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    if(pFile != NULL && pArrayListEmployee != NULL){
	        Employee* emp;
    while(!feof(pFile))
    {

        emp = employee_new();
        if( fread(emp, sizeof(Employee),1,pFile) == 1 )
        {
            ll_add(pArrayListEmployee, emp);
        }else
        {
            break;
        }
    }
}
    return 1;
}
