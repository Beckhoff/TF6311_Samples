///////////////////////////////////////////////////////////////////////////////
// TcpClientClassFactory.cpp
#include "TcPch.h"
#pragma hdrstop

#include "TcpClientClassFactory.h"
#include "TcpClientServices.h"
#include "TcpClientVersion.h"
#include "TcpClient.h"

BEGIN_CLASS_MAP(CTcpClientClassFactory)
///<AutoGeneratedContent id="ClassMap">
	CLASS_ENTRY_LIB(VID_TcpClient, CID_TcpClientCTcpClient, SRVNAME_TCPCLIENT "!CTcpClient", CTcpClient)
///</AutoGeneratedContent>
END_CLASS_MAP()

CTcpClientClassFactory::CTcpClientClassFactory() : CObjClassFactory()
{
	TcDbgUnitSetImageName(TCDBG_UNIT_IMAGE_NAME_TMX(SRVNAME_TCPCLIENT)); 
#if defined(TCDBG_UNIT_VERSION)
	TcDbgUnitSetVersion(TCDBG_UNIT_VERSION(TcpClient));
#endif //defined(TCDBG_UNIT_VERSION)
}

