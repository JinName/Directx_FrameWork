#include "Stage.h"



CStage::CStage()
{
}


CStage::~CStage()
{
}

void CStage::OnInit(LPDIRECT3DDEVICE9 _pDevice)
{
	// stage number
	m_iStageNum = 1;

	// map initialize
	m_MapMngr.StageMap_Init(_pDevice, m_iStageNum);
	m_CollisionMngr.Init();

	// monster initialize
	m_Monster.Init(_pDevice);

	// player initialize
	m_Player.Init(_pDevice);
}

void CStage::OnUpdate(LPDIRECT3DDEVICE9 _pDevice)
{
	m_MapMngr.StageMap_Update();
	m_Monster.Update();
	m_Player.Update();

	// �� ������ ���� Ÿ�ϰ� ĳ���� ���¸� Ȯ��
	m_CollisionMngr.Update(m_MapMngr.Get_TileArray(), 8, m_Player);
}

void CStage::OnRender(LPDIRECT3DDEVICE9 _pDevice)
{
	m_MapMngr.StageMap_Render();
	m_Player.Render();
	m_Monster.Render();
}

void CStage::OnCleanup(LPDIRECT3DDEVICE9 _pDevice)
{
	m_MapMngr.StageMap_Cleanup();
	m_Player.Clean();
	m_Monster.Clean();
}

