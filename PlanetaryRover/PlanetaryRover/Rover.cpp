#include "stdafx.h"
#include "Rover.h"
#include "Battery.h"
#include "Device.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

Rover::Rover()
{
}

Rover::Rover(string name)
{
}

Rover::Rover(const Rover& orig)
{
	for (int i = 0; i < orig._batteries.size(); ++i)
	{
		Battery* battery = orig._batteries[i];

		_batteries.push_back(battery->cloneBattery());
	}
	for (int i = 0; i < orig._devices.size(); ++i)
	{
		Device* device = orig._devices[i];

		_devices.push_back(device->clone());
	}
}


//Delete all the device and batteries
Rover::~Rover()
{
	for (int i = 0; i < _devices.size(); ++i)
	{
		this->disconnectDeviceAndBattery(_devices[i]);
		delete _devices[i];
	}

	for (int i = 0; i < _batteries.size(); ++i)
	{
		delete _batteries[i];
	}
}

int Rover::deviceCount() const
{
	return _devices.size();
}

int Rover::batteryCount() const
{
	return _batteries.size();
}

void Rover::attachDevice(Device* device)
{
	if (_batteries.size() > 0)
	{
		this->ConnectDeviceWithBattery(device, this->GoodBattery());
		_devices.push_back(device);
	}
	else
	{
		// cannot attach device because there is no battery
		cout << "No Battery detacted, cannot attach devices";
	}
}

void Rover::ConnectDeviceWithBattery(Device* device, Battery* battery)
{
	//Enable batteries to be use with device attached
	battery->useBattery(0);

	device->ConnectBattery(battery);
}

// insert a battery to a vector
void Rover::attachBattery(Battery* battery)
{
	// if _batteries is empty, add a new battery
	if (_batteries.size() == 0)
	{
		_batteries.push_back(battery);
	}
	else
	{
		vector <Battery*>::iterator iterator = _batteries.begin();

		// if the battery charge is less than the first charge add it in the beginning
		if (battery->charge() < _batteries[0]->charge())
		{
			_batteries.insert(iterator, battery);
		}
		else
		{
			// Sort through and find a slot for battery to insert
			for (int i = 0; i < _batteries.size(); ++i)
			{
				if (battery->charge() > _batteries[i]->charge())
				{
					_batteries.insert(iterator + (i + 1), battery);
					break;
				}
			}
		}

	}

}

Battery* Rover::disconnectDeviceAndBattery(Device* device)
{
	Battery* temperory = device->getBatteryConnected();

	// add it back to the rover's _batteries for future use
	this->attachBattery(temperory);

	device->ConnectBattery(NULL);
	return temperory;
}

Battery* Rover::GoodBattery()
{
	Battery* good = _batteries.back();
	_batteries.pop_back();

	return good;
}

void Rover::detachDevice(Device* device)
{
	// Remove Battery
	Battery* battery = this->disconnectDeviceAndBattery(device);

	// Delete Devices
	for (int i = 0; i < _devices.size(); ++i)
	{
		if (_devices[i] == device)
		{
			_devices.erase(_devices.begin() + i);
		}
	}
}

void Rover::operate()
{
	for (int i = 0; i < _devices.size(); ++i)
	{
		_devices[i]->operate();
	}
}