#include "main.h"
#include "lemlib/api.hpp"
#include "Globals.hpp"
#include "PIDControllers.hpp"

lemlib::Drivetrain_t drivetrain {
	&Leftsidedrive, // left drivetrain motors
	&Rightsidedrive, // right drivetrain motors
	11.3, // track width
	3.25, // wheel diameter
	360 // wheel rpm
};

// odometry struct
lemlib::OdomSensors_t sensors {
	nullptr, // vertical tracking wheel 1
	nullptr, // vertical tracking wheel 2
	nullptr, // horizontal tracking wheel 1
	nullptr, // horizontal tracking wheel 2
	&inertial_sensor // inertial sensor
};

lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);