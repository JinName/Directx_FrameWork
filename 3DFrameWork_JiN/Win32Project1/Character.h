#pragma once

#include "Header.h"
#include "DirectInput.h"

class CCharacter
{
protected:
	// ĳ���� ��ġ
	D3DXVECTOR3 m_pos;

public:
	CCharacter();
	//CCharacter();
	~CCharacter();

	// �������� Ű���� ���� ���� �޾Ƽ� ������
	VOID Move();

	void Init();
	void Update();
	void Render();
	void Clean();
};

