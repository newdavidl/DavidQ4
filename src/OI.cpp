#include "OI.h"
#include "WPILib.h"
#include "CommandBase.h"

OI::OI() : joystick(new Joystick(JOYSTICK))
{

}

Joystick* OI::getJoystick()
{
	return joystick;
}
