#include "Character.h"



CCharacter::CCharacter()
	:m_fSpeed(1.0f)
	,m_vDirection(0.0f, 0.0f)
{
}


CCharacter::~CCharacter()
{
}

void CCharacter::Init()
{

}
void CCharacter::Update()
{
	Move();
}
void CCharacter::Render()
{

}
void CCharacter::Clean()
{

}

VOID CCharacter::Move()
{
	if (CInput::Get_Instance()->IsKeyPressed(DIK_LEFT) == true)
	{
		m_vPos.x -= m_fSpeed;
		m_vDirection.x = -1.0f;
	}
	else if (CInput::Get_Instance()->IsKeyPressed(DIK_RIGHT) == true)
	{
		m_vPos.x += m_fSpeed;
		m_vDirection.x = 1.0f;
	}
	else if (CInput::Get_Instance()->IsKeyPressed(DIK_UP) == true)
	{
		m_vPos.y -= m_fSpeed;
		m_vDirection.y = -1.0f;
	}
	else if (CInput::Get_Instance()->IsKeyPressed(DIK_DOWN) == true)
	{
		m_vPos.y += m_fSpeed;
		m_vDirection.y = 1.0f;
	}

	if (CInput::Get_Instance()->IsKeyPressed(DIK_LEFT) == false &&
		CInput::Get_Instance()->IsKeyPressed(DIK_RIGHT) == false &&
		CInput::Get_Instance()->IsKeyPressed(DIK_UP) == false &&
		CInput::Get_Instance()->IsKeyPressed(DIK_DOWN) == false)
	{
		m_vDirection = { 0.0f, 0.0f };
	}
}