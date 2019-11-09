//
//  Order_System.hpp
//  comp252_final_project
//
//  Created by Matthew Haddad on 10/31/19.
//  Copyright © 2019 Matthew Haddad. All rights reserved.
//

#pragma once
#include <iostream>
#include <string>
#include <list>
#include "MainMenu.hpp"
using namespace std;

void open_order_system_options();
int orderNumber;
string foodOrderName;
string drinkOrderName;
float foodOrderPrice;
float drinkOrderPrice;
float foodOrderTime;
float drinkOrderTime;
list <string> subOrderList;

list<string> listFoodItem, listDrinkItem;
list<float> listFoodPrice, listDrinkPrice;
/*******************************************************/
void printActiveSubOrder();               /*view active sub order*/
void newOrderTable();                /*Add a new order to a table*/
void newOrderToGo(void);               /*Add a order without defining a table (Take-Out Order)*/
void addToExistingOrder();               /*Add a suborder to an existing order*/
void deleteSubOrder();                /*Delete a suborder that has not yet been confirmed within the order system*/
void printOptionalIngredients();             /*View optional ingredients in a meal*/
void printCookingPreferences();              /*view cooking preferences of ingredients that can be cooked different ways*/
void printActiveMenu(void);               /*only view the active menu*/
void printSubOrderStatus();               /*view the status of all active suborders*/
void printFinalReceipts();               /*print customer receipts on order completion*/
void printTransactionList();              /*view the transaction list of current order*/
void drinksAlert();                 /*Alert waiter when the drinks are complete*/
void deleteTransactionList();              /*Delete an item or clear the transaction list*/
void setStaticMenu();
/*Setters*/
void setFoodName(string foodName);
void setFoodPrice(float foodPrice);
void setDrinkName(string drinkName);
void setDrinkPrice(float drinkPrice);
void setSubOrder(list<string> subOrder);
/*Getters*/
string getFoodName();
float getFoodPrice();
string getDrinkName();
float getDrinkPrice();
list<string> getSubOrder();

void open_order_system_options(){};
