#pragma once
#include "Car.h"

int FindCarIndex(Car* cars, const int SIZE, Car& car);
void AddCar(Car* cars, int* size);
void DeleteCar(Car* cars, int* size, int index);