#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"
#include "LinkedList.h"

Employee* employee_new()
{
    Employee* empleado= (Employee*)malloc(sizeof(Employee));

    return empleado;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{

    int id=atoi(idStr);
    int horasTrabajada=atoi(horasTrabajadasStr);
    int sueldo=atoi(sueldoStr);
    Employee* list=employee_new();

    employee_setId(list,id);
    employee_setNombre(list, nombreStr);
    employee_setHorasTrabajadas(list,horasTrabajada);
    employee_setSueldo(list,sueldo);

    return list;
}

void employee_delete(Employee* this)
{
    free(this);
}

int employee_setId(Employee* this,int id)
{
    if(this!=NULL){
        this->id=id;
    }
    return 0;
}
int employee_getId(Employee* this,int* id)
{
    if(this!=NULL){
        *id=this->id;
    }
    return 0;
}
int employee_setNombre(Employee* this,char* nombre)
{
    if(this!=NULL){
        strcpy(this->nombre,nombre);
    }
    return 0;
}
int employee_getNombre (Employee* this,char* nombre)
{
    if(this!=NULL){
        strcpy(nombre,this->nombre);
    }
    return 0;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    if(this!=NULL){
        this->horasTrabajadas=horasTrabajadas;
    }
    return 0;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    if(this!=NULL){
        *horasTrabajadas=this->horasTrabajadas;
    }
    return 0;
}
int employee_setSueldo(Employee* this,int sueldo)
{
    if(this!=NULL){
        this->sueldo=sueldo;
    }
    return 0;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    if(this!=NULL){
        *sueldo=this->sueldo;
    }
    return 0;
}

int employee_IngresarDatos(Employee* this,int opcion,char* mensaje)
{
    char ingreso[128];

    puts(mensaje);
    fflush(stdin);
    switch(opcion)
    {
    case 1:
        scanf("%s",ingreso);

        ingreso[0]=toupper(ingreso[0]);

        employee_setNombre(this,ingreso);

        break;
    case 2:
        scanf("%s",ingreso);
        while(employee_checkStr(ingreso)==0)
        {
            printf("ERROR:");
            scanf("%s",ingreso);
        }
        employee_setHorasTrabajadas(this,atoi(ingreso));
        break;
    case 3:
        scanf("%s",ingreso);
        while(employee_checkStr(ingreso)==0)
        {
            printf("ERROR:");
            scanf("%s",ingreso);
        }
        employee_setSueldo(this,atoi(ingreso));
        break;
    case 4:
        system("cls");
        break;
    default:
        printf("\n\nError modificacion\n");
        break;
    }
    return 0;
}

int employee_checkStr(char* ingreso)
{
    int i;
    int flag=1;
    int len;
    len=strlen(ingreso);
    for(i=0;i<len;i++)
    {
        if(ingreso[i]=='\0')
        {
            break;
        }else{
            if(isdigit(ingreso[i])==0)
            {
                flag=isdigit(ingreso[i]);
                break;
            }
        }
    }
    return flag;
}
int employee_chooseMod(Employee* this,char* mensaje)
{
    char mensajeMod[3][30]={"\nIngrese nombre:","\nIngrese Horas Trabajadas:","\nIngrese Salario:"};
    int opcion;

    puts(mensaje);
    scanf("%d",&opcion);
    system("cls");

    if(opcion>0&&opcion<=4)
    {
        employee_IngresarDatos(this,opcion,mensajeMod[opcion-1]);
    }else{
        employee_IngresarDatos(this,-1," ");
    }

    return 1;

}
int employee_list(Employee* this)
{
    printf("%5d %20s %10d       %10d\n",this->id,this->nombre,this->sueldo,this->horasTrabajadas);

    return 1;
}
int employee_compareByName(void *e1, void *e2)
{
    Employee* aux1=e1;
    Employee* aux2=e2;

    return strcmp(aux1->nombre,aux2->nombre);
}
