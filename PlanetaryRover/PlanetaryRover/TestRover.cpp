#include "stdafx.h"
#include "TestRover.h"
#include "Rover.h"
#include "Device.h"
#include "Battery.h"
#include "Radar.h"
#include "SolarPanel.h"
#include "Drill.h"
#include "Object.h"
#include <cassert>
#include <iostream>


using namespace std;

TestRover::TestRover() {
}

TestRover::~TestRover() {
}

void TestRover::AttachTesting()
{
	cout << Object::getCount() << endl;
	Rover * Curosity = new Rover();

	//Set three batteries to power device 
	Battery * battery = new Battery(6);
	Battery * battery2 = new Battery(3);
	Battery * battery3 = new Battery(5);

	//Rover attach batteries
	Curosity->attachBattery(battery);
	Curosity->attachBattery(battery2);
	Curosity->attachBattery(battery3);
	
	//Rover attach device
	Radar* radar = new Radar();
	Curosity->attachDevice(radar);
	assert(Curosity->deviceCount() == 1);

	//Able to choose the good battery
	Drill* drill = new Drill();
	Curosity->attachDevice(drill);
	assert(Curosity->deviceCount() == 2);
	
	
	SolarPanel* SP = new SolarPanel();
	Curosity->attachDevice(SP);
	assert(Curosity->deviceCount() == 3);

	// Rover can detach a Device
	Curosity->detachDevice(SP);
	assert(Curosity->deviceCount() == 2);

	// Devices can connected and disconnected from Battery
	Curosity->disconnectDeviceAndBattery(radar);
	assert(radar->getBatteryConnected() == NULL);
	Curosity->ConnectDeviceWithBattery(radar, battery3);
	assert(radar->getBatteryConnected() == battery3);

	Curosity->attachDevice(SP);
	delete Curosity;

	assert(Object::getCount() == 0);
}

void TestRover::RadarTesting()
{
	cout << "Memory object count: " << Object::getCount() << "\n";
	Radar * radar = new Radar();
	Battery * battery = new Battery(9);
	radar->ConnectBattery(battery);
	cout << radar->operate();
	cout << radar->operate();
	cout << radar->operate();
	cout << radar->operate();
	cout << radar->operate();
	cout << radar->operate();
	cout << radar->operate();
	assert(radar->checkBattery()->CheckCharge() == 9);
	cout << "Memory object count: " << Object::getCount() << endl;
	delete radar;
	cout << "Memory object count: " << Object::getCount() << endl;
}

void TestRover::SolarPanelTesting()
{
	cout << "Memory object count: " << Object::getCount() << endl;
	SolarPanel * SP = new SolarPanel();
	Battery * battery = new Battery(9);
	SP->ConnectBattery(battery);
	cout<<SP->operate();
	SP->checkBattery()->SetCharge(8);
	cout<<SP->operate();
	assert(SP->checkBattery()->CheckCharge() == 9);
	cout << "Memory object count: " << Object::getCount() <<endl;
	delete SP;
	cout << "Memory object count: " << Object::getCount() << endl;
}

void TestRover::DrillTesting()
{
	cout << "Memory object count: " << Object::getCount() << endl;
	Drill * drill = new Drill();
	Battery * battery = new Battery(7);
	drill->ConnectBattery(battery);
	assert(drill->Safety() == true);
	cout << drill->operate();
	drill->SafetyEnable(false);
	assert(drill->Safety() == false);
	cout << drill->operate();
	assert(drill->checkBattery()->CheckCharge() == 7);
	cout << "Memory object count: " << Object::getCount() << endl;
	delete drill;
	cout << "Memory object count: " << Object::getCount() << endl;
}

void TestRover::RoversTesting()
{
	cout << "Memory object count: " << Object::getCount() << endl;
	Rover * Curosity = new Rover();
	Drill * drill = new Drill();
	Radar * radar = new Radar();
	SolarPanel * SP = new SolarPanel();
	Battery * bat1 = new Battery(8);
	Battery * bat2 = new Battery(8);
	bat2->SetCharge(80);
	Battery * bat3 = new Battery(8);
	bat3->SetCharge(0);
	Curosity->attachBattery(bat1);
	Curosity->attachBattery(bat2);
	Curosity->attachBattery(bat3);
	Curosity->attachDevice(drill);
	Curosity->attachDevice(radar);
	Curosity->attachDevice(SP);
	Curosity->operate();
	drill->SafetyEnable(false);
	Curosity->operate();
	cout << "Memory object count: " << Object::getCount() << endl;
	delete Curosity;
	cout << "Memory object count: " << Object::getCount() << endl;
}

void TestRover::MemoryLeaksTesting()
{
	Rover * Curosity = new Rover("rover2");

	Battery * battery = new Battery(10);

	Radar * radar = new Radar();

	Curosity->attachBattery(battery);

	Curosity->attachDevice(radar);

	delete Curosity;

	assert(Object::getCount() == 0);

}

void TestRover::CopyConstructorTesting()
{
	Rover* Curosity = new Rover("rover3");

	Battery* battery = new Battery(5);

	Curosity->attachBattery(battery);
	Curosity->attachDevice(new Radar());

	Rover* acopy = new Rover(*Curosity);

	assert(Curosity->deviceCount() == acopy->deviceCount());
}

void TestRover::ObjectAliasingTesting()
{
	Rover* Curosity = new Rover("rover4");
	Battery* battery = new Battery(7);

	Curosity->attachBattery(battery);
	Curosity->attachDevice(new Radar());

	Rover* acopy = new Rover(*Curosity);

	delete Curosity;

	// if test fails the following line will causes a crash
	delete acopy;
	assert(Object::getCount() == 0);
	// if the program is still running, then the test has passed
	assert(true);
}
