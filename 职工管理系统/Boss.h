#pragma once
#include<iostream>
#include<string>
using namespace std;
#include "Worker.h"

//�ϰ���
class Boss :public Worker {
public:
	Boss(int id,string name,int deptId);
	//��ȡ��λ��Ϣ
	string getDepet();
	//��ʾ������Ϣ
	void showInfo();

};