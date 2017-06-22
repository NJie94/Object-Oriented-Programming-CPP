#include "stdafx.h"
#include "Device.h"
#include "Rover.h"
#include "Battery.h"
#include <iostream>

using namespace std;

Device::Device() 
{
}

Device::Device(const Device& orig) {
	cerr << "Constructor" << endl;
	if (orig._battery != NULL)
		_battery = orig._battery->cloneBattery();
	else
		_battery = NULL;
}

Device::~Device() 
{
}

void Device::ConnectBattery(Battery* battery)
{
	_battery = battery;
}

Battery* Device::getBatteryConnected()
{
	return _battery;
}

Battery* Device::getBatteryDisconnected()
{
	Battery* battery = _battery;
	_battery = NULL;
	return battery;
}

Battery* Device::checkBattery()
{
	return _battery;
}

char const * Device::operate()
{
	return "Its working";
}