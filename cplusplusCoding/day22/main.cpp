#include <iostream>
#include "Candidate.h"
#include "Judges.h"
#include "Grade.h"
#include <deque>
#include <string>
#include <vector>
/*һ��򵥵ĸ�ϰ�������麯������̬����װ���̳�*/
/*Ȼ�����deque��vector��һЩ��Ӧ�õĸ�ϰ*/
void evaluate(Person* c, Person* j, double grade, Grade &g) {
	g.name_judges = j->p_name;
	g.name_candidates = c->p_name;
	g.grade = grade;
	cout << "�ɹ�����ί" << g.name_judges << "��������" << 
		g.name_candidates << "���" << g.grade << "��¼��" << endl;
}

int main() {
	Person* c1, * c2, * c3, * c4, * c5;
	c1 = new Candidate("��һ", 21, "��");
	c2 = new Candidate("Ǯ��", 22, "Ů");
	c3 = new Candidate("����", 23, "��");
	c4 = new Candidate("����", 24, "Ů");
	c5 = new Candidate("����", 25, "��");
	vector<Person*>c_v;
	c_v.push_back(c1);
	c_v.push_back(c2);
	c_v.push_back(c3);
	c_v.push_back(c4);
	c_v.push_back(c5);
	Person* j1, * j2, * j3, * j4, * j5;
	j1 = new Judges("��ԯ", 31, "��");
	j2 = new Judges("��ũ", 32, "��");
	j3 = new Judges("���", 33, "��");
	j4 = new Judges("Ů�", 34, "Ů");
	j5 = new Judges("����", 35, "��");
	vector<Person*>j_v;
	j_v.push_back(j1);
	j_v.push_back(j2);
	j_v.push_back(j3);
	j_v.push_back(j4);
	j_v.push_back(j5);
	int g_1 = 1, g_2 = 1;
	for (auto c : c_v) {
		for (auto j : j_v) {
			Grade g;
			evaluate(c, j, g_2*g_1,g);
			c->grade.push_back(g);
			j->grade.push_back(g);
		    ++g_2;
		}
		++g_1;
	}
	for (auto c : c_v) {
		c->showInfo();
		cout << "���յ÷֣�" << (double)c->return_final_grade() << endl<< endl;
	}
	for (auto j : j_v) {
		j->showInfo();
	}
	return 0;
}