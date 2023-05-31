///////////////////////////////////////////////////////////////////////////////
// TcpClientDriver.h

#ifndef __TCPCLIENTDRIVER_H__
#define __TCPCLIENTDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define TCPCLIENTDRV_NAME        "TCPCLIENT"
#define TCPCLIENTDRV_Major       1
#define TCPCLIENTDRV_Minor       0

#define DEVICE_CLASS CTcpClientDriver

#include "ObjDriver.h"

class CTcpClientDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl TCPCLIENTDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(TCPCLIENTDRV)
	VxD_Service( TCPCLIENTDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __TCPCLIENTDRIVER_H__