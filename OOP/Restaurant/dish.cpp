#include "dish.h"
#include <iostream>

using namespace std;


Dish::Dish(string name, float price) {
	this->name = name;
	this->price = price;
}
Dish::Dish() {}
string Dish::getName() { return this->name; }
float Dish::getPrice() { return this->price; }
