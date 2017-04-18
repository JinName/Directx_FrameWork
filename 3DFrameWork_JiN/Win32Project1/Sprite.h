#pragma once
#include "Header.h"
//#include "WinConfigure.h"
#include "Texture.h"

class CSprite : public CTexture
{
private:
	LPD3DXSPRITE m_pSprite;

	int m_iWidth;
	int m_iHeight;

public:
	CSprite();
	~CSprite();

	// ��������Ʈ ���� (����̽�, �ؽ��� ���, �÷�Ű, )
	void Create_Sprite();

	void DrawBitmap(D3DXVECTOR3* pos, D3DCOLOR mask, bool reverse);
};

