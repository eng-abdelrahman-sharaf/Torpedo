#ifndef DISH_H
#define DISH_H
#include <iostream>
using namespace std;
class Dish {
	private:
		string name;
		float price;
	public:
		Dish(string name, float price);
		Dish();
		string getName();
		float getPrice();
};
#endif