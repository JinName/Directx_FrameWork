#pragma once

#include "Header.h"
#include "Meshes.h"
#include "GameBase.h"


class CCharacter : public CGameBase
{
protected:
	// ĳ���� �޽� - ĳ������ ���¿� ���� ������ �ʿ�
	CMeshes* m_meshes;

	// ĳ���� ��ġ ����ü
	//Position m_CharPosition;

public:
	CCharacter();
	~CCharacter();

	// �θ��� �Լ�
	virtual void OnInit();
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnCleanup();


	// �������� Ű���� ���� ���� �޾Ƽ� ������
	VOID Move();
};

