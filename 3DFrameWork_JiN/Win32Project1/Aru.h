#pragma once
#include "Header.h"
#include "Character.h"
#include "Sprite.h"

class CAru : public CCharacter
{
private:
	CSprite m_sprite;
	
public:
	CAru();
	~CAru();

	void Init(LPDIRECT3DDEVICE9 _pDevice);
	void Update();
	void Render();
	void Clean();
};

