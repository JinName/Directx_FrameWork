#include "CollisionManager.h"



CCollisionManager::CCollisionManager()
{
}


CCollisionManager::~CCollisionManager()
{
}

void CCollisionManager::Init()
{
	m_boxCollider.Init();
}

void CCollisionManager::Update(list<RECT> &_Rect_List, CAru &_aru)
{
	std::list<RECT>::iterator begin_iter = _Rect_List.begin();
	std::list<RECT>::iterator end_iter = _Rect_List.end();
	int count = 0;

	for (int i = 0; i < _Rect_List.size(); i++)
	{
		if (m_boxCollider.isIntersect(*begin_iter, (&_aru)->Get_Collider()))
		{
			// 수직 , 수평 충돌
			// 1 : 수직 / 2 : 수평
			if (m_boxCollider.Get_Vertical_or_Horizontal() == 1)
			{
				(&_aru)->Set_isVertical(true);
			}
			else if (m_boxCollider.Get_Vertical_or_Horizontal() == 2)
			{
				(&_aru)->Set_isHorizontal(true);
			}
			count++;
		}
		begin_iter++;
		
		if (begin_iter == end_iter)
		{
			if (count == 0)
			{
				(&_aru)->Set_isVertical(false);
				(&_aru)->Set_isHorizontal(false);
			}
			//count = 0;
		}
	}
}