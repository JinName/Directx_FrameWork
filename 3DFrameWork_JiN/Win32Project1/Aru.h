#pragma once
#include "Header.h"
#include "Character.h"
#include "Sprite.h"

class CAru : public CCharacter
{
private:
	// ��Ȳ�� ���� �ٸ� ��������Ʈ �Ҵ�
	// m_baseSprite->Run();
	// m_baseSprite->Stand(); ���
	// ��������Ʈ Ŭ������ ������� �߰��ؾ����� ��� �ʿ�
	// CSprite *m_baseSprite;

	CSprite *m_sprite;
	
public:
	CAru();
	~CAru();

	virtual void OnInit();
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnCleanup();

	void aruInit();
	void aruUpdate();
	void aruRender();
	void aruClean();
};

