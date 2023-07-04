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
		cout << "Email: " << employers[i].email << endl;
	}
}

void PrintCarsInfo(Car* cars, int* size) {
	for (int i = 0; i < *size; i++) {
		cout << "Car " << i+1 <<": " << endl;
		cout << "Producer: " << cars[i].producer << endl;
		cout << "Model: " << cars[i].model << endl;
		cout << "Year production: " << cars[i].YearProduction << endl;
		cout << "Price: " << cars[i].price << endl;
		cout << "Potential price: " << cars[i].PotentialPrice << endl;
	}
}

void PrintSalesInfo(Car* cars, int* size) {
	for (int i = 0; i < *size; i++) {
		cout << "Car " << i+1 <<": " << endl;
		cout << "Producer: " << cars[i].producer << endl;
		cout << "Model: " << cars[i].model << endl;
		cout << "Year production: " << cars[i].YearProduction << endl;
		cout << "Price: " << cars[i].price << endl;
		cout << "Potential price: " << cars[i].PotentialPrice << endl;
	}
}