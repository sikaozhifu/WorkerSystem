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

	//判断系统中是否有记录
	bool systemIsEmpty();//true为无记录，false为有记录

	//统计文件中的人数
	int getNumInFile();

	//初始化员工
	void initEmp();

	//显示职工信息
	void showInfo();

	//删除职工信息
	void deleteEmp();

	//根据id查找职工信息
	int getEmpById(int id);

	//根据姓名查找职工信息
	void getEmpByName(string name);

	//查找职工信息
	void getEmp();

	//按照职工编号排序
	void sortEmp();

	//清空文件
	void clearEmp();
};