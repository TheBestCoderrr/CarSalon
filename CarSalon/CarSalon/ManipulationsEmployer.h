#pragma once
#include "Employer.h"
int FindEmployerIndex(Employer* employers, const int SIZE, Employer& employer);
void AddEmployer(Employer* employers, int* size);
void DeleteEmployer(Employer* employers, int* size, int index);