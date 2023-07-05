#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "Employer.h"
#include "Car.h"
#include "Sale.h"

#include "ManipulationsEmployer.h"
#include "ManipulationsCar.h"
#include "ManipulationsSales.h"
#include "PrintInfo.h"

using namespace std;

int main() {
	FILE* EmployerFile, * CarFile, * SalesFile;
	int a = 1, b = 2;
	int* SizeEmployers = &b;
	int* SizeCars = &b;
	int* SizeSales = &a;

	Employer* employers = new Employer[*SizeEmployers];
	Car* cars = new Car[*SizeCars];
	Sale* sales = new Sale[*SizeSales];
}