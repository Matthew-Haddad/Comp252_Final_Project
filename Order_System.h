#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include "ClassTypes.h"


int userChoice;
int tableCounter = 1;
void open_order_system_options();
void orderSystemStartMenu();

/*PROTOTYPES*/
/*************************************************************************************************************************************************************/
/*MAIN MENU SECTION*/
void orderSystemMenu();

/*ADD NEW ORDER SECTION*/
Order newOrderToGo();					 /*Add a order without defining a table (Take-Out Order)*/
Table newOrderTable();                    /*Add a new order to a table*/
Order addToExistingOrder();               /*Add a suborder to an existing order*/

/*VIEW OPTIONS SECTION*/
void viewActiveSubOrder();               /*view active sub order*/
void viewOptionalIngredients();          /*View optional ingredients in a meal*/
void viewCookingPreferences();           /*view cooking preferences of ingredients that can be cooked different ways*/
void viewAllSubOrders();                 /*view the status of all active suborders*/
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







/********************************************************************VIEW SECTION******************************************************************************/

void viewActiveSubOrder()
{
	std::cout << "------------------------------------------------------------------------------------------------------------------------------\n";
	std::cout << "|" << std::setw(62) << "CURRENT ORDERS" << std::setw(63) << "|" << "\n";
	std::cout << "------------------------------------------------------------------------------------------------------------------------------\n";
	std::cout << "NAME" << std::setw(40) << "UNIT COST" << std::setw(24) << "PRICE" << std::setw(25) << "COOK TIME" << std::setw(25) << "TABLE" << "\n";
}




void viewActiveMenu()									// SHOWS A STATIC MENU
{
	std::cout << "------------------------------------------------------------------------------------------------------\n";
	std::cout << "|" << std::setw(50) << "MENU" << std::setw(51) << "|" << "\n";
	std::cout << "------------------------------------------------------------------------------------------------------\n";
	std::cout << "NAME" << std::setw(40) << "UNIT COST" << std::setw(24) << "PRICE" << std::setw(25) << "COOK TIME" << std::setw(25) << "\n";
	
}


void viewAllSubOrders()									// USED TO VIEW ALL SUBORDERS
{
	std::cout << "-------------------------------------------------------------------------------------------------------------\n";
	std::cout << "|" << std::setw(65) << "ACTIVE ORDERS" << std::setw(43) << "|" << "\n";
	std::cout << "-------------------------------------------------------------------------------------------------------------\n";
	std::cout << "NAME" << std::setw(40) << "UNIT COST" << std::setw(24) << "PRICE" << std::setw(25) << "COOK TIME" << "\n";

}





/********************************************************************PRINT SECTION*******************************************************************************/
/********************************************************************DELETE SECTION*******************************************************************************/
/********************************************************************ALERT SECTION*******************************************************************************/











