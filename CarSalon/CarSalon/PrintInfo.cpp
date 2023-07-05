#include <iostream>
#include <string.h>
#include "Sale.h"
#include "Consts.h"

using namespace std;

void PrintEmployersInfo(Employer* employers, int* size) {
	for (int i = 0; i < *size; i++) {
		cout << "Employer " << i + 1 << ": " << endl;
		cout << "PIB: " << employers[i].firstname << ' ' << employers[i].lastname << ' ' << employers[i].surname << endl;
		cout << "Position: " << employers[i].position << endl;
		cout << "Contact: " << employers[i].contact << endl;
		cout << "Email: " << employers[i].email << endl << endl;
	}
}

void PrintCarsInfo(Car* cars, int* size) {
	for (int i = 0; i < *size; i++) {
		cout << "Car " << i+1 <<": " << endl;
		cout << "Producer: " << cars[i].producer << endl;
		cout << "Model: " << cars[i].model << endl;
		cout << "Year production: " << cars[i].YearProduction << endl;
		cout << "Price: " << cars[i].price << endl;
		cout << "Potential price: " << cars[i].PotentialPrice << endl << endl;
	}
}

void PrintSalesInfo(Sale* sales, int* size) {
	for (int i = 0; i < *size; i++) {
		cout << "Sale " << i + 1 << ": " << endl;

		cout << "Employer " << i + 1 << ": " << endl;
		cout << "PIB: " << sales[i].employer.firstname << ' ' << sales[i].employer.lastname << ' ' << sales[i].employer.surname << endl;
		cout << "Position: " << sales[i].employer.position << endl;
		cout << "Contact: " << sales[i].employer.contact << endl;
		cout << "Email: " << sales[i].employer.email << endl;

		cout << "Car " << i + 1 << ": " << endl;
		cout << "Producer: " << sales[i].car.producer << endl;
		cout << "Model: " << sales[i].car.model << endl;
		cout << "Year production: " << sales[i].car.YearProduction << endl;
		cout << "Price: " << sales[i].car.price << endl;
		cout << "Potential price: " << sales[i].car.PotentialPrice << endl;

		cout << "Date(d/m/y): ";
		cout << sales[i].datesale.day << ' ' << sales[i].datesale.month<< ' ' << sales[i].datesale.year << endl;
		cout << "Real price: " << sales[i].RealPrice << endl << endl;
	}
}