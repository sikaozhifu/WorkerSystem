#pragma once
#include<iostream>
#include<string>
using namespace std;
#include "Worker.h"
#include<fstream>
#define FILENAME "empFile.txt"

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
	//保存到empFile.txt文件中
	void save();
	//数组中职工数量
	int empNum;
	//职工数组
	Worker ** empArray;

	//判断文件是否为空
	bool fileIsEmpty;

	//统计文件中的人数
	int getNumInFile();

	//初始化员工
	void initEmp();
};