#pragma once
#include "Header.h"

class CEntity
{
protected:
	D3DXVECTOR3 m_vPos;

	// �浹 �ڽ�
	RECT m_rt;

	// �浹 �˻�� �� �׸��� ����
	LPD3DXLINE m_pLine;
	D3DXVECTOR2 vList[5];
	
public:
	CEntity();
	~CEntity();

	// �Ŵ������� ���ٿ� �Լ�
	D3DXVECTOR3 Get_Position() { return m_vPos; }

	// �浹 �ڽ� ��ȯ �Լ�
	RECT Get_Collider() { return m_rt; }

	// �浹 �ڽ� ���� �׸���
	void Line_Init(LPDIRECT3DDEVICE9 _pDevice);
	void Draw_RectLine();

	// �浹 �ڽ� ����
	void Set_Collider(float _width, float _height);

	// �⺻ ������ ��ȯ �Լ�
	void Set_Position(float _x, float _y, float _z) {
		m_vPos.x = _x;
		m_vPos.y = _y;
		m_vPos.z = _z;
	}
};

