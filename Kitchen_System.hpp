//
//  Kitchen_System.hpp
//  comp252_final_project
//
//  Created by Matthew Haddad on 10/31/19.
//  Copyright © 2019 Matthew Haddad. All rights reserved.
//

#pragma once
#ifndef Kitchen_System_h
#define Kitchen_System_h

#include "MainMenu.hpp"

void open_kitchen_system_options();

//display options
void displayActiveOrders();//displays active orders
void displayProgress();//displays elapsed time and progress of each order

//waiter options
void informIP();//informs waiter with an order update of "in progress"
void informReady();//informs waiter with an order update of "ready"

int option = 0;

void KitchenSystem(){
    std::cout << "Welcome to the diner kitchen system.\nSelect an option:\n";
    std::cout << "\t[1]Display Active Orders\n\t[2]Display Progress of Each Active Order\n>> ";
    std::cin >> option;
    if(option == 1){
        displayActiveOrders();
    }else if(option == 2){
        displayProgress();
    }
}

void displayActiveOrders(){
    
}

void displayProgress(){
    
}

void informIP(){
    
}

void informReady(){
    
}

void open_kitchen_system_options(){};


#endif
