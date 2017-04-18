#pragma once
#include "Header.h"
#include "Sprite.h"
#include "Character.h"

class CAru : public  CCharacter
{
private:
	// 상황에 따라 다른 스프라이트 할당
	// m_baseSprite->Run();
	// m_baseSprite->Stand(); 등등
	// 스프라이트 클래스에 어떤식으로 추가해야할지 고민 필요
	// CSprite *m_baseSprite;

	CSprite m_sprite;
	
public:
	CAru();
	~CAru();

	virtual void OnInit();
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnCleanup();
};

