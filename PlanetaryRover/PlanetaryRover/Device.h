#pragma once
#include "Battery.h"
#include "Object.h"

class Device : public Object
{
private:
	Battery* _battery;

public:
	Device();
	Device(const Device& orig);
	virtual ~Device();

	virtual char const * operate();
	void ConnectBattery(Battery* battery);
	Battery* getBatteryConnected();
	Battery* getBatteryDisconnected();
	Battery* checkBattery();

	virtual Device * clone() const = 0;

};