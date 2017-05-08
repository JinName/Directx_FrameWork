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
	int m_iSprite_Count;

	// 스프라이트 한칸의 너비, 높이
	int m_rectWidth;
	int m_rectHeight;

	// 스프라이트 재생 속도
	DWORD m_dwSpriteTime;
	DWORD m_dwOldTime;

	D3DXVECTOR3 m_vCenter;

	// 스프라이트 용
	RECT m_SpriteRect;

	// 충돌 범위
	RECT m_Collider;
public:
	CSprite();
	~CSprite();

	// 스프라이트 생성 (디바이스, 텍스쳐 경로, 컬러키, )
	HRESULT Create_Sprite(LPDIRECT3DDEVICE9 _pDevice, std::wstring _filePath, int _width, int _height, int _spriteCount, D3DCOLOR mask);

	void DrawBitmap(D3DXVECTOR3* pos, D3DCOLOR mask, bool reverse);

	void Animation_Frame();

	void Set_SpriteCollider();

	void CleanUp();
};

