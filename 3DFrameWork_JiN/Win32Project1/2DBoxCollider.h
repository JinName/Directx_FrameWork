#pragma once
#include "Header.h"

class C2DBoxCollider
{
private:
	bool isVertical;
	bool isHorizontal;
public:
	C2DBoxCollider();
	~C2DBoxCollider();

	// init
	void Init();
	
	// RECT 충돌
	bool isIntersect(RECT _object1, RECT _object2);

	// 수직, 수평 충돌 여부 반환
	int Get_Vertical_or_Horizontal();

};

