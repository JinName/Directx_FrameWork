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
			// ���� , ���� �浹
			// 1 : ���� / 2 : ����
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
				// ���� , ���� �浹
				// 1 : ���� / 2 : ����
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

		// �÷��̾ Ÿ�� ���� ������ Ÿ���� �浹 ���ɻ���
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