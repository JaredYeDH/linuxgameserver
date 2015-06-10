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

#pragma once
#include "../NetWork/LServerBaseNetWork.h"
class LLobbyServerMainLogic;

class LLBConnectToServersNetWork : public LServerBaseNetWork 
{
public:
	LLBConnectToServersNetWork();
	~LLBConnectToServersNetWork();
public:
	bool Initialize(char* pConfigFile, unsigned int unMaxProcessPacketOnce, char* pConfigHeader);
public:
	virtual bool OnAddSession(uint64_t u64SessionID, t_Session_Accepted& tsa);
	virtual void OnRemoveSession(uint64_t u64SessionID);
	virtual void OnRecvedPacket(t_Recv_Packet& tRecvedPacket); 
public:
	bool StopConnectToServersNetWork();
	void ReleaseConnectToServersNetWork();
public:
	void SetLobbyServerMainLogic(LLobbyServerMainLogic* plsm);
	LLobbyServerMainLogic* GetLobbyServerMainLogic();
private:
	LLobbyServerMainLogic* m_pLobbyServerMainLogic;
};


