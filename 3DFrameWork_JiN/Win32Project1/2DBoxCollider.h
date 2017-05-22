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
	
	// RECT �浹
	bool isIntersect(RECT _object1, RECT _object2);

	// ����, ���� �浹 ���� ��ȯ
	int Get_Vertical_or_Horizontal();

};

