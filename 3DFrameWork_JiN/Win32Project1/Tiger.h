#pragma once

#include "Character.h"

class CTiger : public CCharacter
{
public:
	CTiger();
	~CTiger();

	// �θ��� �Լ�
	virtual void OnInit();
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnCleanup();
};

