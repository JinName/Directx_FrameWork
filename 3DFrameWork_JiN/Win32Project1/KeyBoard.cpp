#include "KeyBoard.h"


CKeyBoard::CKeyBoard()
{
}


CKeyBoard::~CKeyBoard()
{
}

HRESULT CKeyBoard::CreateKeyboard(HWND _hWnd)
{
	/*
	HRESULT hr;

	m_hWnd = _hWnd;
	
	if (FAILED(hr = DirectInput8Create(GetModuleHandle(NULL), DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&m_pDI, NULL)))
		return hr;

	// 키보드 객체 생성
	if (FAILED(hr = m_pDI->CreateDevice(GUID_SysKeyboard, &m_pKeyboard, NULL)))
		return hr;

	// 사전정의 DirectInput 장치 데이터 구조체 c_dfDIKeyboard
	// extern const DIDATAFORMAT c_dfDIKeyboard; 로 dinput.h에 있음.
	if (FAILED(hr = m_pKeyboard->SetDataFormat(&c_dfDIKeyboard)))
		return hr;

	// 협동 레벨이란 DirectInput을 사용하는 응용 프로그램과 시스템간의 상호 작용에 대한 설정
	hr = m_pKeyboard->SetCooperativeLevel(_hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
	

	if (FAILED(hr))
		return hr;

	m_pKeyboard->Acquire();


	return S_OK;
	*/
	return S_OK;
}


VOID CKeyBoard::FreeDirectInput()
{
	/*
	if (m_pKeyboard)
		m_pKeyboard->Unacquire();

	SAFE_RELEASE(m_pKeyboard);
	SAFE_RELEASE(m_pDI);
	*/
}

void CKeyBoard::OnActivate(WPARAM _wParam)
{
	/*
	if (WA_INACTIVE != _wParam && m_pKeyboard)
		m_pKeyboard->Acquire();
		*/
}

HRESULT CKeyBoard::ReadData()
{
	/*
	HRESULT hr;

	if (NULL == m_pKeyboard)
		return S_OK;

	// 현재 키상태를 알아내기 위해 먼저 버퍼 초기화 후 GetDeviceState()
	ZeroMemory(m_Keys, sizeof(m_Keys));
	hr = m_pKeyboard->GetDeviceState(sizeof(m_Keys), m_Keys);
	if (FAILED(hr))
	{
		hr = m_pKeyboard->Acquire();
		while (hr == DIERR_INPUTLOST)
			hr = m_pKeyboard->Acquire();

		return S_OK;
	}

	return S_OK;
	*/
	return S_OK;
}

BOOL CKeyBoard::KeyDown(BYTE _Key)
{
	if (m_Keys[_Key] & 0x80)
		return TRUE;

	return FALSE;
}

void CKeyBoard::Update(WPARAM _wParam, BYTE _Key)
{
	OnActivate(_wParam);
	ReadData();
	KeyDown(_Key);
}