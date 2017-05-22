#include "MapManager.h"


CMapManager::CMapManager()
{
}


CMapManager::~CMapManager()
{
}

void CMapManager::Create_Background(LPDIRECT3DDEVICE9 _pDevice, int _iStageNum)
{
	m_Background.Init(_pDevice);
}

void CMapManager::Create_Tiles(LPDIRECT3DDEVICE9 _pDevice, int _iStageNum)
{
	m_Tile.Init(_pDevice, STYLE_LONG, D3DXVECTOR3(0.0f, 200.0f, 0.0f));
	
	m_TileList.push_back(m_Tile);
	m_Collider_List.push_back(m_Tile.Get_Collider());
}

void CMapManager::StageMap_Init(LPDIRECT3DDEVICE9 _pDevice, int _iStageNum)
{
	Create_Background(_pDevice, _iStageNum);
	Create_Tiles(_pDevice, _iStageNum);
}

void CMapManager::StageMap_Update()
{

}

void CMapManager::StageMap_Render()
{
	m_Background.Render();

	std::list<CTile>::iterator begin_iter = m_TileList.begin();
	std::list<CTile>::iterator end_iter = m_TileList.end();

	while (begin_iter != end_iter)
	{
		begin_iter->Render();
		begin_iter++;
	}
}

void CMapManager::StageMap_Cleanup()
{
	m_Background.Clean();

	std::list<CTile>::iterator begin_iter = m_TileList.begin();
	std::list<CTile>::iterator end_iter = m_TileList.end();

	while (begin_iter != end_iter)
	{
		begin_iter->Clean();
		begin_iter++;
	}
}