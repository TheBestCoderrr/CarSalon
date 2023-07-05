#pragma once
#include <iostream>
#include "Car.h"

void CopyCar(FILE* CarFile, Car* cars, int i);
int FindCarIndex(Car* cars, const int SIZE, Car& car);
void AddCar(Car* cars, int* size);
void DeleteCar(Car* cars, int* size, int index);
void SaveCarFile(FILE* CarFile, Car* cars, const int* SIZE);