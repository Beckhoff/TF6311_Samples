///////////////////////////////////////////////////////////////////////////////
// PingModule.h
#pragma once

#include "PingClientInterfaces.h"

class CPingModule 
	: public ITComObject
	, public ITcADI
	, public ITcWatchSource
///<AutoGeneratedContent id="InheritanceList">
	, public ITcCyclic
	, public ITcIoArpPingRecv
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

	CPingModule();
	virtual	~CPingModule();


///<AutoGeneratedContent id="InterfaceMembers">
	// ITcCyclic
	virtual HRESULT TCOMAPI CycleUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context);

	// ITcIoArpPingRecv
	virtual HRESULT TCOMAPI ArpReply(ULONG ipAddr, ETHERNET_ADDRESS macAddr, ETYPE_VLAN_HEADER* pVlan=0);
	virtual HRESULT TCOMAPI PingReply(ULONG ipAddr, ULONG nData, PVOID pData, ETYPE_VLAN_HEADER* pVlan=0);

///</AutoGeneratedContent>

protected:
	DECLARE_ITCOMOBJECT_SETSTATE();

	HRESULT AddModuleToCaller();
	VOID RemoveModuleFromCaller();

	// Tracing
	CTcTrace m_Trace;

///<AutoGeneratedContent id="Members">
	TcTraceLevel m_TraceLevelMax;
	PingModuleParameter m_Parameter;
	IPADDR m_IpAddress;
	PingModuleInputs m_Inputs;
	PingModuleOutputs m_Outputs;
	ITcCyclicCallerInfoPtr m_spCyclicCaller;
	ITcIoArpPingPtr m_spArpProt;
///</AutoGeneratedContent>

	// TODO: Custom variable
	UINT m_counter;
	BOOL m_bSendRequest;
	BOOL m_PendingArp;
	BOOL m_PendingPing;
};