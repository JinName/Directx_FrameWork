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

	// ��������Ʈ ��ĭ�� �ʺ�, ����
	int m_rectWidth;
	int m_rectHeight;

	// ��������Ʈ ��� �ӵ�
	DWORD m_dwSpriteTime;
	DWORD m_dwOldTime;

	RECT m_rt;
public:
	CSprite();
	~CSprite();

	// ��������Ʈ ���� (����̽�, �ؽ��� ���, �÷�Ű, )
	HRESULT Create_Sprite(LPDIRECT3DDEVICE9 _pDevice, std::wstring _filePath, int _width, int _height, int _spriteCount);

	void DrawBitmap(D3DXVECTOR3* pos, D3DCOLOR mask, bool reverse);

	void Animation_Frame();
};

