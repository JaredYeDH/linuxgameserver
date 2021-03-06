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

class LDBServerMainLogicThread;
class LWorkItem;

class LDBServerMessageProcess
{
public:
	LDBServerMessageProcess();
	~LDBServerMessageProcess(); 
public:
	//	分发消息包进行处理
	void DispatchMessageToProcess(LWorkItem* pWorkItem);
public:
	void SetDBServerMainLogicThread(LDBServerMainLogicThread* pdbsmlt);
	LDBServerMainLogicThread* GetDBServerMainLogicThread();
private:
	LDBServerMainLogicThread* m_pDBServerMainLogicThread;	

public:		//	数据库线程返回的数据包在这里处理，这里是处理函数，这些函数在主线程中执行

};


