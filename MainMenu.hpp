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
#include <iomanip>
#include "ClassTypes.hpp"
#include "Management_System.hpp"
#include "Kitchen_System.hpp"
#include "Order_System.hpp"

class MainMenu{
public:
    void mMenu();
    
    void readFileData();
    void writeFileData();
    void clearFile(std::string file);
    void loadIngredientData();
    void loadMenuOptionData();
    void loadMenuData();
    
    void viewCompletedOrders();
    
    void open_management_system_options();
    void open_order_system_options();
    void open_kitchen_system_options();
    
    void open_inventory_options();
    void open_menu_options();
    void open_order_options();
    void open_discount_options();
    void open_ingredient_options();
    void open_meal_options();
    void open_waiter_options();
    
private:
    std::vector<Ingredient> Ingredients;
    std::vector<MenuOption> MenuOptions;
    std::vector<Discount> Discounts;
    std::vector<Menu> Menus;
    std::vector<Order> Orders;
    std::vector<Waiter> Waiters;
    std::vector<Table> Tables;
    int option_select;
    int    tableCounter = 1;
};


void MainMenu::mMenu(){
    readFileData();
    std::cout << "Welcome to Data's Diner!\n";
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
    std::cout << "1. Inventory & Menu Options\n2. View Completed Orders\n3. Add New Waiters\n";
    std::cout << "4. Manage Coupons and Discounts\n5. Manage Seating Layout\n6. Go Back\n>> ";
    std::cin >> option_select;
    switch(option_select){
        case(1): open_inventory_options(); break;
        case(2): open_order_options(); break;
        case(3): open_waiter_options(); break;
        case(4): open_discount_options(); break;
        case(5): open_seating_options(); break;
        case(6): mMenu(); break;
    }
}

void MainMenu::open_kitchen_system_options() {
    std::cout << "Welcome to the diner kitchen system!\nSelect an option:\n";
    std::cout << "\t[1]Display Active Orders\n\t[2]Display the Progress of Each Active Order\n\t[3]Display Meal Preferences and Options\n\t[4]Go Back\n>>";
    std::cin >> option;
    while (option < 1 || option > 4 || std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a valid option:\n>>";
        std::cin >> option;
    };
    switch (option) {
        case(1): {
            std::cout << "\n[ACTIVE ORDERS]\n";
            std::cout << " -------------------------------------------------------" << std::endl;
            std::cout << "| Table #\tActive Order(s)\t\t\t\t|" << std::endl;
            std::cout << " -------------------------------------------------------" << std::endl;
            
            //displays active orders from Orders
            int oCount = 1;
            for (Order o : Orders) {
                displayActiveOrders(o, oCount);
                oCount++;
            }
            
            //displays active orders from Tables
            int tCount = 1;
            for (Table t : Tables) {
                for (Order o : t.orders) {
                    displayActiveTableOrders(t, tCount);
                }
                tCount++;
            }
            std::cout << " -------------------------------------------------------end\n" << std::endl;
            break;
        }
        case(2): {
            std::cout << "\n[ORDERS PROGRESS]\n";
            std::cout << " -------------------------------------------------------------------------------" << std::endl;
            std::cout << "| Table #" << std::setw(22) << "Elapsed Time" << std::setw(12) << "Progress" << std::setw(13) << "Order" << std::setw(10) << "|" << std::endl;
            std::cout << " -------------------------------------------------------------------------------" << std::endl;
            int tCount = 1;
            for (Table t : Tables) {
                displayTableProgress(t, tCount);
                tCount++;
            }
            int oCount = 1;
            for (Order o : Orders) {
                displayOrderProgress(o, oCount);
                oCount++;
            }
            std::cout << " -------------------------------------------------------------------------------\n" << std::endl;
            break;
        }
        case(3): {
            std::cout << "\n[MEAL PREFERENCES]\n";
            std::cout << " ---------------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << "| Order Name\tCook Options" << std::setw(67) << "Ingredients(Optional to remove)" << std::setw(18) << "|" << std::endl;
            std::cout << " ---------------------------------------------------------------------------------------------------------------" << std::endl;
            for (MenuOption m: MenuOptions) {
                displayMealPreferences(m);
            }
            std::cout << " ---------------------------------------------------------------------------------------------------------------\n" << std::endl;
            break;
        }
        case(4): {
            mMenu();
        }
        default: {
            std::cout << "Input does not match any of the options." << std::endl;
            open_kitchen_system_options();
        }
    }
    open_kitchen_system_options();
}

