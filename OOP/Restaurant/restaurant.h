#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include "dish.h"

using namespace std;

class Restaurant
{
public:
	Restaurant(string restaurantName);
	void requestDishes();
	float getOrderPrice();


private:
	float orderPrice = 0;
	vector<Dish> orderedAdditionalDishes;
	Dish orderedMainDish;
	string restaurantName;
	vector<Dish> mainDishes;
	vector<Dish> additionalDishes;

	void requestMainDish() {
		int dishNumber;
		do {
			for (int i = 0; i < this->mainDishes.size(); i++) {
				cout << i + 1 << '-' << this->mainDishes[i].getName() << ' ' << this->mainDishes[i].getPrice() << '\n';
			}
			cout << "choose one of the main dishes : ";
			cin >> dishNumber;
		} while (1 > dishNumber || dishNumber > this->mainDishes.size());
		this->orderedMainDish = this->mainDishes[dishNumber - 1];
		this->orderPrice += this->orderedMainDish.getPrice();
	}
	void requestAdditionalDishes() {
		int orderNumber;
		while (1) {
			cout << 0 << '-' << "No More\n";
			for (int i = 0; i < this->additionalDishes.size(); i++) {
				cout << i + 1 << '-' << this->additionalDishes[i].getName() << ' ' << this->additionalDishes[i].getPrice() << '\n';
			}
			cout << "choose your additional dishes : ";
			cin >> orderNumber;
			if (orderNumber == 0) return;
			if (orderNumber < 1 || orderNumber > this->additionalDishes.size()) continue;
			this->orderedAdditionalDishes.push_back(this->additionalDishes[orderNumber - 1]);
			this->orderPrice += this->additionalDishes[orderNumber - 1].getPrice();
		}
	}
};

#endif