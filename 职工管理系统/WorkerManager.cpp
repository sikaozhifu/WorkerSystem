#include"WorkerManager.h"


WorkerManager::WorkerManager() {

}
WorkerManager::~WorkerManager() {

}
void WorkerManager::showMenu() {
	cout << "**************************************" << endl;
	cout << "*********��ӭʹ��ְ������ϵͳ*********"<< endl;
	cout << "*********   0.�˳�����ϵͳ   *********" << endl;
	cout << "*********   1.����ְ����Ϣ   *********" << endl;
	cout << "*********   2.��ʾְ����Ϣ   *********" << endl;
	cout << "*********   3.ɾ����ְְ��   *********" << endl;
	cout << "*********   4.�޸�ְ����Ϣ   *********" << endl;
	cout << "*********   5.����ְ����Ϣ   *********" << endl;
	cout << "*********   6.���ձ������   *********" << endl;
	cout << "*********   7.��������ĵ�   *********" << endl;
	cout << "**************************************" << endl;

}
void WorkerManager::exitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}