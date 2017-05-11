#include "Background.h"



CBackground::CBackground()
{
}


CBackground::~CBackground()
{
}

void CBackground::init(LPDIRECT3DDEVICE9 _pDevice)
{
	m_vPos = { 0.0f, 0.0f, 0.0f };

	m_texture.LoadTexture(_pDevice, L"Objects\\Background.png", 800, 427, NULL);
}