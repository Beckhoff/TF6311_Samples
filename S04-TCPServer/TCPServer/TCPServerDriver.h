///////////////////////////////////////////////////////////////////////////////
// TCPServerDriver.h

#ifndef __TCPSERVERDRIVER_H__
#define __TCPSERVERDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define TCPSERVERDRV_NAME        "TCPSERVER"
#define TCPSERVERDRV_Major       1
#define TCPSERVERDRV_Minor       0

#define DEVICE_CLASS CTCPServerDriver

#include "ObjDriver.h"

class CTCPServerDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl TCPSERVERDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(TCPSERVERDRV)
	VxD_Service( TCPSERVERDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __TCPSERVERDRIVER_H__