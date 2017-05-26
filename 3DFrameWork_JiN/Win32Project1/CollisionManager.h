#pragma once
#include "Header.h"
#include "2DBoxCollider.h"
#include "Entity.h"
#include "Tile.h"
#include "Aru.h"

class CCollisionManager
{
private:
	// 충돌박스들을 리스트로 가지고 있음
	// ex) Character vs TileList 타일들과 충돌체크
	C2DBoxCollider m_boxCollider;
public:
	CCollisionManager();
	~CCollisionManager();

	void Init();
	void Update(list<RECT> &_Rect_List, CAru &_aru);
	void Update(CTile* _Tile_Array, int _Tile_Array_Len, CAru &_aru);
};

