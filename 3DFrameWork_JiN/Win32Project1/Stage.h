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
	CMonster m_Monster[4];

	list<CMonster> m_Monster_List;

	// 맵 매니저
	CMapManager m_MapMngr;
	// 충돌 처리 매니저
	CCollisionManager m_CollisionMngr;

public:
	CStage();
	~CStage();

	void Create_Monster(LPDIRECT3DDEVICE9 _pDevice);
	void Update_Monster();
	void Render_Monster();
	void Clean_Monster();

	virtual void OnInit(LPDIRECT3DDEVICE9 _pDevice);
	virtual void OnUpdate(LPDIRECT3DDEVICE9 _pDevice);
	virtual void OnRender(LPDIRECT3DDEVICE9 _pDevice);
	virtual void OnCleanup(LPDIRECT3DDEVICE9 _pDevice);
};

