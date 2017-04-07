#include "GameManager.h"



CGameManager::CGameManager()
{

}

CGameManager::CGameManager(HWND _hWnd)
{
	m_GameBase = new CGameBase;

	m_GameBase->InitD3D(_hWnd);
}



CGameManager::~CGameManager()
{
}

void CGameManager::Initialize()
{
	//m_GameBase = new CTiger;
	// ī�޶� �ʱ�ȭ
	m_Camera.InitCamera(m_GameBase->GetDevice());
}

void CGameManager::Update()
{
	m_GameBase->Update();

	// ī�޶� ������Ʈ
}

void CGameManager::Render()
{
	m_GameBase->Render();
}

void CGameManager::Cleanup()
{
	m_GameBase->Cleanup();
}
