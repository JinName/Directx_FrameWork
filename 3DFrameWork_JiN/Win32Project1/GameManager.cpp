#include "GameManager.h"



CGameManager::CGameManager()
{

}

CGameManager::CGameManager(HINSTANCE _hInstance, HWND _hWnd)
	:m_hWnd(_hWnd)
	,m_hInstance(_hInstance)
{

	m_pGameBase = new CStage;
	m_pGameBase->InitD3D(m_hWnd);
}

CGameManager::~CGameManager()
{
}

void CGameManager::Initialize()
{
	// 카메라 초기화
	m_Camera.InitCamera(m_pGameBase->GetDevice());
}

void CGameManager::Update()
{
	m_pGameBase->Update();
	// 카메라 업데이트
}

void CGameManager::Render()
{
	m_pGameBase->Render();
}

void CGameManager::Cleanup()
{
	m_pGameBase->Cleanup();
}
