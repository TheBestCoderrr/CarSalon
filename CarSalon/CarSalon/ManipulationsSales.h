#pragma once
#include "Sale.h"
void CopySales(FILE* SalesFile, Sale* sales, int i);
int FindSaleIndex(Sale* sales, const int SIZE, Sale& sale);
void AddSale(Sale* sales, int* SizeSales, Employer* employers, int* SizeEmployers, Car* cars, int* SizeCars, int ImployerIndex, 
	int CarIndex, int UserPrice);
void DeleteSale(Sale* sales, int* size, int index);
int FindSum(Sale* sales, const int* SizeSales, Date firstdate, Date lastdate);
void SaveSaleFile(FILE* SalesFile, Sale* sales, const int* SIZE);