#pragma once
#include "Header.h"

class C2DBoxCollider
{
public:
	C2DBoxCollider();
	~C2DBoxCollider();

	// RECT �浹
	static bool isIntersect(RECT _object1, RECT _object2);

};

