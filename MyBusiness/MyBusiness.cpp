#include <iostream>
#include <Windows.h>
#include "Assistant.h"
#include "threadpool/MyThread.h"
#include "threadpool/MyThreadPool.h"
#include "threadpool/TestTask.h"

void ThreadTest() {
	CMyThreadPool* pool = new CMyThreadPool();
	pool->CreatAPPDataThread(1);

	CTestTask* task1 = new CTestTask(1);
	CTestTask* task2 = new CTestTask(2);
	CTestTask* task3 = new CTestTask(3);
	pool->addTask(task1, NORMAL);
	pool->addTask(task2, NORMAL);
	pool->addTask(task3, NORMAL);
}


int main()
{

	ThreadTest();

}


