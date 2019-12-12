//
//  Management_System.hpp
//  comp252_final_project
//
//  Created by Matthew Haddad on 9/26/19.
//  Copyright © 2019 Matthew Haddad. All rights reserved.
//

#ifndef Management_System_hpp
#define Management_System_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "ClassTypes.hpp"
using std::cerr;
using std::fstream;
using std::endl;

void open_management_system_options();
void open_menu_options();
void open_order_options();
void open_waiter_options();
void open_discount_options();
void open_seating_options();

void saveDiscountData(){};
void saveOrderData(){};
void saveWaiterData(){};
void saveTableData(){};

// viewing options
void printIngredients();

// menu options
void checkStockLevel();
void changeStockLevel();
void changeMinStockLevel();

// Ingredient Functions
Ingredient addIngredient();
Ingredient editIngredient(Ingredient i);
void deleteIngredient();
void saveIngredientData(Ingredient i);

// MenuOption Functions
MenuOption addMenuOption();
void viewMenuOption(MenuOption m);
MenuOption editMenuOption(MenuOption m);
void deleteMenuOption();
void saveMenuOptionData(MenuOption i);

// Menu Functions
Menu addMenu();
void viewMenu(Menu m);
void editMenuItems();
void editMenuLayout();
void deleteMenu();
void saveMenuData(Menu m);


// order options
void viewCompletedOrders();

// waiter options
void addWaiter();

// discount options
void addDiscount();
void editDiscount();
void deleteDiscount();
void editMenuDiscount();

// seating options
void displaySeatingLayout();
void editSeatingLayout();
int rows = 8;
int columns = 8;

std::vector < std::vector < int > > Seating(rows, std::vector< int >(columns,0));
int option_select = 0;

void checkStockLevel();


Ingredient addIngredient(){
    std::cout << "What is the name of the ingredient you would like to add?\n>> ";
    std::string name;
    std::cin >> name;
    std::cout << "What is the starting inventory quantity of this ingredient?\n>> ";
    int quantity;
    std::cin >> quantity;
    std::cout << "What is the unit cost of this ingredient?\n>> ";
    double cost;
    std::cin >> cost;
    Ingredient newIngredient(name, quantity, cost);
    std::cout << "\n" << name << " added to Ingredients.\n";
    return newIngredient;
}

Ingredient editIngredient(Ingredient i){
    std::cout << "What is the new name of the ingredient?\n>> ";
    std::string name;
    std::cin >> name;
    std::cout << "What is the new starting inventory?\n>> ";
    int quantity;
    std::cin >> quantity;
    std::cout << "What is the new unit cost?\n>> ";
    double cost;
    std::cin >> cost;
    i.name = name;
    i.quantity = quantity;
    i.cost = cost;
    std::cout << "\n" << name << " added to Ingredients.\n";
    return i;
}

void saveIngredientData(Ingredient i){
    std::ofstream fout;
    fout.open("Ingredient_data.txt", std::ios::app);
    fout << i.name << " " << i.cost << " " << i.quantity << endl;
    fout.close();
}



MenuOption addMenuOption(){         // fills all menu option fields except ingredients
    option_select = 1;
    std::cout << "What is the name of the menu option you would like to add?\n>> ";
    std::string name;
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "What is the unit cost of this menu option?\n>> ";
    double UnitCost;
    std::cin.clear();
    std::cin >> UnitCost;
    std::cout << "What is the price of this menu option?\n>> ";
    double Price;
    std::cin.clear();
    std::cin >> Price;
    std::cout << "What is the cook time for this menu option?\n>> ";
    double CookTime;
    std::cin.clear();
    std::cin >> CookTime;
    MenuOption newMenuOption(name, UnitCost, Price, CookTime);
    std::string str;
    std::cout << "What are the cooking options for this menu option?\n";
    while (str != "done"){
        std::cin.clear();
        std::cout << "Enter a cooking option or enter 'done' to finish adding cooking options:\n>> ";
        std::cin >> str;
        if(str != "done")
            newMenuOption.CookOptions.push_back(str);
    }
    return newMenuOption;
}

MenuOption editMenuOption(MenuOption m){
    std::cout << "What is the new name of the menu option you would like to add?\n>> ";
    std::string name;
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "What is the new unit cost of this menu option?\n>> ";
    double UnitCost;
    std::cin.clear();
    std::cin >> UnitCost;
    std::cout << "What is the new price of this menu option?\n>> ";
    double Price;
    std::cin.clear();
    std::cin >> Price;
    std::cout << "What is the new cook time for this menu option?\n>> ";
    double CookTime;
    std::cin.clear();
    std::cin >> CookTime;
    m.setMain(name, UnitCost, Price, CookTime);
    std::cout << "What are the new cooking options for this menu option?\n";
    std::string cookOption = " ";
    while (cookOption != "done"){
        std::cin.clear();
        std::cout << "Enter a cooking option or enter 'done' to finish adding cooking options:\n>> ";
        std::cin >> cookOption;
        if(cookOption != "done")
            m.CookOptions.push_back(cookOption);
    }
    return m;
}


