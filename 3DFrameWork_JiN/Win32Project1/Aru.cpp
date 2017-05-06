#include "Aru.h"



CAru::CAru()
{
	m_sprite = new CSprite;
}

CAru::~CAru()
{
	//if (m_sprite != NULL)
	//	m_sprite->CleanUp();
}

void CAru::OnInit()
{
	
}

void CAru::OnUpdate()
{
	
}

void CAru::OnRender()
{
	
}

void CAru::OnCleanup()
{
	
}

void CAru::aruInit()
{
	m_sprite->Create_Sprite(CGameBase::Get_Instance()->GetDevice(), L"2D_Sprites\\Aru_stand_8peaces.bmp", 512, 64, 8);
}

void CAru::aruUpdate()
{
	m_sprite->Animation_Frame();

}

void CAru::aruRender()
{
	m_sprite->DrawBitmap(&D3DXVECTOR3(100.0f, 100.0f, 0.0f), 0xFFFFFFFF, false);
}

void CAru::aruClean()
{
	if (m_sprite != NULL)
	{
		m_sprite->CleanUp();
		delete m_sprite;
	}
}