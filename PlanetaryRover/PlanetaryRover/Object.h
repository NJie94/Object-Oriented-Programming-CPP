#pragma once

class Object
{
private: 
	static int _count;

public:
	Object();
	Object(const Object& orig);
	virtual ~Object();

	static int getCount();


};