#pragma once
#include "Employer.h"
#include "Car.h"
#include "Date.h"

struct Sale {
	Employer employee;
	Car car;
	Date datesale;
	int RealPrice;
};