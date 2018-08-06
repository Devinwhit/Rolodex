#pragma once
#include <string>
#include <list>
#include <iterator>
#include <algorithm>
#include "Card.h"
using namespace std;

class Rolodex
{
public:
	void add(Card&);
	Rolodex();
	Card remove();
	Card getCurrentCard();
	Card flip();
	bool search(const string&);
	void show(ostream& os);
	std::list<Card>::iterator nextIterFunc(std::list<Card>::iterator);
private:
	list<Card> rolo;
	list<Card>::iterator currentCard;
};