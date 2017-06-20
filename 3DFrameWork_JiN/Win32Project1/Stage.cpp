#include "Stage.h"

CStage::CStage()
{
}

CStage::~CStage()
{
}

bool CStage::GameOver()
{
	if (m_Player.Get_HP() == 0)
		return true;

	return false;
}

void CStage::Create_Monster(LPDIRECT3DDEVICE9 _pDevice)
{
	// monster initialize
	m_Monster[0].Init(_pDevice, D3DXVECTOR3(200.0f, 160.0f, 0.0f), 200.0f);
	m_Monster_List.push_back(m_Monster[0]);

	m_Monster[1].Init(_pDevice, D3DXVECTOR3(730.0f, 370.0f, 0.0f), 250.0f);
	m_Monster_List.push_back(m_Monster[1]);

	m_Monster[2].Init(_pDevice, D3DXVECTOR3(300.0f, 470.0f, 0.0f), 180.0f);
	m_Monster_List.push_back(m_Monster[2]);

	m_Monster[3].Init(_pDevice, D3DXVECTOR3(810.0f, 590.0f, 0.0f), 100.0f);
	m_Monster_List.push_back(m_Monster[3]);
}

void CStage::Update_Monster()
{
	if (m_Monster_List.size() > 0)
	{
		for (list<CMonster>::iterator begin_iter = m_Monster_List.begin();
			begin_iter != m_Monster_List.end(); )
		{
			begin_iter->Update();

			if (begin_iter->Get_Destroy() == true)
			{
				begin_iter = m_Monster_List.erase(begin_iter);
			}
			else
				++begin_iter;
		}
	}
}

void CStage::Render_Monster()
{
	if (m_Monster_List.size() > 0)
	{
		for (list<CMonster>::iterator begin_iter = m_Monster_List.begin();
			begin_iter != m_Monster_List.end(); begin_iter++)
		{
			begin_iter->Render();
		}
	}
}

void CStage::Clean_Monster()
{
	if (m_Monster_List.size() > 0)
	{
		for (list<CMonster>::iterator begin_iter = m_Monster_List.begin();
			begin_iter != m_Monster_List.end(); begin_iter++)
		{
			begin_iter->Clean();
		}
		m_Monster_List.clear();
	}
}

void CStage::OnInit(LPDIRECT3DDEVICE9 _pDevice)
{
	// stage number
	m_iStageNum = 1;	
	m_iGameScene_Num = STAGE;

	// map initialize
	m_MapMngr.StageMap_Init(_pDevice, m_iStageNum);
	m_CollisionMngr.Init();

	// monster initialize
	Create_Monster(_pDevice);	

	// player initialize
	m_Player.Init(_pDevice);

	// ui initialize
	m_UIMnger.Init(_pDevice, m_Player.Get_HP());
}

void CStage::OnUpdate(LPDIRECT3DDEVICE9 _pDevice)
{
	m_MapMngr.StageMap_Update();

	// 몬스터
	Update_Monster();

	// FireBall 생성을 위해 디바이스 필요
	m_Player.Update(_pDevice);

	// UI 업데이트
	m_UIMnger.Update(m_Player.Get_HP());

	// 매 프래임 마다 충돌체크할 것들
	m_CollisionMngr.Charater_Tile_Check(m_MapMngr.Get_TileArray(), 8, m_Player);
	m_CollisionMngr.CharAttack_Monster_Check(m_Player.Get_FireBall_List(), m_Monster_List);
	m_CollisionMngr.Charater_Monster_Check(m_Player, m_Monster_List);

	// GameOver
	if (GameOver())
		m_bChange_Scene = true;
}

void CStage::OnRender(LPDIRECT3DDEVICE9 _pDevice)
{
	m_MapMngr.StageMap_Render();

	// 몬스터
	Render_Monster();

	m_Player.Render();

	m_UIMnger.Render();
}

void CStage::OnCleanup(LPDIRECT3DDEVICE9 _pDevice)
{
	m_UIMnger.Clean();
	m_MapMngr.StageMap_Cleanup();

	// 몬스터
	Clean_Monster();

	m_Player.Clean();
}