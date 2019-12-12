#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include "ClassTypes.h"


int userChoice;
int tableCounter = 1;

/*PROTOTYPES*/
/*************************************************************************************************************************************************************/

/*VIEW OPTIONS SECTION*/
void viewActiveSubOrder();               /*view active sub order*/
void viewAllSubOrders();                 /*view the status of all active suborders*/
void viewActiveMenu();                   /*only view the active menu*/
void viewTransactionList();
/*PRINT OPTIONS SECTION*/
void printFinalReceipts();               /*print customer receipts on order completion*/


/**************************************************************************************************************************************************************/


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

void viewTransactionList()
{
	std::cout << "************************************************************************************\n";
	std::cout << "*" << std::setw(50) << "TRANSACTION LIST ORDERS" << std::setw(28) << "*\n";
	std::cout << "************************************************************************************\n";
	std::cout << "NAME" << std::setw(40) << "UNIT COST" << std::setw(24) << "PRICE" << "\n";
}




/********************************************************************PRINT SECTION*******************************************************************************/
void printFinalReceipts()               /*print customer receipts on order completion*/
{
	std::cout << "******************************************\n";
	std::cout << "*" << std::setw(25) << "FINAL RECEIPT" << std::setw(17) << "*\n";
	std::cout << "******************************************\n";
	std::cout << "\n";
	std::cout << "NAME" << std::setw(35) << "SUB TOTAL\n";

}












