#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <unistd.h>
#include "MainMenu.hpp"

int hours = 0; int minutes = 0; int seconds = 0;

int main(){
    MainMenu menu;
	menu.mMenu();
    return 0;
}
