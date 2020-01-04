#pragma once
#include<iostream>
#include<string>
using namespace std;
#include "Worker.h"

class WorkerManager {
public:
	WorkerManager();
	
	~WorkerManager();
	//显示菜单
	void showMenu();
	//退出系统
	void exitSystem();
	//添加职工
	void addEmp();
	int empNum;
	Worker ** empArray;
};