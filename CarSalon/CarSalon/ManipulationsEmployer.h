#pragma once
#include <iostream>
#include "Employer.h"
void CopyEmployer(FILE* EmployerFile, Employer* employers, int i);
int FindEmployerIndex(Employer* employers, const int SIZE, Employer& employer);
void AddEmployer(Employer* employers, int* size);
void DeleteEmployer(Employer* employers, int* size, int index);
void SaveEmployerFile(FILE* EmployerFile, Employer* employers, const int* SIZE);