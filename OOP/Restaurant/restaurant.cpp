#include "restaurant.h"
#include "dish.h"
#include <iostream>
#include <vector>

void Restaurant::requestDishes() {
	cout << "Welcome to " << this->restaurantName << '\n';
	this->requestMainDish();
	this->requestAdditionalDishes();
}

float Restaurant::getOrderPrice() {
	return this->orderPrice;
}


Restaurant::Restaurant(string restaurantName)
{
	this->restaurantName = restaurantName;
	this->mainDishes.push_back(Dish("Mixed Grill", 100));
	this->mainDishes.push_back(Dish("Chicken Broast", 150));
	this->mainDishes.push_back(Dish("Pizza", 70));

	this->additionalDishes.push_back(Dish("Ranch Sauce", 10.5));
	this->additionalDishes.push_back(Dish("Ketchup", 7));
	this->additionalDishes.push_back(Dish("Soda", 15.25));
}
