#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "Employee.h"


Employee* employee_new(void)
{
    Employee* emp = (Employee*)malloc(sizeof(Employee));

    return emp;
}


int employee_setId(Employee* this, int id)
{
    int retorno=-1;
    if(this != NULL)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}


int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL&&nombre!=NULL&&strlen(nombre)<=sizeof(this->nombre))
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;

    if(this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }

    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;

    if(this != NULL)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }

    return retorno;
}


int employee_getId(Employee* this,int* id){
    int estado= -1;
    if(this != NULL){
        *id= this->id;
        estado= 0;
    }
    return estado;
}


int employee_getNombre(Employee* this, char* nombre){
    int estado= -1;
    if(this != NULL && nombre != NULL){
        strcpy(nombre, this->nombre);
        estado= 0;
    }
    return estado;
}


int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas){
    int estado= -1;
    if(this != NULL && horasTrabajadas != NULL) {
        *horasTrabajadas= this->horasTrabajadas;
        estado= 0;
    }
    return estado;
}

int employee_getSueldo(Employee* this, int* sueldo){
    int estado= -1;
    if(this != NULL && sueldo != NULL){
        *sueldo= this->sueldo;
        estado= 0;
    }
    return estado;
}


void employee_mostrarUno(Employee* this){
    if(this != NULL){
        printf("%d \t%20s \t\t%d \t\t\t%d\n", this->id, this->nombre,this->horasTrabajadas, this->sueldo);
    }
}

Employee* employee_newParametros(int id, char* nombre, int horasTrabajadas, int sueldo){
    Employee* this= employee_new();
    if(this != NULL){
        employee_setId(this, id);
        employee_setHorasTrabajadas(this, horasTrabajadas);
        employee_setNombre(this, nombre);
        employee_setSueldo(this, sueldo);
    }
    return this;
}
