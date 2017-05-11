#pragma once
#include "Header.h"

class CEntity
{
protected:
	D3DXVECTOR3 m_vPos;
public:
	CEntity();
	~CEntity();

	// 매니저에서 접근용 함수
	D3DXVECTOR3 Get_Position() { return m_vPos; }
	void Set_Position(float _x, float _y, float _z) {
		m_vPos.x = _x;
		m_vPos.y = _y;
		m_vPos.z = _z;
	}
};

