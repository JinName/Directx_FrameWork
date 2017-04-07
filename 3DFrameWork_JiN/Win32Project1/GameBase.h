#pragma once

#include "Header.h"
#include "D3DSetup.h"
#include "Vertex.h"

class CGameBase : public CD3DSetup
{
private:
	CVertex *vertex;

	Position m_pos;

	// �� 3��
	LPD3DXMESH m_Sun;
	LPD3DXMESH m_Earth;
	LPD3DXMESH m_Moon;

protected:
	// ��ġ ���� - ���� ��ǥ ��ȯ
	void SetPosition(float _fx, float _fy, float _fz);

public:
	CGameBase();
	~CGameBase();

	// �θ��� �Լ�
	virtual void OnInit();
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnCleanup();
};

