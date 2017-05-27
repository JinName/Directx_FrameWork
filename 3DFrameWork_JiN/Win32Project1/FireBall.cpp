#include "FireBall.h"



CFireBall::CFireBall()
{
}


CFireBall::~CFireBall()
{
}

void CFireBall::FireBall_Move()
{
	m_vPos.x += m_iDirection * m_fSpeed; // ���� * �ӵ�
}

void CFireBall::FireBall_Destroy_Check()
{
	// ���� �浹�ϰų�
	if (m_b_is_Collision == true)
	{
		m_bDestroy = true;
	}

	// ȭ������� ������
	if (m_vPos.x > 1100.0f || m_vPos.x < -100.0f)
	{
		m_bDestroy = true;
	}
}

/*
bool CFireBall::Check_Reverse()
{
	if(m_iDirection > 0)
	return false;
}
*/

void CFireBall::Set_Sprite(CSprite &_normalSprite, CSprite &_hitSprite)
{
	m_FireBall = _normalSprite;
	m_FireBall_Hit = _hitSprite;
}

void CFireBall::Init(LPDIRECT3DDEVICE9 _pDevice, D3DXVECTOR3 _vPos, int _iDirection)
{
	m_vPos = _vPos;
	m_iDirection = _iDirection;
	m_fDamage = 3.0f;
	m_fSpeed = 10.0f;
	m_b_is_Collision = false;
	m_bDestroy = false;
}

void CFireBall::Update()
{
	FireBall_Move();
	m_FireBall.Animation_Frame();
}

void CFireBall::Render()
{
	// ĳ���� ���⿡ ���� reverse �� ����
	m_FireBall.DrawBitmap(&m_vPos, 0xFFFFFFFF, false);
}

void CFireBall::Clean()
{
	m_FireBall.CleanUp();
}