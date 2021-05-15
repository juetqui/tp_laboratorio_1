/*
 * ArrayEmployees.h
 *
 *  Created on: 12 May 2021
 *      Author: julian
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define LENEMPLOYEE 51

typedef struct
{
	int id;
	char name[LENEMPLOYEE];
	char lastName[LENEMPLOYEE];
	float salary;
	int sector;
	int isEmpty;
}Employee;

int initEmployees(Employee* list, int len);

int addEmployee(Employee* list, int len, int indice, int* id);

int findEmployeeById(Employee* list, int len,int id);

int removeEmployee(Employee* list, int len, int id);

int sortEmployees(Employee* list, int len, int order);

int printEmployees(Employee* list, int length);

int print(Employee* pList);

int Emp_getEmptyIndex(Employee* array,int limite);

int Emp_modificarArray(Employee* array, int limite, int indice);

int Emp_CalculosSalario(Employee* array, int limite);

#endif /* ARRAYEMPLOYEES_H_ */
