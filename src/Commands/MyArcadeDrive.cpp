#include "MyArcadeDrive.h"

MyArcadeDrive::MyArcadeDrive()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drive);
}

// Called just before this Command runs the first time
void MyArcadeDrive::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void MyArcadeDrive::Execute()
{
	if ( fabs(oi->getJoystick()->GetY()) > .2 )
	{
		CommandBase::drive->arcadeDrive(oi->getJoystick()->GetY(), oi->getJoystick()->GetZ());
	}
	else
	{
		CommandBase::drive->arcadeDrive(0, 0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool MyArcadeDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void MyArcadeDrive::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MyArcadeDrive::Interrupted()
{

}
