#include "Judges.h"

Judges::Judges() {
	//Ĭ�Ϲ��죬����ʼ��
	cout << "Ĭ�Ϲ���һ��judge" << endl;
}
Judges::Judges(string n, int a, string gen) {
	cout << "�вι���һ��judge" << endl;
	this->p_name = n;
	this->p_age = a;
	this->p_gender = gen;
	this->grade.resize(0);//������ʼ��
}
void Judges::showInfo() {
	cout << "������ " << this->p_name << endl;
	cout << "��ɫ�� " << "��ί" << endl;
	cout << "���䣺 " << this->p_age << endl;
	cout << "�Ա� " << this->p_gender << endl;
	cout << "��ӡ����ί������" << endl;
	for (auto i : this->grade) {
		cout << i.name_candidates << " " << i.grade << " " << i.name_judges << endl;
	}
	cout << endl;
}
void Judges::add_grade(Grade& g) {
	this->grade.push_back(g);
	cout << "�ɹ����һ������" << endl;
}
Judges::~Judges() {
	cout << "�޶������ݣ�Ĭ������" << endl;
}

double Judges::return_final_grade() {
	return 0;
}