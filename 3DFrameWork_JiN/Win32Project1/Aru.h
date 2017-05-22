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

	// 행동 변수
	bool m_bAttacking;
	bool m_bJump;

	// 마지막 움직인 방향 ( 좌우 스프라이트 반전용 )
	int currentDirection;

	// 애니매이션 번호
	int m_iAnimate_Num;
	// 애니매이션 마다 스프라이트 크기가 다르므로 RECT 재설정 필요

	// 중력계산용 시간
	DWORD dwOldtime;
	// 속력
	float velocity;

	// 충돌 시 캐릭터 움직임 제어
	bool isVertical; // 수직 충돌
	bool isHorizontal; // 수평 충돌
	bool isHit; // 피격

public:
	CAru();
	~CAru();

	// 충돌 시 변수 셋팅
	void Set_isVertical(bool _isVertical) { isVertical = _isVertical; }
	void Set_isHorizontal(bool _isHorizontal) { isHorizontal = _isHorizontal; }
	void Set_isHit(bool _isHit) { isHit = _isHit; }

	// 방향에 따른 애니매이션 번호 지정 함수
	void Set_Animation();
	// 캐릭터 최근 상태에 따른 DrawBitmap Reverse 여부
	bool Check_Reverse();

	// 캐릭터 중력
	void Gravity();

	// 캐릭터가 타일과 충돌 시 움직임
	void isCrash_Tile();
	// 적과 부딪혔을때
	void isCrash_Enemy();

	void Init(LPDIRECT3DDEVICE9 _pDevice);
	void Update();
	void Render();
	void Clean();
};

