#pragma once
#include <iostream>
#include "Sale.h"

void PrintEmployersInfo(FILE* EmployerFile, Employer* employers, int i);
void PrintCarsInfo(FILE* CarsFile, Car* cars, int i);
void PrintSalesInfo(FILE* SalesFile, Sale* sales, int i);
void PrintCertainDateSales(FILE* SalesFile, Sale* sales, const int* SizeSales, Date date);
void PrintPeriodDateSales(FILE* SalesFile, Sale* sales, const int* SizeSales, Date firstdate, Date lastdate);
void PrintSalesCertainEmployer(FILE* SalesFile, Sale* sales, const int* SizeSales, Employer& useremployer);
void PrintMostSalesCar(Sale* sales, const int* SizeSales, Date firstdate, Date lastdate);