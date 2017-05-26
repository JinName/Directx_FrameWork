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
				//(&_aru)->Set_isHorizontal(true);
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
		}
	}
}

void CCollisionManager::Update(CTile* _Tile_Array, int _Tile_Array_Len, CAru &_aru)
{
	int count = 0;
	for(int i = 0; i < _Tile_Array_Len; i++)
	{
		if (_Tile_Array->Get_Collision_is_Possible() == true && (&_aru)->Get_Collision_is_Possible() == true)
		{
			if (m_boxCollider.isIntersect(_Tile_Array->Get_Collider(), (&_aru)->Get_Collider()))
			{
				// 수직 , 수평 충돌
				// 1 : 수직 / 2 : 수평
				if (m_boxCollider.Get_Vertical_or_Horizontal() == 1)
				{
					(&_aru)->Set_isVertical(true);
					_Tile_Array->Set_isCollision(true);
				}
				count++;
			}
			else
			{
				_Tile_Array->Set_isCollision(false);
			}
			
		}

		if (i == _Tile_Array_Len - 1)
		{
			if (count == 0)
			{
				(&_aru)->Set_isVertical(false);
				(&_aru)->Set_isHorizontal(false);
			}
		}

		// 플레이어가 타일 위에 있으면 타일이 충돌 가능상태
		if (m_boxCollider.Player_upCheck((&_aru)->Get_Collider(), _Tile_Array->Get_Collider()))
		{
			_Tile_Array->Set_Collision_is_Possible(true);
		}
		else
		{
			if (_Tile_Array->Get_isCollision() == false)
				_Tile_Array->Set_Collision_is_Possible(false);
		}

		_Tile_Array++;
	}
}