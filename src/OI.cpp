/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include "RobotMap.h"

#include <WPILib.h>

OI::OI() :
	drive(DRIVER_JOY)
{
	// Process operator interface input here.
}

double OI::getAxis(int axis)
{
	return drive.GetRawAxis(axis);
}
