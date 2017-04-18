#include "Texture.h"



CTexture::CTexture()
{
}


CTexture::~CTexture()
{
}

HRESULT CTexture::LoadTexture(LPDIRECT3DDEVICE9 _pDevice, std::wstring _filename)
{
	if (FAILED(D3DXCreateTextureFromFileEx(_pDevice, _filename.c_str()
		, D3DX_DEFAULT // ������ ��
		, D3DX_DEFAULT // ������ ����
		, 1 // �Ӹ� 2d : 1 / 3d : default
		, 0
		, D3DFMT_UNKNOWN // ���� ����
		, D3DPOOL_MANAGED // �޸� ����� �� ����
		, D3DX_DEFAULT // ����
		, D3DX_DEFAULT // ������
		, D3DCOLOR_XRGB(0, 255, 255) // �÷� Ű
		, NULL
		, NULL
		, &m_pTexture))) // output
	{
		MessageBox(NULL, L"Could not find...", L"LoadTextures.exe", MB_OK);
		return E_FAIL;
	}

	return S_OK;
}