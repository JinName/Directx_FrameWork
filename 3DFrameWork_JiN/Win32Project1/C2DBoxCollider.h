#pragma once
#include "Header.h"

class C2DBoxCollider
{
public:
	C2DBoxCollider();
	~C2DBoxCollider();

	// RECT Ãæµ¹
	static bool isIntersect(RECT _object1, RECT _object2);

};

