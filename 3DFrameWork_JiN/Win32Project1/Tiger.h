#pragma once

#include "Character.h"

class CTiger : public CCharacter
{
public:
	CTiger();
	~CTiger();

	// 부모의 함수
	virtual void OnInit();
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnCleanup();
};

