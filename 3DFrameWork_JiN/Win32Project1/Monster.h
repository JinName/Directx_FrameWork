#pragma once
#include "Header.h"
#include "Entity.h"
#include "Sprite.h"

class CMonster : public CEntity
{
private:
	CSprite m_Sprite;

	// HP
	int m_iHP;

	// �¿� �ִ� �ּ� �̵� ����
	float m_fMax_x;
	float m_fMin_x;

	// �� �� ó�� �̵����� ����
	float m_iDirection;

	// �̵� �ӵ�
	float m_fSpeed;

	// �浹���� ��
	bool m_b_is_Collision;

	// HP �� ��������
	bool m_bDestroy;
public:
	CMonster();
	~CMonster();

	bool Get_Destroy() { return m_bDestroy; }

	bool Get_isCollision() { return m_b_is_Collision; }
	void Set_isCollision(bool _b_is_Collision) { m_b_is_Collision = _b_is_Collision; }

	// ���� �¿� ������
	void Monster_Move();

	// �浹��
	void Monster_Collision_Check();

	// ���� �Ҹ�
	void Monster_Destroy();

	void Init(LPDIRECT3DDEVICE9 _pDevice, D3DXVECTOR3 _vPos, float _fMove_Width);
	void Update();
	void Render();
	void Clean();
};

