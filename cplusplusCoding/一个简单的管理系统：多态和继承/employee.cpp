#include "employee.h"

void Employee::showPersonalInfo() {
	cout << "Ա������:" << this->w_person_id << endl;
	cout << "Ա������:" << this->w_name << endl;
	cout << "���ű��:" << this->w_department_id << endl;
	cout << "��λ���:" << this->getJobInfo() << endl;
	cout << "��λ����:" << this->getDepartmentInfo() << endl;
	cout << endl;
}

string Employee::getDepartmentInfo() {
	return "��ͨԱ��";
}

string Employee::getJobInfo() {
	return "��ɾ�����������";
}

Employee::Employee(string n, int id, int d_id) {
	this->w_name = n;
	this->w_person_id = id;
	this->w_department_id = d_id;

}
Employee::Employee() {

}

Employee::~Employee() {

}
