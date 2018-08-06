#pragma once

#include <string>
using namespace std;

class Card
{
private:
	string _fName;
	string _lName;
	string _occ;
	string _address;
	string _phoneNum;
public:
	Card();
	Card(string, string, string, string, string);
	void setfName(string firstName);
	string getfName();
	void setlName(string lastName);
	string getlName();
	void setOcc(string occupation);
	string getOcc();
	void setAddress(string address);
	string getAddress();
	void setPhone(string phoneNumber);
	string getPhone();
	void show(ostream& output);
};