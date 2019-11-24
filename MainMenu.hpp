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
    void open_inventory_options();  // new
    void open_menu_options();
    void open_ingredient_options(); // new
    void open_meal_options();       // new
    
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
    std::cout << "1. Inventory Options\n2. Order Options\n3. Waiter Options\n";
    std::cout << "4. Coupon Options\n5. Seating Options\n>> ";
    std::cin >> option_select;
    switch(option_select){
        case(1): open_inventory_options(); break;
        case(2): open_order_options(); break;
        case(3): open_waiter_options(); break;
        case(4): open_discount_options(); break;
        case(5): open_seating_options();
    }
}

void MainMenu::open_inventory_options(){
    std::cout << "Select a Menu Option:\n";
    std::cout << "1. Ingredient Options\n2. Meal Options\n";
    std::cout << "3. Menu Options\n 4. Go Back\n>> ";
    std::cin >> option_select;
    switch(option_select){
        case(1): open_ingredient_options(); break;
        case(2): open_meal_options(); break;
        case(3): open_menu_options(); break;
        case(4): open_management_system_options(); break;
        default:{
            cout << "Invalid input.\n";
            open_inventory_options();
        }
    }
}
    
    
void MainMenu::open_ingredient_options(){
    option_select = NULL;
    std::cout << "1. Add Ingredient\n2. Edit Ingredient\n";
    std::cout << "3. View Ingredients\n 4. Delete Ingredient\n5. Go Back\n>> ";
    std::cin >> option_select;
    switch(option_select){
        case(1):{
            Ingredient ing = addIngredient();
            Ingredients.push_back(ing);
            open_ingredient_options();
            break;}
        case(2):{
            std::cout << "Ingredients:\n";
            int counter = 1;
            for ( Ingredient i : Ingredients){
                std::cout << counter << ". " << i.name << endl;
                counter++;
            }
            std::cout << "Enter the number of the Ingredient you would like to edit\n>> ";
            std::cin >> option_select;
            Ingredients[option_select - 1] = editIngredient(Ingredients[option_select - 1]);
            open_ingredient_options();
            break;}
        case(3):{
            std::cout << "\n\t\tIngredients\n Name    Quantity    Cost\n";
            for (Ingredient i : Ingredients){
                std::cout << i.name << "      " << i.quantity << "       " << i.cost << endl;
            }
            cout << endl << endl;
            open_ingredient_options();
            break;}
        case(4):{
            std::cout << "Ingredients:\n";
            int counter = 1;
            for ( Ingredient i : Ingredients){
                std::cout << counter << ". " << i.name << endl;
                counter++;
            }
            std::cout << "Enter the number of the Ingredient you would like to remove\n>> ";
            std::cin >> option_select;
            Ingredients.erase(Ingredients.begin() + option_select - 1);
            open_ingredient_options();
            break;}
        case(5):{open_inventory_options(); break;}
        default:{
            std::cout << "Invalid input.\n";
            open_menu_options();
            break;
        }
    }
}

void MainMenu::open_meal_options(){
    std::cout << "1. Add Order Option\n2. Edit Order Option\n";
    std::cout << "3. View Order Options\n 4. Delete Order Option\n>> ";
    std::cin.clear();
    std::cin >> option_select;
    switch(option_select){
        case(1):{
            MenuOption newMenuOption = addMenuOption();
            std::cout << "What ingredients are in this menu option?\n";
            while (option_select != 0){
                std::cout << "Enter the number of ingredient from list below or enter 0 to finish adding ingredients:\n";
                int counter = 1;
                for ( Ingredient i : Ingredients){
                    std::cout << counter << ". " << i.name << endl;
                    counter++;
                }
                std::cout << "\n>> ";
                std::cin.clear();
                std::cin >> option_select;
                if(option_select != 0){ newMenuOption.Ingredients.push_back(Ingredients[option_select - 1]);}
            }
            MenuOptions.push_back(newMenuOption);
            open_meal_options();
            break;}
        case(3):{
            while(option_select != 0){
                std::cout << "\n\t\tOrder Options\n Name \n";
                int counter = 1;
                for (MenuOption i : MenuOptions){
                    std::cout << counter << ". " << i.name << std::endl;
                    counter++;
                }
                cout << "\n\nEnter the number of an order option from list above to view details or enter 0 to go back:\n>> ";
                std::cin.clear();
                std::cin >> option_select;
                if (option_select != 0){viewMenuOption(MenuOptions[option_select -1]);}
            }
            open_meal_options();
            }
        }
}


            
void MainMenu::open_menu_options(){
    std::cout << "1. Add Menu\n2. Edit Menu\n";
    std::cout << "3. View Menus\n 4. Delete Menu\n>> ";
    std::cin >> option_select;
    switch(option_select){
        case(1):{
            Menu newMenu = addMenu();
            while (option_select != 0){
                std::cout << "\n\t\tOrder Options\n Name \n";
                int counter = 1;
                for (MenuOption i : MenuOptions){
                    std::cout << counter << ". " << i.name << std::endl;
                    counter++;
                }
                std::cin.clear();
                std::cout << "Enter the number of an order option to add to the menu or enter 0 to go back:\n>> ";
                std::cin >> option_select;
                if (option_select != 0){ newMenu.MenuOptions.push_back(MenuOptions[option_select - 1]);}
            }
            open_menu_options();
            break;
        }
            
        case(3):{
            std::cout << "\n\t\tMenus\n Name \n";
            int counter = 1;
            for (Menu i : Menus){
                std::cout << counter << ". " << i.name << std::endl;
                counter++;
            }
            std::cin.clear();
            std::cout << "Enter the number of an menu option to view details or enter 0 to go back:\n>> ";
            std::cin >> option_select;
            
        }
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
