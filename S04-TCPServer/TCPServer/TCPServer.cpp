///////////////////////////////////////////////////////////////////////////////
// TCPServer.cpp
#include "TcPch.h"
#pragma hdrstop

#include "TCPServer.h"
#include "TCPServerVersion.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
DEFINE_THIS_FILE()

///////////////////////////////////////////////////////////////////////////////
// CTCPServer
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Collection of interfaces implemented by module CTCPServer
BEGIN_INTERFACE_MAP(CTCPServer)
	INTERFACE_ENTRY_ITCOMOBJECT()
	INTERFACE_ENTRY(IID_ITcADI, ITcADI)
	INTERFACE_ENTRY(IID_ITcWatchSource, ITcWatchSource)
///<AutoGeneratedContent id="InterfaceMap">
	INTERFACE_ENTRY(IID_ITcCyclic, ITcCyclic)
	INTERFACE_ENTRY(IID_ITcIoTcpProtocolRecv, ITcIoTcpProtocolRecv)
///</AutoGeneratedContent>
END_INTERFACE_MAP()


IMPLEMENT_IPERSIST_LIB(CTCPServer, VID_TCPServer, CID_TCPServerCTCPServer)
IMPLEMENT_ITCOMOBJECT(CTCPServer)
IMPLEMENT_ITCOMOBJECT_SETSTATE_LOCKOP2(CTCPServer)
IMPLEMENT_ITCADI(CTCPServer)
IMPLEMENT_ITCWATCHSOURCE(CTCPServer)


///////////////////////////////////////////////////////////////////////////////
// Set parameters of CTCPServer 
BEGIN_SETOBJPARA_MAP(CTCPServer)
	SETOBJPARA_DATAAREA_MAP()
///<AutoGeneratedContent id="SetObjectParameterMap">
	SETOBJPARA_VALUE(PID_TcTraceLevel, m_TraceLevelMax)
	SETOBJPARA_VALUE(PID_TCPServerParameter, m_Parameter)
	SETOBJPARA_VALUE(PID_TCPServerTcpServerPort, m_TcpServerPort)
	SETOBJPARA_ITFPTR(PID_Ctx_TaskOid, m_spCyclicCaller)
	SETOBJPARA_ITFPTR(PID_TCPServerTcpProt, m_spTcpProt)
///</AutoGeneratedContent>
END_SETOBJPARA_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get parameters of CTCPServer 
BEGIN_GETOBJPARA_MAP(CTCPServer)
	GETOBJPARA_DATAAREA_MAP()
///<AutoGeneratedContent id="GetObjectParameterMap">
	GETOBJPARA_VALUE(PID_TcTraceLevel, m_TraceLevelMax)
	GETOBJPARA_VALUE(PID_TCPServerParameter, m_Parameter)
	GETOBJPARA_VALUE(PID_TCPServerTcpServerPort, m_TcpServerPort)
	GETOBJPARA_ITFPTR(PID_Ctx_TaskOid, m_spCyclicCaller)
	GETOBJPARA_ITFPTR(PID_TCPServerTcpProt, m_spTcpProt)
///</AutoGeneratedContent>
END_GETOBJPARA_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get watch entries of CTCPServer
BEGIN_OBJPARAWATCH_MAP(CTCPServer)
	OBJPARAWATCH_DATAAREA_MAP()
///<AutoGeneratedContent id="ObjectParameterWatchMap">
///</AutoGeneratedContent>
END_OBJPARAWATCH_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get data area members of CTCPServer
BEGIN_OBJDATAAREA_MAP(CTCPServer)
///<AutoGeneratedContent id="ObjectDataAreaMap">
///</AutoGeneratedContent>
END_OBJDATAAREA_MAP()


///////////////////////////////////////////////////////////////////////////////
CTCPServer::CTCPServer()
	: m_Trace(m_TraceLevelMax, m_spSrv)
	, m_counter(0)
{
///<AutoGeneratedContent id="MemberInitialization">
	m_TraceLevelMax = tlAlways;
	memset(&m_Parameter, 0, sizeof(m_Parameter));
	m_TcpServerPort = 0;
///</AutoGeneratedContent>
	m_SockId = 0;
}

///////////////////////////////////////////////////////////////////////////////
CTCPServer::~CTCPServer() 
{
}


///////////////////////////////////////////////////////////////////////////////
// State Transitions 
///////////////////////////////////////////////////////////////////////////////
IMPLEMENT_ITCOMOBJECT_SETOBJSTATE_IP_PI(CTCPServer)