void MainMenu::open_order_system_options() //new
{ //new
orderSystem:
    std::cout << "Welcome to the Diner Order System \nPlease select an option:\n";
    std::cout << "\t[1]Place an Order\n\t[2]View Options\n\t[3]Print Final Receipt\n\t[4]Delete Options\n\t[5]Go Back\n>> ";
    std::cin >> userChoice;
    while (userChoice < 1 || userChoice > 5 || std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a valid option \n>>";
        std::cin >> userChoice;
    };
    switch (userChoice)
    {
            
        case 1:                        // case 1 used to place an order
            std::cout << "What kind of order do you want to place?\n";
            std::cout << "\t[1]Order To Go\n\t[2]Order For Here\n\t[3]Add to Existing Order\n\t[4]Go Back\n>> ";
            std::cin >> userChoice;
            while (userChoice < 1 || userChoice > 4 || std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Please enter a valid option \n>> ";
                std::cin >> userChoice;
            };
            
            if (userChoice == 1)            //used for placing an order to go
            {
                Order newOrder;
                int counter = 1;
                
                viewActiveMenu();
                for (MenuOption m : MenuOptions)
                {
                    std::cout << counter << ". " << m.name << std::setw(24) << "$" << m.UnitCost << std::setw(24) << "$" << m.Price << std::setw(25) << m.CookTime << "\n";
                    counter++;
                }
                std::cout << std::endl;
                std::cout << "What would you like to order? \n";
                std::cout << ">>";
                std::cin >> option_select;
                newOrder.OrderOptions.push_back(MenuOptions[option_select - 1]);
                Orders.push_back(newOrder);
                goto orderSystem;
            }
            else if (userChoice == 2)        // used to place an order for here
            {
                Table newTable;
                Order newOrder;
                int counter = 1;
                viewActiveMenu();
                for (MenuOption m : MenuOptions)
                {
                    std::cout << counter << ". " << m.name << std::setw(24) << "$" << m.UnitCost << std::setw(24) << "$" << m.Price << std::setw(25) << m.CookTime << "\n";
                    counter++;
                }
                std::cout << std::endl;
                std::cout << "What would you like to order? \n";
                std::cout << ">>";
                std::cin >> option_select;
                newOrder.OrderOptions.push_back(MenuOptions[option_select - 1]);
                newTable.number = tableCounter;
                tableCounter++;
                newTable.orders.push_back(newOrder);
                Tables.push_back(newTable);
                
                goto orderSystem;
            }
            else if (userChoice == 3)            // used to add to an existing order for table
            {
                Table newTable;
                Order newOrder;
                viewActiveSubOrder();
                int tableChoice;
                int counter = 1;
                for (Table t : Tables)
                {
                    for (Order o : t.orders)
                    {
                        for (MenuOption m : o.OrderOptions)
                        {
                            std::cout << counter << "." << m.name << std::setw(24) << "$" << m.UnitCost << std::setw(24) << "$" << m.Price << std::setw(25) << m.CookTime << std::setw(25) << t.number << "\n";
                        }
                    }
                }
                std::cout << std::endl;
                std::cout << "Which table do you want to add an order to? \n";
                std::cin >> tableChoice;
                newTable.number = tableChoice;
                std::cout << std::endl;
                viewActiveMenu();
                for (MenuOption m : MenuOptions)
                {
                    std::cout << counter << ". " << m.name << std::setw(24) << "$" << m.UnitCost << std::setw(24) << "$" << m.Price << std::setw(25) << m.CookTime << "\n";
                    counter++;
                }
                std::cout << std::endl;
                std::cout << "What would you like to add to the table " << tableChoice << "\n";
                std::cin >> option_select;
                newOrder.OrderOptions.push_back(MenuOptions[option_select - 1]);
                newTable.number = tableChoice;
                newTable.orders.push_back(newOrder);
                Tables.push_back(newTable);
                goto orderSystem;
            }
            else if (userChoice == 4)            // used to go back to orderSystem main menu
            {
                goto orderSystem;
            }
            break;
            
        case 2:                    // case 2 is used to view different types of info
            std::cout << "What information do you want to view?\n";
            std::cout << "\t[1]Menu\n\t[2]Optional Ingredients\n\t[3]Cooking Preferences\n\t[4]Active Suborder\n\t[5]Transaction List\n\t[6]All Active Suborders Status\n\t[7]Go Back\n>> ";
            std::cin >> userChoice;
            while (userChoice < 1 || userChoice > 7 || std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Please enter a valid option \n>> ";
                std::cin >> userChoice;
            };
            if (userChoice == 1)
            {
                // VIEW MENU
                viewActiveMenu();
            }
            else if (userChoice == 2)
            {
                std::cout << "Optional Ingredients";
            }
            else if (userChoice == 3)
            {
                std::cout << "Cooking Preferences";
            }
            else if (userChoice == 4)
            {
                viewActiveSubOrder();
                int counter = 1;
                for (Table t : Tables)
                {
                    for (Order o : t.orders)
                    {
                        for (MenuOption m : o.OrderOptions)
                        {
                            std::cout << counter << ". " << m.name << std::setw(24) << "$" << m.UnitCost << std::setw(24) << "$" << m.Price << std::setw(25) << m.CookTime << std::setw(25) << t.number << "\n";
                        }
                        counter++;
                    }
                }
                for (Order o : Orders)
                {
                    for (MenuOption m : o.OrderOptions)
                    {
                        std::cout << counter << ". " << m.name << std::setw(24) << "$" << m.UnitCost << std::setw(24) << "$" << m.Price << std::setw(25) << m.CookTime << std::setw(25) << "\n";
                    }
                    counter++;
                }
                std::cout << std::endl;
                goto orderSystem;
            }
            else if (userChoice == 5)
            {
                std::cout << "Transaction List";
            }
            else if (userChoice == 6)
            {
                viewActiveSubOrder();
                int counter = 1;
                for (Table t : Tables)
                {
                    for (Order o : t.orders)
                    {
                        for (MenuOption m : o.OrderOptions)
                        {
                            std::cout << counter << ". " << m.name << std::setw(24) << "$" << m.UnitCost << std::setw(24) << "$" << m.Price << std::setw(25) << m.CookTime << std::setw(25) << t.number << "\n";
                        }
                        counter++;
                    }
                }
                for (Order o : Orders)
                {
                    for (MenuOption m : o.OrderOptions)
                    {
                        std::cout << counter << ". " << m.name << std::setw(24) << "$" << m.UnitCost << std::setw(24) << "$" << m.Price << std::setw(25) << m.CookTime << std::setw(25) << "\n";
                    }
                    counter++;
                }
                std::cout << std::endl;
                goto orderSystem;
                
            }
            else if (userChoice == 7)
            {
                goto orderSystem;
            }
            
            break;
        case 3:                            // used to print certain info
            std::cout << "Printing stuff\n";
            break;
            
        case 4:                            // used to delete certain info
            std::cout << "What would you like to delete?\n";
            std::cout << "\t[1]Delete Active SubOrder\n\t[2]Delete Transaction List\n\t[3]Go Back\n";
            std::cin >> userChoice;
            while (userChoice < 1 || userChoice > 3 || std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Please enter a valid option \n>> ";
                std::cin >> userChoice;
            };
            if (userChoice == 1)
            {
                std::cout << "Delete Active Suborder\n";
            }
            else if (userChoice == 2)
            {
                std::cout << "Delete Transaction List\n";
            }
            else if (userChoice == 3)
            {
                goto orderSystem;
            }
        case 5:            // case 5 used to go back to the top menu
        {
            mMenu();
        }
        default:
            break;
    }
} //new

