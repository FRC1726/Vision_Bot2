/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int kLeftMotor = 1;
// constexpr int kRightMotor = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int kRangeFinderPort = 1;
// constexpr int kRangeFinderModule = 1;

constexpr int RIGHT_BACK = 1;
constexpr int RIGHT_FRONT = 0;
constexpr int LEFT_BACK = 3;
constexpr int LEFT_FRONT = 2;

constexpr int DRIVER_JOY = 0;

constexpr int LEFT_X_AXIS = 0;
constexpr int LEFT_Y_AXIS = 1;
constexpr int RIGHT_X_AXIS = 4;
constexpr int RIGHT_Y_AXIS = 5;
constexpr int LEFT_TRIGGER = 2;
constexpr int RIGHT_TRIGGER = 3;
