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

// tracking wheels
lemlib::TrackingWheel back_tracking_wheel(
	&brot, // uses "brot" as the encoder.
	2.75, // 2.75" wheel diameter
	4.3, // 4.3" offset from tracking center
	1 // 1:1 gear ratio
);

// odometry struct
lemlib::OdomSensors_t sensors {
	nullptr, // vertical tracking wheel 1
	nullptr, // vertical tracking wheel 2
	&back_tracking_wheel, // horizontal tracking wheel 1
	nullptr, // we don't have a second tracking wheel, so we set it to nullptr
	&inertial_sensor // inertial sensor
};

// Chassis constructor
lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);