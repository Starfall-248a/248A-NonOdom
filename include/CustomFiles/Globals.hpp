#include "main.h"
#pragma once

// Motors for drivetrain, cata, and intake
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor FL(3, pros::E_MOTOR_GEARSET_06, true); // port 3, blue gearbox, reversed
pros::Motor BL(4, pros::E_MOTOR_GEARSET_06, true); // port 4, blue gearbox, reversed
pros::Motor TL(5, pros::E_MOTOR_GEARSET_06, false); // port 5, blue gearbox, not reveresed
pros::Motor FR(6, pros::E_MOTOR_GEARSET_06, false); // port 6, blue gearbox, not reveresed
pros::Motor BR(7, pros::E_MOTOR_GEARSET_06, false); // port 7, blue gearbox, not reveresed
pros::Motor TR(8, pros::E_MOTOR_GEARSET_06, true); // port 8, blue gearbox, reversed
pros::Motor Cata(9, pros::E_MOTOR_GEARSET_36, true); // port 9, red gearbox, reversed
pros::Motor Intake(10, pros::E_MOTOR_GEARSET_06, false); // port 11, blue gearbox, not reveresed

// Motor groups for drive
pros::MotorGroup Leftsidedrive({FL, BL, TL});
pros::MotorGroup Rightsidedrive({FR, BR, TR});

//Pnematics
pros::ADIDigitalOut WingL('B'); // 3 Wire slot b, Left wing
pros::ADIDigitalOut WingR('C'); // 3 Wire slot c, Right wing
pros::ADIDigitalOut Blocka('D'); // 3 Wire slot d, Blocka

// Rotation sensors for odom
pros::Rotation brot(11, false); // port 10, not reversed

// inertial sensor
pros::Imu inertial_sensor(2); // port 2

// Cata limit switch
pros::ADIDigitalIn Catalimit('A'); // slot a, limit switch

