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
Ingredient editIngredient(Ingredient i);      // Ingredient as parameter
void deleteIngredient();    // Ingredient as parameter
MenuOption addMenuOption();             // Meal as parameter
void viewMenuOption(MenuOption m);                                          // new
void editMenuOption();            // Meal as parameter
void deleteMenuOption();          // Meal as parameter
Menu addMenu();             // Menu as parameter
void viewMenu(Menu m);
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
    std::cout << "What are to cooking options for this menu option?\n";
    std::string cookOption = " ";
    while (cookOption != "done"){
        std::cin.clear();
        std::cout << "Enter a cooking option or enter 'done' to finish adding cooking options:\n>> ";
        std::cin >> cookOption;
        if(cookOption != "done")
            newMenuOption.CookOptions.push_back(cookOption);
    }
    return newMenuOption;
}

void viewMenuOption(MenuOption m){
    std::cout << "\n\n" << m.name << "\nUnit Cost: " << m.UnitCost;
    std::cout << "\nPrice: " << m.Price;
    std::cout << "\nNumber Sold: " << m.NumSold;
    std::cout << "\nTotal Revenue: " << m.TotalRevenue;
    std::cout << "\nCook Time: " << m.CookTime;
    std::cout << "\nIngredients:\n";
    for (Ingredient i : m.Ingredients){
        std::cout << "\t" << i.name << std::endl;
    }
    std::cout << "\nCooking Options:\n";
    for (std::string i : m.CookOptions){
        std::cout << "\t" << i << std::endl;
    }
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
    std::cout << "\n\n" << m.name << std::endl;
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

#endif /* Management_System_hpp */
