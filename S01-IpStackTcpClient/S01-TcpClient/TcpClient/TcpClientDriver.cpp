///////////////////////////////////////////////////////////////////////////////
// TcpClientDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "TcpClientDriver.h"
#include "TcpClientClassFactory.h"

DECLARE_GENERIC_DEVICE(TCPCLIENTDRV)

IOSTATUS CTcpClientDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CTcpClientClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CTcpClientDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CTcpClientDriver::TCPCLIENTDRV_GetVersion( )
{
	return( (TCPCLIENTDRV_Major << 8) | TCPCLIENTDRV_Minor );
}

