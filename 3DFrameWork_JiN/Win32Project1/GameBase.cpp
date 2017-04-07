#include "GameBase.h"


CGameBase::CGameBase()
	//:vertex(NULL),
	//m_pos()
{
	//vertex = new CVertex;
	/*
	m_Sun = NULL;
	m_Earth = NULL;
	m_Moon = NULL;
	*/
}


CGameBase::~CGameBase()
{
}

void CGameBase::OnInit()
{
	//vertex->InitVB(GetDevice());

	/*
	LPD3DXMESH tempSun = NULL;
	LPD3DXMESH tempEarth = NULL;
	D3DXCreateSphere(GetDevice(), 1.0f, 20, 20, &tempSun, NULL);
	D3DXCreateSphere(GetDevice(), 1.0f, 10, 10, &tempEarth, NULL);
	D3DXCreateSphere(GetDevice(), 0.5f, 8, 8, &m_Moon, NULL);

	LPDIRECT3DVERTEXBUFFER9 pTempVB = NULL;
	tempEarth->CloneMeshFVF(0, D3DFVF_XYZ | D3DFVF_DIFFUSE, GetDevice(), &m_Earth);

	if (SUCCEEDED(m_Earth->GetVertexBuffer(&pTempVB)))
	{
		int nNumVerts = m_Earth->GetNumVertices();
		CUSTOMVERTEX *pVertices = NULL;

		pTempVB->Lock(0, 0, (void**)&pVertices, 0);
		{
			for (int i = 0; i < nNumVerts; ++i)
				pVertices[i].color = D3DCOLOR_COLORVALUE(0.0, 0.0, 1.0, 1.0);
		}
		pTempVB->Unlock();
		pTempVB->Release();
	}

	tempSun->CloneMeshFVF(0, D3DFVF_XYZ | D3DFVF_DIFFUSE, GetDevice(), &m_Sun);

	if (SUCCEEDED(m_Sun->GetVertexBuffer(&pTempVB)))
	{
		int nNumVerts = m_Sun->GetNumVertices();
		CUSTOMVERTEX *pVertices = NULL;

		pTempVB->Lock(0, 0, (void**)&pVertices, 0);
		{
			for (int i = 0; i < nNumVerts; ++i)
				pVertices[i].color = D3DCOLOR_COLORVALUE(1.0, 1.0, 0.0, 1.0);
		}
		pTempVB->Unlock();
		pTempVB->Release();
	}
	
	tempSun->Release();
	tempEarth->Release();
	*/
}

void CGameBase::OnUpdate()
{}

void CGameBase::OnRender()
{
	/*
	D3DXMATRIXA16 matWorld;

	// Set up the rotation matrix to generate 1 full rotation (2*PI radians) 
	// every 1000 ms. To avoid the loss of precision inherent in very high 
	// floating point numbers, the system time is modulated by the rotation 
	// period before conversion to a radian angle.
	UINT iTime = timeGetTime() % 1000;
	FLOAT fAngle = iTime * (2.0f * D3DX_PI) / 1000.0f;
	D3DXMatrixRotationY(&matWorld, fAngle);
	GetDevice()->SetTransform(D3DTS_WORLD, &matWorld);

	GetDevice()->SetStreamSource(0, vertex->GetVertexBuffer(), 0, sizeof(CUSTOMVERTEX));
	GetDevice()->SetFVF(D3DFVF_CUSTOMVERTEX);
	GetDevice()->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
	*/

	/*
	D3DXMATRIX SunScale;
	D3DXMATRIX SunSpinRotation;
	D3DXMATRIX SunMatrix;

	D3DXMatrixRotationY( &SunSpinRotation, D3DXToRadian(10.0f));
	D3DXMatrixScaling(&SunScale, 5.0f, 5.0f, 5.0f);

	SunMatrix = SunScale * SunSpinRotation;

	GetDevice()->SetTransform(D3DTS_WORLD, &SunMatrix);
	m_Sun->DrawSubset(0);
	*/
}

void CGameBase::OnCleanup()
{
	//vertex->Release();
	//delete vertex;
}

void CGameBase::SetPosition(float _fx, float _fy, float _fz)
{
	m_pos.m_fx = _fx;
	m_pos.m_fy = _fy;
	m_pos.m_fz = _fz;

	//matrix 연산 필요

	D3DXMATRIXA16 matWorld;
	D3DXMatrixTranslation(&matWorld, m_pos.m_fx, m_pos.m_fy, m_pos.m_fz);
	//D3DXMatrixRotationY(&matWorld, timeGetTime() / 1000.0f);
	GetDevice()->SetTransform(D3DTS_WORLD, &matWorld);
}