#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include "ClassTypes.h"


int userChoice;
void open_order_system_options();
void orderSystemStartMenu();

/*PROTOTYPES*/
/*************************************************************************************************************************************************************/
/*MAIN MENU SECTION*/
void orderSystemMenu();

/*ADD NEW ORDER SECTION*/
Order newOrderToGo();					 /*Add a order without defining a table (Take-Out Order)*/
Order newOrderTable();                    /*Add a new order to a table*/
void addToExistingOrder();               /*Add a suborder to an existing order*/

/*VIEW OPTIONS SECTION*/
void viewActiveSubOrder();              /*view active sub order*/
void viewOptionalIngredients();          /*View optional ingredients in a meal*/
void viewCookingPreferences();           /*view cooking preferences of ingredients that can be cooked different ways*/
void viewAllSubOrders();               /*view the status of all active suborders*/
void viewTransactionList();              /*view the transaction list of current order*/
void viewActiveMenu();                   /*only view the active menu*/

/*PRINT OPTIONS SECTION*/
void printFinalReceipts();               /*print customer receipts on order completion*/

/*DELETE OPTIONS SECTION*/
void deleteSubOrder();                /*Delete a suborder that has not yet been confirmed within the order system*/
void deleteTransactionList();         /*Delete an item or clear the transaction list*/

/*ALERTS*/
void drinksAlert(); /*Alert waiter when the drinks are complete*/
/**************************************************************************************************************************************************************/



/********************************************************************ADD SECTION*******************************************************************************/

Order newOrderToGo()
{
	std::cout << "ORDER TO GO\n";
	std::cout << "What would you like to order?\n";
	viewActiveMenu();
	std::cin >> userChoice;
	auto start = std::chrono::system_clock::now();
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	Order newOrder;
	if (userChoice == 1)
	{
		MenuOption newMenuOption("Hamburger", 1.25, 7.45, 4.55);
		newOrder.OrderOptions.push_back(newMenuOption);
	}
	else if (userChoice == 2)
	{
		MenuOption newMenuOption("MilkShake", 1.25, 7.45, 4.55);
		newOrder.OrderOptions.push_back(newMenuOption);
	}
	else if (userChoice == 3)
	{
		MenuOption newMenuOption("Coke", 1.25, 7.45, 4.55);
		newOrder.OrderOptions.push_back(newMenuOption);
	}
	return newOrder;
}


//Order newOrderTable()
//{

//}






/********************************************************************VIEW SECTION******************************************************************************/

void viewActiveSubOrder()
{
	std::cout << "----------------------------------------------------------------------------------\n";
	std::cout << "|\t\t\t\t CURRENT ORDER\t\t\t\t\t |\n";
	std::cout << "----------------------------------------------------------------------------------\n";
	std::cout << "NAME\t\t\tPRICE\t\t\tSTART TIME \n";
}




void viewActiveMenu()									// SHOWS A STATIC MENU
{
	std::cout << "NAME\t\t\t\tPRICE\t\t\t\n";
	std::cout << "********************************************************\n";
	std::cout << "[1] Hamburger \t\t\t $14\n";
	std::cout << "[2] MilkShake \t\t\t $5\n";
	std::cout << "[3] Coke \t\t\t $1.99\n";
}


void viewAllSubOrders()									// USED TO VIEW ALL SUBORDERS
{
	std::cout << "----------------------------------------------------------------------------------\n";
	std::cout << "|\t\t\t\tACTIVE ORDERS\t\t\t\t\t |\n";
	std::cout << "----------------------------------------------------------------------------------\n";
	std::cout << "NAME\t\t\tPRICE\t\t\tSTART TIME \n";

}





/********************************************************************PRINT SECTION*******************************************************************************/
/********************************************************************DELETE SECTION*******************************************************************************/
/********************************************************************ALERT SECTION*******************************************************************************/











