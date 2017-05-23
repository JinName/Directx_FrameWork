#pragma once
#include "Header.h"
#include "Entity.h"
#include "Sprite.h"

class CMonster : public CEntity
{
private:
	CSprite m_Sprite;

	// �¿� �ִ� �ּ� �̵� ����
	float m_fMax_x;
	float m_fMin_x;

	// �� �� ó�� �̵����� ����
	float m_iDirection;

	// �̵� �ӵ�
	float m_fSpeed;
public:
	CMonster();
	~CMonster();

	// ���� �¿� ������
	void Monster_Move();

	void Init(LPDIRECT3DDEVICE9 _pDevice);
	void Update();
	void Render();
	void Clean();
};

