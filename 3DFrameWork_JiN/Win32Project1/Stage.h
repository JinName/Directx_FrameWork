#pragma once
#include "Header.h"
#include "GameBase.h"
#include "Background.h"
#include "Aru.h"
#include "Tile.h"
#include "MapManager.h"
#include "CollisionManager.h"
#include "Monster.h"

class CStage : public CGameBase
{
private:
	// �������� �ѹ�
	int m_iStageNum;

	CBackground m_Background;
	CAru m_Player;
	CTile m_Tile;
	CMonster m_Monster;

	// �� �Ŵ���
	CMapManager m_MapMngr;
	// �浹 ó�� �Ŵ���
	CCollisionManager m_CollisionMngr;

public:
	CStage();
	~CStage();

	virtual void OnInit(LPDIRECT3DDEVICE9 _pDevice);
	virtual void OnUpdate(LPDIRECT3DDEVICE9 _pDevice);
	virtual void OnRender(LPDIRECT3DDEVICE9 _pDevice);
	virtual void OnCleanup(LPDIRECT3DDEVICE9 _pDevice);
};

