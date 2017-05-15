#pragma once
#include "Header.h"
#include "Character.h"
#include "Sprite.h"

enum{ STAND, UP, DOWN, LEFT, ATTACK };

class CAru : public CCharacter
{
private:
	// 스탠드, 상 하 좌(우), 공격
	CSprite m_sprite[5];

	bool m_bAttacking;

	// 마지막 움직인 방향 ( 좌우 스프라이트 반전용 )
	int currentDirection;

	// 애니매이션 번호
	int m_iAnimate_Num;
	// 애니매이션 마다 스프라이트 크기가 다르므로 RECT 재설정 필요
	

public:
	CAru();
	~CAru();

	// 방향에 따른 애니매이션 번호 지정 함수
	void Set_Animation();
	// 캐릭터 최근 상태에 따른 DrawBitmap Reverse 여부
	bool Check_Reverse();

	void Init(LPDIRECT3DDEVICE9 _pDevice);
	void Update();
	void Render();
	void Clean();
};

