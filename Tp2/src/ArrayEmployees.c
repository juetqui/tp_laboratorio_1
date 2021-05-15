/*
 * ArrayEmployees.c
 *
 *  Created on: 12 May 2021
 *      Author: julian
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len)
{
	int retorno=-1;
	int i;

	if(list != NULL && len > 0)
	{
		retorno = 0;
		for(i=0; i<len;i++)
		{
			list[i].isEmpty = 1;
		}
	}
	return retorno;
}

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
*		free space] - (0) if Ok
 */
int addEmployee(Employee* list, int len, int indice, int* id)
{
	int retorno = -1;
	Employee bufferEmployee;

	if(list != NULL && len > 0 && indice < len && indice >= 0 && id != NULL)
	{
		if( utn_getNombre(bufferEmployee.name, LENEMPLOYEE, "\nIngrese el nombre del empleado: \n", "No!\n", 2)==0 &&
			utn_getNombre(bufferEmployee.lastName, LENEMPLOYEE, "\nIngrese el apellido del empleado: \n", "No!\n", 2)==0 &&
			utn_getNumeroFlotante(&bufferEmployee.salary,"\nIngrese el salario del empleado: \n", "No!\n",0,10000000,2)==0 &&
			utn_getNumero(&bufferEmployee.sector,"\nIngrese el sector del empleado: \n", "No!\n",0,100,2)==0 )
		{
			retorno = 0;
			bufferEmployee.id = *id;
			bufferEmployee.isEmpty = 0;
			list[indice]=bufferEmployee;
			*id = *id + 1;
		}
	}
	return retorno;
}

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id)
{
	int retorno=-1;
	int i;

	if(list != NULL && len > 0 && id >=0)
	{
		retorno = 0;
		for(i=0; i<len;i++)
		{
			if(list[i].id == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id)
{
	int retorno = -1;
	if(list != NULL && len > 0 && id < len && id >= 0 && list[id].isEmpty == 0)
	{
		list[id].isEmpty = 1;
		retorno = 0;
	}
	return retorno;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order) //HAY QUE VER EL TEMA DEL ORDEN
{
	int respuesta = -1;
	int flagSwap;
	int i;
	int j;
	Employee buffer;
	int auxiliar;

	if(list != NULL && len > 0)
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<len-1;i++)
			{
				if(list[i].isEmpty || list[i+1].isEmpty)
				{
					continue;
				}
				if(order == 1)
				{
					for(i=0;i<len;i++)
					{
						for(j=i+1; j<len;j++)
						{
							auxiliar = strncmp(list[i].lastName, list[j].lastName, LENEMPLOYEE);
							if(auxiliar<0 || (auxiliar == 0  && list[i].sector < list[j].sector))
							{
								flagSwap = 1;
								buffer = list[i];
								list[i] = list[j];
								list[j] = buffer;
								respuesta = 0;
							}
						}
					}
				}
				else if (order == 0)
				{
					for(i=0;i<len;i++)
					{
						for(int j=i+1; j<len;j++)
						{
							auxiliar = strncmp(list[i].lastName, list[j].lastName, LENEMPLOYEE);
							if(auxiliar==1 || (auxiliar == 0  && list[i].sector > list[j].sector))
							{
								flagSwap = 1;
								buffer = list[i];
								list[i] = list[j];
								list[j] = buffer;
								respuesta = 0;
							}
						}
					}
				}
			}
			len--;
		}while(flagSwap);
	}
	return respuesta;
}

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int length)
{
	int retorno=-1;
	int i;

	if(list != NULL && length > 0)
	{
		retorno = 0;
		for(i=0; i<length;i++)
		{
			print(&list[i]);
		}
	}
	return retorno;
}

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int print(Employee* pList)
{
	int retorno=-1;

	if(pList != NULL && pList ->isEmpty == 0)
	{
		retorno=0;
		printf("\nID: %d - %s - %s - Salario: %f - Sector: %d\n", 	pList->id,
																	pList->name,
																	pList->lastName,
																	pList->salary,
																	pList->sector);
	}
	return retorno;
}

/**
 * \brief Buscar primer posicion vacia
 * \param array array de clientes a ser actualizado
 * \param limite limite del array de productos
 * \return Retorna el indice de la posicion vacia y -1 (ERROR)
 */
int Emp_getEmptyIndex(Employee* array,int limite)
{
	int retorno=-1;
	int i;

	if(array != NULL && limite > 0)
	{
		for(i=0; i<limite;i++)
		{
			if(array[i].isEmpty == 1)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Actualiza los datos de un cliente en una posicion del array
 * \param Array array de clientes a ser actualizado
 * \param limite limite del array de clientes
 * \param indice posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int Emp_modificarArray(Employee* array, int limite, int indice)
{
	int retorno = -1;
	Employee bufferEmployee;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		if( utn_getNombre(bufferEmployee.name, LENEMPLOYEE, "\nIngrese el nombre del empleado: \n", "No!\n", 2)==0 &&
			utn_getNombre(bufferEmployee.lastName, LENEMPLOYEE, "\nIngrese el apellido del empleado: \n", "No!\n", 2)==0 &&
			utn_getNumeroFlotante(&bufferEmployee.salary,"\nIngrese el salario del empleado: \n", "No!\n",0,10000000,2)==0 &&
			utn_getNumero(&bufferEmployee.sector,"\nIngrese el sector del empleado: \n", "No!\n",0,100,2)==0 )
		{
			retorno = 0;
			bufferEmployee.id = array[indice].id;
			bufferEmployee.isEmpty = 0;
			array[indice]=bufferEmployee;
		}
	}
	return retorno;
}

/**
 * \brief Calcula el salario total y su promedio, y cuantos empleados superan ese promedio
 * \param array array de clientes a ser actualizado
 * \param limite limite del array de productos
 * \return Retorna el indice de la posicion vacia y -1 (ERROR)
 */
int Emp_CalculosSalario(Employee* array, int limite)
{
	int retorno = -1;
	float totalSalarios=0;
	float promedioSalarios=0;
	int cantSalarios=0;
	int contadorEmpleado=0;
	int i;

	if(array != NULL && limite > 0)
		{
			for(i=0; i<limite;i++)
			{
				if(array[i].isEmpty == 0)
				{
					totalSalarios=totalSalarios+array[i].salary;
					cantSalarios++;
				}
			}

			promedioSalarios= totalSalarios/cantSalarios;

			for(i=0; i<limite;i++)
			{
				if(array[i].isEmpty == 0)
				{
					if(promedioSalarios<array[i].salary)
					{
						contadorEmpleado++;
					}
				}
			}
			retorno=0;
			printf("\nEl total del salario es: %f"
					"\nEl promedio de los salarios es: %f\n"
					"\n la cantidad de empleados que superan el salario promedio es: %d\n"
					,totalSalarios,promedioSalarios, contadorEmpleado);
		}
	return retorno;
}



