#include <iostream>
#include <string.h>
#include "Car.h"
#include "Consts.h"

using namespace std;

void CopyCar(FILE* CarFile, Car* cars, int i) {
	char str[TEXTSIZE];
	fgets(str, TEXTSIZE, CarFile);
	fgets(str, TEXTSIZE, CarFile);
	strcpy_s(cars[i].producer, TEXTSIZE, str);
	cars[i].producer[strlen(cars[i].producer) - 1] = '\0';

	fgets(str, TEXTSIZE, CarFile);
	cars[i].YearProduction = 0;
	for (int j = 0; j < strlen(str) - 1; j++) {
		cars[i].YearProduction *= 10;
		cars[i].YearProduction += str[j] - '0';
	}

	fgets(str, TEXTSIZE, CarFile);
	strcpy_s(cars[i].model, TEXTSIZE, str);
	cars[i].model[strlen(cars[i].model) - 1] = '\0';

	fgets(str, TEXTSIZE, CarFile);
	cars[i].price = 0;
	for (int j = 0; j < strlen(str) - 1; j++) {
		cars[i].price *= 10;
		cars[i].price += str[j] - '0';
	}
	
	fgets(str, TEXTSIZE, CarFile);
	int size;
	str[strlen(str) - 1] == '\n' ? size = strlen(str) - 1 : size = strlen(str);
	cars[i].PotentialPrice = 0;
	for (int j = 0; j < size; j++) {
		cars[i].PotentialPrice *= 10;
		cars[i].PotentialPrice += str[j] - '0';
	}
}

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