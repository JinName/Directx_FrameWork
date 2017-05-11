#pragma once
#include "Header.h"
#include "Entity.h"
#include "Texture.h"

// 뒷 배경은 센터를 잡지않고 그냥 왼쪽 위를 기준으로 그릴것
class CBackground :public CEntity
{
private:
	CTexture m_texture;
public:
	CBackground();
	~CBackground();

	void init(LPDIRECT3DDEVICE9 _pDevice);
};

