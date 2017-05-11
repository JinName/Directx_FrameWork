#pragma once

#include "Header.h"
#include "DirectInput.h"
#include "Entity.h"

class CCharacter : public CEntity
{
protected:
	// ĳ���� �ӵ�
	float m_fSpeed;

	// ĳ���� ����
	D3DXVECTOR2 m_vDirection;

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

