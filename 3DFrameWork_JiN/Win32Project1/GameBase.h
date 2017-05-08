#pragma once

#include "Header.h"
#include "D3DSetup.h"
//#include "Vertex.h"
//#include "Aru.h"

class CGameBase : public CD3DSetup
{
protected:
	Position m_pos;

protected:
	// ��ġ ���� - ���� ��ǥ ��ȯ
	void SetPosition(float _fx, float _fy, float _fz);

public:	
	CGameBase() {};
	~CGameBase() {};
	
	
	// �θ��� �Լ�
	virtual void OnInit(LPDIRECT3DDEVICE9 _pDevice);
	virtual void OnUpdate(LPDIRECT3DDEVICE9 _pDevice);
	virtual void OnRender(LPDIRECT3DDEVICE9 _pDevice);
	virtual void OnCleanup(LPDIRECT3DDEVICE9 _pDevice);
};
