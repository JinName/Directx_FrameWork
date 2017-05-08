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
	// 위치 셋팅 - 월드 좌표 변환
	void SetPosition(float _fx, float _fy, float _fz);

public:	
	CGameBase() {};
	~CGameBase() {};
	
	
	// 부모의 함수
	virtual void OnInit(LPDIRECT3DDEVICE9 _pDevice);
	virtual void OnUpdate(LPDIRECT3DDEVICE9 _pDevice);
	virtual void OnRender(LPDIRECT3DDEVICE9 _pDevice);
	virtual void OnCleanup(LPDIRECT3DDEVICE9 _pDevice);
};
