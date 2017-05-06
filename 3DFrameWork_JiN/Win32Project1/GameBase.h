#pragma once

#include "Header.h"
#include "D3DSetup.h"
//#include "Vertex.h"
//#include "Aru.h"

class CGameBase : public CD3DSetup
{
protected:
	CGameBase() {};
	CGameBase(const CGameBase& other);
	~CGameBase() {};

	Position m_pos;

protected:
	// 위치 셋팅 - 월드 좌표 변환
	void SetPosition(float _fx, float _fy, float _fz);

public:	
	static CGameBase* Get_Instance()
	{
		static CGameBase instance;
		return &instance;
	}
	
	// 부모의 함수
	virtual void OnInit();
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnCleanup();
};
