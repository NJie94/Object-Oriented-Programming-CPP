#pragma once

#include "Device.h"

class Radar : public Device
{
public:
	Radar();
	Radar(const Radar& orig);
	virtual ~Radar();
	char const * operate() override;
	virtual Device* clone() const;
};