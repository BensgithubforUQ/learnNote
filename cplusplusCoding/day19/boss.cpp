#include "boss.h"

void Boss::showPersonalInfo() {
	cout << "�ϰ幤��:" << this->w_person_id << endl;
	cout << "�ϰ�����:" << this->w_name << endl;
	cout << "��λ���:" << this->getBossInfo() << endl;
	cout << "��λ����:" << "��˾�ϰ�" << endl;
	cout << endl;
}

string Boss::getBossInfo() {
	return "��˾�ϰ壬����˾��������";
}

Boss::Boss(string n, int id, int d_id) {
	if (d_id != 0) {
		cerr << "��˾�ϰ�Ĳ��ű�ű���Ϊ0" << endl;
	}
	else {
		this->w_name = n;
		this->w_person_id = id;
		this->w_department_id = d_id;

	}
}

Boss::Boss() {

}

Boss::~Boss() {

}
