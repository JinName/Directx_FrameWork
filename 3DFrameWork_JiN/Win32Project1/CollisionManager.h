#pragma once
#include "Header.h"

class CCollisionManager
{
private:
	// 충돌박스들을 리스트로 가지고 있음
	// ex) Character vs TileList 타일들과 충돌체크
public:
	CCollisionManager();
	~CCollisionManager();

	void Init();
	void Update();
};

