///////////////////////////////////////////////////////////////////////////////
// UdpDemoDriver.h

#ifndef __UDPDEMODRIVER_H__
#define __UDPDEMODRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define UDPDEMODRV_NAME        "UDPDEMO"
#define UDPDEMODRV_Major       1
#define UDPDEMODRV_Minor       0

#define DEVICE_CLASS CUdpDemoDriver

#include "ObjDriver.h"

class CUdpDemoDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl UDPDEMODRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(UDPDEMODRV)
	VxD_Service( UDPDEMODRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __UDPDEMODRIVER_H__