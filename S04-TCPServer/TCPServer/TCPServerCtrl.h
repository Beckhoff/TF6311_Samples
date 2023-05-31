///////////////////////////////////////////////////////////////////////////////
// TCPServerCtrl.h

#ifndef __TCPSERVERCTRL_H__
#define __TCPSERVERCTRL_H__

#include <atlbase.h>
#include <atlcom.h>

#define TCPSERVERDRV_NAME "TCPSERVER"

#include "resource.h"       // main symbols
#include "TCPServerW32.h"
#include "TcBase.h"
#include "TCPServerClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CTCPServerCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CTCPServerCtrl, &CLSID_TCPServerCtrl>
	, public ITCPServerCtrl
	, public ITcOCFCtrlImpl<CTCPServerCtrl, CTCPServerClassFactory>
{
public:
	CTCPServerCtrl();
	virtual ~CTCPServerCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_TCPSERVERCTRL)
DECLARE_NOT_AGGREGATABLE(CTCPServerCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CTCPServerCtrl)
	COM_INTERFACE_ENTRY(ITCPServerCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __TCPSERVERCTRL_H__
