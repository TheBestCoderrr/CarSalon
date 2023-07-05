#include <iostream>
#include <string.h>
#include "Sale.h"
#include "Consts.h"

using namespace std;

void PrintEmployerInfo(FILE* EmployersFile, Employer* employers, int i) {
	fprintf(EmployersFile, "Employer %i:\n", i + 1);
	fprintf(EmployersFile, "PIB: %s %s %s\n", employers[i].firstname, employers[i].lastname, employers[i].surname);
	fprintf(EmployersFile, "Position: %s \n", employers[i].position);
	fprintf(EmployersFile, "Contact: %s \n", employers[i].contact);
	fprintf(EmployersFile, "Email: %s \n", employers[i].email);
}

void PrintCarInfo(FILE* CarsFile, Car* cars, int i) {
	fprintf(CarsFile, "Car %i:\n", i + 1);
	fprintf(CarsFile, "Producer: %s\n", cars[i].producer);
	fprintf(CarsFile, "Model: %s\n", cars[i].model);
	fprintf(CarsFile, "Year production: %i\n", cars[i].YearProduction);
	fprintf(CarsFile, "Price: %i\n", cars[i].price);
	fprintf(CarsFile, "Potential price: %i\n", cars[i].PotentialPrice);
}

void PrintSaleInfo(FILE* SalesFile, Sale* sales, int i) {
	fprintf(SalesFile, "Sale %i:\n Employer:\n", i + 1);
	fprintf(SalesFile, "PIB: %s %s %s\n", sales[i].employer.firstname, sales[i].employer.lastname, sales[i].employer.surname);
	fprintf(SalesFile, "Position: %s\n", sales[i].employer.position);
	fprintf(SalesFile, "Contact: %s\n", sales[i].employer.position);
	fprintf(SalesFile, "Email: %s\n Car:\n", sales[i].employer.email);
	fprintf(SalesFile, "Producer: %s\n", sales[i].car.producer);
	fprintf(SalesFile, "Model: %s\n", sales[i].car.model);
	fprintf(SalesFile, "Year production: %i\n", sales[i].car.YearProduction);
	fprintf(SalesFile, "Price: %i\n", sales[i].car.price);
	fprintf(SalesFile, "Potential price: %i\n", sales[i].car.PotentialPrice);
	fprintf(SalesFile, "Date(d/m/y): %i %i %i\n", sales[i].datesale.day, sales[i].datesale.month, sales[i].datesale.year);
	fprintf(SalesFile, "Real price: %i\n", sales[i].RealPrice);
}

void PrintCertainDateSales(FILE* SalesFile, Sale* sales,const int* SizeSales, Date date) {
	for (int i = 0; i < *SizeSales; i++) {
		if (sales[i].datesale.day == date.day && sales[i].datesale.month == date.month && sales[i].datesale.year == date.year)
			PrintSaleInfo(SalesFile, sales, i);
	}
}

void PrintPeriodDateSales(FILE* SalesFile, Sale* sales,const int* SizeSales, Date firstdate, Date lastdate) {
	for (int i = 0; i < *SizeSales; i++) {
		if (sales[i].datesale.day >= firstdate.day && sales[i].datesale.month >= firstdate.month && sales[i].datesale.year >= firstdate.year 
			&& sales[i].datesale.day <= lastdate.day && sales[i].datesale.month <= lastdate.month && sales[i].datesale.year <= lastdate.year)
			PrintSaleInfo(SalesFile, sales, i);
	}
}

void PrintSalesCertainEmployer(FILE* SalesFile, Sale* sales, const int* SizeSales, Employer& useremployer) {
	for (int i = 0; i < *SizeSales; i++) {
		if(strcmp(useremployer.firstname, sales[i].employer.firstname) == 0 && 
			strcmp(useremployer.lastname, sales[i].employer.lastname) == 0 && 
			strcmp(useremployer.surname, sales[i].employer.surname) == 0)
			PrintSaleInfo(SalesFile, sales, i);
	}
}

void PrintMostSalesCar(Sale* sales, const int* SizeSales, Date firstdate, Date lastdate) {
	char modelcar[TEXTSIZE];
	char modelcar2[TEXTSIZE];
	for (int i = 0; i < *SizeSales - 1; i++) {
		if (sales[i].datesale.day >= firstdate.day && sales[i].datesale.month >= firstdate.month && sales[i].datesale.year >= firstdate.year
			&& sales[i].datesale.day <= lastdate.day && sales[i].datesale.month <= lastdate.month && sales[i].datesale.year <= lastdate.year) {
			strcpy_s(modelcar, sales[i].car.model);
			strcpy_s(modelcar2, sales[i + 1].car.model);
		}	
	}
}