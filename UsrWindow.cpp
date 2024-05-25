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
        cout << "scegli un' opzione: ";
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
          //  usr_choice = 0;
            cout << " command not valid "<<endl;
            break;
        }
    }
}

void Window::option_one() { 
    int counter = 0;
    cout << endl;
    if (shapes.size() == 0){
        cout << "non ci sono forme inserite" << endl;
    }
    else{
        for (auto it = shapes.begin(); it != shapes.end(); ++it) {
            cout << "\t" << counter <<" -\t";
            (*it)->Drawing(); 
            counter ++;
        }
    }
}

void Window::option_two() {
    int choice = 0;
    while (choice!=1 && choice!=2){
        cout << "che tipo di forma vuoi creare?"<<endl ;
        cout << "\t 1 - rettangolo" << endl;
        cout << "\t 2 - rombo" << endl;
        cout << "scegli un' opzione: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int w,l;
            TextArea* textarea_rect;

            cout << "width?\t";
            cin >> w;
            while (w <= 0){
                cout << "il valore inserito non è valido, riprova:  ";
                cin >> w;
            }
            cout << "height?\t";
            cin >> l;
            while (l <= 0){
                cout << "il valore inserito non è valido, riprova:  ";
                cin >> l;
            }
            shapes.push_back(std::make_shared<Rectangle>(w,l));
            textarea_req(shapes.size());
            cout << "creato rettangolo" << endl;
            break;

        case 2:
            int dL,dS;

            cout << "diagL?\t";
            cin >> dL;
            while (dL <= 0){
                cout << "il valore inserito non è valido, riprova:  ";
                cin >> dL;
            }
            cout << "diagS?\t";
            cin >> dS;
            while (dS <= 0){
                cout << "il valore inserito non è valido, riprova:  ";
                cin >> dS;
            }
            shapes.push_back(std::make_shared<Rhombus>(dL,dS));
            textarea_req(shapes.size());
            break;
           
        default:
            choice = 0;
            cout << " command not valid "<<endl;
            break;
            cout << "creato roombo" << endl;
        }
    }
        

}
void Window::textarea_req(int shape_position){
    int font_size=0;
    char text[SLEN];                                        //to fix
    char YN;

    cout << "vuoi inserire un testo? [Y/N]: ";
    cin >> YN;
    while (YN != 'Y' && YN != 'N'){
        cout << "risposta non valida" << endl;
        cout << "vuoi inserire un testo? [Y/N]: ";
        cin >> YN;
    }
    if (YN == 'Y'){
        cout <<"che testo vuoi inserire?" ;
        cin >> text; 
        shapes[shape_position-1]->SetText(text);
        
        cout << "con quale font size?" ;
        cin >> font_size;
    
        while (font_size <= 0){
            cout << "il valore inserito non è valido, riprova:  ";
            cout << "con quale font size?" ;
            cin >> font_size;
        }
        shapes[shape_position-1]->SetFontSize((unsigned int)(font_size));
    }
}

void Window::option_three(){
    int choice_del;
    if (shapes.size() == 0){
        cout << "non ci sono forme da eliminare";
    }
    else{
        cout << "Quale forma vuoi eliminare? ";
        option_one();
        cout << "scegli una forma: ";
        cin >> choice_del;
        while (choice_del >= shapes.size() && choice_del < 0){
            cout << "il valore inserito non è valido, riprova:  ";
            cout << "scegli una forma: ";
            cin >> choice_del;
        }
        shapes[choice_del]->Reset();
        shapes.erase(shapes.begin() + choice_del);
    }
}
void Window::option_four(){
    int i;
    for (i=0 ; i < shapes.size(); i++){
        shapes[i]->Reset(); 
        shapes.erase(shapes.begin() + i);
       
    }
    cout << "tutte le forme sono state eliminate" << endl;
}