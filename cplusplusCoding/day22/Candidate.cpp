#include "Candidate.h"
#include <deque>
#include <algorithm>

Candidate::Candidate() {
	//Ĭ�Ϲ��죬����ʼ��
	cout << "Ĭ�Ϲ���һ��judge" << endl;
}
Candidate::Candidate(string n, int a, string gen) {
	cout << "�вι���һ��judge" << endl;
	this->p_name = n;
	this->p_age = a;
	this->p_gender = gen;
	this->grade.resize(0);//������ʼ��
}
void Candidate::showInfo() {
	cout << "������ " << this->p_name << endl;
	cout << "��ɫ�� " << "������" << endl;
	cout << "���䣺 " << this->p_age << endl;
	cout << "�Ա� " << this->p_gender << endl;
	cout << "��ӡ�ò����ߵĵ÷�" << endl;
	for (auto i : this->grade) {
		cout << i.name_candidates << " " << i.grade << " " << i.name_judges << endl;
	}
}
void Candidate::add_grade(Grade& g) {
	this->grade.push_back(g);
	cout << "�ɹ����һ������" << endl;
}
Candidate::~Candidate() {
	cout << "�޶������ݣ�Ĭ������" << endl;
}

double Candidate::return_final_grade() {
	deque<double> d_grade;
	for (auto c : this->grade) {
		d_grade.push_back(c.grade);
	}
	sort(d_grade.begin(),d_grade.end());
	d_grade.pop_front();
	d_grade.pop_back();
	double final_grade = 0.0;
	for (deque<double>::const_iterator it = d_grade.begin(); it != d_grade.end(); it++) {
		final_grade += *it;
	}
	final_grade = final_grade / d_grade.size();
	return final_grade;
}