#pragma once
#include "Header.h"
#include "Character.h"
#include "Sprite.h"

enum{ STAND, UP, DOWN, LEFT, ATTACK };

class CAru : public CCharacter
{
private:
	// ���ĵ�, �� �� ��(��), ����
	CSprite m_sprite[5];

	bool m_bAttacking;

	// ������ ������ ���� ( �¿� ��������Ʈ ������ )
	int currentDirection;

public:
	CAru();
	~CAru();

	void Init(LPDIRECT3DDEVICE9 _pDevice);
	void Update();
	void Render();
	void Clean();
};

