#include "Tile.h"

CTile::CTile()
{
}

CTile::~CTile()
{
}

void CTile::Init(LPDIRECT3DDEVICE9 _pDevice, TILE_STYLE _STYLE)
{
	Line_Init(_pDevice);
	m_vPos = { 200.0f, 200.0f, 0.0f };
	m_Sprite.Create_Sprite(_pDevice, L"Objects\\LowTile.PNG", 400, 51, 1, NULL);
	Set_Collider(400, 21);
}
void CTile::Update()
{

}

void CTile::Render()
{
	m_Sprite.DrawBitmap(&m_vPos, 0xFFFFFFFF, false);
	Draw_RectLine();
}

void CTile::Clean()
{
	m_Sprite.CleanUp();
}