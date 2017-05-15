#include "C2DBoxCollider.h"


C2DBoxCollider::C2DBoxCollider()
{
}

C2DBoxCollider::~C2DBoxCollider()
{
}


bool C2DBoxCollider::isIntersect(RECT _object1, RECT _object2)
{
	if (_object1.right >= _object2.left && _object1.left <= _object2.right && _object1.top >= _object2.bottom && _object1.bottom <= _object2.top)
	{
		return true;
	}

	return false;
}