///////////////////////////////////////////////////////////////////////////////
// PingClientCtrl.h

#ifndef __PINGCLIENTCTRL_H__
#define __PINGCLIENTCTRL_H__

#include <atlbase.h>
#include <atlcom.h>

#define PINGCLIENTDRV_NAME "PINGCLIENT"

#include "resource.h"       // main symbols
#include "PingClientW32.h"
#include "TcBase.h"
#include "PingClientClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CPingClientCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CPingClientCtrl, &CLSID_PingClientCtrl>
	, public IPingClientCtrl
	, public ITcOCFCtrlImpl<CPingClientCtrl, CPingClientClassFactory>
{
public:
	CPingClientCtrl();
	virtual ~CPingClientCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_PINGCLIENTCTRL)
DECLARE_NOT_AGGREGATABLE(CPingClientCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CPingClientCtrl)
	COM_INTERFACE_ENTRY(IPingClientCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __PINGCLIENTCTRL_H__
