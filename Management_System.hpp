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
#include "ClassTypes.hpp"

void open_management_system_options();
void open_menu_options();
void open_order_options();
void open_waiter_options();
void open_discount_options();
void open_seating_options();

// viewing options
void printIngredients();                                    // done

// menu options
void checkStockLevel();     // Ingredient as parameter
void changeStockLevel();    // Ingredient as parameter
void changeMinStockLevel(); // Ingredient as parameter
Ingredient addIngredient();       // Ingredient as parameter      // done
void editIngredient();      // Ingredient as parameter
void deleteIngredient();    // Ingredient as parameter
void addMenuOption();             // Meal as parameter
void editMenuOption();            // Meal as parameter
void deleteMenuOption();          // Meal as parameter
void addMenu();             // Menu as parameter
void editMenuItems();       // Menu as parameter
void editMenuLayout();      // Menu as parameter
void deleteMenu();          // Menu as parameter

// order options
void displayOrderStats();   // Order as parameter

// waiter options
void addWaiter();           // Waiter as parameter

// discount options
void addDiscount();         // Discount as parameter
void editDiscount();        // Discount as parameter
void deleteDiscount();      // Discount as parameter
void editMenuDiscount();    // Menu as parameter

// seating options
void editSeatingLayout();

int option_select = 0;



void checkStockLevel(){
    
}

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
    //Ingredients.insert(0, &newIngredient);
    
    return newIngredient;
}

//void printIngredients(){db.printIngredients();}

void addMenuOption(){
    MenuOption newMenuOption;
    option_select = 1;
    std::cout << "What is the name of the menu option you would like to add?\n>> ";
    std::string name;
    std::cin >> name;
    std::cout << "What is the unit cost of this menu option?\n>> ";
    double UnitCost;
    std::cin >> UnitCost;
    std::cout << "What is the price of this menu option?\n>> ";
    double Price;
    std::cin >> Price;
    std::cout << "What is the cook time for this menu option?\n>> ";
    double CookTime;
    std::cin >> CookTime;
    std::cout << "Time to select ingredients.\n";
    while (option_select != 0){
        std::cout << "Enter the number of ingredient from list below or enter 0 to finish adding ingredients:\n>> ";
        //printIngredients();
        std::cin >> option_select;
        
        //newMenuOption.pushMenuOptionIngredient(i);
    }
    //double NumSold = 0;
    //double TotalRevenue = 0;
    
    std::vector<std::string> CookOptions;
}

#endif /* Management_System_hpp */
