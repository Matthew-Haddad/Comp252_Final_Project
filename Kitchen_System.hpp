#pragma once
#ifndef Kitchen_System_h
#define Kitchen_System_h
#include <iomanip>
//-------------------------------kitchenSystemFunctionDeclarations--------------------------------//
//display options
void displayActiveOrders(Table t, int i);//displays active orders
void displayProgress(Table t, int i);//displays elapsed time and progress of each order
void displayMealPreferences();//display preferences and optional choices of every meal
//waiter options
void informIP();//informs waiter with an order update of "in progress"
void informReady();//informs waiter with an order update of "ready"
//-------------------------------kitchenSystemFunctionDeclarations--------------------------------//
int option = 0;
//-----------------------------kitchenSystemFunctionImplementationns------------------------------//
void displayActiveOrders(Table t, int i){//display active orders in a table, grab from vector<Table> Tables
	for(MenuOption m: t.order.OrderOptions){
		std::cout << " " << i << "\t" << m.name;
	}
}

void displayProgress(Table t, int i){//display progress of orders based on timer
	for(MenuOption m: t.order.OrderOptions){
		int eTime=1;//
		int progress = (eTime/m.ct)*100;
		std::cout << i << "\t" << etime << "\t" << progress << m.name << std::endl;
	}
}

void displayMealPreferences(){//display meal preferences, grab from vector<MenuOptions> OrderOptions
	
}

void informIP(){
    
}

void informReady(){
    
}

//-----------------------------kitchenSystemFunctionImplementationns------------------------------//
#endif
