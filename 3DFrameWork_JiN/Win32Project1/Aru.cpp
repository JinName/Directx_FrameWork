#include "Aru.h"



CAru::CAru()
{
	//m_sprite = new CSprite;
}

CAru::~CAru()
{
	//if (m_sprite != NULL)
	//	m_sprite->CleanUp();
}


void CAru::Init(LPDIRECT3DDEVICE9 _pDevice)
{
	m_sprite.Create_Sprite(_pDevice, L"2D_Sprites\\Aru_stand_8peaces.bmp", 512, 64, 8);
}

void CAru::Update()
{
	m_sprite.Animation_Frame();
}

void CAru::Render()
{
	m_sprite.DrawBitmap(&D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0xFFFFFFFF, false);
}

void CAru::Clean()
{
	//if (m_sprite != NULL)
	{
		m_sprite.CleanUp();
		//delete m_sprite;
	}
}