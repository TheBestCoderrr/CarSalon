#include <iostream>
#include <string.h>
#include "Employer.h"
#include "Consts.h"

#include "PrintInfo.h"

using namespace std;

void CopyEmployer(FILE* EmployerFile, Employer* employers, int i) {
	char str[TEXTSIZE];
	fgets(str, TEXTSIZE, EmployerFile);
	fgets(str, TEXTSIZE, EmployerFile);
	strcpy_s(employers[i].firstname, TEXTSIZE, str);
	employers[i].firstname[strlen(employers[i].firstname) - 1] = '\0';
	fgets(str, TEXTSIZE, EmployerFile);
	strcpy_s(employers[i].lastname, TEXTSIZE, str);
	employers[i].lastname[strlen(employers[i].lastname) - 1] = '\0';
	fgets(str, TEXTSIZE, EmployerFile);
	strcpy_s(employers[i].surname, TEXTSIZE, str);
	employers[i].surname[strlen(employers[i].surname) - 1] = '\0';
	fgets(str, TEXTSIZE, EmployerFile);
	strcpy_s(employers[i].position, TEXTSIZE, str);
	employers[i].position[strlen(employers[i].position) - 1] = '\0';
	fgets(str, TEXTSIZE, EmployerFile);
	strcpy_s(employers[i].contact, TEXTSIZE, str);
	employers[i].contact[strlen(employers[i].contact) - 1] = '\0';
	fgets(str, TEXTSIZE, EmployerFile);
	strcpy_s(employers[i].email, TEXTSIZE, str);
	employers[i].email[strlen(employers[i].email) - 1] = '\0';
}

int FindEmployerIndex(Employer* employers, const int SIZE, Employer& employer) {
	for (int i = 0; i < SIZE; i++) {
		if (strcmp(employers[i].firstname, employer.firstname) == 0 && strcmp(employers[i].lastname, employer.lastname) == 0)
			return i;
	}
	return -1;
}

void AddEmployer(Employer* employers, int* size) {
	*size += 1;
	
	cout << "Enter first name: ";
	cin.getline(employers[*size - 1].firstname, TEXTSIZE);
	cout << "Enter last name: ";
	cin.getline(employers[*size - 1].lastname, TEXTSIZE);
	cout << "Enter Surname: ";
	cin.getline(employers[*size - 1].surname, TEXTSIZE);
	cout << "Enter position: ";
	cin.getline(employers[*size - 1].position, TEXTSIZE);
	cout << "Enter contact: ";
	cin.getline(employers[*size - 1].contact, TEXTSIZE);
	cout << "Enter email: ";
	cin.getline(employers[*size - 1].email, TEXTSIZE);
}

void DeleteEmployer(Employer* employers, int* size, int index) {
	for (int i = index; i < *size - 1; i++)
		employers[i] = employers[i + 1];
	*size -= 1;
}

void SaveEmployerFile(FILE* EmployerFile, Employer* employers, const int* SIZE) {
	EmployerFile = fopen("G:\\Text\\CarSalon\\Employers.txt", "w");
	if (EmployerFile != NULL) {
		for (int i = 0; i < *SIZE; i++)
			PrintEmployerInfo(EmployerFile, employers, i);
		fclose(EmployerFile);
	}
}
