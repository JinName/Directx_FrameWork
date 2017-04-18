#include "Aru.h"



CAru::CAru()
{
}

CAru::~CAru()
{
}

void CAru::OnInit()
{
	m_sprite.Create_Sprite(GetDevice(), L"2D_Sprites\\3DS_Aru_Stand.bmp", 512, 64, 8);
}

void CAru::OnUpdate()
{
	m_sprite.Animation_Frame();
}

void CAru::OnRender()
{
	m_sprite.DrawBitmap(&D3DXVECTOR3(100.0f, 100.0f, 0.0f), D3DCOLOR_XRGB(0, 170, 255), false);
}

void CAru::OnCleanup()
{
}
