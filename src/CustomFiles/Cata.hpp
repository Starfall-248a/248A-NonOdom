#include "main.h"
#include "Globals.hpp"

void Catacontrol(){ 
     if (Catalimit.get_value() == true && !master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) { 
         Cata.move(127); 
     }else if (Catalimit.get_value() == true) { 
         Cata.brake(); 
     }else if (Catalimit.get_value() == false) { 
         Cata.move(127); 
     } 
	}
