#pragma once

#include <vector>
#include <iostream>

#include "Device.h"
#include "Battery.h"
#include "Object.h"

using namespace std;

class Rover : public Object
{
private : 
	vector <Device*> _devices;
	vector <Battery*> _batteries;
	string _name;

public:
	Rover();
	Rover(string name);
	Rover(const Rover& orig);
	virtual ~Rover();
	int deviceCount() const;
	int batteryCount() const;
	void attachDevice(Device * device);
	void attachBattery(Battery * battery);
	Battery * GoodBattery();

	void ConnectDeviceWithBattery(Device* device, Battery* battery);
	Battery* disconnectDeviceAndBattery(Device* device);
	void detachDevice(Device* device);
	void operate();
};