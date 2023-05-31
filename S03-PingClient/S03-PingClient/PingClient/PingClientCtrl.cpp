// PingClientCtrl.cpp : Implementation of CTcPingClientCtrl
#include "TcPch.h"
#pragma hdrstop

#include "PingClientW32.h"
#include "PingClientCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CPingClientCtrl

CPingClientCtrl::CPingClientCtrl() 
	: ITcOCFCtrlImpl<CPingClientCtrl, CPingClientClassFactory>() 
{
}

CPingClientCtrl::~CPingClientCtrl()
{
}

