#include <iostream>
#include <string.h>
#include "Car.h"
#include "Consts.h"

using namespace std;

int FindCarIndex(Car* cars, const int SIZE, Car& car) {
	for (int i = 0; i < SIZE; i++) {
		if (strcmp(cars[i].producer, car.producer) == 0)
			return i;
	}
	return -1;
}

void AddCar(Car* cars, int* size) {
	*size += 1;

	cout << "Enter producer: ";
	cin.getline(cars[*size - 1].producer, TEXTSIZE);
	cout << "Enter year production: ";
	cin >> cars[*size - 1].YearProduction;
	cout << "Enter model: ";
	cin.getline(cars[*size - 1].model, TEXTSIZE);
	cout << "Enter price: ";
	cin >> cars[*size - 1].price;
	cout << "Enter potential price: ";
	cin >> cars[*size - 1].PotentialPrice;
}

void DeleteCar(Car* cars, int* size, int index) {
	for (int i = index; i < *size - 1; i++)
		cars[i] = cars[i + 1];
	*size -= 1;
}