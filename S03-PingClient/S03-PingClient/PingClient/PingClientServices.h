///////////////////////////////////////////////////////////////////////////////
// PingClientServices.h

#pragma once

#include "TcServices.h"

const ULONG DrvID_PingClient = 0x3F000000;
#define SRVNAME_PINGCLIENT "PingClient"

///<AutoGeneratedContent id="ClassIDs">
const CTCID CID_PingClientCPingModule = {0x05fc6380,0xfdc8,0x4b82,{0x85,0xe0,0xb7,0xae,0xf5,0xaa,0xe5,0x5f}};
///</AutoGeneratedContent>

///<AutoGeneratedContent id="ParameterIDs">
const PTCID PID_PingModuleParameter = 0x00000001;
const PTCID PID_PingModuleIpAddress = 0x00000003;
const PTCID PID_PingModuleArpProt = 0x00000002;
///</AutoGeneratedContent>

///<AutoGeneratedContent id="DataTypes">
#if !defined(_TC_TYPE_CC07E0A0_FC03_45CD_BFD9_D46B7C731E7C_INCLUDED_)
#define _TC_TYPE_CC07E0A0_FC03_45CD_BFD9_D46B7C731E7C_INCLUDED_
typedef struct _ETHERNET_ADDRESS
{
	BYTE b[6];
} ETHERNET_ADDRESS, *PETHERNET_ADDRESS;
#endif // !defined(_TC_TYPE_CC07E0A0_FC03_45CD_BFD9_D46B7C731E7C_INCLUDED_)

#if !defined(_TC_TYPE_478C4436_6F33_4F6F_B4A8_88074B54DCD4_INCLUDED_)
#define _TC_TYPE_478C4436_6F33_4F6F_B4A8_88074B54DCD4_INCLUDED_
typedef ULONG ETYPE_VLAN_HEADER;
#endif // !defined(_TC_TYPE_478C4436_6F33_4F6F_B4A8_88074B54DCD4_INCLUDED_)

#if !defined(_TC_TYPE_18071995_0000_0000_0000_00000000003E_INCLUDED_)
#define _TC_TYPE_18071995_0000_0000_0000_00000000003E_INCLUDED_
typedef BYTE IPADDR[4];
#endif // !defined(_TC_TYPE_18071995_0000_0000_0000_00000000003E_INCLUDED_)

typedef struct _PingModuleParameter
{
	ULONG data1;
	ULONG data2;
	double data3;
} PingModuleParameter, *PPingModuleParameter;

typedef struct _PingModuleInputs
{
	ULONG Value;
	ULONG Status;
	ULONG Data;
} PingModuleInputs, *PPingModuleInputs;

typedef struct _PingModuleOutputs
{
	ULONG Value;
	ULONG Control;
	ULONG Data;
} PingModuleOutputs, *PPingModuleOutputs;

///</AutoGeneratedContent>



///<AutoGeneratedContent id="DataAreaIDs">
#define ADI_PingModuleInputs 0
#define ADI_PingModuleOutputs 1
///</AutoGeneratedContent>

///<AutoGeneratedContent id="InterfaceIDs">
#if !defined(_TC_IID_03010096_0000_0000_E000_000000000064_INCLUDED_)
#define _TC_IID_03010096_0000_0000_E000_000000000064_INCLUDED_
TCOM_DECL_INTERFACE("03010096-0000-0000-e000-000000000064", ITcIoArpPingRecv)
#endif // !defined(_TC_IID_03010096_0000_0000_E000_000000000064_INCLUDED_)

#if !defined(_TC_IID_0301009E_0000_0000_E000_000000000064_INCLUDED_)
#define _TC_IID_0301009E_0000_0000_E000_000000000064_INCLUDED_
TCOM_DECL_INTERFACE("0301009e-0000-0000-e000-000000000064", ITcIoArpPing)
#endif // !defined(_TC_IID_0301009E_0000_0000_E000_000000000064_INCLUDED_)

///</AutoGeneratedContent>

///<AutoGeneratedContent id="EventClasses">
///</AutoGeneratedContent>
