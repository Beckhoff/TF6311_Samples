///////////////////////////////////////////////////////////////////////////////
// PingClientDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "PingClientDriver.h"
#include "PingClientClassFactory.h"

DECLARE_GENERIC_DEVICE(PINGCLIENTDRV)

IOSTATUS CPingClientDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CPingClientClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CPingClientDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CPingClientDriver::PINGCLIENTDRV_GetVersion( )
{
	return( (PINGCLIENTDRV_Major << 8) | PINGCLIENTDRV_Minor );
}

