/*
 * utn.h
 *
 *  Created on: 15 Apr 2021
 *      Author: julian
 */

#ifndef UTN_H_
#define UTN_H_

/** \brief retorna la suma de dos enteros
 *
 * \param a int	primer entero para la suma
 * \param b int segundo entero para la suma
 * \return int el resultado de la suma de los dos numeros ingresados
 *
 */
int Sumar(int num1, int num2);

/** \brief  retorna la resta de dos enteros
 *
 * \param a int primer entero para la resta
 * \param b int segundo entero para la resta
 * \return int el resultado de la resta de los dos numeros ingresados
 *
 */
int Restar(int num1, int num2);

/** \brief retorna la division de dos enteros como un flotante
 *
 * \param numero1 int	primer entero para la division
 * \param numero2 int	segundo entero para la division
 * \param presultadoDivision float*	carga en la direccion de memoria el resultado como flotante
 * \return int	retorna si se pudo dividir o no
 *
 */
int dividir(int num1,int num2,float* presultadoDivision);

/** \brief  retorna la multiplicacion de dos enteros
 *
 * \param a int primer entero para la multiplicacion
 * \param b int segundo entero para la multiplicacion
 * \return int el resultado de la multiplicacion de los dos numeros ingresados
 *
 */
int Multiplicar(int num1, int num2);


long long int factorialNumeroUno(int num1);

long long int factorialNumeroDos(int num2);

/** \brief  retorna todos los calculos de dos enteros (sumar, restar, dividir, multiplicar y factorial)
 *
 * \param a int primer entero para el calculo
 * \param b int segundo entero para el calculo
 * \return int el resultado de los calculos con los dos numeros ingresados
 *
 */
int calcular(int num1, int num2, int* resultado, int* respuesta, float* resultadoDivision, long int* resultadoFactorial);

void resultadosDelCalculo(int* resultado, long int* resultadoFactorial, int* respuesta, float resultadoDivision);


int menu();

int utn_getNumero (int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int utn_getNumeroFlotante (float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);
int utn_getCaracter (char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos);

#endif /* UTN_H_ */
