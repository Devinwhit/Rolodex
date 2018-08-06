#include "Card.h"
#include <string>
#include <iostream>
using namespace std;


Card::Card()
{
	_fName = '\0';
	_lName = '\0';
	_occ = '\0';
	_address = '\0';
	_phoneNum = '\0';
};
Card::Card(string fName, string lName, string occ, string address, string phone)
{
	setfName(fName);
	setlName(lName);
	setOcc(occ);
	setAddress(address);
	setPhone(phone);
}
void Card::setfName(string firstName)
{
	_fName = firstName;
};
string Card::getfName()
{
	return _fName;
};
void Card::setlName(string lastName)
{
	_lName = lastName;
};
string Card::getlName()
{
	return _lName;
};
void Card::setOcc(string occupation)
{
	_occ = occupation;
};
string Card::getOcc()
{
	return _occ;
};
void Card::setAddress(string address)
{
	_address = address;
};
string Card::getAddress()
{
	return _address;
};
void Card::setPhone(string phoneNumber)
{
	_phoneNum = phoneNumber;
};
string Card::getPhone()
{
	return _phoneNum;
};
void Card::show(ostream& output)
{
	output << "Name: " << getlName() << ", " << getfName() << "\nOccupation: " << getOcc() << "\nAddress: " << getAddress() << "\nPhone Number: " << getPhone() << endl;
};

