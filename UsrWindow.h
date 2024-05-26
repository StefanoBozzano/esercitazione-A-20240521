/*! \file UsrWindow.h
	\brief Declaration of the general class Window

	Details.
*/


#ifndef USRWINDOW_H
#define USRWINDOW_H

#include<iostream> 
#include "CQuadrilateral.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include <vector>
#include <memory>

using namespace std;

/// @class Window
/// @brief to organize a container of shapes chosen by the user
class Window {
private:
    bool debug_win = false;
    int usr_choice = 0;
 
	vector< shared_ptr<Quadrilateral>> shapes;
	 void Loop();	

	/// @name user options
	/// @{
    void option_one();
    void option_two();
    void option_three();
    void option_four();
	/// @}
	
	void textarea_req();
	
public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Window();
	~Window();
	/// @}
};

#endif