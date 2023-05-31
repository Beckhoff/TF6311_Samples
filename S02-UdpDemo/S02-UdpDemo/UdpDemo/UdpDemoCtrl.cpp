// UdpDemoCtrl.cpp : Implementation of CTcUdpDemoCtrl
#include "TcPch.h"
#pragma hdrstop

#include "UdpDemoW32.h"
#include "UdpDemoCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CUdpDemoCtrl

CUdpDemoCtrl::CUdpDemoCtrl() 
	: ITcOCFCtrlImpl<CUdpDemoCtrl, CUdpDemoClassFactory>() 
{
}

CUdpDemoCtrl::~CUdpDemoCtrl()
{
}

