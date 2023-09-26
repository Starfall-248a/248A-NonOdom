#include "main.h"

void setIntake(int power){
    Intake = power;   
}

void setIntakeMotor(){
    int intakePower = 127 * (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) - master.get_digital(pros::E_CONTROLLER_DIGITAL_R2));
    setIntake(intakePower);
}