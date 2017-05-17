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

	// �� ��� ����
	void Create_Background(int _iStageNum);
	// �� �ٴ� ����
	void Create_Tiles(int _iStageNum);
public:
	CMapManager();
	~CMapManager();

	void StageMap_Init(int _iStageNum);
	void StageMap_Update();
	void StageMap_Render();
};

