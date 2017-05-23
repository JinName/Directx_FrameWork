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
	// 스테이지 넘버
	int m_iStageNum;

	CBackground m_Background;
	CAru m_Player;
	CTile m_Tile;
	CMonster m_Monster;

	// 맵 매니저
	CMapManager m_MapMngr;
	// 충돌 처리 매니저
	CCollisionManager m_CollisionMngr;

public:
	CStage();
	~CStage();

	virtual void OnInit(LPDIRECT3DDEVICE9 _pDevice);
	virtual void OnUpdate(LPDIRECT3DDEVICE9 _pDevice);
	virtual void OnRender(LPDIRECT3DDEVICE9 _pDevice);
	virtual void OnCleanup(LPDIRECT3DDEVICE9 _pDevice);
};

