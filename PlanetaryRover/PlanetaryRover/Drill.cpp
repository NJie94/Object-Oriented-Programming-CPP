#include "stdafx.h"
#include "Drill.h"
#include <iostream>

using namespace std;

Drill::Drill()
{
	_safety= false;
}

Drill::Drill(const Drill& orig) : Device(orig) 
{
}

Drill::~Drill() 
{
}

void Drill:: Operate()
{
	if (_safety)
	{
		cout <<"Safety First\n"<<endl;
	}
	else
	{
		Battery *battery = this->getBatteryConnected();

		if (battery->useBattery(10))
		{
			cout << "VRMM! VRMM!" << endl;
		}
		else
		{
			cout << "Battery Low" << endl;
		}
	}
}

void Drill::SafetyEnable(bool Battery)
{
	_safety = Battery;
}

bool Drill::Safety()
{
	return _safety;
}

Device* Drill::clone() const {

	return new Drill(*this);
}
