// Rolodex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Rolodex.h"
#include "Card.h"
#include <string>
#include <list>
#include <cctype>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	Rolodex rolo;
	rolo.add(Card("Tony", "Hansen", "Writer", "12 E. St. NY, NY 33333", "555-9999"));
	rolo.add(Card("Jon", "Smyth", "Computer Hardware", "CMU Computer Services Pittsburgh, PA", "555-1324"));
	rolo.add(Card("Alonza", "Heard", "Mechanic", "123 Anyplace Ave Malden, MA", "555-5678"));
	rolo.add(Card("Jen", "Reyes", "Graphic artist", "325 Oak Rd Wilmington, MA", "555-4950"));
	rolo.add(Card("Alan", "Lupine", "Vet", "1 Bigelow Ave. Lawrence, MA", "555-7654"));
	rolo.add(Card("Jewel", "Proverb", "Landscaper", "34 Washington St. Waltham, MA", "555-3333"));
	rolo.add(Card("Paul", "Revere", "Radical Revolutionary", "45 Commonwealth Ave. Boston, MA", "555-1776"));
	rolo.add(Card("Adolf", "Coors", "Beer Manufacturer", "Boston MA", "555-2337"));
	rolo.add(Card("Seymour", "Papert", "Lego Professor", "MIT", "555-1111"));
	rolo.add(Card("Fred", "Milton", "Sales", "12 Freedom Way Nashua, NH", "555-9981"));
	string input;
	string lastName;
	while (input != "done")
	{
		cout << "Please enter an action (list, view, flip, search, add, remove, or done)" << endl;
		cin >> input;
		if (input == "list")
		{
			rolo.show(cout);
		}
		else if (input == "view")
		{
			Card tmp;
			tmp = rolo.getCurrentCard();
			tmp.show(cout);
		}
		else if (input == "flip")
		{
			rolo.flip();
			Card tmp;
			tmp = rolo.getCurrentCard();
			tmp.show(cout);
		}
		else if (input == "search")
		{
			cout << "Please enter a last name to search: ";
			cin >> lastName;
			if (rolo.search(lastName) == true)
			{
				cout << "Card found! Card is now set to the current card" << endl;
			}
		}
		else if (input == "add")
		{
			string fName, lName, occ, houseNum, streetName, streetSuffix, town, state, phoneNum;
			cout << "Please enter the following: first name, last name, occupation, address, and phone number: " << endl;
			cin >> fName >> lName >> occ >> houseNum >> streetName >> streetSuffix >> town >> state>> phoneNum;
			string address = houseNum + " " + streetName + " " + streetSuffix + ", " + town + " " + state;
			rolo.add(Card(fName, lName, occ, address, phoneNum));
		}
		else if (input == "remove")
		{
			rolo.remove();
		}
	}
	return 0;
}

