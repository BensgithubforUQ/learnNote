#include <iostream>
#include <string>
#include "myHead.h"
#include <vector>
using namespace std;

//int main() {
//	struct student stu1;
//	stu1.name = "����";
//	stu1.age = 26;
//	stu1.grade = 95.0;
//	struct student stu2 {
//		"����", 19, 96.0
//	};
//	struct student stu3;
//	stu3.name = "����" ;
//	stu3.age = 24;
//	stu3.grade = 97.5;
//	struct student stu4[5]{
//		"½��", 31, 31.0,
//		"½���",5,99.0,
//		"½����",9,100.0,
//		"Ф����",29,94.0,
//		"��Ƥè",200,120.0
//	};
//	printStructStudent(stu1);
//	printStructStudent(stu2); 
//	printStructStudent(stu3);
//
//	cout << endl;
//	//�ṹ������
//	struct student studentArray[] = { stu1,stu2,stu3,{"����",30,99.0}};
//	studentArray[2].age = 31;
//	studentArray[2].grade = 100.0;
//	auto len = sizeof(studentArray) / sizeof(studentArray[0]);
//	cout << "size :" <<len<< endl;
//	for (auto i : studentArray) {
//		printStructStudent(i);
//	}
//
//	//�ṹ��ָ��
//	struct student* p = &stu1; //��һ��ָ��p��ָ��stu1;
//	cout << endl;
//	cout << "ָ��->��ӡ" << endl;
//	//cout << p->name << " ���� " << p->age << " �ɼ� " << p->grade << endl;
//	printStructStudent2(&stu1);
//
//	//����ָ����ʽṹ������p->name
//	cout << endl;
//	cout << "����ָ����ʽṹ������" << endl;
//	struct student* p1 = studentArray;
//	for (int i = 0; i < len; i++) {
//		printStructStudent2(p1 + i);
//	}
//
//	//�ṹ��Ƕ�׽ṹ��
//	cout << endl;
//	cout << "�ṹ��Ƕ�׽ṹ��" << endl;
//	struct teacher t[2];
//	t[0].name = "����";
//	t[0].age = 100;
//	for (int i = 0; i < 3; i++) {
//		t[0].stu.push_back(studentArray[i]);
//	}
//	t[1].name = "����";
//	t[1].age = 99;
//	t[1].stu.push_back(studentArray[3]);
//	//cout << "�����Ϊ������ʦ����ѧ����Ϣ" << endl;
//	//inputStructStudent(t+1);
//	struct teacher* pt = t;
//	int len1 = sizeof(t) / sizeof(t[0]);
//	//printStructTeacher(pt, len1);
//
//	inputStructStudent2(&t[1], stu4, 5);
//	printStructTeacher(pt, len1);
//
//
//	return 0;
//}