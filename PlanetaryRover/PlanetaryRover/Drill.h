#pragma once

#include "Device.h"

class Drill : public Device
{
private:
	bool _safety;
	virtual void Operate();

public:
	Drill();
	Drill(const Drill& orig);
	void SafetyEnable(bool Battery);
	bool Safety();
	virtual ~Drill();

	virtual Device * clone() const;

};