#include "MyDrive.h"
#include "../RobotMap.h"
#include "CommandBase.h"
#include "Commands/MyArcadeDrive.h"
#define max(x, y) ((x) > (y) ? (x) : (y))

MyDrive::MyDrive() :
		Subsystem("MyDrive"), leftMC(new Talon(LEFT_TALON)), rightMC(new Talon(RIGHT_TALON)), mult(1)
{

}

void MyDrive::arcadeDrive(float moveValue, float rotateValue) {
	float leftMotorOutput;
			float rightMotorOutput;

			moveValue = MyDrive::Limit(moveValue,1.0) * mult;
			rotateValue = MyDrive::Limit(rotateValue,1.0);

			if (moveValue > 0.0)
			{
				if (rotateValue > 0.0)
				{
					leftMotorOutput = moveValue - rotateValue;
					rightMotorOutput = max(moveValue, rotateValue);
				}
				else
				{
					leftMotorOutput = max(moveValue, -rotateValue);
					rightMotorOutput = moveValue + rotateValue;
				}
			}
			else
			{
				if (rotateValue > 0.0)
				{
					leftMotorOutput = - max(-moveValue, rotateValue);
					rightMotorOutput = moveValue + rotateValue;
				}
				else
				{
					leftMotorOutput = moveValue - rotateValue;
					rightMotorOutput = - max(-moveValue, -rotateValue);
				}
			}
			//double mult;
			//if((moveValue >= 0.01 && rotateValue >= 0.01) || eRight->GetRate() == 0)
			//	mult = 1;
			//else
			//	mult = fabs(eLeft->GetRate()/eRight->GetRate());
			float limitedL = MyDrive::Limit(leftMotorOutput,1.0);
			float limitedR = -MyDrive::Limit(rightMotorOutput,1.0);
			//printf("%f, %f\n", eLeft->GetRate(), eRight->GetRate());

			/*
			//if(not rotating)
			 * {
			 * if(leftRate > rightRate)
			 * {
			 * increase right speed
			 * }
			 *
			 * else if(rightRate < leftRate)
			 * {
			 * increase left speed
			 * }
			 *
			 * else do nothing
			 *
			 *
			 */

			//if(rotateValue > 0)

			leftMC->Set(limitedL);
			rightMC->Set(limitedR);
}

void MyDrive::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new MyArcadeDrive);
}

float MyDrive::Limit(float num, float maximum)
{
	if (num>maximum)
		return maximum;
	else if (num < -maximum)
		return -maximum;
	else return num;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
