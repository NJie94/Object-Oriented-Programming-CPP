#include "stdafx.h"
#include "Object.h"

using namespace std;

int Object::_count = 0;

int Object::getCount()
{
	return _count;
}

Object::Object()
{
	_count++;
}

Object::Object(const Object& orig)
{
	_count++;
}

Object::~Object()
{
	_count--;
}
