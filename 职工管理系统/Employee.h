#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"Worker.h"
//��ְͨ����
class Employee :public Worker {
public:
	Employee(int id,string name,int deptId);
	//��ȡ��λ��Ϣ
	string getDepet();
	//��ʾ������Ϣ
	void showInfo();
};