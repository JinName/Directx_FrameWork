#pragma once

#include "Header.h"
#include "Meshes.h"
#include "GameBase.h"


class CCharacter //: public CGameBase
{
protected:
	// 캐릭터 메시 - 캐릭터의 상태에 따라 동적일 필요
	CMeshes* m_meshes;

	// 캐릭터 위치 구조체
	//Position m_CharPosition;

public:
	CCharacter();
	~CCharacter();

	// 윈도우의 키보드 값을 리턴 받아서 움직임
	VOID Move();

	void Init();
	void Update();
	void Render();
	void Clean();
};

