///////////////////////////////////////////////////////////////////////////////
// UdpDemoDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "UdpDemoDriver.h"
#include "UdpDemoClassFactory.h"

DECLARE_GENERIC_DEVICE(UDPDEMODRV)

IOSTATUS CUdpDemoDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CUdpDemoClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CUdpDemoDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CUdpDemoDriver::UDPDEMODRV_GetVersion( )
{
	return( (UDPDEMODRV_Major << 8) | UDPDEMODRV_Minor );
}

