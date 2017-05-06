#include "Texture.h"



CTexture::CTexture()
	:m_pTexture(NULL)
{
}


CTexture::~CTexture()
{
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		delete m_pTexture;
	}
}

HRESULT CTexture::LoadTexture(LPDIRECT3DDEVICE9 _pDevice, std::wstring _filename, int _width, int _height)
{
	if (FAILED(D3DXCreateTextureFromFileEx(_pDevice, L"Aru_stand_8peaces.bmp"
		, _width // ������ ��
		, _height // ������ ����
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