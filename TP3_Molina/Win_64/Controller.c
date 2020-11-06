#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path ,char* pathId ,LinkedList* pArrayListEmployee ,int* idMax)
{
    parser_EmployeeFromText(path ,pathId, pArrayListEmployee, idMax);
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path ,char* pathId ,LinkedList* pArrayListEmployee ,int* idMax)
{
    parser_EmployeeFromBinary(path ,pathId, pArrayListEmployee, idMax);
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee ,int* idMax)
{
    Employee* empleado=employee_new();

    printf("\n\nCrear empleado\n");

    *idMax=*idMax+1;
    printf("%d",*idMax);
    employee_setId(empleado, *idMax);
    employee_IngresarDatos(empleado,1,"\nIngrese nombre:");
    employee_IngresarDatos(empleado,2,"\nIngrese Horas trabajadas:");
    employee_IngresarDatos(empleado,3,"\nIngrese salario:");

    ll_add(pArrayListEmployee,empleado);

    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int id;
    int auxId;
    int flag=0;
    Employee* aux;


    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        aux= (Employee*)  ll_get(pArrayListEmployee, i);
        employee_list(aux);

    }

    printf("Ingrese id: ");
    scanf("%d",&id);

    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        aux=(Employee*) ll_get(pArrayListEmployee,i);
        employee_getId(aux, &auxId);
        if(id==auxId)
        {
            flag=1;
            break;
        }

    }
    system("cls");
    if(flag==1)
    {
        employee_chooseMod(aux, "\n\nModificar empleado\n\n1.Nombre\n2.Horas trabajadas\n3.Salario\n4.Salir\n\nSeleccion: ");
        ll_set(pArrayListEmployee,i,(Employee*)aux);
    }else
    {
        printf("No existe id\n");
    }


    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee ,int* idMax)
{
    int i;
    int id;
    int auxId;
    int flag=0;
    Employee* aux;


    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        aux= (Employee*)  ll_get(pArrayListEmployee, i);
        employee_list(aux);

    }

    printf("Ingrese id: ");
    scanf("%d",&id);

    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        aux=(Employee*) ll_get(pArrayListEmployee,i);
        employee_getId(aux, &auxId);
        if(id==auxId)
        {
            employee_delete(aux);
            ll_remove(pArrayListEmployee, i);
            flag=1;
            *idMax=*idMax-1;
            break;
        }

    }
    if(flag==0)
    {
        printf("No existe id");
    }


    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    Employee* aux;

    printf("\n\nLista de empleados\n");
    printf("id   |Nombre              |sueldo     |horas trabajadas\n");
    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        aux= (Employee*)  ll_get(pArrayListEmployee, i);
        employee_list(aux);

    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int order;

    printf("\n\nOrdenar caracteres\n");
    printf("1.A-Z\n2.Z-A\nSeleccion");
    scanf("%d",&order);

    if(order==1)
    {
        ll_sort(pArrayListEmployee, employee_compareByName, 1);

    }else
    {
        if(order==2)
        {
            ll_sort(pArrayListEmployee, employee_compareByName, 0);

        }else
        {
            printf("\nInvalido...\n");
            system("pause");
        }
    }

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path,char* pathIdMax, LinkedList* pArrayListEmployee ,int* idMax)
{
    int i;
    int auxS;
    int auxId;
    int auxH;
    char auxN[50];
    Employee* aux;
    FILE* pData;
    FILE* pIdMax;

    pData=fopen(path,"w");
    pIdMax=fopen(pathIdMax,"wb");

    if(pIdMax!=NULL&&pData!=NULL)
    {

        fprintf(pIdMax,"%d",*idMax);
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            aux= (Employee*)  ll_get(pArrayListEmployee, i);

            employee_getId(aux, &auxId);
            employee_getSueldo(aux, &auxS);
            employee_getHorasTrabajadas(aux, &auxH);
            employee_getNombre(aux, auxN);

            fprintf(pData,"%d,%s,%d,%d\n",auxId,auxN,auxH,auxS);
        }

        fclose(pData);
        fclose(pIdMax);

    }else
    {
        printf("\n\nERROR MEMORIA\n");

        system("pause");
    }


    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path,char* pathIdMax, LinkedList* pArrayListEmployee ,int* idMax)
{
    int i;
    int auxS;
    int auxId;
    int auxH;
    char auxN[50];
    Employee* aux;
    FILE* pData;
    FILE* pIdMax;

    pIdMax=fopen(pathIdMax,"wb");
    pData=fopen(path,"wb");

    if(pIdMax!=NULL&&pData!=NULL)
    {

        fprintf(pIdMax,"%d",*idMax);
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            aux= (Employee*)  ll_get(pArrayListEmployee, i);

            employee_getId(aux, &auxId);
            employee_getSueldo(aux, &auxS);
            employee_getHorasTrabajadas(aux, &auxH);
            employee_getNombre(aux, auxN);

            fprintf(pData,"%d,%s,%d,%d\n",auxId,auxN,auxH,auxS);
        }

        fclose(pData);
        fclose(pIdMax);

    }else
    {
        printf("\n\nERROR MEMORIA\n");

        system("pause");
    }
    return 1;
}

