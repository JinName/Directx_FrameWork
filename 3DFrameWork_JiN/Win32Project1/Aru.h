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

	// ĳ���� �ӵ�
	float m_fSpeed;

	// ĳ���� ����
	D3DXVECTOR2 m_vDirection;

	// �ൿ ����
	bool m_bAttacking;
	bool m_bJump;
	// ���� �뵵
	// ���� ������ �����϶� true (�ٴڿ� �پ�������)
	bool m_bJump_is_Possible;
	// ������ �� ������ ����
	float m_fOld_Pos_y;
	bool m_bOld_Check;

	// ������ ������ ���� ( �¿� ��������Ʈ ������ )
	int currentDirection;

	// �ִϸ��̼� ��ȣ
	int m_iAnimate_Num;
	// �ִϸ��̼� ���� ��������Ʈ ũ�Ⱑ �ٸ��Ƿ� RECT �缳�� �ʿ�

	// �߷°��� �ð�
	DWORD dwOldtime;
	float m_fCharacter_mass; // ĳ���� ����
	// �ӷ�
	float velocity;

	// �浹 �� ĳ���� ������ ����
	bool isVertical; // ���� �浹
	bool isHorizontal; // ���� �浹
	bool isHit; // �ǰ�

public:
	CAru();
	~CAru();

	// �浹 �� ���� ����
	void Set_isVertical(bool _isVertical) { isVertical = _isVertical; }
	void Set_isHorizontal(bool _isHorizontal) { isHorizontal = _isHorizontal; }
	void Set_isHit(bool _isHit) { isHit = _isHit; }

	// ���⿡ ���� �ִϸ��̼� ��ȣ ���� �Լ�
	void Set_Animation();
	// ĳ���� �ֱ� ���¿� ���� DrawBitmap Reverse ����
	bool Check_Reverse();

	// ĳ���� �߷�
	void Gravity();
	// ĳ���� ����
	void Jump();

	// ĳ���Ͱ� Ÿ�ϰ� �浹 �� ������
	void isCrash_Tile();
	// ���� �ε�������
	void isCrash_Enemy();

	// Move
	VOID Move();

	void Init(LPDIRECT3DDEVICE9 _pDevice);
	void Update();
	void Render();
	void Clean();
};

