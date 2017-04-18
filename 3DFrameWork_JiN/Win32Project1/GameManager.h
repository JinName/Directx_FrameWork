#pragma once
#include "Header.h"
#include "GameBase.h"
#include "Tiger.h"
#include "Camera.h"
#include "Aru.h"

class CGameManager
{
private:
	CGameBase *m_GameBase;

	// Ä«¸Þ¶ó
	CCamera m_Camera;
public:
	CGameManager();
	CGameManager(HWND _hWnd);
	~CGameManager();

	void Initialize();

	void Update();
	void Render();
	void Cleanup();
};

