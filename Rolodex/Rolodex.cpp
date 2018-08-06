#include "Rolodex.h"
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <list>
#include <iostream>
#include <iterator>
using namespace std;

Rolodex::Rolodex()
{
	
};

bool sort(Card one, Card two) {
	string oneName = one.getlName();
	string twoName = two.getlName();
	if (oneName == twoName)
		return false;
	for (int i = 0; i < oneName.length() && i < twoName.length(); ++i)
	{
		if (tolower(oneName[i]) > tolower(twoName[i]))
		{
			return false;
		}
		else if (tolower(oneName[i]) < tolower(twoName[i]))
		{
			return true;
		}
		
	}
}
 void Rolodex::add(Card& card)
{
	rolo.push_front(card);
	currentCard = rolo.begin();
	rolo.sort(sort);
};
Card Rolodex::remove()
{
	Card tmp;
	if (currentCard != rolo.end() && nextIterFunc(currentCard) == rolo.end())
	{
		rolo.erase(currentCard);
		currentCard = rolo.begin();
		tmp = *currentCard;
	}
	else
	{
		list<Card>::iterator next = currentCard;
		next++;
		rolo.erase(currentCard);
		tmp = *next;
		currentCard = next;
	}
	cout << "Card has been deleted" << endl;
	return tmp;
};
Card Rolodex::getCurrentCard()
{
	return *currentCard;
};
Card Rolodex::flip()
{
	if (currentCard != rolo.end() && nextIterFunc(currentCard) == rolo.end())
	{
		currentCard = rolo.begin();
	}
	else
	{
		currentCard++;
	}
	cout << "Card has been flipped" << endl;
	return *currentCard;
};
bool Rolodex::search(const string& lastName)
{
	int i;
	list<Card>::iterator tmp = currentCard;
	currentCard = rolo.begin();
	while (currentCard != rolo.end()) {
		if (!currentCard->getlName().compare(lastName))
			return true;
		else
			currentCard++;
	}
	for (currentCard = rolo.begin(); currentCard != rolo.end(); currentCard++)
		for (i = 0; tolower(currentCard->getlName()[0]) > tolower(lastName[0]); i++)
			if (tolower(currentCard->getlName()[i]) < tolower(lastName[i]))
			break;
			else if (currentCard->getlName()[i] == lastName[i]);
			else if (currentCard->getlName()[i] > lastName[i] && !currentCard->getlName()[0])
				return true;
	cout << "Person cannot be located: " << lastName << endl;
	return false;
};
void Rolodex::show(ostream& os)
{
	list<Card>::iterator tmp = currentCard;
	for (currentCard = rolo.begin(); currentCard != rolo.end(); currentCard++)
		currentCard->show(os);
	currentCard = tmp;
};
std::list<Card>::iterator Rolodex::nextIterFunc(std::list<Card>::iterator iter) {
	return ++iter;
};