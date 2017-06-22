#include "stdafx.h"
#include "Radar.h"
#include "Battery.h"
#include "Device.h"
#include <cstring>
#include <cstdlib>
#include <random>
#include "iostream"

std::random_device rd; // random engine initialisation 
std::mt19937 random(rd()); //int ramdomize engine

using namespace std;

Radar::Radar() 
{
}

Radar::Radar(const Radar& orig) : Device(orig)
{
}

Radar::~Radar()
{
}

char const * Radar:: operate()
{
	Battery *battery = this->getBatteryConnected();

	//uses 4 power from the battery
	if (battery->useBattery(4))
	{
		return "PING\n";

		uniform_int_distribution<int> uniform(1, 4); //Print the message "PONG" randomly with 25% chance
		auto random_number = uniform(random);

			if (random_number == 1)
				return "PONG\n";

	}
	else
	{
		return"Battery Low\n";
	}
}

Device* Radar::clone() const {
	return new Radar(*this);
}

//end