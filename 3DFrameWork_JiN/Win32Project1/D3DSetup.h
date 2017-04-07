#pragma once

#include "Header.h"

class CD3DSetup
{
private:
	// ����̽� ������ ���� ����
	LPDIRECT3D9             m_pD3D;

	// ����̽� ������ ���� ����
	LPDIRECT3DDEVICE9       m_pd3dDevice;

	// ������ ����
	HWND m_hWnd;

protected:

	// �ݹ��Լ� - ȣ��Ǿ����� ó���ؾ��� �����ڵ带 ȣ���ؾ���
	// �������� ���, �������� �����Լ� ȣ��, ���� �����Լ�
	virtual void OnInit() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnRender() = 0;
	virtual void OnCleanup() = 0;


public:
	CD3DSetup();
	~CD3DSetup();

	// ����̽� ��ȯ
	LPDIRECT3DDEVICE9 GetDevice() { return m_pd3dDevice; }

	// D3D �ʱ�ȭ
	HRESULT InitD3D(HWND hWnd);

	// Update, Render, Cleanup
	void Update();
	void Render();
	void Cleanup();
};

