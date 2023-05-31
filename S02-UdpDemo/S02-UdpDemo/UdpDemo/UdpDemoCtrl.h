///////////////////////////////////////////////////////////////////////////////
// UdpDemoCtrl.h

#ifndef __UDPDEMOCTRL_H__
#define __UDPDEMOCTRL_H__

#include <atlbase.h>
#include <atlcom.h>

#define UDPDEMODRV_NAME "UDPDEMO"

#include "resource.h"       // main symbols
#include "UdpDemoW32.h"
#include "TcBase.h"
#include "UdpDemoClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CUdpDemoCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CUdpDemoCtrl, &CLSID_UdpDemoCtrl>
	, public IUdpDemoCtrl
	, public ITcOCFCtrlImpl<CUdpDemoCtrl, CUdpDemoClassFactory>
{
public:
	CUdpDemoCtrl();
	virtual ~CUdpDemoCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_UDPDEMOCTRL)
DECLARE_NOT_AGGREGATABLE(CUdpDemoCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CUdpDemoCtrl)
	COM_INTERFACE_ENTRY(IUdpDemoCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __UDPDEMOCTRL_H__
