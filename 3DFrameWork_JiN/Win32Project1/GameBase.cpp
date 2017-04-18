#include "GameBase.h"


CGameBase::CGameBase()
	//:vertex(NULL),
	//m_pos()
{
	//vertex = new CVertex;
	/*
	m_Sun = NULL;
	m_Earth = NULL;
	m_Moon = NULL;
	*/
}


CGameBase::~CGameBase()
{
}

void CGameBase::OnInit()
{
}

void CGameBase::OnUpdate()
{
}

void CGameBase::OnRender()
{
}

void CGameBase::OnCleanup()
{
}

void CGameBase::SetPosition(float _fx, float _fy, float _fz)
{
	m_pos.m_fx = _fx;
	m_pos.m_fy = _fy;
	m_pos.m_fz = _fz;

	//matrix 연산 필요

	D3DXMATRIXA16 matWorld;
	D3DXMatrixTranslation(&matWorld, m_pos.m_fx, m_pos.m_fy, m_pos.m_fz);
	//D3DXMatrixRotationY(&matWorld, timeGetTime() / 1000.0f);
	GetDevice()->SetTransform(D3DTS_WORLD, &matWorld);
}