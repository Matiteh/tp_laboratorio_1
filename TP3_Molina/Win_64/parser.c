#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(char* pFile ,char* pFileLen ,LinkedList* pArrayListEmployee ,int* idMax)
{
    int r;
    char auxP[50];
    char auxI[10];
    char auxS[10];
    char auxH[5];
    Employee* aux;

    FILE* data;

    data=fopen(pFile,"r");
    r=parser_maxId(pFileLen,idMax);

    if(data!=NULL&&r!=0)
    {
        do
        {
            r=fscanf(data,"%[^,],%[^,],%[^,],%[^\n]",auxI,auxP,auxH,auxS);
            if(r==4)
            {
                aux=employee_newParametros(auxI,auxP,auxH,auxS);
                ll_add(pArrayListEmployee,aux);

            }

        }while(!feof(data));
        fclose(data);

        printf("\n\nSe cargaron correctamente!\n");
        printf("Cantidad de datos cargados:  %d\n",ll_len(pArrayListEmployee));
    }else
    {
        printf("\n\n Error de carga en archivo data.csv");
    }

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(char* pFile ,char* pFileLen ,LinkedList* pArrayListEmployee ,int* idMax)
{
    int r;
    char auxP[50];
    char auxI[10];
    char auxS[10];
    char auxH[5];
    Employee* aux;

    FILE* data;

    data=fopen(pFile,"rb");
    r=parser_maxId(pFileLen,idMax);

    if(data!=NULL&&r!=0)
    {
        do
        {
            r=fscanf(data,"%[^,],%[^,],%[^,],%[^\n]",auxI,auxP,auxH,auxS);
            if(r==4)
            {
                aux=employee_newParametros(auxI,auxP,auxH,auxS);
                ll_add(pArrayListEmployee,aux);

            }

        }while(!feof(data));
        fclose(data);

        printf("\n\nSe cargaron correctamente!\n");
        printf("Cantidad de datos cargados:  %d\n",ll_len(pArrayListEmployee));
    }else
    {
        printf("\n\n Error de carga en archivo data.csv");
    }

    return 1;
}

int parser_maxId(char* pFileLen ,int* idMax)
{
    int flag=0;
    FILE* data;

    data=fopen(pFileLen,"rb");

    if(data!=NULL)
    {
        fscanf(data,"%d",idMax);
        flag=1;

    }
    fclose(data);

    return flag;
}
