
#pragma once
#include "task.h"


class CTestTask : public CTask
{
public:
	CTestTask(int id);
	virtual  void  taskRecClientProc();
	virtual  void  taskSaveSQL();
	virtual  void  taskAPPRecProc();
	virtual  void  printMessage();
private:
	int m_id;
};

