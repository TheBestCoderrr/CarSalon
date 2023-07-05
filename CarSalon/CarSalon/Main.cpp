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
	int a = 0, b = 2;
	int* SizeEmployers = &b;
	int* SizeCars = &b;
	int* SizeSales = &a;

	Employer* employers = new Employer[*SizeEmployers];
	Car* cars = new Car[*SizeCars];
	Sale* sales = new Sale[*SizeSales];

	EmployerFile = fopen("G:\\Text\\CarSalon\\Employers.txt", "r");

	if (EmployerFile != NULL) {
		for(int i = 0; i < *SizeEmployers; i++)
			CopyEmployer(EmployerFile, employers, i);
		fclose(EmployerFile);
	}
	PrintEmployersInfo(employers, SizeEmployers);

	CarFile = fopen("G:\\Text\\CarSalon\\Cars.txt", "r");

	if (CarFile != NULL) {
		for (int i = 0; i < *SizeCars; i++)
			CopyCar(CarFile, cars, i);
		fclose(CarFile);
	}
	PrintCarsInfo(cars, SizeCars);
}