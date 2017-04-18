#include "Sprite.h"



CSprite::CSprite()
{
}


CSprite::~CSprite()
{
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
	m_pSprite->Draw(m_pTexture, NULL, NULL, pos, mask);
	m_pSprite->SetTransform(&oldMat);
	m_pSprite->End();

}