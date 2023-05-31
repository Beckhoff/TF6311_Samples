///////////////////////////////////////////////////////////////////////////////
// TCPServerServices.h

#pragma once

#include "TcServices.h"

const ULONG DrvID_TCPServer = 0x3F000000;
#define SRVNAME_TCPSERVER "TCPServer"

///<AutoGeneratedContent id="ClassIDs">
const CTCID CID_TCPServerCTCPServer = {0x0ac9c3bc,0x178d,0x48ce,{0x87,0x6a,0x10,0xa6,0xe1,0x76,0xca,0x72}};
///</AutoGeneratedContent>

///<AutoGeneratedContent id="ParameterIDs">
const PTCID PID_TCPServerParameter = 0x00000001;
const PTCID PID_TCPServerTcpServerPort = 0x00000002;
const PTCID PID_TCPServerTcpProt = 0x00000003;
///</AutoGeneratedContent>

///<AutoGeneratedContent id="DataTypes">
#if !defined(_TC_TYPE_7CECC506_F55F_4594_B611_972D650865D2_INCLUDED_)
#define _TC_TYPE_7CECC506_F55F_4594_B611_972D650865D2_INCLUDED_
enum TCPIP_EVENT : ULONG {
	TCPIP_EVENT_NONE = 0,
	TCPIP_EVENT_ERROR = 1,
	TCPIP_EVENT_RESET = 2,
	TCPIP_EVENT_TIMEOUT = 3,
	TCPIP_EVENT_CONN_ESTABLISHED = 4,
	TCPIP_EVENT_CONN_INCOMING = 5,
	TCPIP_EVENT_CONN_CLOSED = 6,
	TCPIP_EVENT_CONN_IDLE = 7,
	TCPIP_EVENT_DATA_RECEIVED = 8,
	TCPIP_EVENT_DATA_SENT = 9,
	TCPIP_EVENT_KEEP_ALIVE = 10,
	TCPIP_EVENT_LINKCONNECT = 11,
	TCPIP_EVENT_LINKDISCONNECT = 12
};
#endif // !defined(_TC_TYPE_7CECC506_F55F_4594_B611_972D650865D2_INCLUDED_)

typedef struct _TCPServerParameter
{
	ULONG data1;
	ULONG data2;
	double data3;
} TCPServerParameter, *PTCPServerParameter;

///</AutoGeneratedContent>



///<AutoGeneratedContent id="DataAreaIDs">
///</AutoGeneratedContent>

///<AutoGeneratedContent id="InterfaceIDs">
#if !defined(_TC_IID_03010099_0000_0000_E000_000000000064_INCLUDED_)
#define _TC_IID_03010099_0000_0000_E000_000000000064_INCLUDED_
TCOM_DECL_INTERFACE("03010099-0000-0000-e000-000000000064", ITcIoTcpProtocolRecv)
#endif // !defined(_TC_IID_03010099_0000_0000_E000_000000000064_INCLUDED_)

#if !defined(_TC_IID_03010098_0000_0000_E000_000000000064_INCLUDED_)
#define _TC_IID_03010098_0000_0000_E000_000000000064_INCLUDED_
TCOM_DECL_INTERFACE("03010098-0000-0000-e000-000000000064", ITcIoTcpProtocol)
#endif // !defined(_TC_IID_03010098_0000_0000_E000_000000000064_INCLUDED_)

///</AutoGeneratedContent>

///<AutoGeneratedContent id="EventClasses">
///</AutoGeneratedContent>
