#pragma once
#include "Header.h"
#include "GameBase.h"
#include "Background.h"
#include "Aru.h"
#include "Tile.h"

class CStage : public CGameBase
{
private:
	// 스테이지 넘버
	int m_iStageNum;

	CBackground m_Background;
	CAru m_Player;
	CTile m_Tile;

public:
	CStage();
	~CStage();

	virtual void OnInit(LPDIRECT3DDEVICE9 _pDevice);
	virtual void OnUpdate(LPDIRECT3DDEVICE9 _pDevice);
	virtual void OnRender(LPDIRECT3DDEVICE9 _pDevice);
	virtual void OnCleanup(LPDIRECT3DDEVICE9 _pDevice);
};

