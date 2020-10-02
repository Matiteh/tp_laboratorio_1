#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define TAM 1000

int main()
{
    int initID=1;
    eEmployee list[TAM];
    char conf='s';
    int opcion;
    int flag=0;
    initEmployees(list, TAM);
    do{
            opcion=menuPrincipal("ABM TRABAJO PRACTICO\n1.ALTA\n2.BAJA\n3.MODIFICAR\n4.INFORMAR\n5.SALIR\n");

            switch(opcion){

                case 1:/*ALTA*/
                    altaEmpleado(list, TAM, initID);
                    initID++;
                    flag++;
                    system("pause");
                    break;

                case 2:/*BAJA*/
                    flag=bajaEmpleado(list, TAM, flag);
                    system("pause");
                    break;



                case 3:/*MODIFICAR*/
                    modificarEmpleado(list, TAM, flag);
                    break;



                case 4:/*INFORMAR*/
                    imprimirEmpleados(list, TAM, flag);
                    system("pause");
                    break;



                case 5:/*SALIR*/
                    conf='n';
                    break;

                default:

                    break;
                }
                system("cls");
        }while (conf!='n');

}
