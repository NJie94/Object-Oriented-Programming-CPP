#pragma once

#include "Device.h"
#include"Battery.h"
#include <cstring>

class SolarPanel : public Device
{
public:
	SolarPanel();
	SolarPanel(const SolarPanel& orig);
	virtual void Operate();
	virtual ~SolarPanel();
	virtual Device* clone() const;
};