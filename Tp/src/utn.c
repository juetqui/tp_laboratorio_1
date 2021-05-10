/*
 * utn.c
 *
 *  Created on: 15 Apr 2021
 *      Author: julian
 */
#include <stdio.h>
#include <stdlib.h>


int Sumar(int num1, int num2){

	return num1+num2;
}

int Restar(int num1, int num2){

	return num1-num2;
}

int dividir(int num1,int num2,float* presultadoDivision){

	float resultado;
	int retorno = -1;

	if(presultadoDivision != NULL && num2 != 0)
	{
		resultado = (float)num1/num2;
		(*presultadoDivision) = resultado;
		retorno = 0;
	}
	return retorno;
}

int Multiplicar(int num1, int num2){

	return num1*num2;
}

long int factorialNumeroUno(int num1){

	long int resp;
	if(num1==1){
		return 1;
	}else{
		resp = num1* factorialNumeroUno (num1-1);
		return (resp);
	}
}

long int factorialNumeroDos(int num2){

	long int resp;
	if(num2==1){
		return 1;
	}else{
		resp = num2* factorialNumeroDos (num2-1);
		return (resp);
	}
}

int calcular(int num1, int num2, int* resultado, int* respuesta, float resultadoDivision, long int* resultadoFactorial){

	(*resultado) = Sumar(num1, num2);

	(*resultado) = Restar(num1, num2);

	(*respuesta) = dividir(num1,num2,&resultadoDivision);

	(*resultado) = Multiplicar(num1, num2);

	(*resultadoFactorial) = factorialNumeroUno(num1);

	(*resultadoFactorial) = factorialNumeroDos(num2);

	return 0;
}

void resultadosDelCalculo(int* resultado, long int* resultadoFactorial, int* respuesta, float resultadoDivision){

	printf("El resultado de la suma es: %d\n", resultado);
	printf("El resultado de la resta es: %d\n", resultado);
	if(respuesta==0){
		printf("El resultado de la division es: %f\n",&resultadoDivision);
	}
	else{
		printf("No se puede dividir por cero\n");
	}
	printf("El resultado de la multiplicacion es: %d\n", resultado);
	printf("El factorial de el numero uno es: %ld\n",resultadoFactorial);
	printf("El factorial de el numero dos es: %ld\n",resultadoFactorial);

}

int menu(){

	int opcion;

	printf("MENU CALCULADORA\n");
	printf("1.Ingrese el primer numero\n");
	printf("2.Ingrese el segundo numero\n");
	printf("3.Calcular todas las operaciones\n");
	printf("4.Informar resultados\n");
	printf("5.Salir\n");
	printf("Ingrese opcion\n");
	fflush(stdin);

	scanf("%d",&opcion);

	return opcion;
}

int utn_getNumero (int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos){

	int retorno;
	int bufferInt;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){

		while(reintentos > 0){

			printf("%s", mensaje);
			if (scanf("%d",&bufferInt)==1){

				if(bufferInt >= minimo && bufferInt <= maximo){

					break;
				}
				else{
					printf("%s",mensajeError);
					reintentos--;
					fflush(stdin);
				}
			}
		}

		if (reintentos==0){
			retorno = -1;
		}else{
			retorno = 0;
			*pResultado = bufferInt;
		}
	}
	return retorno;
}

int utn_getNumeroFlotante (float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos){

	int retorno = -1;
	float bufferFloat;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){

		do{
			printf("%s", mensaje);
			if (scanf("%f",&bufferFloat)==1){
				if(bufferFloat >= minimo && bufferFloat <= maximo){
					*pResultado=bufferFloat;
					retorno = 0;
					break;
				}
				else{
					printf("%s",mensajeError);
					reintentos--;
					fflush(stdin);
				}
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

int utn_getCaracter (char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos){

	int retorno = -1;
	char bufferChar;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){

		do{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c",&bufferChar);

			if(bufferChar >= minimo && bufferChar <= maximo){
				*pResultado=bufferChar;
				retorno = 0;
				break;
			}
			else{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}
