/// \file UsrWindow.cpp
///	\brief class Window: implementation of the functions
///
///	Details.
///

#include<iostream>
#include <cstring>
#include "UsrWindow.h"

/// @brief default constructor 
Window::Window() {
    if (debug_win){cout << "-- created a new main window --" << endl;}
    Loop();
}

/// @brief destructor
Window::~Window() {
    if (debug_win){cout << "-- Window - destructor --" << endl;}
    option_four();
}

/// @brief main menù
void Window::Loop() {
    while (usr_choice != 5){
        cout << " -- -- -- -- -- -- -- -- -- -- " << endl;
        cout << " -- Quadrilateral container -- " << endl;
        cout << " -- -- -- -- -- -- -- -- -- -- " << endl;
        cout << " \t 1 - Visualizzare tutte le forme" << endl;
        cout << " \t 2 - Aggiungere una forma" << endl;
        cout << " \t 3 - Rimuovere una forma" << endl;
        cout << " \t 4 - Rimuovere tutte le forme" << endl;
        cout << " \t 5 - Esci" << endl << endl;
        cout << "Scegli un' opzione: ";
        cin >> usr_choice;
        cout<<endl;
        switch (usr_choice)
        {
        case 1:
            option_one();
            break;

        case 2:
            option_two();
            break;
        
        case 3:
            option_three();
            break;
        
        case 4:
            option_four();
            break;
        
        default:
            cout << "Comando non valido"<<endl;
            break;
        }
    }
}

/// @brief view all shapes
void Window::option_one() { 
    int counter = 0;
    cout << endl;
    if (shapes.size() == 0){
        cout << "Non ci sono forme inserite" << endl;
    }
    else{
        for (auto shape = shapes.begin(); shape != shapes.end(); ++shape) {
            cout << "\t" << counter <<" -\t";
            (*shape)->Drawing(); 
            counter ++;
        }
    }
}

/// @brief add a shape
void Window::option_two() {
    int choice = 0;
    while (choice!=1 && choice!=2){
        cout << "Quale tipo di forma vuoi creare?"<<endl ;
        cout << "\t 1 - Rettangolo" << endl;
        cout << "\t 2 - Rombo" << endl;
        cout << "Scegli un' opzione: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int w,l;
            TextArea* textarea_rect;

            cout << "Lunghezza? ";
            cin >> w;
            while (w <= 0){
                cout << "il valore inserito non è valido, riprova:  ";
                cin >> w;
            }
            cout << "Altezza? ";
            cin >> l;
            while (l <= 0){
                cout << "il valore inserito non è valido, riprova:  ";
                cin >> l;
            }
            shapes.push_back(std::make_shared<Rectangle>(w,l));
            textarea_req();
            cout << "Rettangolo aggiunto" << endl;
            break;

        case 2:
            int dL,dS;

            cout << "Diagonale maggiore? ";
            cin >> dL;
            while (dL <= 0){
                cout << "il valore inserito non è valido, riprova:  ";
                cin >> dL;
            }
            cout << "Diagonale minore? ";
            cin >> dS;
            while (dS <= 0){
                cout << "il valore inserito non è valido, riprova:  ";
                cin >> dS;
            }
            shapes.push_back(std::make_shared<Rhombus>(dL,dS));
            textarea_req();
            cout << "Rombo aggiunto" << endl;
            break;
           
        default:
            choice = 0;
            cout << "Comando non valido"<<endl;
            break;
        }
    }
}

/// @brief request to add text
void Window::textarea_req(){
    int font_size=0;
    char text[SLEN];                                        //to fix
    char YN;

    cout << "Vuoi inserire un testo? [Y/N]: ";
    cin >> YN;
    while (YN != 'Y' && YN != 'N'){
        cout << "Comando non valido"<<endl;
        cout << "vuoi inserire un testo? [Y/N]: ";
        cin >> YN;
    }
    if (YN == 'Y'){
        cout <<"Quale testo vuoi inserire? " ;
        cin >> text; 
        shapes[shapes.size()-1]->SetText(text);
        
        cout << "Dimensione del testo? " ;
        cin >> font_size;
    
        while (font_size <= 0){
            cout << "Il valore inserito non è valido, riprova" << endl;
            cout << "Dimensione del testo? " ;
            cin >> font_size;
        }
        shapes[shapes.size()-1]->SetFontSize((unsigned int)(font_size));
    }
}

/// @brief remove a shape
void Window::option_three(){
    int choice_del;
    if (shapes.size() == 0){
        cout << "Il contenitore è vuoto, non ci sono forme da eliminare";
    }
    else{
        cout << "Quale forma vuoi eliminare? ";
        option_one();
        cout << "Scegli una forma: ";
        cin >> choice_del;
        while (choice_del >= shapes.size() && choice_del < 0){
            cout << "Il valore inserito non è valido, riprova" << endl;
            cout << "Scegli una forma: ";
            cin >> choice_del;
        }
        shapes[choice_del]->Reset();
        shapes.erase(shapes.begin() + choice_del);
    }
}

/// @brief remove all shapes
void Window::option_four(){
    int i;
    for (i=0 ; i < shapes.size(); i++){
        shapes[i]->Reset(); 
        shapes.erase(shapes.begin() + i);
    }
    cout << "Tutte le forme sono state eliminate" << endl;
}