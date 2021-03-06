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

#include "LGSPacketProcessManager.h"
#include "LGameServerMainLogic.h"

LGSPacketProcessManager::LGSPacketProcessManager()
{
	m_pGSMainLogic = NULL;
}
LGSPacketProcessManager::~LGSPacketProcessManager()
{
}

bool LGSPacketProcessManager::Initialize()
{
	if (m_pGSMainLogic == NULL)
	{
		return false;
	}


	REGISTER_GAMESERVER_PACKET_PROCESS_PROC(Packet_SS_Start_Req); 
	REGISTER_GAMESERVER_PACKET_PROCESS_PROC(Packet_SS_Start_Res);
	REGISTER_GAMESERVER_PACKET_PROCESS_PROC(Packet_SS_Register_Server_Req1);
	REGISTER_GAMESERVER_PACKET_PROCESS_PROC(Packet_SS_Register_Server_Res);
	REGISTER_GAMESERVER_PACKET_PROCESS_PROC(Packet_SS_Server_Register_Broadcast1);
	REGISTER_GAMESERVER_PACKET_PROCESS_PROC(Packet_SS_Server_Will_Connect_Req);
	REGISTER_GAMESERVER_PACKET_PROCESS_PROC(Packet_SS_Server_Will_Connect_Res);
	REGISTER_GAMESERVER_PACKET_PROCESS_PROC(Packet_SS_Server_Can_ConnectTo_Server_Infos);
 	return true;
}
//	注册函数
bool LGSPacketProcessManager::Register(unsigned int unPacketID, GAMESERVER_PACKET_PROCESS_PROC pProc)
{
	if (pProc == NULL)
	{
		return false;
	}
	map<unsigned int, GAMESERVER_PACKET_PROCESS_PROC>::iterator _ito = m_mapPacketProcessProcManager.find(unPacketID);
	if (_ito != m_mapPacketProcessProcManager.end())
	{
		return false;
	}
	m_mapPacketProcessProcManager[unPacketID] = pProc;
	return true;
}
//	派遣处理函数
void LGSPacketProcessManager::DispatchMessageProcess(uint64_t u64SessionID, LPacketSingle* pPacket, E_GameServer_Packet_From_Type eFromType)
{
	if (pPacket == NULL)
	{
		return ;
	}
	unsigned int unPacketID = pPacket->GetPacketID();

	map<unsigned int, GAMESERVER_PACKET_PROCESS_PROC>::iterator _ito = m_mapPacketProcessProcManager.find(unPacketID);
	if (_ito == m_mapPacketProcessProcManager.end())
	{
		return ;
	}
	_ito->second(this, u64SessionID, pPacket, eFromType);
}


void LGSPacketProcessManager::SetGameServerMainLogic(LGameServerMainLogic* pgsml)
{
	m_pGSMainLogic = pgsml;
}
LGameServerMainLogic* LGSPacketProcessManager::GetGameServerMainLogic()
{
	return m_pGSMainLogic;
}
