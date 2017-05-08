#include "Character.h"



CCharacter::CCharacter()
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
		m_pos.x -= 0.5f;
	if (CInput::Get_Instance()->IsKeyPressed(DIK_RIGHT) == true)
		m_pos.x += 0.5f;
	if (CInput::Get_Instance()->IsKeyPressed(DIK_UP) == true)
		m_pos.y -= 0.5f;
	if (CInput::Get_Instance()->IsKeyPressed(DIK_DOWN) == true)
		m_pos.y += 0.5f;
}