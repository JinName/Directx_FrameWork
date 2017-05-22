#pragma once
#include "Header.h"
#include "Background.h"
#include "Tile.h"

// Ÿ�� ����
class CMapManager
{
private:
	// Ÿ�� �浹�ڽ� ����Ʈ
	list<RECT> m_Collider_List;

	// �� ���� ��ü��
	CBackground m_Background;
	CTile m_Tile;

	list<CTile> m_TileList;

	// �� ��� ����
	void Create_Background(LPDIRECT3DDEVICE9 _pDevice, int _iStageNum);
	// �� �ٴ� ����
	void Create_Tiles(LPDIRECT3DDEVICE9 _pDevice, int _iStageNum);
public:
	CMapManager();
	~CMapManager();

	void StageMap_Init(LPDIRECT3DDEVICE9 _pDeviceint, int _iStageNum);
	void StageMap_Update();
	void StageMap_Render();
	void StageMap_Cleanup();

	// Ÿ�ϸ���Ʈ ��ȯ
	list<CTile> Get_TileList() { return m_TileList; }
	// �浹�ڽ� ����Ʈ ��ȯ
	list<RECT> Get_Collider_List() { return m_Collider_List; }
};

