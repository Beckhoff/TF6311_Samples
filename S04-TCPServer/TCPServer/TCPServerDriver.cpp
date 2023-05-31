///////////////////////////////////////////////////////////////////////////////
// TCPServerDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "TCPServerDriver.h"
#include "TCPServerClassFactory.h"

DECLARE_GENERIC_DEVICE(TCPSERVERDRV)

IOSTATUS CTCPServerDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CTCPServerClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CTCPServerDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CTCPServerDriver::TCPSERVERDRV_GetVersion( )
{
	return( (TCPSERVERDRV_Major << 8) | TCPSERVERDRV_Minor );
}

