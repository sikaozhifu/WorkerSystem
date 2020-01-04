#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"Worker.h"
//普通职工类
class Employee :public Worker {
public:
	Employee(int id,string name,int deptId);
	//获取岗位信息
	string getDepet();
	//显示个人信息
	void showInfo();
};