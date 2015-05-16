#ifndef MyDrive_H
#define MyDrive_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CommandBase.h"

class MyDrive: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon* leftMC;
	Talon* rightMC;
	float mult;
public:
	MyDrive();
	void InitDefaultCommand();
	static float Limit(float num, float max);
	void arcadeDrive(float moveValue, float rotateValue);
};

#endif
