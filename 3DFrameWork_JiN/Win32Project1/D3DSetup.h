#pragma once

#include "Header.h"

class CD3DSetup
{
protected:
	// 디바이스 생성을 위한 변수
	LPDIRECT3D9             m_pD3D;

	// 디바이스 셋팅을 위한 변수
	LPDIRECT3DDEVICE9       m_pd3dDevice;

	// 윈도우 정보
	HWND m_hWnd;

protected:

	// 콜백함수 - 호출되었을때 처리해야할 게임코드를 호출해야함
	// 하위에서 상속, 상위에서 하위함수 호출, 순수 가상함수
	virtual void OnInit() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnRender() = 0;
	virtual void OnCleanup() = 0;


public:
	CD3DSetup();
	CD3DSetup(LPDIRECT3DDEVICE9 _pDevice)
	{
		m_pd3dDevice = _pDevice;
	}
	~CD3DSetup();

	// 디바이스 반환
	LPDIRECT3DDEVICE9 GetDevice() { return m_pd3dDevice; }

	// D3D 초기화
	HRESULT InitD3D(HWND hWnd);

	// Update, Render, Cleanup
	void Update();
	void Render();
	void Cleanup();
};

