#include <winsock2.h>
#include "TestTask.h"
#include "stdio.h"
#include<ctime> 
#include <string>
#include "../CDebug.h"
CTestTask::CTestTask(int id) : CTask(id)
{
}

void CTestTask::taskRecClientProc()
{
}

void CTestTask::taskSaveSQL()
{
}

void CTestTask::taskAPPRecProc()
{
}

void CTestTask::printMessage()
{
	std::string s = "==================>>>>  JJBURNFLY !!! \n";

	OutputDebugPrintf(s.c_str());
	printf(s.c_str());
}
