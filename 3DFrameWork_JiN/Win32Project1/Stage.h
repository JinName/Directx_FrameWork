#pragma once
#include "Header.h"
#include "GameBase.h"
#include "Character.h"
#include "Aru.h"

class CStage : public CGameBase
{
private:
	CAru *m_Player;

public:
	CStage();
	~CStage();

	virtual void OnInit();
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnCleanup();
};

