#pragma once
#include "Header.h"

class CCollisionManager
{
private:
	// �浹�ڽ����� ����Ʈ�� ������ ����
	// ex) Character vs TileList Ÿ�ϵ�� �浹üũ
public:
	CCollisionManager();
	~CCollisionManager();

	void Init();
	void Update();
};

