#include "Boss.h"

Boss::Boss(int id, string name, int deptId) {
	this->id = id;
	this->name = name;
	this->deptId = deptId;
}
//��ȡ��λ��Ϣ
string Boss::getDepet() {
	return string("��˾�ܲ�");
}
//��ʾ������Ϣ
void Boss::showInfo() {
	cout << "ְ����ţ�" << this->id
		<< "\tְ��������" << this->name
		<< "\tְ����λ��" << this->getDepet()
		<< "\tְ��ְ�𣺹���˾��������"<<endl;
}