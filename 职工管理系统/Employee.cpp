#include"Employee.h"

Employee::Employee(int id, string name, int deptId) {
	this->id = id;
	this->name = name;
	this->deptId = deptId;
}
//��ȡ��λ��Ϣ
string Employee::getDepet() {
	return string("��ͨԱ��");
}
//��ʾ������Ϣ
void Employee::showInfo() {
	cout << "ְ����ţ�" << this->id
		<< "\tְ��������" << this->name
		<< "\tְ����λ��" << this->getDepet()
		<< "\tְ��ְ����ɾ�����������"<<endl;
}