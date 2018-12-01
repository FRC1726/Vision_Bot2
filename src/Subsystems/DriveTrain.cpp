/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "DriveTrain.h"
#include "../RobotMap.h"

DriveTrain::DriveTrain() : Subsystem("ExampleSubsystem"),
	rightBack(RIGHT_BACK),
	rightFront(RIGHT_FRONT),
	leftBack(LEFT_BACK),
	leftFront(LEFT_FRONT),
	leftMotor(leftBack, leftFront),
	rightMotor(rightBack, rightFront),
	drive(leftMotor, rightMotor)
{

}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void DriveTrain::arcadeDrive(double speed, double turn){
	drive.ArcadeDrive(speed, turn, true);
}
