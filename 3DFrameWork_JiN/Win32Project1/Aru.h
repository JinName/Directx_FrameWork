#pragma once
#include "Header.h"
#include "Character.h"
#include "Sprite.h"

enum{ STAND, UP, DOWN, LEFT, ATTACK };

class CAru : public CCharacter
{
private:
	// 스탠드, 상 하 좌(우), 공격
	CSprite m_sprite[5];

	bool m_bAttacking;

	// 마지막 움직인 방향 ( 좌우 스프라이트 반전용 )
	int currentDirection;

public:
	CAru();
	~CAru();

	void Init(LPDIRECT3DDEVICE9 _pDevice);
	void Update();
	void Render();
	void Clean();
};

