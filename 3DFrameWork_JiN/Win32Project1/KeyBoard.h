#pragma once

#include "Header.h"
//#include <dinput.h>


class CKeyBoard
{
private:
	//LPDIRECTINPUT8			m_pDI;			// Directinput Object
	//LPDIRECTINPUTDEVICE8	m_pKeyboard;	// Keyboard Device

	HWND					m_hWnd;
	BYTE					m_Keys[256];

public:
	CKeyBoard();
	~CKeyBoard();

	//객체 생성
	HRESULT		CreateKeyboard(HWND _hWnd);

	// 객체 해제
	VOID		FreeDirectInput();

	// 응용프로그램이 키보드 제어권을 되찾는 함수
	void		OnActivate(WPARAM _wParam);
	
	// 키 상태 확인
	HRESULT		ReadData();

	// 키 입력 확인
	BOOL		KeyDown(BYTE _Key);

	void		Update(WPARAM _wParam, BYTE _Key);
};

