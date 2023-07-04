#include <iostream>
#include <string.h>
#include "Employer.h"
#include "Consts.h"

using namespace std;

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
	cin >> employers[*size - 1].contact;
	cout << "Enter email: ";
	cin.ignore();
	cin.getline(employers[*size - 1].email, TEXTSIZE);
}

void DeleteEmployer(Employer* employers, int* size, int index) {
	for (int i = index; i < *size - 1; i++)
		employers[i] = employers[i + 1];
	*size -= 1;
}