void viewMenuOption(MenuOption m){
    std::cout << "\n\n" << m.name << "\nUnit Cost: " << m.UnitCost;
    std::cout << "\nPrice: " << m.Price;
    std::cout << "\nNumber Sold: " << m.NumSold;
    std::cout << "\nTotal Revenue: " << m.TotalRevenue;
    std::cout << "\nCook Time: " << m.CookTime;
    std::cout << "\nIngredients:\n";
    for (std::string i : m.Ingredients){
        std::cout << "\t" << i << std::endl;
    }
    std::cout << "\nCooking Options:\n";
    for (std::string i : m.CookOptions){
        std::cout << "\t" << i << std::endl;
    }
}

void saveMenuOptionData(MenuOption m){
    std::ofstream fout;
    fout.open("MenuOption_data.txt", std::ios::app);
    
    fout << m.name << " " << m.UnitCost << " " << m.Price << " ";
    fout << m.CookTime << " " << m.NumSold << " "  << m.TotalRevenue << endl;
    fout.close();
    std::ofstream fout2;
    fout2.open("MenuOption_extraData.txt", std::ios::app);
    for ( std::string i : m.Ingredients){
        fout2 << i << " ";
    }
    //fout2 << m.Ingredients.back();
    fout2 << endl;
    fout2.close();
    /*
    for ( std::string c : m.CookOptions){
        fout << c << endl;
    }
     */
}

Menu addMenu(){
    std::cout << "What is the name of this menu?\n>> ";
    std::cin.ignore();
    std::string name;
    std::getline(std::cin, name);
    Menu newMenu(name);
    return newMenu;
}

void viewMenu(Menu m){
    std::cout << "\n\nMenu name: " << m.name << std::endl;
    std::cout << "Menu Options:\n";
    for (MenuOption i : m.MenuOptions){
        std::cout << "\t" << i.name << std::endl;
    }
    std::cout << "Menu Discounts:\n";
    for (Discount i : m.MenuDiscounts){
        std::cout << "\t" << i.name << std::endl;
    }
    std::cout << std::endl;
}

void saveMenuData(Menu m){
    std::ofstream fout;
    fout.open("Menu_data.txt", std::ios::app);
    fout << m.name << "\n";
    fout.close();
    std::ofstream fout2;
    fout2.open("Menu_extraData.txt", std::ios::app);
    for ( MenuOption i : m.MenuOptions){
        fout2 << i.name << " ";
    }
    //fout2 << m.MenuOptions.back().name;
    fout2 << endl;
    /*
    for ( Discount c : m.MenuDiscounts){
        fout2 << c.name << " ";
    }
     */
    fout2.close();
}

std::vector<std::string> createVector(std::string str){
    std::vector<std::string> returnVec;
    std::string word = "";
    for (auto x : str){
        if (x == ' '){
            returnVec.push_back(word);
            word = "";
        }
        else{
            word = word + x;
        }
    }
    return returnVec;
}

void editSeatingLayout()
{
	int userChoice;
	int rChoice;
	int cChoice;
	std::vector<std::vector<int>> seatingLayout{ {0,0,0,0,1,1,1,1},
												 {0,0,0,0,1,1,1,1},
												 {0,0,0,0,0,0,0,0},
												 {0,0,0,0,0,0,0,0},
												 {0,0,0,0,0,0,0,0},
												 {0,0,0,0,0,0,0,0},
												 {1,1,0,0,0,0,0,0},
												 {1,1,0,0,0,0,0,0}};

	for (int i = 0; i < seatingLayout.size(); i++) {
		for (int j = 0; j < seatingLayout.size(); j++) {
			std::cout << seatingLayout[i][j] << " ";
		}
		std::cout << "\n";
	}

	std::cout<< "What postion do you want to edit? \n";
	std::cout << "Row Position? \n";
	std::cin >> rChoice;
	while (rChoice < 1 || rChoice > 8 || std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Please enter a valid option:\n>>";
		std::cin >> rChoice;
	};
	std::cout << "Column Position? \n";
	std::cin >> cChoice;
	while (cChoice < 1 || cChoice > 8 || std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Please enter a valid option:\n>>";
		std::cin >> cChoice;
	};
	std::cout << "What value do you want to enter? \n";
	std::cout << "'0' for empty space and 1 for occupied space\n";
	std::cin >> userChoice;
	while (userChoice < 0 || userChoice > 1 || std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Please enter a valid option:\n>>";
		std::cin >> userChoice;
	};
	for (int i = 0; i < rChoice; i++) {
		for (int j = 0; j < cChoice; j++) {
			seatingLayout[rChoice -1][cChoice -1] = userChoice;

		}
		for (int i = 0; i < seatingLayout.size(); i++) {
			for (int j = 0; j < seatingLayout.size(); j++) {
				std::cout << seatingLayout[i][j] << " ";
			}
			std::cout << "\n";
		}
		break;
	}
}




#endif /* Management_System_hpp */
