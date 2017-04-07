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

	//��ü ����
	HRESULT		CreateKeyboard(HWND _hWnd);

	// ��ü ����
	VOID		FreeDirectInput();

	// �������α׷��� Ű���� ������� ��ã�� �Լ�
	void		OnActivate(WPARAM _wParam);
	
	// Ű ���� Ȯ��
	HRESULT		ReadData();

	// Ű �Է� Ȯ��
	BOOL		KeyDown(BYTE _Key);

	void		Update(WPARAM _wParam, BYTE _Key);
};