void MainMenu::open_inventory_options(){
    std::cout << "Select a Menu Option:\n";
    std::cout << "1. Manage Ingredients\n2. Manage Menu Options\n";
    std::cout << "3. Manage Menus\n 4. Go Back\n>> ";
    std::cin >> option_select;
    switch(option_select){
        case(1): open_ingredient_options(); break;
        case(2): open_meal_options(); break;
        case(3): open_menu_options(); break;
        case(4): open_management_system_options(); break;
        default:{
            std::cout << "Invalid input.\n";
            open_inventory_options();
        }
    }
}


void MainMenu::open_ingredient_options(){       // Menu to add, edit, view, and delete ingredients
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
            std::cout << endl << endl;
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
        case(5):{
            open_inventory_options();
            writeFileData();
            break;}
        default:{
            std::cout << "Invalid input.\n";
            open_ingredient_options();
            break;
        }
    }
}

void MainMenu::open_meal_options(){         // Menu to add, edit, view, and delete new meals/menu options
    std::cout << "1. Add Order Option\n2. Edit Order Option\n";
    std::cout << "3. View Order Options\n4. Delete Order Option\n5. Go Back\n>> ";
    std::cin.clear();
    std::cin >> option_select;
    switch(option_select){
        case(1):{
            MenuOption newMenuOption = addMenuOption();
            int counter = 1;
            while (option_select != 0){
                std::cout << endl;
                for (Ingredient i : Ingredients){
                    std::cout << counter << ". " << i.name << endl;
                    counter++;
                }
                std::cin.clear();
                std::cout << "What are the ingredients in this menu option?";
                std::cout << " Enter a number from the list above or enter 0 to finish adding ingredients:\n>> ";
                std::cin >> option_select;
                if (option_select != 0){
                    newMenuOption.Ingredients.push_back(Ingredients[option_select - 1].name);
                }
            }
            MenuOptions.push_back(newMenuOption);
            open_meal_options();
            break;
        }
        case(2):{
            std::cout << "Menu Options:\n";
            int counter = 1;
            for ( MenuOption i : MenuOptions){
                std::cout << counter << ". " << i.name << endl;
                counter++;
            }
            std::cout << "Enter the number of the Menu Option you would like to edit\n>> ";
            std::cin >> option_select;
            MenuOptions[option_select - 1] = editMenuOption(MenuOptions[option_select - 1]);
            open_ingredient_options();
            break;}
        case(3):{
            while(option_select != 0){
                std::cout << "\n\t\tOrder Options\n Name \n";
                int counter = 1;
                for (MenuOption i : MenuOptions){
                    std::cout << counter << ". " << i.name << std::endl;
                    counter++;
                }
                std::cout << "\n\nEnter the number of an order option from list above to view details or enter 0 to go back:\n>> ";
                std::cin.clear();
                std::cin >> option_select;
                if (option_select != 0){viewMenuOption(MenuOptions[option_select -1]);}
            }
            open_meal_options();
        }
        case(4):{
            std::cout << "Menu Options:\n";
            int counter = 1;
            for ( MenuOption i : MenuOptions){
                std::cout << counter << ". " << i.name << endl;
                counter++;
            }
            std::cout << "Enter the number of the Menu Option you would like to remove\n>> ";
            std::cin >> option_select;
            std::cout << "\n\n" << MenuOptions[option_select - 1].name << " successfully deleted.\n\n";
            MenuOptions.erase(MenuOptions.begin() + option_select - 1);
            open_meal_options();
            break;}
        case(5):{
            writeFileData();
            std::cin.clear();
            open_inventory_options();
        }
        default:{
            std::cout << "Invalid input.\n";
            open_meal_options();
            break;
        }
    }
}

