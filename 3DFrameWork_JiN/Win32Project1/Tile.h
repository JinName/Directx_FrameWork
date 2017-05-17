#pragma once
#include "Header.h"
#include "Entity.h"
#include "Sprite.h"

// ��ȣ�� ���� ��Ÿ�� �ѹ�
typedef enum {
	STYLE_LONG,
	STYLE_MID,
	STYLE_SHORT
} TILE_STYLE;

class CTile : public CEntity
{
	CSprite m_Sprite;

public:
	CTile();
	~CTile();

	void Init(LPDIRECT3DDEVICE9 _pDevice, TILE_STYLE _STYLE);
	void Update();
	void Render();
	void Clean();
};

