#pragma once
#include "Header.h"
#include "Entity.h"
#include "Texture.h"

// �� ����� ���͸� �����ʰ� �׳� ���� ���� �������� �׸���
class CBackground :public CEntity
{
private:
	CTexture m_texture;
public:
	CBackground();
	~CBackground();

	void init(LPDIRECT3DDEVICE9 _pDevice);
};

