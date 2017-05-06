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
	// ��ġ ���� - ���� ��ǥ ��ȯ
	void SetPosition(float _fx, float _fy, float _fz);

public:	
	static CGameBase* Get_Instance()
	{
		static CGameBase instance;
		return &instance;
	}
	
	// �θ��� �Լ�
	virtual void OnInit();
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnCleanup();
};
