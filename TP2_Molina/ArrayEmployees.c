#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#define TRUE 1
#define FALSE 0
int menuPrincipal(char mensaje[]){
    int opcion;
    printf(mensaje);
    fflush(stdin);
    scanf("%d",&opcion);
    system("cls");
    return opcion;
}

int initEmployees(eEmployee list[], int tam){
    if(list!= NULL && tam>0){
        for(int i=0; i<tam; i++)
        {
            list[i].isEmpty=TRUE;

        }
    }
    return 0;
}
int altaEmpleado(eEmployee list[], int tam, int initID){
    if(addEmployee(list,tam,initID)==1){
        printf("No hay espacio para agregar un nuevo empleado\n");
    }else{
        printf("\nSe a ingresado el nuevo empleado con exito!\n");
    }
    return 0;
}

int addEmployee(eEmployee list[], int tam, int initID){
    int isError=1;
    int indice;
    int aux=1;
    float auxF=1;
    eEmployee nuevoEmpleado;
    if(list!= NULL && tam>0 && initID>0)
    {
        indice = buscarLibre(list, tam);
        if(indice!= -1){
            nuevoEmpleado.id = initID;

            nuevoEmpleado.isEmpty = FALSE;

            do{
                printf("Ingrese Sector: ");
                scanf("%d", &aux);
                nuevoEmpleado.sector=aux;
            }while(validacionSector(aux)!=0);
            printf("Ingrese Nombre de empleado: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);
            strcpy(validacionNombrecompleto(nuevoEmpleado.nombre), nuevoEmpleado.nombre);
            printf("Ingrese Apellido de empleado: ");
            fflush(stdin);
            gets(nuevoEmpleado.apellido);
            strcpy(validacionNombrecompleto(nuevoEmpleado.apellido), nuevoEmpleado.apellido);
            do{
                printf("Ingrese Salario: ");
                scanf("%f", &auxF);
                nuevoEmpleado.salario=auxF;
            }while(validacionSalario(auxF)!=0);

            list[indice]= nuevoEmpleado;

            isError=0;
        }
    }
    return isError;
}

int buscarLibre(eEmployee list[], int tam){
    int aux=-1;

    for(int i=0; i<tam; i++){
        if(list[i].isEmpty == TRUE){
            aux = i;
            break;
        }
    }
    return aux;
}

int imprimirEmpleados(eEmployee list[], int tam, int flag){
    int opcion=0;
    if(flag!=0){
        do{
                printf("ID |Nombre  |Apellido  |Sueldo |Sector\n");
                for(int i=0;i<tam;i++){
                    if(list[i].isEmpty==FALSE){
                        printf("%2d |%5s |%5s |%.2f |%d\n", list[i].id, list[i].nombre, list[i].apellido, list[i].salario, list[i].sector);
                    }
                }
                salariosEmpleadosTotal(list, tam);
                salariosEmpleadosPromedio(list, tam);

                opcion=menuPrincipal("\n1.ASCENDENTE\n2.DESCENDENTE\n3.MENU PRINCIPAL\n");

                switch(opcion){

                    case 1:
                        opcion=ordenamientoEmpleados(list, tam, opcion);
                        break;

                    case 2:
                        opcion=ordenamientoEmpleados(list, tam, opcion);
                        break;

                    case 3:
                        opcion=3;
                        break;
                }
                system("cls");
        }while(opcion != 3);
    }else{
        flagAlta(flag);
    }
    return 0;
}

int salariosEmpleadosTotal(eEmployee list[], int tam){
    float auxTotal;
    for(int i=0;i<tam;i++){
        if(list[i].isEmpty==FALSE){
           auxTotal=list[i].salario;
        }
    }
    printf("\nEl total de salarios de los empleados es: %.2f\n",auxTotal);
    return 0;
}

int salariosEmpleadosPromedio(eEmployee list[], int tam){
    int contador=0;
    int contadorMayor=0;
    float auxTotal;
    for(int i=0;i<tam;i++){
        if(list[i].isEmpty==FALSE){
            contador++;
            auxTotal+=list[i].salario;
        }
    }
    auxTotal=auxTotal/contador;
    for(int i=0;i<tam;i++){
        if(list[i].isEmpty==FALSE){
            if(list[i].salario>auxTotal){
            contadorMayor++;
            }
        }
    }
    printf("El promedio de salarios de los empleados es: %.2f\n",auxTotal);
    printf("La cantidad de empleados que superan el promedio son: %d",contadorMayor);

    return 0;
}

int flagAlta(int flag){
    if(flag==0){
        printf("No se puede usar esta opcion hasta que se realize la primera ALTA\n");
    }
    return 0;
}

int bajaEmpleado(eEmployee list[], int tam,int flag){
    int aux;
    if(flag!=0){
        printEmpleados(list, tam, flag);
        printf("\nIngrese el ID del empleado a dar de baja: ");
        scanf("%d", &aux);
        aux=removeEmployee(list,tam, aux);
        if(aux==0){
            printf("No se a encontrado el empleado\n");
        }else if(aux==1){
            printf("Se cancelo la baja del empleado\n");
        }else{
            printf("La baja se realizo con exito!\n");
            flag--;
        }
    }else{
        flagAlta(flag);
    }
    return flag;
}
int removeEmployee(eEmployee list[], int tam, int id){
    char resp;
    int encontrado=0;
    int aux;
    aux=findEmployeeById(list, tam, id);
    if(aux!=-1){
        encontrado=-1;
        printf("\nEsta seguro que desea dar de baja al empleado %s %s?(s|n) ",list[aux].nombre,list[aux].apellido);
        fflush(stdin);
        scanf("%c", &resp);
        if(resp=='n'){

            encontrado=1;

        }else{

            list[aux].isEmpty=TRUE;
        }
    }
    return encontrado;
}

int findEmployeeById(eEmployee list[], int tam, int id){
    int indice=-1;
    for(int i=0;i<tam;i++){
        if(list[i].id==id && list[i].isEmpty==FALSE){
            indice=i;
            break;
        }
    }
    return indice;
}

int printEmpleados(eEmployee list[], int tam, int flag){
    if(flag!=0){
        printf("ID |Nombre  |Apellido  |Sueldo |Sector\n");
        for(int i=0;i<tam;i++){
            if(list[i].isEmpty==FALSE){
                printf("%2d |%5s |%5s |%.2f |%d\n", list[i].id, list[i].nombre, list[i].apellido, list[i].salario, list[i].sector);
            }
        }
    }else{
        flagAlta(flag);
    }

    return 0;
}

int modificarEmpleado(eEmployee list[], int tam,int flag){
    int aux;
    if(flag!=0){
        printEmpleados(list, tam, flag);
        printf("\nIngrese el ID del empleado a modificar: ");
        fflush(stdin);
        scanf("%d", &aux);
        system("cls");
        aux=modifyEmployees(list,tam, aux);
        if(aux==0){
            printf("No se a encontrado el empleado\n");
            system("pause");
        }else if(aux==1){
        }else{
            printf("La modificacion se realizo con exito!\n");
            system("pause");
        }
    }else{
        flagAlta(flag);
        system("pause");
    }
    return 0;
}

int modifyEmployees(eEmployee list[],int tam,int id){
    int aux;
    int encontrado=0;
    int menu;
    char conf='s';
    aux=findEmployeeById(list, tam, id);
    if(aux!=-1){
        encontrado=-1;
        do{

            printf("MENU MODIFICAR EMPLEADO\n1.NOMBRE\n2.APELLIDO\n3.SALARIO\n4.SECTOR\n5.MENU PRINCIPAL\n");

            fflush(stdin);

            scanf("%d", &menu);

            switch(menu){

                case 1:
                    printf("Ingrese nuevo nombre de empleado: ");
                    fflush(stdin);
                    gets(list[aux].nombre);
                    break;

                case 2:
                    printf("Ingrese nuevo apellido de empleado: ");
                    fflush(stdin);
                    gets(list[aux].apellido);
                    break;

                case 3:
                    printf("Ingrese nuevo salario: ");
                    scanf("%f", &list[aux].salario);
                    break;

                case 4:
                    printf("Ingrese nuevo sector: ");
                    scanf("%d", &list[aux].sector);
                    break;

                case 5:
                    conf='n';
                    encontrado=1;
                    break;
            }
            if(menu!=5){
                printf("Desea realizar otro cambio al empleado?(s|n) \n");
                fflush(stdin);
                scanf("%c",&conf);
                system("cls");
            }

        }while (menu!=5 && conf!='n');
    }else{
        list[aux].isEmpty=TRUE;
    }
    return encontrado;
}
int validacionSector(int aux){
    int isError=1;
    if(aux>0 && aux<4){
        isError=0;
    }else{
        printf("Sector Incorrecto!\n");
    }
    return isError;
}

float validacionSalario(float aux){
    int isError=1;
    if(aux>0){
        isError=0;
    }else{
        printf("Salario Incorrecto!\n");
    }
    return isError;
}
char* validacionNombrecompleto(char nombreApellido[]){

    strlwr(nombreApellido);
    nombreApellido[0]=toupper(nombreApellido[0]);

    for(int i=0;i<strlen(nombreApellido);i++){
        if(nombreApellido[i]==' '){
            nombreApellido[i+1]=toupper(nombreApellido[i+1]);
           }
    }
    return nombreApellido;
}
int ordenamientoEmpleados(eEmployee list[], int tam, int orden){
    int comp;
    eEmployee auxEmpleado;

    switch(orden){
        case 1:
            for(int i=0;i<tam-1;i++){
                if(list[i].isEmpty == FALSE){
                    for(int j=i+1;j<tam;j++){
                        if(list[j].isEmpty == FALSE){
                            comp=stricmp(list[i].apellido,list[j].apellido);
                            if(comp>=0 && list[i].sector==list[j].sector){
                                auxEmpleado=list[i];
                                list[i]=list[j];
                                list[j]=auxEmpleado;
                            }
                        }
                    }
                }

            }
            break;

        case 2:
            for(int i=0;i<tam-1;i++){
                if(list[i].isEmpty == FALSE){
                    for(int j=i+1;j<tam;j++){
                        if(list[j].isEmpty == FALSE){
                            comp=stricmp(list[i].apellido,list[j].apellido);
                            if(comp<=0 && list[i].sector==list[j].sector){
                                auxEmpleado=list[i];
                                list[i]=list[j];
                                list[j]=auxEmpleado;
                            }
                        }
                    }
                }

            }
            break;
    }

    return orden;
}
