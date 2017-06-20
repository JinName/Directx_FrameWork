#pragma once

#include "Header.h"
#include "D3DSetup.h"
//#include "Vertex.h"
//#include "Aru.h"

enum { TITLE, STAGE, GAMEOVER };

class CGameBase : public CD3DSetup
{
protected:
	Position m_pos;

	bool m_bChange_Scene;

	int m_iGameScene_Num;

protected:
	// ��ġ ���� - ���� ��ǥ ��ȯ
	void SetPosition(float _fx, float _fy, float _fz);

public:	
	CGameBase();
	~CGameBase() {};
	
	int Get_GameScene_Num() { return m_iGameScene_Num; }
	bool Get_Change_Scene() { return m_bChange_Scene; }
	
	// �θ��� �Լ�
	virtual void OnInit(LPDIRECT3DDEVICE9 _pDevice);
	virtual void OnUpdate(LPDIRECT3DDEVICE9 _pDevice);
	virtual void OnRender(LPDIRECT3DDEVICE9 _pDevice);
	virtual void OnCleanup(LPDIRECT3DDEVICE9 _pDevice);
};
