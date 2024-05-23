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

    while (usr_choice != 5){
        cout << " -- Quadrilateral container -- " << endl;
        cout << " \t 1 - visualizza tutte le forme" << endl;
        cout << " \t 2 - aggiungere forma" << endl;
        cout << " \t 3 - rimuovere forma" << endl;
        cout << " \t 4 - rimuovere tutte le forme" << endl;
        cout << " \t 5 - exit" << endl << endl;

        cin >> usr_choice;
        if (debug_win){cout << "scelta: " << usr_choice << endl;}
        switch (usr_choice)
        {
        case 1:
            option_one();
            break;
        
        default:
            cout << " command not valid "<<endl;
            break;
        }
    }
}

void Window::option_one() {
    int choice = 0;
    while (choice!=1 || choice!=2)
        cout << "che tipo di forma vuoi creare?" << endl;
        cout << "\t 1 - quadrato" << endl;
        cout << "\t 2 - rombo" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            add_object();
            break;
        case 2:
            /* code */
            break;
        
        default:
            choice = 0;
            cout << " command not valid "<<endl;
            break;
        }
        

}


void Window::new_rectangle(){
    quadrilateral_container* Actual_ptr = first_quadrilateral_pointer;
    while(Actual_ptr != NULL){
        Actual_ptr = Actual_ptr->next_quadrilateral_ptr;
    }
    quadrilateral_container* new_quadrilateral;
    if (new_quadrilateral != NULL){
        new_quadrilateral->quadrilateral_ptr = usr_rectangle;
        new_quadrilateral->next_quadrilateral_ptr = NULL;
        Actual_ptr = new_quadrilateral;
    }
    else{
        cout << " ERROR Window::new_rectangle -- NUll Pointer" << endl;
    }

    //creo il nuovo rettangolo in base alle richieste dell'utente
    // return &rettangolo
};

Rectangle Window::usr_rectangle(){
    //richieste all'utente su come creare il nuovo rettangolo:
    // TEMP_rect SOLO per debug
    Rectangle TEMP_rect;
    return TEMP_rect;


}


void Window::new_rhombus(){
    //creo il nuovo rettangolo in base alle richieste dell'utente
    // return &rettangolo
};