///////////////////////////////////////////////////////////////////////////////
// State transition from PREOP to SAFEOP
//
// Initialize input parameters 
// Allocate memory
HRESULT CTCPServer::SetObjStatePS(PTComInitDataHdr pInitData)
{
	m_Trace.Log(tlVerbose, FENTERA);
	HRESULT hr = S_OK;
	IMPLEMENT_ITCOMOBJECT_EVALUATE_INITDATA(pInitData);

	// TODO: Add initialization code

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
// State transition from SAFEOP to OP
//
// Register with other TwinCAT objects
HRESULT CTCPServer::SetObjStateSO()
{
	m_Trace.Log(tlVerbose, FENTERA);
	HRESULT hr = S_OK;

	if (SUCCEEDED(hr) && m_spTcpProt.HasOID())
	{
		hr = m_spSrv->TcQuerySmartObjectInterface(m_spTcpProt);
	}


	// If following call is successful the CycleUpdate method will be called, 
	// possibly even before method has been left.
	hr = FAILED(hr) ? hr : AddModuleToCaller(); 

	// Cleanup if transition failed at some stage
	if ( FAILED(hr) )
	{
		RemoveModuleFromCaller(); 
	}

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
// State transition from OP to SAFEOP
HRESULT CTCPServer::SetObjStateOS()
{
	m_Trace.Log(tlVerbose, FENTERA);

	HRESULT hr = S_OK;

	RemoveModuleFromCaller(); 

	if (m_SockId != 0)
	{
		if (m_spTcpProt->IsConnected(m_SockId))
		{
			m_spTcpProt->Close(m_SockId);
			m_spTcpProt->CheckReceived();
		}

		m_spTcpProt->FreeSocket(m_SockId);
		m_SockId = 0;
	}

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
// State transition from SAFEOP to PREOP
HRESULT CTCPServer::SetObjStateSP()
{
	HRESULT hr = S_OK;
	m_Trace.Log(tlVerbose, FENTERA);

	// TODO: Add deinitialization code

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///<AutoGeneratedContent id="ImplementationOf_ITcCyclic">
HRESULT CTCPServer::CycleUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context)
{
	HRESULT hr = S_OK;

	if ( m_SockId == 0 )
	{
		if (SUCCEEDED_DBG(hr = m_spTcpProt->AllocSocket(THIS_CAST(ITcIoTcpProtocolRecv), m_SockId)))
		{
			if (FAILED(hr = m_spTcpProt->Listen(m_SockId,  m_TcpServerPort)))
			{
				m_spTcpProt->FreeSocket(m_SockId);
				m_SockId = 0;
			}	
		}
	}
	m_spTcpProt->CheckReceived();

	return hr;
}
///</AutoGeneratedContent>

///////////////////////////////////////////////////////////////////////////////
HRESULT CTCPServer::AddModuleToCaller()
{
	m_Trace.Log(tlVerbose, FENTERA);

	HRESULT hr = S_OK;
	if ( m_spCyclicCaller.HasOID() )
	{
		if ( SUCCEEDED_DBG(hr = m_spSrv->TcQuerySmartObjectInterface(m_spCyclicCaller)) )
		{
			if ( FAILED(hr = m_spCyclicCaller->AddModule(m_spCyclicCaller, THIS_CAST(ITcCyclic))) )
			{
				m_spCyclicCaller = NULL;
			}
		}
	}
	else
	{
		hr = ADS_E_INVALIDOBJID; 
		SUCCEEDED_DBGT(hr, "Invalid OID specified for caller task");
	}

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
VOID CTCPServer::RemoveModuleFromCaller()
{
	m_Trace.Log(tlVerbose, FENTERA);

	if ( m_spCyclicCaller )
	{
		m_spCyclicCaller->RemoveModule(m_spCyclicCaller);
	}
	m_spCyclicCaller	= NULL;

	m_Trace.Log(tlVerbose, FLEAVEA);
}


///<AutoGeneratedContent id="ImplementationOf_ITcIoTcpProtocolRecv">
HRESULT CTCPServer::ReceiveData(ULONG socketId, ULONG nData, PVOID pData)
{
	HRESULT hr = S_OK;

	PCHAR pResponse = new CHAR[100];
	if (pResponse != NULL)
	{		
		memset(pResponse, 0, 100);
		int endpos = min(100, nData);
		memcpy(pResponse, pData, endpos);
		pResponse[endpos] = 0; //\0 term

		m_Trace.Log(tlInfo, FLEAVEA "Received packet w/ length %d : first 100 chars:'%s'", nData, pResponse);
		ULONG nSendData = 0;
		m_spTcpProt->SendData(socketId, endpos, pResponse, nSendData); 
		delete[] pResponse;
	}
	return hr;

}

HRESULT CTCPServer::ReceiveEvent(ULONG socketId, TCPIP_EVENT tcpEvent)
{
	m_Trace.Log(tlInfo, FLEAVEA "Receive TCP Event: SocketId: %d Event: %d", socketId, tcpEvent);

	switch (tcpEvent)
	{
	case TCPIP_EVENT_RESET:
	case TCPIP_EVENT_TIMEOUT:
		if (socketId == m_SockId)
		{
			m_Trace.Log(tlInfo, FLEAVEA "Connection failed!");
		}
		break;
	case TCPIP_EVENT_CONN_CLOSED:
		m_Trace.Log(tlInfo, FLEAVEA "Close connection: SocketId: %d", socketId);
		m_spTcpProt->FreeSocket(socketId);
		break;
    case TCPIP_EVENT_CONN_INCOMING:
			m_spTcpProt->Accept(socketId); //Server
		break;
	case TCPIP_EVENT_KEEP_ALIVE:
	case TCPIP_EVENT_CONN_IDLE:
		break;
	case TCPIP_EVENT_DATA_SENT:
	case TCPIP_EVENT_DATA_RECEIVED:
		break;
	case TCPIP_EVENT_LINKCONNECT:
		break;
	case TCPIP_EVENT_LINKDISCONNECT:
		m_Trace.Log(tlInfo, FLEAVEA "link disconnect connection: SocketId: %d", socketId);
		m_spTcpProt->FreeSocket(socketId);
		m_SockId = 0;
		break;
	case TCPIP_EVENT_ERROR:
	default:
		break;
	}

	return S_OK;
}
///</AutoGeneratedContent>
