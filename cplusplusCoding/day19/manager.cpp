#include "manager.h"

void Manager::showPersonalInfo() {
	cout << "������:" << this->w_person_id << endl;
	cout << "��������:" << this->w_name << endl;
	cout << "���ű��:" << this->w_department_id << endl;
	cout << "��λ���:" << this->getJobInfo() << endl;
	cout << "��λ����:" << this->getDepartmentInfo() << endl;
	cout << endl;
}

string Manager::getDepartmentInfo() {
	return "����";
}

string Manager::getJobInfo() {
	return "�����˾���������񣬹�������";
}

Manager::Manager(string n, int id, int d_id) {
	this->w_name = n;
	this->w_person_id = id;
	this->w_department_id = d_id;

}
Manager::Manager() {

}

Manager::~Manager() {

}
