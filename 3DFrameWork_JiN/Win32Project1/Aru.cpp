#include "Aru.h"



CAru::CAru()
{
}

CAru::~CAru()
{
}

void CAru::Set_Animation()
{
	if (m_vDirection.x == 0 && m_vDirection.y == 0)
	{
		m_iAnimate_Num = 0;
	}
	else if (m_vDirection.y < 0)
	{
		m_iAnimate_Num = 1;
	}
	else if (m_vDirection.y > 0)
	{
		m_iAnimate_Num = 2;
	}
	else if (m_vDirection.x > 0 || m_vDirection.x < 0)
	{
		m_iAnimate_Num = 3;
		if (m_vDirection.x < 0)
			currentDirection = LEFT;
		else if (m_vDirection.x > 0)
			currentDirection = -LEFT;
	}
	else if (m_bAttacking == true)
	{
		m_iAnimate_Num = 4;
	}
}

bool CAru::Check_Reverse()
{
	if (m_vDirection.x == 0 && m_vDirection.y == 0)
	{
		if (currentDirection == LEFT)
			return false;
		else if (currentDirection == -LEFT)
			return true;
	}
	else if (m_vDirection.x > 0 || m_vDirection.x < 0)
	{
		if (m_vDirection.x < 0)
			return false;
		else if (m_vDirection.x > 0)
			return true;
	}

	return false;
}

void CAru::Gravity()
{	
	DWORD currentTime = GetTickCount();

	DWORD TempTime = currentTime - dwOldtime;
		
	dwOldtime = currentTime;

	if (!isVertical && !isHorizontal)
	{
		velocity += 0.0098f * (float)TempTime / 60.0f;
		m_vPos.y = m_vPos.y + velocity * (float)TempTime;
	}
	else
	{
		velocity = 0.0f;
	}
}

void CAru::isCrash_Tile()
{
	if (isVertical)
	{
		m_vPos.y = m_vPos.y;
	}
	else if (isHorizontal)
	{
		m_vPos.x = m_vPos.x;
	}
}

void CAru::isCrash_Enemy()
{

}

void CAru::Init(LPDIRECT3DDEVICE9 _pDevice)
{
	bool isVertical = false; // 수직 충돌
	bool isHorizontal = false; // 수평 충돌
	bool isHit = false; // 피격

	// 충돌박스 선 그리기
	Line_Init(_pDevice);

	// 캐릭터 기본 시작 위치
	m_vPos = { 100.0f, 100.0f, 0.0f };

	// 공격 중인지
	m_bAttacking = false;

	// 마지막 움직인 방향 ( 좌우 스프라이트 반전용 )
	currentDirection = LEFT;

	// 애니매이션 넘버 ( 기본 = 0 )
	m_iAnimate_Num = 0;

	dwOldtime = GetTickCount();
	velocity = 0.0f;
	
	// 캐릭터 스탠드 스프라이트
	m_sprite[STAND].Create_Sprite(_pDevice, L"2D_Sprites\\Aru_stand_8peaces.bmp", 512, 64, 8, D3DCOLOR_XRGB(0, 170, 255));
	m_sprite[UP].Create_Sprite(_pDevice, L"2D_Sprites\\Aru_up_8peaces.bmp", 512, 64, 8, D3DCOLOR_XRGB(0, 170, 255));
	m_sprite[DOWN].Create_Sprite(_pDevice, L"2D_Sprites\\Aru_down_8peaces.bmp", 512, 64, 8, D3DCOLOR_XRGB(0, 170, 255));
	m_sprite[LEFT].Create_Sprite(_pDevice, L"2D_Sprites\\Aru_left_8peaces.bmp", 512, 64, 8, D3DCOLOR_XRGB(0, 170, 255));
	m_sprite[ATTACK].Create_Sprite(_pDevice, L"2D_Sprites\\Aru_attack_6peaces.bmp", 480, 48, 6, D3DCOLOR_XRGB(0, 170, 255));
}

void CAru::Update()
{
	isCrash_Tile();
	Gravity();
	Move();

	Set_Animation();

	m_sprite[m_iAnimate_Num].Animation_Frame();

	Set_Collider(m_sprite[m_iAnimate_Num].Get_Sprite_Width(), m_sprite[m_iAnimate_Num].Get_Sprite_Height(), true);
}

void CAru::Render()
{
	m_sprite[m_iAnimate_Num].DrawBitmap(&m_vPos, 0xFFFFFFFF, Check_Reverse());
	Draw_RectLine();
}

void CAru::Clean()
{
	for (int i = 0; i < 5; ++i)
	{
		m_sprite[i].CleanUp();
	}
}