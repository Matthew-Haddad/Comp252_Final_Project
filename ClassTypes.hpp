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

struct Ingredient{
    Ingredient(std::string n, int q, double c){name = n; quantity = q; cost = c;}
    std::string name;
    int quantity;
    double cost;
};

struct MenuOption{
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
    std::string name;
    std::vector<MenuOption> DiscountItems;
    std::vector<int> DiscountTimes;
    double DiscountAmount;
};

struct Menu{
    std::string name;
    std::vector<MenuOption> MenuOptions;
    std::vector<Discount> MenuDiscounts;
};

struct Order{
    std::vector<MenuOption> OrderOptions;
    double orderPrice;
};

struct Waiter{
    std::string name;
    std::vector<Order> WaiterOrders;
};

struct Table{
    int number;
    Waiter waiter;
    Order order;
};

#endif /* ClassTypes_hpp */
