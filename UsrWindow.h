/*! \file UsrWindow.h
	\brief Declaration of the general class Window

	Details.
*/


#ifndef USRWINDOW_H
#define USRWINDOW_H

#include<iostream> 
#include "CQuadrilateral.h"


using namespace std;

/// @class Window
/// @brief an abstract base class for quadrilateral
class Window {
private:
    bool debug_win = true;
    int usr_choice;

	quadrilateral_container* first_quadrilateral_pointer = NULL;
	void new_rectangle();
	Rectangle usr_rectangle();
	void new_rhombus();
	

public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Window();
	
	//virtual ~Window();
	/// @}

    /// @name BASIC HANDLING
	/// @{
	void Init();	
    void Loop();						
	void Reset();												
	/// @}


    /// @name 
	/// @{
	void options();
    void option_one();
    void option_two();
    void option_tree();
    void option_four();
	/// @}

	
	
	


};

#endif