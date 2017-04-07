#pragma once

#include "Header.h"
#include "D3DSetup.h"
#include "Vertex.h"

class CGameBase : public CD3DSetup
{
private:
	CVertex *vertex;

	Position m_pos;

	// 구 3개
	LPD3DXMESH m_Sun;
	LPD3DXMESH m_Earth;
	LPD3DXMESH m_Moon;

protected:
	// 위치 셋팅 - 월드 좌표 변환
	void SetPosition(float _fx, float _fy, float _fz);

public:
	CGameBase();
	~CGameBase();

	// 부모의 함수
	virtual void OnInit();
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnCleanup();
};

