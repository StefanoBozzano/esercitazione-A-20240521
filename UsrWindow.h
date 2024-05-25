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
/// @brief an abstract base class for quadrilateral
class Window {
private:
    bool debug_win = true;
    int usr_choice = 0;
 
	vector< shared_ptr<Quadrilateral>> shapes;
	
	//std::vector<std::shared_ptr<Quadrilateral>> shapes;

    // Aggiungi un Square e un Rhombus al vector
   // shapes.push_back(std::make_shared<Square>(5.0));
    //shapes.push_back(std::make_shared<Rhombus>(3.0, 4.0));

    // Itera sugli oggetti e chiama il metodo display
    //for (const auto& shape : shapes) {
    //    shape->display();
    //}
	//void add_object();
	void textarea_req(int shape_position);
	

public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Window();
	
	//virtual ~Window();
	/// @}

    /// @name BASIC HANDLING
	/// @{
	//void Init();	
    void Loop();						
	//void Reset();												
	/// @}


    /// @name 
	/// @{
	//void options();
    void option_one();
    void option_two();
    void option_three();
    void option_four();
	/// @}

	
	
	


};

#endif