#include "FireBall.h"



CFireBall::CFireBall()
{
}


CFireBall::~CFireBall()
{
}

void CFireBall::FireBall_Move()
{
	m_vPos.x += m_iDirection * m_fSpeed; // 방향 * 속도
}

bool CFireBall::FireBall_Destroy_Check()
{
	// 적과 충돌하거나
	if (m_b_is_Collision == true)
	{
		m_bDestroy = true;
	}

	// 화면밖으로 나가면
	if (m_vPos.x > 1100.0f || m_vPos.x < -100.0f)
	{
		m_bDestroy = true;
	}

	return m_bDestroy;
}

bool CFireBall::Check_Reverse()
{
	if (m_iDirection > 0)
		return false;
	else if (m_iDirection < 0)
		return true;
}

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

	Line_Init(_pDevice);
}

void CFireBall::Update()
{
	FireBall_Move();
	m_FireBall.Animation_Frame();

	Set_Collider(32.0f, 32.0f, true);
}

void CFireBall::Render()
{
	// 캐릭터 방향에 따라 reverse 값 적용
	m_FireBall.DrawBitmap(&m_vPos, 0xFFFFFFFF, Check_Reverse());

	Draw_RectLine();
}

void CFireBall::Clean()
{
	m_FireBall.CleanUp();
}