/*
 ============================================================================
 Name        : Tp2.c
 Author      : julian
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"

#define CANT_EMPLOYEE 1000

int main(void)
{
	setbuf(stdout, NULL);

	Employee arrayEmployee[CANT_EMPLOYEE];
	int idEmployee = 0;
	int opcion;
	int auxiliarId;
	int auxiliarIndice;
	int flagAlta=0;
	int auxiliarOrder;

	if(initEmployees(arrayEmployee, CANT_EMPLOYEE) == 0)
	{
		printf("Array inicializado correctamente.\n");
	}

	do
	{
		if(!utn_getNumero(	&opcion,
							"\n\n1.Dar de alta un Empleado"
							"\n2.Modificar un Empleado"
							"\n3.Dar de baja un Empleado"
							"\n4.Informar"
							"\n5.Salir",
							"\nError opcion invalida\n", 1, 5, 2))
		{
			switch(opcion)
			{
			case 1:
				auxiliarIndice = Emp_getEmptyIndex(arrayEmployee, CANT_EMPLOYEE);
				if(auxiliarIndice >= 0)
				{
					if(addEmployee(arrayEmployee, CANT_EMPLOYEE, auxiliarIndice, &idEmployee) == 0)
					{
						printf("\nCarga realizada con exito\n");
						flagAlta=1;
					}
				}else
				{
					printf("No hay mas lugares\n");
				}
				break;
			case 2:
				if(utn_getNumero(&auxiliarId, "\nIndique el ID del empleado a modificar", "\nID invalido", 0, idEmployee, 2) == 0 && flagAlta==1)
				{
					auxiliarIndice = findEmployeeById(arrayEmployee, CANT_EMPLOYEE, auxiliarId);
					if(	auxiliarIndice >= 0 &&
						Emp_modificarArray(arrayEmployee, CANT_EMPLOYEE, auxiliarIndice) == 0)
					{
						printf("\nModificacion realizada con exito\n");
					}
				}else
				{
					printf("Primero debe dar de alta un empleado\n");
				}
				break;
			case 3:
				if(utn_getNumero(&auxiliarId, "\nIndique el ID del empleado a eliminar", "\nID invalido", 0, idEmployee, 2) == 0 && flagAlta==1)
				{
					auxiliarIndice = findEmployeeById(arrayEmployee, CANT_EMPLOYEE, auxiliarId);
					if(	auxiliarIndice >= 0 &&
						removeEmployee(arrayEmployee, CANT_EMPLOYEE, auxiliarIndice) == 0)
					{
						printf("\nBaja realizada con exito\n");
					}
				}else
				{
					printf("Primero debe dar de alta un empleado\n");
				}
				break;
			case 4:
				if(utn_getNumero(&auxiliarOrder, "\nIndique el orden para listar [1.Ascendente - 0.Desendente]\n", "\nNumero invalido", 0, 1, 2) == 0 && flagAlta==1)
				{
					sortEmployees(arrayEmployee, CANT_EMPLOYEE, auxiliarOrder);
					printEmployees(arrayEmployee, CANT_EMPLOYEE);
					Emp_CalculosSalario(arrayEmployee, CANT_EMPLOYEE);
					break;
				}else
				{
					printf("Primero debe dar de alta un empleado\n");
				}
			}
		}
	}while(opcion != 5);


	return EXIT_SUCCESS;
}









