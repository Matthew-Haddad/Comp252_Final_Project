//
//  MainMenu.hpp
//  comp252_final
//
//  Created by Matthew Haddad on 11/9/19.
//  Copyright © 2019 Matthew Haddad. All rights reserved.
//

#ifndef MainMenu_hpp
#define MainMenu_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "ClassTypes.hpp"
#include "Management_System.hpp"
#include "Kitchen_System.hpp"
#include "Order_System.hpp"

class MainMenu{
public:
    MainMenu();
    void readFileData();
    void writeFileData();
    void open_management_system_options();
    void open_menu_options();
    
private:
    std::vector<Ingredient> Ingredients;
    std::vector<MenuOption> MenuOptions;
    std::vector<Discount> Discounts;
    std::vector<Menu> Menus;
    std::vector<Order> Orders;
    std::vector<Waiter> Waiters;
    std::vector<Table> Tables;
    int option_select;
};

MainMenu::MainMenu(){
    std::cout << "Welcome to the Diner Management System!\n";
    std::cout << "Enter the number of the option you want or -1 to exit:\n";
    std::cout << "1. Management System\n2. Order System\n3. Kitchen System\n>> ";
    std::cin >> option_select;
    switch(option_select){
        case(1): open_management_system_options(); break;
        case(2): open_order_system_options(); break;
        case(3): open_kitchen_system_options(); break;
        case(-1):
            writeFileData();
            std::cout << "Thank you for using the Diner Management System. Have a good day.\n";
            exit(0);
    }
}

void MainMenu::open_management_system_options(){
    std::cout << "Welcome to the diner management system!\nEnter a number to view options:\n";
    std::cout << "1. Menu Options\n2. Order Options\n3. Waiter Options\n";
    std::cout << "4. Coupon Options\n5. Seating Options\n>> ";
    std::cin >> option_select;
    switch(option_select){
        case(1): open_menu_options(); break;
        case(2): open_order_options(); break;
        case(3): open_waiter_options(); break;
        case(4): open_discount_options(); break;
        case(5): open_seating_options();
    }
}

void MainMenu::open_menu_options(){
    std::cout << "Select a Menu Option:\n";
    std::cout << "1. Add Ingredient\n2. Edit Ingredient\n";
    std::cout << "3. View Ingredients\n4. Add Menu Option\n>> ";
    std::cin >> option_select;
    switch(option_select){
        case(1):
            Ingredient ing = addIngredient();
            Ingredients.push_back(ing);
            std::cout << Ingredients.size() << std::endl;
            break;
        //case(2): /*editIngredient(); */break;
        //case(3): /*printIngredients(); */break;
            
    }
}

void open_order_options(){
    std::cout << "Select a Order Option:\n";
}

void open_waiter_options(){
    std::cout << "Select a Waiter Option:\n";
}

void open_discount_options(){
    std::cout << "Select a Discount Option:\n";
}

void open_seating_options(){
    std::cout << "Select a Menu Option:\n";
}

void MainMenu::writeFileData(){};

#endif /* MainMenu_hpp */
