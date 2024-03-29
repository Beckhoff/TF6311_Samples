///////////////////////////////////////////////////////////////////////////////
// TCPServer.h
#pragma once

#include "TCPServerInterfaces.h"

class CTCPServer 
	: public ITComObject
	, public ITcADI
	, public ITcWatchSource
///<AutoGeneratedContent id="InheritanceList">
	, public ITcCyclic
	, public ITcIoTcpProtocolRecv
///</AutoGeneratedContent>
{
public:
	DECLARE_IUNKNOWN()
	DECLARE_IPERSIST_LIB()
	DECLARE_ITCOMOBJECT_LOCKOP()
	DECLARE_ITCADI()
	DECLARE_ITCWATCHSOURCE()
	DECLARE_OBJPARAWATCH_MAP()
	DECLARE_OBJDATAAREA_MAP()

	CTCPServer();
	virtual	~CTCPServer();


///<AutoGeneratedContent id="InterfaceMembers">
	// ITcCyclic
	virtual HRESULT TCOMAPI CycleUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context);

	// ITcIoTcpProtocolRecv
	virtual HRESULT TCOMAPI ReceiveData(ULONG socketId, ULONG nData, PVOID pData);
	virtual HRESULT TCOMAPI ReceiveEvent(ULONG socketId, TCPIP_EVENT tcpEvent);

///</AutoGeneratedContent>

protected:
	DECLARE_ITCOMOBJECT_SETSTATE();

	HRESULT AddModuleToCaller();
	VOID RemoveModuleFromCaller();

	// Tracing
	CTcTrace m_Trace;

///<AutoGeneratedContent id="Members">
	TcTraceLevel m_TraceLevelMax;
	TCPServerParameter m_Parameter;
	USHORT m_TcpServerPort;
	ITcCyclicCallerInfoPtr m_spCyclicCaller;
	ITcIoTcpProtocolPtr m_spTcpProt;
///</AutoGeneratedContent>

	// TODO: Custom variable
	UINT m_counter;
	ULONG m_SockId;
};
