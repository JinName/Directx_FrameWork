#include "Monster.h"



CMonster::CMonster()
{
}


CMonster::~CMonster()
{
}

void CMonster::Monster_Move()
{
	if (m_iDirection == 1)
	{
		m_vPos.x -= m_fSpeed;
	}
	else if (m_iDirection == 2)
	{
		m_vPos.x += m_fSpeed;
	}
	
	if (m_vPos.x <= m_fMin_x)
	{
		m_iDirection = 2;
	}
	else if (m_vPos.x >= m_fMax_x)
	{
		m_iDirection = 1;
	}
}

void CMonster::Monster_Collision_Check()
{
	if (m_b_is_Collision == true)
	{
		m_iHP -= 1;

		m_b_is_Collision = false;
	}
}

void CMonster::Monster_Destroy()
{
	if (m_iHP == 0)
	{
		m_bDestroy = true;
	}
}

void CMonster::Init(LPDIRECT3DDEVICE9 _pDevice, D3DXVECTOR3 _vPos, float _fMove_Width)
{
	m_iHP = 3;

	m_b_is_Collision = false;

	srand((unsigned int)time(NULL));

	m_iDirection = rand() % 2 + 1; // 1~2 난수 1 : 좌 / 2 : 우
	m_vPos = _vPos;

	m_fMin_x = _vPos.x - _fMove_Width / 2.0f;
	m_fMax_x = _vPos.x + _fMove_Width / 2.0f;

	m_fSpeed = 0.8f;

	Line_Init(_pDevice);

	m_Sprite.Create_Sprite(_pDevice, L"2D_Sprites\\Cake_A.png", 408, 48, 8, NULL);
}

void CMonster::Update()
{
	Monster_Move();

	// 충돌시
	Monster_Collision_Check();

	// HP 다달면
	Monster_Destroy();

	m_Sprite.Animation_Frame();

	Set_Collider(m_Sprite.Get_Sprite_Width(), m_Sprite.Get_Sprite_Height(), true);
}

void CMonster::Render()
{
	if (m_iDirection == 1)
	{
		m_Sprite.DrawBitmap(&m_vPos, 0xFFFFFFFF, false);
	}
	else if (m_iDirection == 2)
	{
		m_Sprite.DrawBitmap(&m_vPos, 0xFFFFFFFF, true);
	}
	Draw_RectLine();
}

void CMonster::Clean()
{
	m_Sprite.CleanUp();
}