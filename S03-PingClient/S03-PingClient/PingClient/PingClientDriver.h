///////////////////////////////////////////////////////////////////////////////
// PingClientDriver.h

#ifndef __PINGCLIENTDRIVER_H__
#define __PINGCLIENTDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define PINGCLIENTDRV_NAME        "PINGCLIENT"
#define PINGCLIENTDRV_Major       1
#define PINGCLIENTDRV_Minor       0

#define DEVICE_CLASS CPingClientDriver

#include "ObjDriver.h"

class CPingClientDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl PINGCLIENTDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(PINGCLIENTDRV)
	VxD_Service( PINGCLIENTDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __PINGCLIENTDRIVER_H__