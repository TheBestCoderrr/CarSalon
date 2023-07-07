#include <iostream>
#include <string.h>
#include "Sale.h"
#include "Consts.h"

#include "ManipulationsEmployer.h"
#include "ManipulationsCar.h"
#include "PrintInfo.h"

using namespace std;

void CopySales(FILE* SalesFile, Sale* sales, int i) {
	char str[TEXTSIZE];

	fgets(str, TEXTSIZE, SalesFile);
	fgets(str, TEXTSIZE, SalesFile);
	fgets(str, TEXTSIZE, SalesFile);
	strcpy_s(sales[i].employer.firstname, TEXTSIZE, str);
	sales[i].employer.firstname[strlen(sales[i].employer.firstname) - 1] = '\0';
	fgets(str, TEXTSIZE, SalesFile);
	strcpy_s(sales[i].employer.lastname, TEXTSIZE, str);
	sales[i].employer.lastname[strlen(sales[i].employer.lastname) - 1] = '\0';
	fgets(str, TEXTSIZE, SalesFile);
	strcpy_s(sales[i].employer.surname, TEXTSIZE, str);
	sales[i].employer.surname[strlen(sales[i].employer.surname) - 1] = '\0';
	fgets(str, TEXTSIZE, SalesFile);
	strcpy_s(sales[i].employer.position, TEXTSIZE, str);
	sales[i].employer.position[strlen(sales[i].employer.position) - 1] = '\0';
	fgets(str, TEXTSIZE, SalesFile);
	strcpy_s(sales[i].employer.contact, TEXTSIZE, str);
	sales[i].employer.contact[strlen(sales[i].employer.contact) - 1] = '\0';
	fgets(str, TEXTSIZE, SalesFile);
	strcpy_s(sales[i].employer.email, TEXTSIZE, str);
	sales[i].employer.email[strlen(sales[i].employer.email) - 1] = '\0';

	fgets(str, TEXTSIZE, SalesFile);
	fgets(str, TEXTSIZE, SalesFile);
	strcpy_s(sales[i].car.producer, TEXTSIZE, str);
	sales[i].car.producer[strlen(sales[i].car.producer) - 1] = '\0';

	fgets(str, TEXTSIZE, SalesFile);
	sales[i].car.YearProduction = 0;
	for (int j = 0; j < strlen(str) - 1; j++) {
		sales[i].car.YearProduction *= 10;
		sales[i].car.YearProduction += str[j] - '0';
	}

	fgets(str, TEXTSIZE, SalesFile);
	strcpy_s(sales[i].car.model, TEXTSIZE, str);
	sales[i].car.model[strlen(sales[i].car.model) - 1] = '\0';

	fgets(str, TEXTSIZE, SalesFile);
	sales[i].car.price = 0;
	for (int j = 0; j < strlen(str) - 1; j++) {
		sales[i].car.price *= 10;
		sales[i].car.price += str[j] - '0';
	}

	fgets(str, TEXTSIZE, SalesFile);
	sales[i].car.PotentialPrice = 0;
	for (int j = 0; j < strlen(str)-1; j++) {
		sales[i].car.PotentialPrice *= 10;
		sales[i].car.PotentialPrice += str[j] - '0';
	}
	
	fgets(str, TEXTSIZE, SalesFile);
	sales[i].datesale.day = 0;
	int n = 0;
	for (; str[n] != '.'; n++) {
		sales[i].datesale.day *= 10;
		sales[i].datesale.day += str[n] - '0';
	}
	sales[i].datesale.month = 0;
	for (n++; str[n] != '.'; n++) {
		sales[i].datesale.month *= 10;
		sales[i].datesale.month += str[n] - '0';
	}
	sales[i].datesale.year = 0;
	for (n++; str[n] != '\0' &&  str[n] != '\n'; n++) {
		sales[i].datesale.year *= 10;
		sales[i].datesale.year += str[n] - '0';
	}

	fgets(str, TEXTSIZE, SalesFile);
	int size;
	str[strlen(str) - 1] == '\n' ? size = strlen(str) - 1 : size = strlen(str);
	sales[i].RealPrice = 0;
	for (int j = 0; j < size; j++) {
		sales[i].RealPrice *= 10;
		sales[i].RealPrice += str[j] - '0';
	}
}

int FindSaleIndex(Sale* sales, const int SIZE, Sale& sale) {
	for (int i = 0; i < SIZE; i++) {
		if (strcmp(sales[i].car.model, sale.car.model) == 0)
			return i;
	}
	return -1;
}

void AddSale(Sale* sales, int* SizeSales, Employer* employers, int* SizeEmployers, Car* cars , int* SizeCars, int EmployerIndex, 
	int CarIndex, int UserPrice) {
	*SizeSales += 1;

	sales[*SizeSales - 1].employer = employers[EmployerIndex];
	DeleteEmployer(employers, SizeEmployers, EmployerIndex);
	sales[*SizeSales - 1].car = cars[CarIndex];
	DeleteCar(cars, SizeCars, CarIndex);
	cout << "Enter Date(d/m/y): ";
	cin >> sales[*SizeSales - 1].datesale.day;
	cin >> sales[*SizeSales - 1].datesale.month;
	cin >> sales[*SizeSales - 1].datesale.year;
	sales[*SizeSales - 1].RealPrice = UserPrice;
}

void DeleteSale(Sale* sales, int* size, int index) {
	for (int i = index; i < *size - 1; i++)
		sales[i] = sales[i + 1];
	*size -= 1;
}

int FindSum(Sale* sales, const int* SizeSales, Date firstdate, Date lastdate) {
	int Sum = 0;
	for (int i = 0; i < *SizeSales; i++) {
		if (sales[i].datesale.day >= firstdate.day && sales[i].datesale.month >= firstdate.month && sales[i].datesale.year >= firstdate.year
			&& sales[i].datesale.day <= lastdate.day && sales[i].datesale.month <= lastdate.month && sales[i].datesale.year <= lastdate.year) {
			Sum += sales[i].RealPrice - sales[i].car.price;
		}	
	}
	return Sum;
}

void SaveSaleFile(FILE* SalesFile, Sale* sales, const int* SIZE) {
	for (int i = 0; i < *SIZE; i++)
		PrintSaleInfo(SalesFile, sales, i);
}