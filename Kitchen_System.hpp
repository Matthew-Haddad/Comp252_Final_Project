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
/**/void displayTableProgress(Table t, int i);//displays elapsed time and progress of each order
/**/void displayOrderProgress(Order ord, int i);
/*DONE*/void displayMealPreferences(Menu m);//display preferences and optional choices of every meal

//waiter options
/*DONE*, in MainMenu.hpp///informs waiter with an order update of "in progress"*/
//initializes orderBeginTime with current time and sets orderInProgress to true
//	newOrder.orderBeginTime = time(NULL);//---------------------------------------------------------------------------------------------------------------------
//	newOrder.orderInProgress = true
//	std::cout << newOrder.orderBeginTime << " " << newOrder.orderInProgress << std::endl;
/*DONE*, informs waiter with an order update of "in progress" for a table*/
//initializes orderBeginTime with current time and sets orderInProgress to true
//	newTable.orders.back.orderBeginTime = time(NULL);
//	newTable.orders.back.orderInProgress = true;

//-------------------------------kitchenSystemFunctionDeclarations--------------------------------//
int option = 0;
//-----------------------------kitchenSystemFunctionImplementationns------------------------------//
void displayActiveTableOrders(Table t, int i) {
	for (Order o : t.orders) {
		for (MenuOption m : o.OrderOptions) {
			std::cout << std::setw(10) << i << std::setw(14) << m.name << std::endl;
		}
	}
}

void displayActiveOrders(Order ord, int i) {
	for (MenuOption m : ord.OrderOptions) {
		std::cout << "  To-Go # " << i << std::setw(14) << m.name << std::endl;
	}
}

void displayTableProgress(Table t, int i) {
	for (Order o : t.orders) {
		time_t begin = o.orderBeginTime;
		for (MenuOption m : o.OrderOptions) {
			time_t now = time(NULL);
			time_t eTime = (now - begin);
			time_t progress = (eTime / m.CookTime)*100;
			std::cout << std::setw(9) << i << std::setw(18) << eTime << std::setw(12) << progress << std::setw(18) << m.name << std::endl;
		}
	}
}

void displayOrderProgress(Order ord, int i) {
	int start = ord.orderBeginTime;
	for (MenuOption m : ord.OrderOptions) {
		int now = time(NULL);
		int eTime = (now - start);
		int progress = (eTime / m.CookTime)*100;
		std::cout << " To - Go # " << i << std::setw(18) << eTime << std::setw(12) << progress << std::setw(18) << m.name << std::endl;
	}
}

void displayMealPreferences(MenuOption m) {//display meal preferences, grab from vector<MenuOptions> OrderOptions
	std::cout << std::setw(11) << m.name << std::setw(10);
	for (std::string co : m.CookOptions) {
		std::cout << co << ",";
	}
	std::cout << std::setw(38);
	for (Ingredient i : m.Ingredients) {
		std::cout << i.name << ",";
	}
	std::cout << std::endl;
}

void informReady() {

}

//-----------------------------kitchenSystemFunctionImplementationns------------------------------//
#endif
#pragma once
