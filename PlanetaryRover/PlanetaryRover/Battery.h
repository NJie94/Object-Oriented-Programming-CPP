#pragma once

#include "Object.h"

class Battery : public Object {
private:
	int _charge;
	bool _connectToDevice;
	int _Power;
public:
	Battery(int Power);
	Battery(const Battery& orig);
	virtual ~Battery();
	void SetCharge(int power);

	int charge() { return _charge; }
	bool useBattery(int Power);
	bool connectToDevice();
	int CheckCharge();
	Battery* cloneBattery();

	
};
