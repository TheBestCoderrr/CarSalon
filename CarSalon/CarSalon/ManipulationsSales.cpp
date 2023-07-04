#include <iostream>
#include <string.h>
#include "Sale.h"
#include "Consts.h"

#include "ManipulationsEmployer.h"
#include "ManipulationsCar.h"

using namespace std;

int FindSaleIndex(Sale* sales, const int SIZE, Sale& sale) {
	for (int i = 0; i < SIZE; i++) {
		if (strcmp(sales[i].car.model, sale.car.model) == 0)
			return i;
	}
	return -1;
}

void AddSale(Sale* sales, int* SizeSales, Employer* employers, int* SizeEmployers, Car* cars , int* SizeCars, int ImployerIndex, 
	int CarIndex) {
	*SizeSales += 1;

	sales[*SizeSales - 1].employee = employers[ImployerIndex];
	DeleteEmployer(employers, SizeEmployers, ImployerIndex);
	sales[*SizeSales - 1].car = cars[CarIndex];
	DeleteCar(cars, SizeCars, CarIndex);
	cout << "Enter Date(d/m/y): ";
	cin >> sales[*SizeSales - 1].datesale.day;
	cin >> sales[*SizeSales - 1].datesale.month;
	cin >> sales[*SizeSales - 1].datesale.year;
	cout << "Enter real price: ";
	cin >> sales[*SizeSales - 1].RealPrice;
}

void DeleteSale(Sale* sales, int* size, int index) {
	for (int i = index; i < *size - 1; i++)
		sales[i] = sales[i + 1];
	*size -= 1;
}