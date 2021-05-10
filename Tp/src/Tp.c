/*
 ============================================================================
 Name        : Tp.c
 Author      : julian
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define INICIAL 0
#define SE_INGRESO_PRIMER_NUMERO 1
#define SE_INGRESO_SEGUNDO_NUMERO 2
#define SE_CALCULO_LAS_OPERACIONES 3

int main(void) {

	setbuf(stdout,NULL);

	int num1;
	int num2;
	int salir=0;
	int flagEstado = INICIAL;
	int resultado;
	long int resultadoFactorial;
	int respuesta;
	float resultadoDivision;

	do{

		switch(menu()){
		case 1:

			utn_getNumero(&num1,"Por favor ingrese un numero.\n","Error ingrese un numero mas chico que 50000000.\n",0,50000000,10);

			flagEstado = SE_INGRESO_PRIMER_NUMERO;
			break;
		case 2:
			if(flagEstado == SE_INGRESO_PRIMER_NUMERO){

				utn_getNumero(&num2,"Por favor ingrese un numero.\n","Error ingrese un numero mas chico que 50000000.\n",0,50000000,10);

				flagEstado = SE_INGRESO_SEGUNDO_NUMERO;
			}else{
				printf("Antes, tiene que ingresar el primer numero.\n");
			}
			break;
		case 3:
			if(flagEstado == SE_INGRESO_SEGUNDO_NUMERO){

				printf("(A= %d) y (B= %d)\n",num1,num2);

				calcular(num1, num2, &resultado, &respuesta, &resultadoDivision, &resultadoFactorial);

				printf("Ya se realizo el calculo.\n");

				flagEstado = SE_CALCULO_LAS_OPERACIONES;
			}else{
				printf("Antes, tiene que ingresar el segundo numero.\n");
			}
			break;
		case 4:
			if(flagEstado == SE_CALCULO_LAS_OPERACIONES){

				resultadosDelCalculo(&resultado, &resultadoFactorial, &respuesta, resultadoDivision);

			}else{
				printf("Antes, tiene que calcular las operaciones.\n");
			}
			break;
		case 5:
			salir=1;
			flagEstado=INICIAL;
			break;
		default:
			printf("La opcion que ingreso es invalida, por favor ingresela de nuevo.\n");
			break;
		}
		system ("cls");
	}while(salir == 0);

	return EXIT_SUCCESS;
}
