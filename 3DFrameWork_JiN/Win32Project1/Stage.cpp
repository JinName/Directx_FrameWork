#include "Stage.h"



CStage::CStage()
{
	m_Player = new CAru;
}


CStage::~CStage()
{
}

void CStage::OnInit()
{
	m_Player->aruInit();
}

void CStage::OnUpdate()
{
	m_Player->aruUpdate();
}

void CStage::OnRender()
{
	m_Player->aruRender();
}

void CStage::OnCleanup()
{
	m_Player->aruClean();
}

