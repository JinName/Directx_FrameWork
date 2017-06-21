#include "Title.h"



CTitle::CTitle()
{
}

CTitle::~CTitle()
{
}

void CTitle::OnInit(LPDIRECT3DDEVICE9 _pDevice)
{
	m_iGameScene_Num = TITLE;
	Button_GameStart.Init(_pDevice, L"2D_Sprites\\GameStart.png", 340.0f, 280.0f, 300.0f, 70.0f);
}

void CTitle::OnUpdate(LPDIRECT3DDEVICE9 _pDevice)
{
	if (CInput::Get_Instance()->IsMouseKeyPressed(DIMOUSE_XAXISAB))
	{
		long x, y, z;
		CInput::Get_Instance()->GetMouseRelativePosition(x, y, z);
		if (Button_GameStart.On_Click(x, y))
		{
			m_bGameOver = true;
		}
	}
}

void CTitle::OnRender(LPDIRECT3DDEVICE9 _pDevice)
{
	Button_GameStart.Render();
}

void CTitle::OnCleanup(LPDIRECT3DDEVICE9 _pDevice)
{
	Button_GameStart.Clean();
}