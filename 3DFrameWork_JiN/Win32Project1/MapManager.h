#pragma once
#include "Header.h"
#include "Background.h"
#include "Tile.h"

// 鸥老 积己
class CMapManager
{
private:
	// 鸥老 面倒冠胶 府胶飘
	list<RECT> m_Collider_List;

	// 甘 备己 按眉甸
	CBackground m_Background;
	CTile m_Tile;

	// 缔 硅版 积己
	void Create_Background(int _iStageNum);
	// 甘 官蹿 积己
	void Create_Tiles(int _iStageNum);
public:
	CMapManager();
	~CMapManager();

	void StageMap_Init(int _iStageNum);
	void StageMap_Update();
	void StageMap_Render();
};

