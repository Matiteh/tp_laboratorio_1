#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

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
    int option = 1;
    int id=0;
    int flag =0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        printf("--------------------MENU ABM EMPLEADOS--------------------\n\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n10. Salir\nOpcion: ");
        scanf("%d",&option);
        system("cls");

        switch(option)
        {
            case 1:
                if (flag==0)
                {
                    controller_loadFromText("data.csv","lenIdText.dat",listaEmpleados,&id);
                    flag++;
                }else{
                    printf("Ya se han cargado los datos!\n");
                }
                break;
            case 2:
                if (flag==0)
                {
                    controller_loadFromBinary("data.dat","lenIdBin.dat",listaEmpleados,&id);
                    flag++;
                }else{
                    printf("Ya se han cargado los datos!\n");
                }
                break;
            case 3:
                if(flag==0){
                    printf("Primero debe realizar la carga de datos!\n");
                }else{
                    controller_addEmployee(listaEmpleados,&id);
                }
                break;
            case 4:
                if(flag==0){
                    printf("Primero debe realizar la carga de datos!\n");
                }else{
                    controller_editEmployee(listaEmpleados);
                }
                break;
            case 5:
                if(flag==0){
                    printf("Primero debe realizar la carga de datos!\n");
                }else{
                    controller_removeEmployee(listaEmpleados,&id);
                }
                break;
            case 6:
                if(flag==0){
                    printf("No hay empleados que mostrar!\n");
                }else{
                    controller_ListEmployee(listaEmpleados);
                }
                break;
            case 7:
                if(flag==0){
                    printf("No hay empleados que ordenar!\n");
                }else{
                    controller_sortEmployee(listaEmpleados);
                }
                break;
            case 8:
                if(flag==0){
                    printf("No hay datos que guardar!\n");
                }else{
                    controller_saveAsText("data.csv","lenIdText.dat",listaEmpleados,&id);
                }
                break;
            case 9:
                if(flag==0){
                    printf("No hay datos que guardar!\n");
                }else{
                    controller_saveAsBinary("data.dat","lenIdBin.dat",listaEmpleados,&id);
                }
                break;
            case 10:/*salida*/
                break;
            default:/*error*/
                printf("Error, ingrese la opcion nuevamente\n");
                break;
        }
        system("pause");
        system("cls");
    }while(option != 10);
    return 0;
}
