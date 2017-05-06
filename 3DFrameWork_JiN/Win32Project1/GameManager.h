#pragma once
#include "Header.h"
#include "GameBase.h"
#include "Camera.h"
#include "Stage.h"

class CGameManager
{
private:
	CGameBase *m_pGameBase;

	// Ä«¸Þ¶ó
	CCamera m_Camera;

	HWND m_hWnd;
public:
	CGameManager();
	CGameManager(HWND _hWnd);
	~CGameManager();

	void Initialize();

	void Update();
	void Render();
	void Cleanup();
};

