/// \file CRectangle.cpp
///	\brief class Rectangle: implementation of the functions
///
///	Details.
///

#include<iostream>
#include <cstring>
#include "UsrWindow.h"

/// @brief default constructor 
Window::Window() {
    if (debug_win){cout << "-- created a new main window --";}
    Loop();
}

/// @brief default initialization of the object
void Window::Loop() {

    cout << " -- Quadrilateral container -- " << endl;
    cout << " \t 1 - visualizza tutte le forme" << endl;
    cout << " \t 2 - aggiungere forma" << endl;
    cout << " \t 3 - rimuovere forma" << endl;
    cout << " \t 4 - rimuovere tutte le forme" << endl;
    cout << " \t 5 - exit" << endl << endl;

    cin >> usr_choice;
    cout << "scelsta: " << usr_choice;
    


}