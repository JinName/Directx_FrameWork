#include "Stage.h"



CStage::CStage()
{
}


CStage::~CStage()
{
}

void CStage::OnInit(LPDIRECT3DDEVICE9 _pDevice)
{
	m_Player.Init(_pDevice);
}

void CStage::OnUpdate(LPDIRECT3DDEVICE9 _pDevice)
{
	m_Player.Update();
}

void CStage::OnRender(LPDIRECT3DDEVICE9 _pDevice)
{
	m_Player.Render();
}

void CStage::OnCleanup(LPDIRECT3DDEVICE9 _pDevice)
{
	m_Player.Clean();
}

