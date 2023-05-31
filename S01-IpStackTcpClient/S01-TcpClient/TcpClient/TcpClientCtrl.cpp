// TcpClientCtrl.cpp : Implementation of CTcTcpClientCtrl
#include "TcPch.h"
#pragma hdrstop

#include "TcpClientW32.h"
#include "TcpClientCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CTcpClientCtrl

CTcpClientCtrl::CTcpClientCtrl() 
	: ITcOCFCtrlImpl<CTcpClientCtrl, CTcpClientClassFactory>() 
{
}

CTcpClientCtrl::~CTcpClientCtrl()
{
}

