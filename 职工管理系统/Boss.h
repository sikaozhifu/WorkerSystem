#pragma once
#include<iostream>
#include<string>
using namespace std;
#include "Worker.h"

//老板类
class Boss :public Worker {
public:
	Boss(int id,string name,int deptId);
	//获取岗位信息
	string getDepet();
	//显示个人信息
	void showInfo();

};