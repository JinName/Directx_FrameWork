#include "Aru.h"



CAru::CAru()
{
}

CAru::~CAru()
{
}


void CAru::Init(LPDIRECT3DDEVICE9 _pDevice)
{
	//캐릭터 기본 시작 위치
	m_pos = { 100.0f, 100.0f, 0.0f };

	// 캐릭터 스탠드 스프라이트
	m_sprite.Create_Sprite(_pDevice, L"2D_Sprites\\Aru_stand_8peaces.bmp", 512, 64, 8, D3DCOLOR_XRGB(0, 170, 255));
}

void CAru::Update()
{
	Move();
	m_sprite.Animation_Frame();
}

void CAru::Render()
{
	m_sprite.DrawBitmap(&m_pos, 0xFFFFFFFF, false);
}

void CAru::Clean()
{
	m_sprite.CleanUp();
}