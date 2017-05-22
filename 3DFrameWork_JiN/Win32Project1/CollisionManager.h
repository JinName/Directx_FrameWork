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
	void Update(list<RECT> &_tileList, CAru &_aru);
};

