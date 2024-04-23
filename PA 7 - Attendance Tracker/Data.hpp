#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>
#include <iostream>
#include "Stack.hpp"

class Data
{
private:
	int recordNumber;
	int idNumber;
	std::string studentName;
	std::string studentEmail;
	std::string credits;
	std::string studentMajor;
	std::string studentStanding;
	int numberAbsences;
	Stack datesOfAbsences;

public:
	Data(int _recordNumber = 0, int _idNumber = 0, std::string _studentName = "N/A", std::string _studentEmail = "N/A",
		std::string _credits = "N/A", std::string _studentMajor = "N/A", std::string _studentStanding = "N/A",
		int _numberAbsences = 0, Stack _datesOfAbsences = Stack());
	Data(Data& _rhs);
	~Data();

	int getRecordNumber() const;
	int getIdNumber() const;
	std::string getName() const;
	std::string getEmail() const;
	std::string getCredits() const;
	std::string getMajor() const;
	std::string getStanding() const;
	int getNumberAbsences() const;
	Stack* getDatesOfAbsences();

	void setRecordNumber(int _recordNumber);
	void setIdNumber(int _idNumber);
	void setName(std::string _studentName);
	void setEmail(std::string _studentEmail);
	void setCredits(std::string _credits);
	void setMajor(std::string _studentMajor);
	void setStanding(std::string _studentStanding);
	void setNumberAbsences(int _numberAbsences);
	void setDatesOfAbsences(Stack _datesOfAbsences);

	Data& operator = (Data& _rhs);
};

std::ostream& operator << (std::ostream& _lhs, const Data& _rhs);
#endif