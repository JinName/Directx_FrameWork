#pragma once

#include "Header.h"
#include "Meshes.h"
#include "GameBase.h"


class CCharacter //: public CGameBase
{
protected:
	// ĳ���� �޽� - ĳ������ ���¿� ���� ������ �ʿ�
	CMeshes* m_meshes;

	// ĳ���� ��ġ ����ü
	//Position m_CharPosition;

public:
	CCharacter();
	~CCharacter();

	// �������� Ű���� ���� ���� �޾Ƽ� ������
	VOID Move();

	void Init();
	void Update();
	void Render();
	void Clean();
};

