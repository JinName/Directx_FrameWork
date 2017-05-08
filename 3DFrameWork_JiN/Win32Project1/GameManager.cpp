#include "GameManager.h"



CGameManager::CGameManager()
{

}

CGameManager::CGameManager(HWND _hWnd)
{
	//CGameBase::Get_Instance()->InitD3D(_hWnd);
	m_hWnd = _hWnd;
	m_pGameBase = new CStage;
	m_pGameBase->InitD3D(_hWnd);
}

CGameManager::~CGameManager()
{
}

void CGameManager::Initialize()
{
	
	// ī�޶� �ʱ�ȭ
	m_Camera.InitCamera(m_pGameBase->GetDevice());


	//m_pGameBase = new CStage;
	//m_pGameBase->InitD3D(m_hWnd);
}

void CGameManager::Update()
{
	m_pGameBase->Update();
	// ī�޶� ������Ʈ
}

void CGameManager::Render()
{
	m_pGameBase->Render();
}

void CGameManager::Cleanup()
{
	m_pGameBase->Cleanup();
}
