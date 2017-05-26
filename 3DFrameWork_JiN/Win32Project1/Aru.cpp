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

void CAru::Jump()
{
	if (m_bJump)
	{
		if (!m_bOld_Check)
		{
			m_fOld_Pos_y = m_vPos.y;
			m_bCollision_is_Possible = false;
			m_bOld_Check = true;
		}
		m_vPos.y -= m_fJump_Power;
	}
}

void CAru::Gravity()
{	
	DWORD currentTime = GetTickCount();

	DWORD TempTime = currentTime - dwOldtime;
		
	dwOldtime = currentTime;

	if (!isVertical)
	{
		velocity += 0.0098f * (float)TempTime / 60.0f;
		m_fGravity_Accel = velocity * (float)TempTime * m_fCharacter_mass;
		m_vPos.y = m_vPos.y + m_fGravity_Accel;
	}
	else
	{
		m_fGravity_Accel = 0.0f;
		velocity = 0.0f;
	}
}

void CAru::isCrash_Tile()
{
	if (isVertical)
	{
		m_vPos.y = m_vPos.y;
		m_bJump = false;
		m_bOld_Check = false;
		m_bJump_is_Possible = true;
	}
	else
	{
		m_bJump_is_Possible = false;
	}
	/*
	else if (isHorizontal)
	{
		m_vPos.x = m_vPos.x;
		m_bJump = false;
		m_bOld_Check = false;
	}
	*/
	
}

void CAru::isCrash_Enemy()
{

}

void CAru::Check_Collision_is_Possible()
{
	if (m_bJump)
	{
		if (m_fGravity_Accel > m_fJump_Power)
		{
			m_bCollision_is_Possible = true;
		}
	}
}

void CAru::Init(LPDIRECT3DDEVICE9 _pDevice)
{
	m_fSpeed = 3.0f;
	m_fJump_Power = 5.5f;
	m_fGravity_Accel = 0.0f;
	m_vDirection = { 0.0f, 0.0f };
	// 캐릭 질량
	m_fCharacter_mass = 4.0f;

	isVertical = false; // 수직 충돌
	isHorizontal = false; // 수평 충돌
	isHit = false; // 피격

	// 충돌박스 선 그리기
	Line_Init(_pDevice);

	// 캐릭터 기본 시작 위치
	m_vPos = { 100.0f, 100.0f, 0.0f };

	// 공격 중인지
	m_bAttacking = false;

	// 점프 관련
	m_bJump_is_Possible = false; // 바닥에 붙어있을때만 true
	m_bCollision_is_Possible = true; // 점프 중일때 false
	m_bJump = false;
	m_fOld_Pos_y = 0.0f;
	m_bOld_Check = false;

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
	Check_Collision_is_Possible();
	
	Move();

	Jump();
	Gravity();

	Set_Animation();

	m_sprite[m_iAnimate_Num].Animation_Frame();

	Set_Collider(m_sprite[m_iAnimate_Num].Get_Sprite_Width() - 20.0f, m_sprite[m_iAnimate_Num].Get_Sprite_Height(), true, RECT{0, 20, 0, 0});
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

VOID CAru::Move()
{
	if (CInput::Get_Instance()->IsKeyPressed(DIK_LEFT) == true)
	{
		if (!isHorizontal)
		{
			m_vPos.x -= m_fSpeed;
			m_vDirection.x = -1.0f;
		}		
	}
	else if (CInput::Get_Instance()->IsKeyPressed(DIK_RIGHT) == true)
	{
		if (!isHorizontal)
		{
			m_vPos.x += m_fSpeed;
			m_vDirection.x = 1.0f;
		}
	}
	else if (CInput::Get_Instance()->IsKeyPressed(DIK_UP) == true)
	{
		m_vPos.y -= m_fSpeed;
		m_vDirection.y = -1.0f;
	}
	else if (CInput::Get_Instance()->IsKeyPressed(DIK_DOWN) == true)
	{
		m_vPos.y += m_fSpeed;
		m_vDirection.y = 1.0f;
	}

	// JUMP
	if (m_bJump_is_Possible)
	{
		if (CInput::Get_Instance()->IsKeyPressed(DIK_SPACE) == true)
		{
			if (!m_bOld_Check)
			{
				m_bJump = true;
			}
		}
	}
	

	if (CInput::Get_Instance()->IsKeyPressed(DIK_LEFT) == false &&
		CInput::Get_Instance()->IsKeyPressed(DIK_RIGHT) == false &&
		CInput::Get_Instance()->IsKeyPressed(DIK_UP) == false &&
		CInput::Get_Instance()->IsKeyPressed(DIK_DOWN) == false)
	{
		m_vDirection = { 0.0f, 0.0f };
	}
}