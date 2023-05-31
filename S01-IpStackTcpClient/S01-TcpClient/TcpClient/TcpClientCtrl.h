///////////////////////////////////////////////////////////////////////////////
// TcpClientCtrl.h

#ifndef __TCPCLIENTCTRL_H__
#define __TCPCLIENTCTRL_H__

#include <atlbase.h>
#include <atlcom.h>

#define TCPCLIENTDRV_NAME "TCPCLIENT"

#include "resource.h"       // main symbols
#include "TcpClientW32.h"
#include "TcBase.h"
#include "TcpClientClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CTcpClientCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CTcpClientCtrl, &CLSID_TcpClientCtrl>
	, public ITcpClientCtrl
	, public ITcOCFCtrlImpl<CTcpClientCtrl, CTcpClientClassFactory>
{
public:
	CTcpClientCtrl();
	virtual ~CTcpClientCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_TCPCLIENTCTRL)
DECLARE_NOT_AGGREGATABLE(CTcpClientCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CTcpClientCtrl)
	COM_INTERFACE_ENTRY(ITcpClientCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __TCPCLIENTCTRL_H__
