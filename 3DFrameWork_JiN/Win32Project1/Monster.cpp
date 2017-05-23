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

void CMonster::Init(LPDIRECT3DDEVICE9 _pDevice)
{
	srand((unsigned int)time(NULL));

	m_iDirection = rand() % 2 + 1; // 1~2 ³­¼ö 1 : ÁÂ / 2 : ¿ì
	m_vPos = { 50.0f, 100.0f, 0.0f };

	m_fMin_x = 25.5f;
	m_fMax_x = 174.5f;

	m_fSpeed = 0.8f;

	Line_Init(_pDevice);

	m_Sprite.Create_Sprite(_pDevice, L"2D_Sprites\\Cake_A.png", 408, 48, 8, NULL);
}

void CMonster::Update()
{
	Monster_Move();

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