void MainMenu::open_menu_options(){         // Menu to add, edit, view, and delete Menus
    std::cout << "1. Add Menu\n2. Edit Menu\n";
    std::cout << "3. View Menus\n 4. Delete Menu\n5. Go Back\n>> ";
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
                if (option_select != 0){
                    newMenu.MenuOptions.push_back(MenuOptions[option_select - 1]);
                    std::cout << "\n\n" << MenuOptions[option_select - 1].name << " added to menu.\n\n";
                }
            }
            Menus.push_back(newMenu);
            open_menu_options();
            break;
        }
        case(2):{
            
        }
        case(3):{
            std::cout << "\n\t\tMenus\n";
            int counter = 1;
            for (Menu i : Menus){
                std::cout << counter << ". " << i.name << std::endl;
                counter++;
            }
            std::cin.clear();
            std::cout << "Enter the number of a menu to view details or enter 0 to go back:\n>> ";
            std::cin >> option_select;
            viewMenu(Menus[option_select - 1]);
            open_menu_options();
            break;
        }
        case(4):{
            std::cout << "Menus:\n";
            int counter = 1;
            for ( Menu i : Menus){
                std::cout << counter << ". " << i.name << endl;
                counter++;
            }
            std::cout << "Enter the number of the Menu you would like to remove or enter 0 to go back\n>> ";
            std::cin >> option_select;
            if (option_select != 0){
                std::cout << "\n\n" << Menus[option_select - 1].name << " successfully deleted.\n\n";
                Menus.erase(Menus.begin() + option_select - 1);
            }
            open_menu_options();
            break;
        }
        case(5):{
            writeFileData();
            std::cin.clear();
            open_inventory_options();
            break;
        }
        default:{
            std::cout << "Invalid input.\n";
            open_menu_options();
            break;
        }
    }
}

void MainMenu::open_order_options(){
    std::cout << "1. View Completed Orders\n2. Go Back\n>> ";
    std::cin >> option_select;
    switch (option_select){
        case(1): viewCompletedOrders(); break;
        case(2): open_management_system_options(); break;
    }
}

