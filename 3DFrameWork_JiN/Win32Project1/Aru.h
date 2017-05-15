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

	// �ִϸ��̼� ��ȣ
	int m_iAnimate_Num;
	// �ִϸ��̼� ���� ��������Ʈ ũ�Ⱑ �ٸ��Ƿ� RECT �缳�� �ʿ�
	

public:
	CAru();
	~CAru();

	// ���⿡ ���� �ִϸ��̼� ��ȣ ���� �Լ�
	void Set_Animation();
	// ĳ���� �ֱ� ���¿� ���� DrawBitmap Reverse ����
	bool Check_Reverse();

	void Init(LPDIRECT3DDEVICE9 _pDevice);
	void Update();
	void Render();
	void Clean();
};

