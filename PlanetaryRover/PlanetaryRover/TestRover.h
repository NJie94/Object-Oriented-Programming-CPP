#pragma once

class TestRover
{
public:
	TestRover();
	virtual ~TestRover();
	void AttachTesting();
	void RadarTesting();
	void SolarPanelTesting();
	void DrillTesting();
	void RoversTesting();
	void MemoryLeaksTesting();
	void CopyConstructorTesting();
	void ObjectAliasingTesting();
};