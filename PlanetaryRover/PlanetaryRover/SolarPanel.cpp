#include "stdafx.h"
#include "SolarPanel.h"

#include <iostream>

using namespace std;

SolarPanel::SolarPanel()
{
}

SolarPanel::SolarPanel(const SolarPanel& orig) : Device(orig) 
{
}

SolarPanel::~SolarPanel() 
{
}

void SolarPanel::Operate() {

	Battery *battery = this->getBatteryConnected();

	// add 1 power to battery when it is connected
	if (battery->useBattery(-1))
	{
		cout << "Battery is charging" << endl;
	}
	else
	{
		cout << "Battery is fully charged" << endl;
	}

}

Device* SolarPanel::clone() const {

	return new SolarPanel(*this);
}