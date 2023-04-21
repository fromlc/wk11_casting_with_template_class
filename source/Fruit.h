//------------------------------------------------------------------------------
// Fruit.h : declaration and definition file for
//      - base class Fruit
//      - derived classes Orange, Banana
//------------------------------------------------------------------------------
#pragma once

#define LC_DEBUG
#ifdef LC_DEBUG
#include <iostream>
using std::cout;
#endif

#include <string>
using std::string;

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int _FRUIT = 0;
constexpr int ORANGE = 1;
constexpr int BANANA = 2;

//------------------------------------------------------------------------------
// Fruit
//------------------------------------------------------------------------------
class Fruit {
public:
    int fruitID;
    string color;
    int calories;

    // constructors
    Fruit(int _fruitID, string _color, int _calories) {
        fruitID = _fruitID;
        color = _color;
        calories = _calories;
    }

    Fruit() : Fruit(_FRUIT, "none", 0) { }

#ifdef LC_DEBUG
    ~Fruit() { cout << "Fruit destructor\n"; }
#endif
};

//------------------------------------------------------------------------------
// Orange
//------------------------------------------------------------------------------
class Orange : public Fruit {
public:
    Orange() : Fruit::Fruit(ORANGE, "orange", 50) { }

#ifdef LC_DEBUG
    ~Orange() { cout << "Orange destructor\n"; }
#endif
};

//------------------------------------------------------------------------------
// Banana
//------------------------------------------------------------------------------
class Banana : public Fruit {
public:
    Banana() : Fruit::Fruit(BANANA, "yellow", 90) { }
#ifdef LC_DEBUG
    ~Banana() { cout << "Banana destructor\n"; }
#endif
};