/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "DriveWithJoysticks.h"
#include "Robot.h"
#include "RobotMap.h"

DriveWithJoysticks::DriveWithJoysticks() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::drivetrain);
	checkKeys();
}

// Called just before this Command runs the first time
void DriveWithJoysticks::Initialize() {
	getPreferences();
}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoysticks::Execute() {
	double speed = driveProfile(Robot::oi.getAxis(LEFT_Y_AXIS));
	double turn = driveProfile(Robot::oi.getAxis(RIGHT_X_AXIS));

	Robot::drivetrain.arcadeDrive(-speed, turn);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoysticks::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveWithJoysticks::End() {
	Robot::drivetrain.arcadeDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoysticks::Interrupted() {
	Robot::drivetrain.arcadeDrive(0, 0);
}

double DriveWithJoysticks::driveProfile(double input) {
	if(fabs(input) <= deadzone){
			return 0;
		}

	double out = (maxSpeed - minSpeed) * fabs(input) + minSpeed;

	if(input > 0){
		return out;
	}
	if(input < 0){
		return -out;
	} else {
		return 0;
	}
}

void DriveWithJoysticks::getPreferences() {
	//Set Drive Profile parameters
	maxSpeed = Preferences::GetInstance()->GetDouble("Joysticks/Max Speed", 1);
	minSpeed = Preferences::GetInstance()->GetDouble("Joysticks/Min Speed", 0.35);
	deadzone = Preferences::GetInstance()->GetDouble("Joysticks/Deadzone", .025);
	acceleration = Preferences::GetInstance()->GetDouble("Joysticks/acceleration", .025);
}

void DriveWithJoysticks::checkKeys() {
	//Drive Profile Values
	if (!Preferences::GetInstance()->ContainsKey("Joysticks/Max Speed")) {
		Preferences::GetInstance()->PutDouble("Joysticks/Max Speed", 1.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Joysticks/Min Speed")) {
		Preferences::GetInstance()->PutDouble("Joysticks/Min Speed", 0.35);
	}
	if (!Preferences::GetInstance()->ContainsKey("Joysticks/Deadzone")) {
		Preferences::GetInstance()->PutDouble("Joysticks/Deadzone", .025);
	}
	if (!Preferences::GetInstance()->ContainsKey("Joysticks/acceleration")) {
		Preferences::GetInstance()->PutDouble("Joysticks/acceleration", 1.0);
	}
}