void MainMenu::open_waiter_options(){
    std::cout << "1. Add New Waiter\n2. View Waiters\n3. Go Back\n";
    std::cin >> option_select;
    switch (option_select){
        case(1):{
            std::cout << "\n\nWhat is the name of the new waiter?\n>> ";
            std::string name;
            std::cin >> name;
            Waiter newWaiter;
            newWaiter.name = name;
            Waiters.push_back(newWaiter);
            std::cout << name << " added to Waiters.\n\n";
            open_waiter_options();
            break;
        }
        case(2):{
            std::cout << "\t\tName\n";
            for (Waiter w : Waiters){
                std::cout << "\t\t" << w.name << endl;
            }
            std::cout << endl;
            open_waiter_options();
            break;
        }
        case(3): { open_management_system_options(); break;}
        default:{
            std::cout << "Invalid input.\n";
            open_waiter_options();
            break;
        }
    }
}

void MainMenu::open_discount_options(){
    std::cout << "Select a Discount Option:\n";
    std::cout << "1. Add New Discount\n2. Edit Discount\n3. View Discounts\n4. Delete Discount\n";
    std::cout << "5. Go Back\n>> ";
    std::cin >> option_select;
    switch (option_select){
        case(1):{
            std::cout << "Enter the name of the discount:\n>> ";
            std::string name;
            std::cin >> name;
            std::cout << "Enter the percentage amount of the discount:\n>> ";
            double discountAmount;
            std::cin >> discountAmount;
            Discount tempDiscount(name, discountAmount);
            
        }
        case(5): { open_management_system_options(); break;}
        default:{
            std::cout << "Invalid input.\n";
            open_discount_options();
            break;
        }
    }
}

void open_seating_options(){
    std::cout << "Select a Menu Option:\n";
}

void MainMenu::clearFile(std::string file){
    std::fstream ofs;
    ofs.open(file, std::ios::out | std::ios::trunc);
    ofs.close();
}

void MainMenu::readFileData(){
    loadIngredientData();
    loadMenuOptionData();
    loadMenuData();
}

void MainMenu::writeFileData(){
    clearFile("Ingredient_data.txt");
    for (Ingredient i : Ingredients){
        saveIngredientData(i);
    }
    clearFile("MenuOption_data.txt");
    clearFile("MenuOption_extraData.txt");
    for (MenuOption m : MenuOptions){
        saveMenuOptionData(m);
    }
    clearFile("Menu_data.txt");
    clearFile("Menu_extraData.txt");
    for (Menu m : Menus){
        saveMenuData(m);
    }
}

void MainMenu::loadIngredientData(){
    std::ifstream fin;
    fin.open("Ingredient_data.txt");
    std::string name;
    double cost;
    double quantity;
    while (fin >> name >> cost >> quantity){
        Ingredient tempIngredient(name, cost, quantity);
        Ingredients.push_back(tempIngredient);
    }
}

void MainMenu::loadMenuOptionData(){
    std::ifstream fin;
    fin.open("MenOp.txt");
    MenuOption tempMenuOption;
    while (fin >> tempMenuOption){
        MenuOptions.push_back(tempMenuOption);
    }
    fin.close();
    std::ifstream fin2;
    fin2.open("MenuOption_extraData.txt");
    int counter = 0;
    std::string str;
    while (!fin2.eof()){
        std::getline(fin2, str);
        std::vector<std::string> tempIngredients = createVector(str);
        for(std::string str : tempIngredients){
            MenuOptions[counter].Ingredients.push_back(str);
        }
        counter++;
    }
}

void MainMenu::loadMenuData(){
    std::ifstream fin;
    fin.open("Menu_data.txt");
    std::string str;
    while (fin >> str){
        Menu tempMenu(str);
        Menus.push_back(tempMenu);
    }
    fin.close();
    std::ifstream fin2;
    fin2.open("Menu_extraData.txt");
    int counter = 0;
    while (!fin2.fail()){
        std::getline(fin2, str);
        std::vector<std::string> tempMenOps = createVector(str);
        for(std::string str : tempMenOps){
            Menus[counter].MenuOptions.push_back(str);
        }
        counter++;
    }
}

void MainMenu::viewCompletedOrders(){
    std::cout << "Completed Orders:\n\n";
    for (Order o : Orders){
        std::cout << "Total Price: " << o.orderPrice << endl;
        std::cout << "Order Options:\n";
        for ( MenuOption m : o.OrderOptions){
            std::cout << "\t" << m.name << endl;
        }
        std::cout << endl;
    }
}



#endif /* MainMenu_hpp */
