//------------------------------------------------------------------------------
// fruit_vector.cpp 
//
// Demos vector that
//	- uses vector of pointers to base class Fruit instances
//	- vector can store pointers to derived class and base class instances
//	- member variable fruitID identifies instance type: _FRUIT, ORANGE, BANANA
//------------------------------------------------------------------------------
#include "Fruit.h"

#include <iostream>
#include <string>
#include <vector>

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cout;
using std::string;
using std::vector;

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
vector<Fruit*>* getFruitVector();
void displayFruits(vector<Fruit*>*);
void deleteFruits(vector<Fruit*>*&);

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

	vector<Fruit*>* pVFruits = getFruitVector();

	displayFruits(pVFruits);

	deleteFruits(pVFruits);

	// very inefficient but convenient way to keep app window open
	system("pause");

	return 0;
}

//------------------------------------------------------------------------------
// - instantiate classes derived from Fruit
// - store instance pointers in new vector<Fruit>
// - return pointer to new vector<Fruit>
//------------------------------------------------------------------------------
vector<Fruit*>* getFruitVector() {

	// tell C++ we'll store pointers to base class instances
	vector<Fruit*>* pV = new vector<Fruit*>;

	// store pointers to derived class instances instead
	// there are different ways to do this...
	Orange* pOrange = new Orange;
	pV->push_back(pOrange);
	pV->push_back(new Orange);
	pV->push_back(new Banana);

	// we can store base class pointers too
	pV->push_back(new Fruit);

	return pV;
}

//------------------------------------------------------------------------------
// display vector elements
//------------------------------------------------------------------------------
void displayFruits(vector<Fruit*>* pV) {

	int elementNum = 0;

	// traverse vector of pointers with range-based for loop
	for (auto p : *pV) {

		cout << "Vector element " << elementNum++ << ": ";

		if (p->fruitID == ORANGE) {
			cout << "Oranges are ";
		}
		else if (p->fruitID == BANANA) {
			cout << "Bananas are ";
		}
		else if (p->fruitID == _FRUIT) {
			cout << "Fruits have ";
		}
		cout << p->color << '\n';
	}
	cout << '\n';
}

//------------------------------------------------------------------------------
// - delete vector elements
// - delete vector and set passed reference pointer to nullptr
//------------------------------------------------------------------------------
void deleteFruits(vector<Fruit*>*& pV) {

	// traverse vector of pointers with iterator this time
	for (auto it = pV->begin(); it != pV->end(); ++it) {
		delete (*it);
	}

	delete pV;
	pV = nullptr;
}

