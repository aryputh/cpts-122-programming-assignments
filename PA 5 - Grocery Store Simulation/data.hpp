#pragma once

#include <iostream>
#include <cstdlib>

class Data
{
private:
	int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
	int serviceTime; // Random time; varies between express and normal lanes; units in minutes
	int totalTime; // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes

public:
	// Constructor
	Data(int _customerNumber = -1, int _serviceTime = -1, int _totalTime = -1);

	// Deconstructor
	~Data();

	// Getters
	int getCustomerNumber();
	int getServiceTime();
	int getTotalTime();

	// Setters
	void setCustomerNumber(int newNumber);
	void setServiceTime(int newTime);
	void setTotalTime(int newTime);
};