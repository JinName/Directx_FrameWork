#pragma once
#include "Header.h"
#include "Entity.h"
#include "Sprite.h"

class CTile : public CEntity
{
	CSprite m_Sprite;

public:
	CTile();
	~CTile();
};

