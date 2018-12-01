#include <Spark.h>
#include <VictorSP.h>
#include <AHRS.h>
#include <Encoder.h>
#include <Drive/DifferentialDrive.h>
#include <SpeedControllerGroup.h>

#pragma once

#include <Commands/Subsystem.h>

class DriveTrain : public frc::Subsystem {
public:
	DriveTrain();
	void InitDefaultCommand();
	void arcadeDrive(double, double);
private:
	Spark rightBack;
	VictorSP rightFront;
	VictorSP leftBack;
	VictorSP leftFront;
	SpeedControllerGroup leftMotor;
	SpeedControllerGroup rightMotor;

	DifferentialDrive drive;

};
