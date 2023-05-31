// TCPServerCtrl.cpp : Implementation of CTcTCPServerCtrl
#include "TcPch.h"
#pragma hdrstop

#include "TCPServerW32.h"
#include "TCPServerCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CTCPServerCtrl

CTCPServerCtrl::CTCPServerCtrl() 
	: ITcOCFCtrlImpl<CTCPServerCtrl, CTCPServerClassFactory>() 
{
}

CTCPServerCtrl::~CTCPServerCtrl()
{
}

