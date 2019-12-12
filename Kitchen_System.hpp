#pragma once
#ifndef Kitchen_System_h
#define Kitchen_System_h
#include "ClassTypes.h"
#include <time.h>
#include <iomanip>
//-------------------------------kitchenSystemFunctionDeclarations--------------------------------//
//display options
/*DONE*/void displayActiveTableOrders(Table t, int i);//displays active orders
/*DONE*/void displayActiveOrders(Order ord, int i);
/*DONE*/void displayTableProgress(Table t, int i);//displays elapsed time and progress of each order
/*DONE*/void displayOrderProgress(Order ord, int i);
/*DONE*/void displayMealPreferences(Menu m);//display preferences and optional choices of every meal

//waiter options
/*DONE*, in MainMenu.hpp///informs waiter with an order update of "in progress"*/
//initializes orderBeginTime with current time and sets orderInProgress to true
/*DONE*, informs waiter with an order update of "in progress" for a table*/
//initializes orderBeginTime with current time and sets orderInProgress to true
/**, inform waiter when order is complete*/
//-------------------------------kitchenSystemFunctionDeclarations--------------------------------//
int option = 0;
//-----------------------------kitchenSystemFunctionImplementationns------------------------------//
void displayActiveTableOrders(Table t, int i) {
	for (Order o : t.orders) {
		for (MenuOption m : o.OrderOptions) {
			std::cout << std::setw(10) << i << std::setw(15) << m.name << std::endl;
		}
	}
}

void displayActiveOrders(Order ord, int i) {
	for (MenuOption m : ord.OrderOptions) {
		std::cout << "  To-Go #" << i << std::setw(15) << m.name << std::endl;
	}
}

void displayTableProgress(Table t, int i) {
	for (Order o : t.orders) {
		time_t begin = o.orderBeginTime;
		for (MenuOption m : o.OrderOptions) {
			time_t now = time(NULL);
			time_t eTime = (now - begin);
			time_t progress = (eTime / m.CookTime)*100;
			std::cout << std::setw(9) << i << std::setw(21) << eTime << "s" << std::setw(11) << progress << "%" << std::setw(17) << m.name << std::endl;
		}
	}
}

void displayOrderProgress(Order ord, int i) {
	int start = ord.orderBeginTime;
	for (MenuOption m : ord.OrderOptions) {
		time_t now = time(NULL);
		time_t eTime = (now - start);
		time_t progress = (eTime / m.CookTime)*100;
		std::cout << " To-Go #" << i << std::setw(21) << eTime << "s" << std::setw(11) << progress << "%" << std::setw(17) << m.name << std::endl;
	}
}

void displayMealPreferences(MenuOption m) {//display meal preferences, grab from vector<MenuOptions> OrderOptions
	std::cout << std::setw(10) << m.name << std::setw(10);
	for (std::string co : m.CookOptions) {
		std::cout << co << ",";
	}
	std::cout << std::setw(38);
	for (Ingredient i : m.Ingredients) {
		std::cout << i.name << ",";
	}
	std::cout << std::endl;
}
//-----------------------------kitchenSystemFunctionImplementationns------------------------------//
#endif
#pragma once
