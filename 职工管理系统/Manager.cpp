#include"Manager.h"

Manager::Manager(int id, string name, int deptId) {

	this->id = id;
	this->name = name;
	this->deptId = deptId;
}
//��ȡ��λ��Ϣ
string Manager::getDepet() {
	return string("���ž���");
}
//��ʾ������Ϣ
void Manager::showInfo() {
	cout << "ְ����ţ�" << this->id
		<< "\tְ��������" << this->name
		<< "\tְ����λ��" << this->getDepet()
		<< "\tְ��ְ������ϰ彻��������"<<endl;
}