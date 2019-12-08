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

    /*
    void saveIngredientData();
    void saveMenuOptionData();
    void saveDiscountData();
    void saveMenuData();
    void saveOrderData();
    void saveWaiterData();
    void saveTableData();
    */
    
    void open_management_system_options();
    void open_inventory_options();
    void open_menu_options();
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
};


void MainMenu::mMenu(){
//	readFileData();
	std::cout << "Welcome to the Diner Management System!\n";
	std::cout << "Enter the number of the option you want or -1 to exit:\n";
	std::cout << "\t[1]Management System\n\t[2]Order System\n\t[3]Kitchen System\n>> ";//new
	std::cin >> option_select;
	switch(option_select){
		case(1): open_management_system_options(); break;
		case(2): open_order_system_options(); break;
		case(3): open_kitchen_system_options(); break;
		case(-1):
//			writeFileData();
			std::cout << "Thank you for using the Diner Management System. Have a good day.\n";
			exit(0);
		default: 
			std::cout << "Input does not match any of the options." << std::endl;
			mMenu();
	}
}

void MainMenu::open_management_system_options(){
    std::cout << "Welcome to the diner management system!\nEnter a number to view options:\n";
    std::cout << "1. Inventory & Menu Options\n2. View Completed Orders\n3. Add New Waiters\n";
    std::cout << "4. Manage Coupons and Discounts\n5. Manage Seating Layout\n>> ";
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
    std::cout << "1. Manage Ingredients\n2. Manage Menu Options\n";
    std::cout << "3. Manage Menus\n 4. Go Back\n>> ";
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

void MainMenu::open_kitchen_system_options(){
	std::cout << "Welcome to the diner kitchen system!\nSelect an option:\n";
	std::cout << "\t[1]Display Active Orders\n\t[2]Display the Progress of Each Active Order\n\t[3]Display Meal Preferences and Options\n\t[4]Go Back\n>>";
	std::cin >> option;
	switch(option){
		case(1):{
			std::cout << "\n[ACTIVE ORDERS]\n";
			std::cout << " -------------------------------------------------------" << std::endl;
			std::cout << "| Table #\tActive Order(s)\t\t\t\t|" << std::endl;
			std::cout << " -------------------------------------------------------" << std::endl;
//			std::cout << "\t1\tHamburger" << std::endl;//example
//			std::cout << "\t2\tMilk Shake" << std::endl; std::cout << "\t3\tCoke" << std::endl;//example

			//displays active orders from Orders
			int oCount =1;
			for(Order o: Orders){
				for(MenuOption m: o.OrderOptions){
					displayActiveOrders(m, oCount);
				}
				oCount++;
			}

			//displays active orders from Tables
			int tCount = 1;
			for(Table t: Tables){
				for(Order o: t.orders){
					displayActiveTableOrders(t, tCount);
				}
				tCount++;
			}
			std::cout << " -------------------------------------------------------end\n" << std::endl;
			break;
		}
		case(2):{
			std::cout << "\n[ORDERS PROGRESS]\n";
			std::cout << " -------------------------------------------------------------------------------" << std::endl;
			std::cout << "| Table #\tElapsed Time\tProgress\tOrder\t\t\t\t|" << std::endl;
			std::cout << " -------------------------------------------------------------------------------" << std::endl;
//			std::cout << "\t1\t00:01\t\t1%\t\tHamburger" << std::endl;//example
			int tCount = 1;
			for(Table t: Tables){
				displayTableProgress(t,tCount); 
				tCount++;
			}
			int oCount =1;
			for(Order o: Orders){
				std::cout << o.orderBeginTime;
				for(MenuOption m: o.OrderOptions){
					displayOrderProgress(o, oCount);
				}
				oCount++;
			}
			std::cout << " -------------------------------------------------------------------------------\n" << std::endl;
			break;
		}
		case(3):{
			std::cout << "\n[MEAL PREFERENCES]\n";
			std::cout << " ---------------------------------------------------------------------------------------------------------------" << std::endl;
			std::cout << "| Order Name\tCook Options\t\t\t\t\tIngredients(Optional to remove)\t\t\t|" << std::endl;
			std::cout << " ---------------------------------------------------------------------------------------------------------------" << std::endl;
//			std::cout << "  Hamburger\tRare\\ Medium Rare\\ Fully Cooked\\ Overcooked\\ \tChicken Patty\\ Lettuce\\ Tomato\\ Fish Patty\\" << std::endl;
			
			for(Menu m: Menus){
				displayMealPreferences(m); 
			}
			std::cout << " ---------------------------------------------------------------------------------------------------------------\n" << std::endl;
			break;
		}
		case(4):{
			mMenu();
		}
		default:{
			std::cout << "Input does not match any of the options." << std::endl;
			open_kitchen_system_options();
		}
	}
	open_kitchen_system_options();
}

void MainMenu::open_order_system_options(){
	orderSystem:
		std::cout << "Welcome to the Diner Order System \nPlease select an option:\n";
		std::cout << "\t[1]Place an Order\n\t[2]View Options\n\t[3]Print Final Receipt\n\t[4]Delete Options\n>> ";
		std::cin >> userChoice;
		while (userChoice < 1 || userChoice > 4 || std::cin.fail()){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Please enter a valid option \n>>";
		std::cin >> userChoice;
	};
	switch (userChoice){
		case 1:{
			std::cout << "What kind of order do you want to place?\n";
			std::cout << "\t[1]Order To Go\n\t[2]Order For Here\n\t[3]Add to Existing Order\n\t[4]Go Back\n>> ";
			std::cin >> userChoice;
			while (userChoice < 1 || userChoice > 4 || std::cin.fail()){
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Please enter a valid option \n>> ";
				std::cin >> userChoice;
			};
			if (userChoice == 1){
				Order ord = newOrderToGo();
				Orders.push_back(ord);
				int counter = 1;
				for (Order o : Orders){
					for(MenuOption m: o.OrderOptions){
						std::cout << counter << ". " << m.name << "\t" << m.Price << "\t"  << "\n";
					}
						time_t now = time(NULL);//new
						o.orderBeginTime = now;//new
						std::cout << o.orderBeginTime << std::endl;
						informOrderIP(o);//new
					counter++;
				}
				goto orderSystem;
			}else if (userChoice == 2){
				
			}else if (userChoice == 3){
				std::cout << "Add to existing order\n";
			}else if (userChoice == 4){
				goto orderSystem;
			}
			break;
		}
		case 2:{
			std::cout << "What information do you want to view?\n";
			std::cout << "\t[1]Menu\n\t[2]Optional Ingredients\n\t[3]Cooking Preferences\n\t[4]Active Suborder\n\t[5]Transaction List\n\t[6]All Active Suborders Status\n\t[7]Go Back\n>> ";
			std::cin >> userChoice;
			while (userChoice < 1 || userChoice > 7 || std::cin.fail()){
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Please enter a valid option \n>> ";
				std::cin >> userChoice;
			}
			if (userChoice == 1){// VIEW MENU
				viewActiveMenu();
			}else if (userChoice == 2){
				std::cout << "Optional Ingredients";
			}else if (userChoice == 3){
			std::cout << "Cooking Preferences";
			}else if (userChoice == 4){
				viewActiveSubOrder();
				//for (Order o : Orders){
					//std::cout << counter << ". " << o.name << "\t\t$" << o.orderPrice << "\t\t\t" << o.orderBeginTime << "\n";
					//counter++;
				//}
				goto orderSystem;
			}else if (userChoice == 5){
				std::cout << "Transaction List";
			}else if (userChoice == 6){// VIEW ALL ACTIVE SUBORDERS
				viewAllSubOrders();
				int counter = 1;
				for (Order o : Orders){
					for(MenuOption m: o.OrderOptions){
						std::cout << counter << ". " << m.name << "\t\t$" << m.Price << "\t\t\t" << "\n";
					}
					counter++;
				}
				goto orderSystem;
			}else if (userChoice == 7){
				goto orderSystem;
			}
			break;
		}
		case 3:{
			std::cout << "Printing stuff\n";
			break;
		}
		case 4:{
			std::cout << "What would you like to delete?\n";
			std::cout << "\t[1]Delete Active SubOrder\n\t[2]Delete Transaction List\n\t[3]Go Back\n";
			std::cin >> userChoice;
			while (userChoice < 1 || userChoice > 3 || std::cin.fail()){
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Please enter a valid option \n>> ";
				std::cin >> userChoice;
			};
			if (userChoice == 1){
				std::cout << "Delete Active Suborder\n";
			}else if (userChoice == 2){
				std::cout << "Delete Transaction List\n";
			}else if (userChoice == 3){
				goto orderSystem;
			}
		}
		default:{
			break;
		}
	}
}

void MainMenu::open_meal_options(){
    std::cout << "1. Add Order Option\n2. Edit Order Option\n";
    std::cout << "3. View Order Options\n4. Delete Order Option\n5. Go Back\n>> ";
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
        case(5):{
            writeFileData();
            open_inventory_options();
        }
        default:{
            std::cout << "Invalid input.\n";
            open_meal_options();
            break;
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
        default:{
            std::cout << "Invalid input.\n";
            open_menu_options();
            break;
        }
    }
}

void open_order_options(){
    std::cout << "1. View Completed Orders\n2. Go Back\n>> ";
    std::cin >> option_select;
    /*
    switch (option_select){
        case(1): viewCompletedOrders(); break;
        case(2): open_management_system_options(); break;
    }
     */
}

void MainMenu::open_waiter_options(){
    std::cout << "1. Add new waiter\n2. View Waiters\n3. Go Back\n";
    std::cin >> option_select;
    switch (option_select){
        case(1):{
            std::cout << "\n\nWhat is the name of the new waiter?\n>> ";
            std::string name;
            std::cin >> name;
            Waiter newWaiter(name);
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

void open_discount_options(){
    std::cout << "Select a Discount Option:\n";
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
}

void MainMenu::writeFileData(){
    clearFile("Ingredient_data.txt");
    for (Ingredient i : Ingredients){
        saveIngredientData(i);
    }
    clearFile("MenuOption_data.txt");
    for (MenuOption m : MenuOptions){
        saveMenuOptionData(m);
    }
}

void MainMenu::loadIngredientData(){
    std::ifstream fin;
    fin.open("Ingredient_data.txt");
    std::string name;
    int quantity;
    double cost;
    while (fin){
        fin >> name >> quantity >> cost;
        Ingredient tempIngredient(name, quantity, cost);
        Ingredients.push_back(tempIngredient);
    }
    Ingredients.pop_back();
}

void MainMenu::loadMenuOptionData(){
    std::ifstream fin;
    fin.open("MenuOption_data.txt");
    std::string str;
    double Price;
    double NumSold;
    double TotalRevenue;
    double CookTime;
    double UnitCost;
    while (fin){
        std::getline (fin, str);
        std::string name = str;
        fin >> UnitCost >> Price >> CookTime >> NumSold >> TotalRevenue;
        MenuOption tempMenuOption(name, UnitCost, Price, CookTime, NumSold, TotalRevenue);
        std::getline (fin, str);
        if (str.size() > 0){
            Ingredient tempIngredient(str);
            tempMenuOption.Ingredients.push_back(tempIngredient);
        }
        if (str.size() > 0){
            tempMenuOption.CookOptions.push_back(str);
        }
        MenuOptions.push_back(tempMenuOption);
    }
    MenuOptions.pop_back();
    fin.close();
}

#endif /* MainMenu_hpp */
