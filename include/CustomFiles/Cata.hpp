// #include "main.h"
// #include "Globals.hpp"

// #pragma once

// void Catacontrol()
// {
//     if (Catalimit.get_value() == true && !master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
//     {
//         Cata.set_brake_mode(MOTOR_BRAKE_BRAKE);
//         Cata.move_voltage(0);
//     }
//     else if (Catalimit.get_value() == true && master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
//     {
//         Cata.move(127);
//     }
//     else if (Catalimit.get_value() == false)
//     {
//         Cata.set_brake_mode(MOTOR_BRAKE_BRAKE);
//         Cata.move(127);
//     }
//     pros::lcd::set_text(3, "cata do be runnin");
// }
