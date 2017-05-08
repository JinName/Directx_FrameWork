#include "Sprite.h"



CSprite::CSprite()
	:m_pSprite(NULL)
	,m_pTexture(NULL)
	,m_iWidth(0)
	,m_iHeight(0)
	,m_iSprite_Count(0)
	,m_rectWidth(0)
	,m_rectHeight(0)
{
	m_SpriteRect = { 0, 0, 0, 0 };
}


CSprite::~CSprite()
{
	if (m_pSprite != NULL)
	{
		m_pSprite->Release();
		//delete m_pSprite;
	}
}

HRESULT CSprite::Create_Sprite(LPDIRECT3DDEVICE9 _pDevice, std::wstring _filePath, int _width, int _height, int _spriteCount)
{
	//m_pDevice = _pDevice;
	m_iWidth = _width;
	m_iHeight = _height;
	m_iSprite_Count = _spriteCount;

	m_rectWidth = m_iWidth / m_iSprite_Count;
	m_rectHeight = m_iHeight;

	m_SpriteRect.left = 0;
	m_SpriteRect.top = 0;
	m_SpriteRect.right = m_rectWidth;
	m_SpriteRect.bottom = m_rectHeight;

	m_dwOldTime = GetTickCount();

	//LoadTexture(_pDevice, _filePath.c_str(), _width, _height);
	if (FAILED(D3DXCreateTextureFromFileEx(_pDevice, L"Aru_stand_8peaces.bmp"
		, _width // 파일의 폭
		, _height // 파일의 높이
		, 1 // 밉맵 2d : 1 / 3d : default
		, 0
		, D3DFMT_UNKNOWN // 파일 포맷
		, D3DPOOL_MANAGED // 메모리 저장될 곳 지정
		, D3DX_DEFAULT // 필터
		, D3DX_DEFAULT // 밉필터
		, D3DCOLOR_XRGB(0, 255, 255) // 컬러 키
		, NULL
		, NULL
		, &m_pTexture))) // output
	{
		MessageBox(NULL, L"Could not find...", L"LoadTextures.exe", MB_OK);
		return E_FAIL;
	}

	D3DXCreateSprite(_pDevice, &m_pSprite);

	return S_OK;
}


void CSprite::DrawBitmap(D3DXVECTOR3* pos, D3DCOLOR mask, bool reverse)
{
	//assert(m_pSprite /*!= NULL*/);
	//boost::mutex::scoped_lock lock(gGraphic_Mutex);

	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);

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
	
	D3DXMatrixIdentity(&oldMat);
	m_pSprite->SetTransform(&oldMat);

	m_pSprite->Draw(m_pTexture, &m_SpriteRect, NULL, pos, mask);
	m_pSprite->End();
}

void CSprite::Animation_Frame()
{
	DWORD dwCurrentTime = GetTickCount();

	if (dwCurrentTime - m_dwOldTime >= m_dwSpriteTime)
	{
		m_dwOldTime = dwCurrentTime;
		m_SpriteRect.left += m_rectWidth;
		m_SpriteRect.right += m_rectWidth;
	}
}

void CSprite::Set_SpriteCollider()
{

}

void CSprite::CleanUp()
{
	
}