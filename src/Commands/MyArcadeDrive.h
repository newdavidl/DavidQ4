#ifndef MyArcadeDrive_H
#define MyArcadeDrive_H

#include "../CommandBase.h"
#include "WPILib.h"

class MyArcadeDrive: public CommandBase
{
public:
	MyArcadeDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
