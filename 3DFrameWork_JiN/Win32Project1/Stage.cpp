#include "Stage.h"



CStage::CStage()
{
}


CStage::~CStage()
{
}

void CStage::OnInit(LPDIRECT3DDEVICE9 _pDevice)
{
	m_Tile.Init(_pDevice);
	m_Background.Init(_pDevice);
	m_Player.Init(_pDevice);
}

void CStage::OnUpdate(LPDIRECT3DDEVICE9 _pDevice)
{
	m_Background.Update();
	m_Player.Update();
}

void CStage::OnRender(LPDIRECT3DDEVICE9 _pDevice)
{
	m_Background.Render();
	m_Tile.Render();
	m_Player.Render();

}

void CStage::OnCleanup(LPDIRECT3DDEVICE9 _pDevice)
{
	m_Tile.Clean();
	m_Background.Clean();
	m_Player.Clean();
}

