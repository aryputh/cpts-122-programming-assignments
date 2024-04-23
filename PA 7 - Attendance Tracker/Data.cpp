#include "Data.hpp"

Data::Data(int _recordNumber, int _idNumber, std::string _studentName, std::string _studentEmail,
	std::string _credits, std::string _studentMajor, std::string _studentStanding, int _numberAbsences,
	Stack _datesOfAbsences)
{
	recordNumber = _recordNumber;
	idNumber = _idNumber;
	studentName = _studentName;
	studentEmail = _studentEmail;
	credits = _credits;
	studentMajor = _studentMajor;
	studentStanding = _studentStanding;
	numberAbsences = _numberAbsences;
	datesOfAbsences = _datesOfAbsences;
}

Data::Data(Data& _rhs)
{
	recordNumber = _rhs.recordNumber;
	idNumber = _rhs.idNumber;
	studentName = _rhs.studentName;
	studentEmail = _rhs.studentEmail;
	credits = _rhs.credits;
	studentMajor = _rhs.studentMajor;
	studentStanding = _rhs.studentStanding;
	numberAbsences = _rhs.numberAbsences;
	datesOfAbsences = _rhs.datesOfAbsences;
}

Data::~Data()
{

}

int Data::getRecordNumber() const
{
	return recordNumber;
}

int Data::getIdNumber() const
{
	return idNumber;
}

std::string Data::getName() const
{
	return studentName;
}

std::string Data::getEmail() const
{
	return studentEmail;
}

std::string Data::getCredits() const
{
	return credits;
}

std::string Data::getMajor() const
{
	return studentMajor;
}

std::string Data::getStanding() const
{
	return studentStanding;
}

int Data::getNumberAbsences() const
{
	return numberAbsences;
}

Stack* Data::getDatesOfAbsences()
{
	return &datesOfAbsences;
}

void Data::setRecordNumber(int _recordNumber)
{
	recordNumber = _recordNumber;
}

void Data::setIdNumber(int _idNumber)
{
	idNumber = _idNumber;
}

void Data::setName(std::string _studentName)
{
	studentName = _studentName;
}

void Data::setEmail(std::string _studentEmail)
{
	studentEmail = _studentEmail;
}

void Data::setCredits(std::string _credits)
{
	credits = _credits;
}

void Data::setMajor(std::string _studentMajor)
{
	studentMajor = _studentMajor;
}

void Data::setStanding(std::string _studentStanding)
{
	studentStanding = _studentStanding;
}

void Data::setNumberAbsences(int _numberAbsences)
{
	numberAbsences = _numberAbsences;
}

void Data::setDatesOfAbsences(Stack _datesOfAbsences)
{
	datesOfAbsences = _datesOfAbsences;
}

Data& Data::operator = (Data& _rhs)
{
	recordNumber = _rhs.getRecordNumber();
	idNumber = _rhs.getIdNumber();
	studentName = _rhs.getName();
	studentEmail = _rhs.getEmail();
	credits = _rhs.getCredits();
	studentMajor = _rhs.getMajor();
	studentStanding = _rhs.getStanding();
	numberAbsences = _rhs.getNumberAbsences();
	datesOfAbsences = *_rhs.getDatesOfAbsences();

	return *this;
}

std::ostream& operator << (std::ostream& _lhs, const Data& _rhs)
{
	_lhs << _rhs.getRecordNumber() << "," << _rhs.getIdNumber() << ",\"" << _rhs.getName() << "\","
		<< _rhs.getEmail() << "," << _rhs.getCredits() << "," << _rhs.getMajor() << "," << _rhs.getStanding()
		<< "," << _rhs.getNumberAbsences();

	return _lhs;
}