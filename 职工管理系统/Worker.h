#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker {
public:
	
	//获取岗位信息
	virtual string getDepet() = 0;
	//显示个人信息
	virtual void showInfo() = 0;

	int id;//职工编号
	string name;//职工姓名
	int deptId;//职工部门编号
};