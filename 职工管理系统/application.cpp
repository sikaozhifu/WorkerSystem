#include<iostream>
using namespace std;
#include "WorkerManager.h"
#include "Worker.h"
#include "Manager.h"
int main() {

	WorkerManager wk;
	int select = 0;
	while (true)
	{
		wk.showMenu();
		cout << "����������ѡ��" << endl;
		cin >> select;
		switch (select)
		{
		case 0:
			wk.exitSystem();
			break;
		case 1://����ְ����Ϣ
			wk.addEmp();
			break;
		case 2://��ʾְ����Ϣ
			wk.showInfo();
			break;
		case 3://ɾ����ְְ��
			wk.deleteEmp();
			break;
		case 4://�޸�ְ����Ϣ
			break;
		case 5://����ְ����Ϣ
			wk.getEmp();
			break;
		case 6://���ձ������
			wk.sortEmp();
			break;
		case 7://��������ĵ�
			wk.clearEmp();
			break;
		default:
			system("pause");
			break;
		}
	}
	
	return 0;
}