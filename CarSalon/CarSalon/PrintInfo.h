#pragma once
#include <iostream>
#include "Sale.h"

void PrintEmployerInfo(FILE* EmployerFile, Employer* employers, int i);
void PrintCarInfo(FILE* CarsFile, Car* cars, int i);
void PrintSaleInfo(FILE* SalesFile, Sale* sales, int i);
void PrintCertainDateSales(FILE* SalesFile, Sale* sales, const int* SizeSales, Date date);
void PrintPeriodDateSales(FILE* SalesFile, Sale* sales, const int* SizeSales, Date firstdate, Date lastdate);
void PrintSalesIndividualEmployer(FILE* SalesFile, Sale* sales, const int* SizeSales, Employer& useremployer);
void PrintMostSalesCar(Sale* sales, const int* SizeSales, Date firstdate, Date lastdate, char** carmodels, const int* countmodels);
void PrintMostSuccessfulSeller(Sale* sales, const int* SizeSales, Employer* employers, const int* SizeEmployers, Date firstdate,
	Date lastdate);