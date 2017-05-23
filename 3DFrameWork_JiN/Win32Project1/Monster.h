#pragma once
#include "Header.h"
#include "Entity.h"
#include "Sprite.h"

class CMonster : public CEntity
{
private:
	CSprite m_Sprite;

	// 좌우 최대 최소 이동 범위
	float m_fMax_x;
	float m_fMin_x;

	// 좌 우 처음 이동방향 랜덤
	float m_iDirection;

	// 이동 속도
	float m_fSpeed;
public:
	CMonster();
	~CMonster();

	// 몬스터 좌우 움직임
	void Monster_Move();

	void Init(LPDIRECT3DDEVICE9 _pDevice);
	void Update();
	void Render();
	void Clean();
};

