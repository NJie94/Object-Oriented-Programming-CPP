// PlanetaryRover.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TestRover.h"
#include <iostream>

using namespace std;

int main()
{
	TestRover * Test = new TestRover();

	Test->AttachTesting();
	Test->RadarTesting();
	Test->SolarPanelTesting();
	Test->DrillTesting();
	cout << "Success!\n" << endl;
	Test->RoversTesting();
	Test->MemoryLeaksTesting();

	cin.get();
	return 0;

}

