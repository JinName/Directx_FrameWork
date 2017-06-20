#pragma once
#include "Header.h"
#include "GameBase.h"
#include "Background.h"
#include "Aru.h"
#include "Tile.h"
#include "UIManager.h"
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
	CMonster m_Monster[4];

	list<CMonster> m_Monster_List;

	// UI �Ŵ���
	CUIManager m_UIMnger;
	// �� �Ŵ���
	CMapManager m_MapMngr;
	// �浹 ó�� �Ŵ���
	CCollisionManager m_CollisionMngr;
public:
	CStage();
	~CStage();

	// GameOver Check
	bool GameOver();

	void Create_Monster(LPDIRECT3DDEVICE9 _pDevice);
	void Update_Monster();
	void Render_Monster();
	void Clean_Monster();

	virtual void OnInit(LPDIRECT3DDEVICE9 _pDevice);
	virtual void OnUpdate(LPDIRECT3DDEVICE9 _pDevice);
	virtual void OnRender(LPDIRECT3DDEVICE9 _pDevice);
	virtual void OnCleanup(LPDIRECT3DDEVICE9 _pDevice);
};