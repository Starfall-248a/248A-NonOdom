#include "main.h"
#include "Globals.hpp"

void Catacontrol()
{
    if (Catalimit.get_value() == true && !master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
    {
        Cata.move_voltage(0);
    }
    else if (Catalimit.get_value() == true && master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
    {
        Cata.move_voltage(12000);
    }
    else if (Catalimit.get_value() == false)
    {
        Cata.move_voltage(12000);
        Intake.move_voltage(0);
    }
}
