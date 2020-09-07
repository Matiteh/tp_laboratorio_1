#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

int main()
{
    int opciones;
    char seguir = 's';
    char confirma;
    double numA=0;
    double numB=0;
    double resultSuma;
    double resultResta;
    double resultDivision;
    double resultMultiplicacion;
    int resultFactorialA;
    int resultFactorialB;
    int flagOpA=0;
    int flagOpB=0;
    int flagOperaciones=0;
   do
   {
    printf("CALCULADORA\n");
    printf("1.Ingresar primer operando (A=%.2lf)\n" , numA);
    printf("2.Ingresar segundo operando (B=%.2lf)\n" , numB);
    printf("3.Calcular operaciones\n");
    printf("4.Resultado operaciones\n");
    printf("5.Salir\n");
    scanf("%d",&opciones);
    system("cls");
    switch(opciones)
    {
        case 1:
            printf("Ingresar primer operando: \n");
            scanf("%lf",&numA);
            flagOpA=1;
        break;

        case 2:
            printf("Ingresar segundo operando: \n");
            scanf("%lf",&numB);
            flagOpB=1;
        break;

        case 3:
            if(flagOpA==1 && flagOpB==1){
                if(numA==0){
                    resultSuma=suma(numA,numB);
                    resultResta=resta(numA, numB);
                    resultMultiplicacion=multiplicacion(numA, numB);
                    resultFactorialA=factorial(numA);
                    resultFactorialB=factorial(numB);
                    flagOperaciones=1;
                }else{
                    resultSuma=suma(numA,numB);
                    resultResta=resta(numA, numB);
                    resultDivision=division(numA, numB);
                    resultMultiplicacion=multiplicacion(numA, numB);
                    resultFactorialA=factorial(numA);
                    resultFactorialB=factorial(numB);
                    flagOperaciones=1;
                }
            }else{
                printf("Primero ingrese los operandos\n");
            }

        break;

        case 4:
            if(flagOperaciones==1){
                printf("Resultado Suma: %.2lf\n", resultSuma);
                printf("Resultado Resta: %.2lf\n", resultResta);
                if(numA!=0){
                    printf("Resultado Division: %.2lf\n", resultDivision);
                }else{
                    printf("No es posible dividir por 0\n");
                }
                printf("Resultado Multiplicacion: %.2lf\n", resultMultiplicacion);
                printf("Resultado Factorial A: %d\n", resultFactorialA);
                printf("Resultado Factorial B: %d\n", resultFactorialB);
            }else if(flagOpA==1 && flagOpB==1){
                printf("Primero calcule las operaciones\n");
            }else{
                printf("Primero ingrese los operandos\n");
            }

        break;

        case 5:
            printf("Confirmar salida?: ");
            fflush(stdin);
            scanf("%c",&confirma);

            if(confirma=='s')
                {
                    seguir='n';
                }
        break;

        default:
            printf("opcion invalida, ingrese una opcion correcta");
    }
    system("pause");
    system("cls");

   }while(seguir == 's');



    return 0;
}

