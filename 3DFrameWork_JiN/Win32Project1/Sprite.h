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

	// 스프라이트 생성 (디바이스, 텍스쳐 경로, 컬러키, )
	void Create_Sprite();

	void DrawBitmap(D3DXVECTOR3* pos, D3DCOLOR mask, bool reverse);
};

