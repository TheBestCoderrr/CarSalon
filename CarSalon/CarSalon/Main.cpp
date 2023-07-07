#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

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
	int a = 5, b = 0;
	int* SizeEmployers = &a;
	int* SizeCars = &a;
	int* SizeSales = &b;

	Employer* employers = new Employer[*SizeEmployers];
	Car* cars = new Car[*SizeCars];
	Sale* sales = new Sale[*SizeSales];

	Employer employer;
	Car car;
	Sale sale;
	Date firstdate, lastdate;
	int EmployerIndex, CarIndex, SaleIndex;
	int UserVariantMenu = -1, UserVariant, Sum, UserPrice;
	bool SuccessPurchase = false;
	
	SalesFile = fopen("G:\\Text\\CarSalon\\PrintInfo.txt", "w");
	if (SalesFile != NULL)
		fclose(SalesFile);

	EmployerFile = fopen("G:\\Text\\CarSalon\\Employers.txt", "r");
	if (EmployerFile != NULL) {
		for (int i = 0; i < *SizeEmployers; i++)
			CopyEmployer(EmployerFile, employers, i);
		fclose(EmployerFile);
	}
	CarFile = fopen("G:\\Text\\CarSalon\\Cars.txt", "r");
	if (CarFile != NULL) {
		for (int i = 0; i < *SizeCars; i++)
			CopyCar(CarFile, cars, i);
		fclose(CarFile);
	}

	bool ismodel = false;
	int* countmodels = &a;
	char** carsmodels = new char* [*countmodels];
	for (int i = 0; i < *countmodels; i++) {
		carsmodels[i] = new char[TEXTSIZE];
		strcpy_s(carsmodels[i], TEXTSIZE, cars[i].model);
	}

	cout << "0 - exit;\n1 - add;\n2 - delete;\n3 - Print info;\n4 - Buy car;\n5 - Save file;" << endl;
	while (UserVariantMenu != NULL) {
		cout << "Enter variant(menu):";
		cin >> UserVariantMenu;
		switch (UserVariantMenu) {
			case 0:
				cout << "Exit!" << endl;
				break;
			case 1:
				cout << "0 - cancel;\n1 - add employer;\n2 - add car;" << endl;
				cout << "Enter variant(add):";
				cin >> UserVariant;
				switch (UserVariant) {
					case 0:
						break;
					case 1:
						AddEmployer(employers, SizeEmployers);
						break;
					case 2:
						AddCar(cars, SizeEmployers);
						for (int i = 0; i < *countmodels; i++) {
							if (strcmp(carsmodels[i], cars[*SizeCars - 1].model) == 0) {
								ismodel = true;
								break;
							}
						}
						if (ismodel == false) {
							*countmodels += 1;
							carsmodels[*countmodels - 1] = new char[TEXTSIZE];
							strcpy_s(carsmodels[*countmodels - 1], TEXTSIZE, cars[*SizeCars - 1].model);
						}
						break;
					default:
						cout << "Invalid variant!" << endl;
						break;
				}
				break;
			case 2:
				cout << "0 - cancel;\n1 - delete employer;\n2 - delete car;\n3 - delete sale;" << endl;
				cout << "Enter variant(delete):";
				cin >> UserVariant;
				switch (UserVariant) {
					case 0:
						break;
					case 1:
						if (*SizeEmployers > 0) {
							cin.ignore();
							cout << "Enter firstname:";
							cin.getline(employer.firstname,TEXTSIZE);
							cout << "Enter lastname:";
							cin.getline(employer.lastname,TEXTSIZE);
							EmployerIndex = FindEmployerIndex(employers, *SizeEmployers, employer);
							if (EmployerIndex != -1)
								DeleteEmployer(employers, SizeEmployers, EmployerIndex);
							else
								cout << "Employer not find!" << endl;
						}
						else
							cout << "Employers not find!" << endl;
						break;
					case 2:
						if (*SizeCars > 0) {
							cin.ignore();
							cout << "Enter model:";
							cin.getline(car.model, TEXTSIZE);
							CarIndex = FindCarIndex(cars, *SizeCars, car);
							if(CarIndex != -1)
								DeleteCar(cars, SizeCars, CarIndex);
							else
								cout << "Car not find!" << endl;
						}
						else
							cout << "Cars not find!" << endl;
						break;
					case 3:
						if (*SizeSales > 0) {
							cin.ignore();
							cout << "Enter model:";
							cin.getline(sale.car.model, TEXTSIZE);
							SaleIndex = FindSaleIndex(sales, *SizeCars, sale);
							if (SaleIndex != -1)
								DeleteSale(sales, SizeSales, SaleIndex);
							else
								cout << "Sale not find!" << endl;
						}
						else
							cout << "Sales not find!" << endl;
						break;
					default:
						cout << "Invalid variant!" << endl;
						break;
				}
				break;
			case 3:
				cout << "0 - cancel;\n1 - print employers;\n2 - print cars;\n3 - print sales;\n4 - print sales certain date;\n" <<
					"5 - print sales period date;\n6 - print sales individual employer;\n7 - print most sale car;\n8 - print succsessful employer\n9 - print sum;" << endl;
				cout << "Enter variant(print):";
				cin >> UserVariant;
				switch (UserVariant) {
					case 0:
						break;
					case 1:
						EmployerFile = fopen("G:\\Text\\CarSalon\\PrintInfo.txt", "a");
						if (EmployerFile != NULL) {
							for (int i = 0; i < *SizeEmployers; i++)
								PrintEmployerInfo(EmployerFile, employers, i);
							fclose(EmployerFile);
						}
						break;
					case 2:
						CarFile = fopen("G:\\Text\\CarSalon\\PrintInfo.txt", "a");
						if (CarFile != NULL) {
							for (int i = 0; i < *SizeCars; i++)
								PrintCarInfo(CarFile, cars, i);
							fclose(CarFile);
						}
						break;
					case 3:
						SalesFile = fopen("G:\\Text\\CarSalon\\PrintInfo.txt", "a");
						if (SalesFile != NULL) {
							for (int i = 0; i < *SizeSales; i++)
								PrintSaleInfo(SalesFile, sales, i);
							fclose(SalesFile);
						}
						break;
					case 4:
						SalesFile = fopen("G:\\Text\\CarSalon\\PrintInfo.txt", "a");
						if (SalesFile != NULL) {
							cout << "Enter date(d/m/y): ";
							cin >> firstdate.day >> firstdate.month >> firstdate.year;
							PrintCertainDateSales(SalesFile, sales, SizeSales, firstdate);
							fclose(SalesFile);
						}
						break;
					case 5:
						SalesFile = fopen("G:\\Text\\CarSalon\\PrintInfo.txt", "a");
						if (SalesFile != NULL) {
							cout << "Enter first date(d/m/y): ";
							cin >> firstdate.day >> firstdate.month >> firstdate.year;
							cout << "Enter flast date(d/m/y): ";
							cin >> lastdate.day >> lastdate.month >> lastdate.year;
							PrintPeriodDateSales(SalesFile, sales, SizeSales, firstdate, lastdate);
							fclose(SalesFile);
						}
						break;
					case 6:
						SalesFile = fopen("G:\\Text\\CarSalon\\PrintInfo.txt", "a");
						if (SalesFile != NULL) {
							cout << "Enter firstname:";
							cin.getline(employer.firstname, TEXTSIZE);
							cout << "Enter lastname:";
							cin.getline(employer.lastname, TEXTSIZE);cin.ignore();
							cout << "Enter surname:";
							cin.getline(employer.surname, TEXTSIZE);
							PrintSalesIndividualEmployer(SalesFile, sales, SizeSales, employer);
							fclose(SalesFile);
						}
						break;
					case 7:
						SalesFile = fopen("G:\\Text\\CarSalon\\PrintInfo.txt", "a");
						if (SalesFile != NULL) {
							cout << "Enter first date(d/m/y): ";
							cin >> firstdate.day >> firstdate.month >> firstdate.year;
							cout << "Enter flast date(d/m/y): ";
							cin >> lastdate.day >> lastdate.month >> lastdate.year;
							PrintMostSalesCar(sales, SizeSales, firstdate, lastdate, carsmodels, countmodels);
							fclose(SalesFile);
						}
						break;
					case 8:
						SalesFile = fopen("G:\\Text\\CarSalon\\PrintInfo.txt", "a");
						if (SalesFile != NULL) {
							cout << "Enter first date(d/m/y): ";
							cin >> firstdate.day >> firstdate.month >> firstdate.year;
							cout << "Enter flast date(d/m/y): ";
							cin >> lastdate.day >> lastdate.month >> lastdate.year;
							PrintMostSuccessfulSeller(sales, SizeSales, employers, SizeEmployers,firstdate, lastdate);
							fclose(SalesFile);
						}
						break;
					case 9:
						cout << "Enter first date(d/m/y): ";
						cin >> firstdate.day >> firstdate.month >> firstdate.year;
						cout << "Enter flast date(d/m/y): ";
						cin >> lastdate.day >> lastdate.month >> lastdate.year;
						Sum = FindSum(sales, SizeSales, firstdate, lastdate);
						cout << "Sum = " << Sum << endl;
						break;
					default:
						cout << "Invalid variant!" << endl;
						break;
				}
				break;
			case 4:
				cin.ignore();
				cout << "Enter model:";
				cin.getline(car.model, TEXTSIZE);
				CarIndex = FindCarIndex(cars, *SizeCars, car);
				cout << "Enter firstname:";
				cin.getline(employer.firstname, TEXTSIZE);
				cout << "Enter lastname:";
				cin.getline(employer.lastname, TEXTSIZE);
				EmployerIndex = FindEmployerIndex(employers, *SizeEmployers, employer);
				cout << "Enter price:";
				cin >> UserPrice;
				cout << "seller enter variant:\n1 - Yes/ 0 - No:";
				cin >> SuccessPurchase;
				if(EmployerIndex != -1 && CarIndex != -1 && SuccessPurchase)
					AddSale(sales, SizeSales, employers, SizeEmployers, cars, SizeCars, EmployerIndex, CarIndex, UserPrice);
				break;
			case 5:
				EmployerFile = fopen("G:\\Text\\CarSalon\\Employers.txt", "w");
				if (EmployerFile != NULL) {
					SaveEmployerFile(EmployerFile, employers, SizeEmployers);
					fclose(EmployerFile);
				}
				CarFile = fopen("G:\\Text\\CarSalon\\Cars.txt", "w");
				if (CarFile != NULL) {
					SaveCarFile(CarFile, cars, SizeCars);
					fclose(CarFile);
				}
				SalesFile = fopen("G:\\Text\\CarSalon\\Sales.txt", "w");
				if (SalesFile != NULL) {
					SaveSaleFile(SalesFile, sales, SizeSales);
					fclose(SalesFile);
				}
				break;
			default:
				cout << "Invalid variant!" << endl;
				break;
		}
	}

	if(employers != nullptr)
		delete[] employers;
	if(cars != nullptr)
		delete[] cars;
	if(sales != nullptr)
		delete[] sales;
	delete[] carsmodels;
}