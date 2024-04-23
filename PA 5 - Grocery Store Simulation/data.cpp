#include "data.hpp"

/*
*	Description: This is the constructor for the class. Default values are assigned in the prototype.
*	Date: 3/4/2024
*
*	Preconditions: Actual arguments are valid.
*	Postconditions: An object is created with the values (or default values) that you supplied.
*/
Data::Data(int _customerNumber, int _serviceTime, int _totalTime)
{
	this->customerNumber = _customerNumber;
	this->serviceTime = _serviceTime;
	this->totalTime = _totalTime;
}

/*
*	Description: This is the deconstructor for the class.
*	Date: 3/4/2024
*
*	Preconditions: None.
*	Postconditions: The object has been destroyed.
*/
Data::~Data()
{

}

/*
*	Description: This is the getter for the class.
*	Date: 3/4/2024
*
*	Preconditions: None.
*	Postconditions: The customer number has been returned.
*/
int Data::getCustomerNumber()
{
	return this->customerNumber;
}

/*
*	Description: This is the getter for the class.
*	Date: 3/4/2024
*
*	Preconditions: None.
*	Postconditions: The service time has been returned.
*/
int Data::getServiceTime()
{
	return this->serviceTime;
}

/*
*	Description: This is the getter for the class.
*	Date: 3/4/2024
*
*	Preconditions: None.
*	Postconditions: The total time has been returned.
*/
int Data::getTotalTime()
{
	return this->totalTime;
}

/*
*	Description: This is the setter for the class.
*	Date: 3/4/2024
*
*	Preconditions: Actual arguments are valid.
*	Postconditions: The number has been updated.
*/
void Data::setCustomerNumber(int newNumber)
{
	this->customerNumber = newNumber;
}

/*
*	Description: This is the setter for the class.
*	Date: 3/4/2024
*
*	Preconditions: Actual arguments are valid.
*	Postconditions: The time has been updated.
*/
void Data::setServiceTime(int newTime)
{
	this->serviceTime = newTime;
}

/*
*	Description: This is the setter for the class.
*	Date: 3/4/2024
*
*	Preconditions: Actual arguments are valid.
*	Postconditions: The time has been updated.
*/
void Data::setTotalTime(int newTime)
{
	this->totalTime = newTime;
}
