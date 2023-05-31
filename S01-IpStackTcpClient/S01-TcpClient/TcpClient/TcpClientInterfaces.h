///////////////////////////////////////////////////////////////////////////////
// TcpClientInterfaces.h

#pragma once

#include "TcInterfaces.h"
#include "TcIoInterfaces.h"
#include "TcRtInterfaces.h"
#include "TcpClientServices.h"

///<AutoGeneratedContent id="Interfaces">
#if !defined(_TC_TYPE_03010099_0000_0000_E000_000000000064_INCLUDED_)
#define _TC_TYPE_03010099_0000_0000_E000_000000000064_INCLUDED_
struct __declspec(novtable) ITcIoTcpProtocolRecv : public ITcUnknown
{
	virtual HRESULT TCOMAPI ReceiveData(ULONG socketId, ULONG nData, PVOID pData)=0;
	virtual HRESULT TCOMAPI ReceiveEvent(ULONG socketId, TCPIP_EVENT tcpEvent)=0;
};
_TCOM_SMARTPTR_TYPEDEF(ITcIoTcpProtocolRecv, IID_ITcIoTcpProtocolRecv);
#endif // !defined(_TC_TYPE_03010099_0000_0000_E000_000000000064_INCLUDED_)

#if !defined(_TC_TYPE_03010098_0000_0000_E000_000000000064_INCLUDED_)
#define _TC_TYPE_03010098_0000_0000_E000_000000000064_INCLUDED_
struct __declspec(novtable) ITcIoTcpProtocol : public ITcUnknown
{
	virtual HRESULT TCOMAPI AllocSocket(ITcIoTcpProtocolRecv* ipRecv, ULONG& socketId)=0;
	virtual HRESULT TCOMAPI FreeSocket(ULONG socketId)=0;
	virtual HRESULT TCOMAPI Connect(ULONG socketId, ULONG ipRemoteAddress, USHORT tcpPort)=0;
	virtual HRESULT TCOMAPI IsConnected(ULONG socketId)=0;
	virtual HRESULT TCOMAPI Close(ULONG socketId)=0;
	virtual HRESULT TCOMAPI Listen(ULONG socketId, USHORT tcpPort)=0;
	virtual HRESULT TCOMAPI Accept(ULONG socketId)=0;
	virtual HRESULT TCOMAPI SendData(ULONG socketId, ULONG nData, PVOID pData, ULONG& nSendData)=0;
	virtual HRESULT TCOMAPI CheckReceived()=0;
	virtual HRESULT TCOMAPI GetRemoteIpAddr(ULONG socketId, ULONG& remoteIpAddr)=0;
	virtual HRESULT TCOMAPI GetFreeSendDataSize(ULONG socketId, ULONG& nData)=0;
};
_TCOM_SMARTPTR_TYPEDEF(ITcIoTcpProtocol, IID_ITcIoTcpProtocol);
#endif // !defined(_TC_TYPE_03010098_0000_0000_E000_000000000064_INCLUDED_)

///</AutoGeneratedContent>
