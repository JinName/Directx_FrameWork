#include "Aru.h"



CAru::CAru()
{
}

CAru::~CAru()
{
}


void CAru::Init(LPDIRECT3DDEVICE9 _pDevice)
{
	// 캐릭터 기본 시작 위치
	m_vPos = { 100.0f, 100.0f, 0.0f };

	// 공격 중인지
	m_bAttacking = false;

	// 마지막 움직인 방향 ( 좌우 스프라이트 반전용 )
	currentDirection = LEFT;
	
	// 캐릭터 스탠드 스프라이트
	m_sprite[STAND].Create_Sprite(_pDevice, L"2D_Sprites\\Aru_stand_8peaces.bmp", 512, 64, 8, D3DCOLOR_XRGB(0, 170, 255));
	m_sprite[UP].Create_Sprite(_pDevice, L"2D_Sprites\\Aru_up_8peaces.bmp", 512, 64, 8, D3DCOLOR_XRGB(0, 170, 255));
	m_sprite[DOWN].Create_Sprite(_pDevice, L"2D_Sprites\\Aru_down_8peaces.bmp", 512, 64, 8, D3DCOLOR_XRGB(0, 170, 255));
	m_sprite[LEFT].Create_Sprite(_pDevice, L"2D_Sprites\\Aru_left_8peaces.bmp", 512, 64, 8, D3DCOLOR_XRGB(0, 170, 255));
	m_sprite[ATTACK].Create_Sprite(_pDevice, L"2D_Sprites\\Aru_attack_6peaces.bmp", 480, 48, 6, D3DCOLOR_XRGB(0, 170, 255));
}

void CAru::Update()
{
	Move();

	if (m_vDirection.x == 0 && m_vDirection.y == 0)
	{
		m_sprite[STAND].Animation_Frame();
	}
	else if (m_vDirection.y < 0)
	{
		m_sprite[UP].Animation_Frame();
	}
	else if (m_vDirection.y > 0)
	{
		m_sprite[DOWN].Animation_Frame();
	}
	else if (m_vDirection.x > 0 || m_vDirection.x < 0)
	{
		m_sprite[LEFT].Animation_Frame();
		if (m_vDirection.x < 0)
			currentDirection = LEFT;
		else if (m_vDirection.x > 0)
			currentDirection = -LEFT;
	}
	else if (m_bAttacking == true)
	{
		m_sprite[ATTACK].Animation_Frame();
	}
}

void CAru::Render()
{
	if (m_vDirection.x == 0 && m_vDirection.y == 0)
	{
		if (currentDirection == LEFT)
			m_sprite[STAND].DrawBitmap(&m_vPos, 0xFFFFFFFF, false);
		else if (currentDirection == -LEFT)
			m_sprite[STAND].DrawBitmap(&m_vPos, 0xFFFFFFFF, true);
	}
	else if (m_vDirection.y < 0)
	{
		m_sprite[UP].DrawBitmap(&m_vPos, 0xFFFFFFFF, false);
	}
	else if (m_vDirection.y > 0)
	{
		m_sprite[DOWN].DrawBitmap(&m_vPos, 0xFFFFFFFF, false);
	}
	else if (m_vDirection.x > 0 || m_vDirection.x < 0)
	{
		if (m_vDirection.x < 0)
			m_sprite[LEFT].DrawBitmap(&m_vPos, 0xFFFFFFFF, false);
		else if (m_vDirection.x > 0)
			m_sprite[LEFT].DrawBitmap(&m_vPos, 0xFFFFFFFF, true);
	}
	else if (m_bAttacking == true)
	{
		m_sprite[ATTACK].DrawBitmap(&m_vPos, 0xFFFFFFFF, false);
	}
}

void CAru::Clean()
{
	for (int i = 0; i < 5; ++i)
	{
		m_sprite[i].CleanUp();
	}
}