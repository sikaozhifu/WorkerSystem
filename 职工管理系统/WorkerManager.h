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
	//��ʾ�˵�
	void showMenu();
	//�˳�ϵͳ
	void exitSystem();
	//���ְ��
	void addEmp();
	//���浽empFile.txt�ļ���
	void save();
	//������ְ������
	int empNum;
	//ְ������
	Worker ** empArray;

	//�ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;

	//�ж�ϵͳ���Ƿ��м�¼
	void systemIsEmpty();

	//ͳ���ļ��е�����
	int getNumInFile();

	//��ʼ��Ա��
	void initEmp();

	//��ʾְ����Ϣ
	void showInfo();

	//ɾ��ְ����Ϣ
	void deleteEmp();

	//����id����ְ����Ϣ
	int getEmpById(int id);

	//������������ְ����Ϣ
	void getEmpByName(string name);

	//����ְ����Ϣ
	void getEmp();

	//����ְ���������
	void sortEmp();
};