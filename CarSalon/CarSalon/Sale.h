#pragma once
#include "Employer.h"
#include "Car.h"
#include "Date.h"

struct Sale {
	Employer employer;
	Car car;
	Date datesale;
	int RealPrice;
};