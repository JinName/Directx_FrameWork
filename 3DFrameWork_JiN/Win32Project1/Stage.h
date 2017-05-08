#pragma once
#include "Header.h"
#include "GameBase.h"
#include "Character.h"
#include "Aru.h"

class CStage : public CGameBase
{
private:
	CAru m_Player;

public:
	CStage();
	~CStage();

	virtual void OnInit(LPDIRECT3DDEVICE9 _pDevice);
	virtual void OnUpdate(LPDIRECT3DDEVICE9 _pDevice);
	virtual void OnRender(LPDIRECT3DDEVICE9 _pDevice);
	virtual void OnCleanup(LPDIRECT3DDEVICE9 _pDevice);
};

