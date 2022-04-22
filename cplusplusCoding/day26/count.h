#pragma once
#include "vector_base.h"
#include <string>
#include "find.h"
using namespace std;

//ͳ��������������
void count_test0() {
	vector<int>v1;
	constructVectorWithSize(v1, 50);
	printVector(v1);
	cout<< "the amount of element with value 5 is :"<< count(v1.begin(), v1.end(), 5)<<endl;
}

//ͳ���Զ������������
void count_test1() {//��find.h�е�person��,��Ҫ��person��������һ��==��������
	vector<Person>v1;
	v1.push_back(Person("��һ", 25));
	v1.push_back(Person("�Ŷ�", 15));
	v1.push_back(Person("����", 35));
	v1.push_back(Person("����", 45));
	v1.push_back(Person("����", 55));
	v1.push_back(Person("����", 65));
	///����һ��person�������v1
	cout << "the amount of element with value ('��һ', 25) is :" << count(v1.begin(), v1.end(), Person("��һ",25)) << endl;
}

class greaterFiveCount_if {
public:
	bool operator()(int n) {
		return n > 5;
	}
};

void count_if_test0() {
	//count_if(iterator beg,iterator end,_predicate)����������Ҫ��ν��
	vector<int>v1;
	constructVectorWithSize(v1, 50);
	printVector(v1);
	cout << "the amount of element with value 5 is :" << count_if(v1.begin(), v1.end(),greaterFiveCount_if()) << endl;
}

class greaterAgeCount_if {
public:
	bool operator()(const Person &p) {
		return p.p_age > 20;
	}
};

void count_if_test1() {
	vector<Person>v1;
	v1.push_back(Person("��һ", 25));
	v1.push_back(Person("�Ŷ�", 15));
	v1.push_back(Person("����", 35));
	v1.push_back(Person("����", 45));
	v1.push_back(Person("����", 55));
	v1.push_back(Person("����", 65));
	///����һ��person�������v1
	cout << "the amount of element with age > 20 :" << count_if(v1.begin(), v1.end(), greaterAgeCount_if()) << endl;
}