#include "main.h"
#include "lemlib/api.hpp"
#include "CustomFiles/DriveOdomConst.hpp"
// #include "CustomFiles/Cata.hpp"
#include "pros/adi.hpp"
// ..................................................................................
// ..................................................................................


bool Blocker = false;
bool Wings = false;

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button()
{
	static bool pressed = false;
	pressed = !pressed;
	if (pressed)
	{
		pros::lcd::set_text(2, "I was pressed!");
	}
	else
	{
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize()
{
	chassis.calibrate();
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Starfall On Top");
	pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled()
{
	pros::lcd::initialize();
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize()
{
	pros::lcd::initialize();
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous()
{
	// Offside match auton
	chassis.setPose(36, 60, 180);
	chassis.moveTo(36, 11, 4000, 95.25);
	chassis.moveTo(43, 11, 2000, 95.25);
	chassis.moveTo(31, 33, 3000, 95.25);
	chassis.moveTo(54, 56, 4000, 82.55);
	chassis.moveTo(31, 33, 3000, 95.25);
	chassis.moveTo(24, 11, 4000, 82.55);
	Intake.move(127);
	chassis.turnTo(24, 11, 1000, true, 50);
	chassis.moveTo(24, 11, 1000, 50);
	Intake.set_brake_mode(MOTOR_BRAKE_BRAKE);
	Intake.move(0);
	pros::delay(100);
	Intake.set_brake_mode(MOTOR_BRAKE_COAST);

	// Onside match auton
	// chassis.setPose(-36, 60, 180);
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol()
{

	while (true)
	{
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
						 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
						 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
		
		
		// Intake controller
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
		{
			Intake.move(127);
		}
		else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
		{
			Intake.move(-127);
		}
		else
		{
			Intake.move(0);
		}

		// Cata controller
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
			Cata.move(127);
		}
		else {
			Cata.brake();
		}
		
	// 	if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)) {
    //   		while(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)) {
    //     		pros::delay(1);
    //   		}
    //   		Wings = !Wings;
    //   		WingL.set_value(Wings);
    //   		WingR.set_value(Wings);
    // }

		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)) {
              Wings = !Wings;
              WingL.set_value(Wings);
              WingR.set_value(Wings);
    }


		// Split arcade drive code
		int power = master.get_analog(ANALOG_LEFT_Y);
		int turn = master.get_analog(ANALOG_RIGHT_X);
		int left = power + turn;
		int right = power - turn;
		Leftsidedrive.move(left);
		Rightsidedrive.move(right);

		// setIntakeMotor();

		pros::delay(20);
	}
}
