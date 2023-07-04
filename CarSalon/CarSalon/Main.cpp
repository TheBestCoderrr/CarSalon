#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "Employer.h"
#include "Car.h"
#include "Sale.h"

#include "ManipulationsEmployer.h"
#include "ManipulationsCar.h"
#include "ManipulationsSales.h"

using namespace std;

int main() {
	FILE* EmployerFile, * CarFile, * SalesFile;
	int a = 0;
	int* SizeEmployers = &a;
	int* SizeCars = &a;
	int* SizeSales = &a;

	Employer* employers = new Employer[*SizeEmployers];
	Car* cars = new Car[*SizeCars];
	Sale* sales = new Sale[*SizeSales];

	
}