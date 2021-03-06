/*
The MIT License (MIT)

Copyright (c) <2010-2020> <wenshengming>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include "LConnectToMaster.h"


LConnectToMaster::LConnectToMaster()
{
	m_unMaxPacketProcessOnce = 100;
}
LConnectToMaster::~LConnectToMaster()
{
}

bool LConnectToMaster::Initialize(char* pConnectToMasterServerConfigFile)
{
	if (pConnectToMasterServerConfigFile == NULL)
	{
		return false;
	}
	LConnectorConfigProcessor ccp;
	if (!ccp.Initialize(pConnectToMasterServerConfigFile, "LoginServer_1_To_MasterServer"))
	{
		return false;
	}
	if (!m_ConnectorToMasterServer.Initialize(ccp.GetConnectorInitializeParams()))
	{
		return false;
	}
	return true;
}
//	获取接收的数据
LPacketSingle* LConnectToMaster::GetOneRecvedPacket()
{
	return m_ConnectorToMasterServer.GetOneRecvedPacket();
}
//	释放一个接收的数据包
void LConnectToMaster::FreePacket(LPacketSingle* pPacket)
{
	if (pPacket == NULL)
	{
		return ;
	}
	return m_ConnectorToMasterServer.FreePacket(pPacket);
}

//	发送数据
//	取一个发送数据包
LPacketSingle* LConnectToMaster::GetOneSendPacketPool(unsigned short usPacketSize)
{
	return m_ConnectorToMasterServer.GetOneSendPacketPool(usPacketSize);
}

//	添加一个发送数据包
bool LConnectToMaster::AddOneSendPacket(LPacketSingle* pPacket)
{
	if (pPacket == NULL)
	{
		return false;
	}

	return m_ConnectorToMasterServer.AddOneSendPacket(pPacket);
}


bool LConnectToMaster::IsConnectted()
{
	return m_ConnectorToMasterServer.IsConnectted();
}

bool LConnectToMaster::StopConnectToMaster()
{
	return m_ConnectorToMasterServer.StopThreadAndStopConnector();
}
void LConnectToMaster::ReleaseConnectToMasterResource()
{
	m_ConnectorToMasterServer.ReleaseConnectorResource();
}



