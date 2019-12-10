//
//  ClassTypes.hpp
//  comp252_final_project
//
//  Created by Matthew Haddad on 10/31/19.
//  Copyright © 2019 Matthew Haddad. All rights reserved.
//

#pragma once
#ifndef ClassTypes_hpp
#define ClassTypes_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <vector>

struct Ingredient{
    Ingredient(std::string n){ name = n;}
    Ingredient(std::string n, int q, double c){name = n; quantity = q; cost = c;}
    std::string name;
    int quantity;
    double cost;
};

struct MenuOption{
    MenuOption(){};
    MenuOption(std::string n){ name = n;}
    MenuOption(std::string n, double un, double p, double ct){
        name = n;
        UnitCost = un;
        Price = p;
        CookTime = ct;
        NumSold = 0;
        TotalRevenue = 0;
    }
    MenuOption(std::string n, double un, double p, double ct, double ns, double tr){
        name = n;
        UnitCost = un;
        Price = p;
        CookTime = ct;
        NumSold = ns;
        TotalRevenue = tr;
    }
    void setAll(std::string n, double un, double p, double ct, double ns, double tr){
        name = n;
        UnitCost = un;
        Price = p;
        CookTime = ct;
        NumSold = ns;
        TotalRevenue = tr;
    }
    void setMain(std::string n, double un, double p, double ct){
        name = n;
        UnitCost = un;
        Price = p;
        CookTime = ct;
    }
    std::string name;
    std::vector<Ingredient> Ingredients;
    double UnitCost;
    double Price;
    double NumSold;
    double TotalRevenue;
    double CookTime;
    std::vector<std::string> CookOptions;
};

struct Discount{
    Discount(std::string n, double da){name = n; DiscountAmount = da;}
    std::string name;
    std::vector<MenuOption> DiscountItems;
    std::vector<int> DiscountTimes;
    double DiscountAmount;
};

struct Menu{
    Menu(std::string n){name = n;}
    std::string name;
    std::vector<MenuOption> MenuOptions;
    std::vector<Discount> MenuDiscounts;
};

struct Order{
    std::vector<MenuOption> OrderOptions;
    double orderPrice;
    bool orderInProgress;
    bool orderComplete;
};

struct Waiter{
    Waiter(std::string n){ name = n;}
    std::string name;
    std::vector<Order> WaiterOrders;
};

struct Table{
    int number;
    Waiter waiter;
    std::vector<Order> orders;
};

#endif /* ClassTypes_hpp */

