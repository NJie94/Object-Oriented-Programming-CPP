#include "stdafx.h"
#include "Battery.h"
#include <iostream>

using namespace std;

Battery:: Battery(int Power)
{
	_charge = Power;
	_connectToDevice = false;
}

Battery::Battery(const Battery& orig)
{
}

Battery::~Battery()
{
}

bool Battery::connectToDevice()
{
	return _connectToDevice;
}

int Battery::CheckCharge()
{
	return _Power;
}

void Battery::SetCharge(int power)
{
	_Power = power;
}

bool Battery::useBattery(int Power)
{
	if (_charge >= Power)
	{
		_charge -= Power;
		_connectToDevice = true;
		return true;
	}

	return false;
}

Battery* Battery::cloneBattery()
{
	return new Battery(this->charge());
}
