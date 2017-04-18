#include "Sprite.h"



CSprite::CSprite()
	:m_pSprite(NULL)
	,m_iWidth(0)
	,m_iHeight(0)
	,m_iSprite_Count(0)
	,m_rectWidth(0)
	,m_rectHeight(0)
{
	m_rt = { 0, 0, 0, 0 };
}


CSprite::~CSprite()
{
	if (m_pSprite != NULL)
	{
		m_pSprite->Release();
		delete m_pSprite;
	}
}

HRESULT CSprite::Create_Sprite(LPDIRECT3DDEVICE9 _pDevice, std::wstring _filePath, int _width, int _height, int _spriteCount)
{
	m_iWidth = _width;
	m_iHeight = _height;
	m_iSprite_Count = _spriteCount;

	m_rectWidth = m_iWidth / m_iSprite_Count;
	m_rectHeight = m_iHeight;

	m_rt.left = 0;
	m_rt.top = 0;
	m_rt.right = m_rectWidth;
	m_rt.bottom = m_rectHeight;

	m_dwOldTime = GetTickCount();

	LoadTexture(_pDevice, _filePath.c_str(), _width, _height);

	D3DXCreateSprite(_pDevice, &m_pSprite);

	return S_OK;
}


void CSprite::DrawBitmap(D3DXVECTOR3* pos, D3DCOLOR mask, bool reverse)
{
	assert(m_pSprite /*!= NULL*/);
	//boost::mutex::scoped_lock lock(gGraphic_Mutex);

	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	// flip the sprite horizontally
	D3DXMATRIX oldMat;
	m_pSprite->GetTransform(&oldMat);
	if (reverse)
	{
		D3DXMATRIX mat;
		D3DXVECTOR2 scale(-1.0f, 1.0f);		// flip horizon
		D3DXVECTOR2 center(pos->x, pos->y);		// set flip center(upper left corner of the sprite)
		D3DXVECTOR2 translate(float(m_iWidth), 0);

		D3DXMatrixTransformation2D(&mat, &center, NULL, &scale, NULL, NULL, &translate);
		m_pSprite->SetTransform(&mat);
	}
	m_pSprite->Draw(m_pTexture, &m_rt, NULL, pos, mask);
	m_pSprite->SetTransform(&oldMat);
	m_pSprite->End();
}

void CSprite::Animation_Frame()
{
	DWORD dwCurrentTime = GetTickCount();

	if (dwCurrentTime - m_dwOldTime >= m_dwSpriteTime)
	{
		m_dwOldTime = dwCurrentTime;
		m_rt.left += m_rectWidth;
		m_rt.right += m_rectWidth;
	}
}