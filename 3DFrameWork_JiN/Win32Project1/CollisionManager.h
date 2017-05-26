#pragma once
#include "Header.h"
#include "2DBoxCollider.h"
#include "Entity.h"
#include "Tile.h"
#include "Aru.h"

class CCollisionManager
{
private:
	// �浹�ڽ����� ����Ʈ�� ������ ����
	// ex) Character vs TileList Ÿ�ϵ�� �浹üũ
	C2DBoxCollider m_boxCollider;
public:
	CCollisionManager();
	~CCollisionManager();

	void Init();
	void Update(list<RECT> &_Rect_List, CAru &_aru);
	void Update(CTile* _Tile_Array, int _Tile_Array_Len, CAru &_aru);
};

