#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker {
public:
	
	//��ȡ��λ��Ϣ
	virtual string getDepet() = 0;
	//��ʾ������Ϣ
	virtual void showInfo() = 0;

	int id;//ְ�����
	string name;//ְ������
	int deptId;//ְ�����ű��
};