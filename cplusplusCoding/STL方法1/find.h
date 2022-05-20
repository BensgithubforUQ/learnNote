#pragma once
#include "vector_base.h"
#include <string>
using namespace std;

//�������õ���������
class Person {
public:
	string p_name;
	int p_age;
	Person() {
		this->p_name = " ";
		this->p_age = 0;
	}
	Person(string n, int a) {
		this->p_name = n;
		this->p_age = a;
	}
	bool operator==(const Person &p) { //����һ��==
		if (p.p_name == this->p_name && p.p_age == this->p_age) {
			return true;
		}
		else {
			return false;
		}
	}

};

//find������������
void find_test() {
	vector<int>v1;
	constructVectorWithSize(v1, 5);
	vector<int>::iterator it = find(v1.begin(),v1.end(),5);
	if (it == v1.end()) {
		cout << "û���ҵ�5" << endl;
	}
	else {
		cout << *it << " position is " <<it-v1.begin() << endl;
	} 
}

//find�Զ�����������
void find_test1() {
	vector<Person>v1;
	v1.push_back(Person("��һ", 25));
	v1.push_back(Person("�Ŷ�", 15));
	v1.push_back(Person("����", 35));
	v1.push_back(Person("����", 45));
	v1.push_back(Person("����", 55));
	v1.push_back(Person("����", 65));

	vector<Person>::iterator it = find(v1.begin(), v1.end(), Person("��һ",25));
	if (it == v1.end()) {
		cout << "û���ҵ�5 " << endl;
	}
	else {
		cout << it->p_name <<it->p_age<<it - v1.begin() << endl;
	}
}

class greaterFive {
public:
	bool operator()(int n) {
		return n > 5;
	}
	bool operator()(Person p) {
		return p.p_age > 25;
	}
};
//find_if ����������������
void find_if_test() {
	vector<int>v1;
	constructVectorWithSize(v1, 5);
	vector<int>::iterator it = find_if(v1.begin(), v1.end(), greaterFive());
	if (it == v1.end()) {
		cout << "û���ҵ�����5������" << endl;
	}
	else {
		cout << *it << " position is " << it - v1.begin() << endl;
	}
}

//find_if �����Զ�����������
void find_if_test1() {
	vector<Person>v1;
	v1.push_back(Person("��һ", 25));
	v1.push_back(Person("�Ŷ�", 15));
	v1.push_back(Person("����", 35));
	v1.push_back(Person("����", 45));
	v1.push_back(Person("����", 55));
	v1.push_back(Person("����", 65));

	vector<Person>::iterator it = find_if(v1.begin(), v1.end(), greaterFive());
	if (it == v1.end()) {
		cout << "û���ҵ�����5������" << endl;
	}
	else {
		cout << it->p_name << it->p_age << it - v1.begin() << endl;
	}
}

void printVector(const vector<Person> v) {
	if (!v.empty()) {
		for (auto it = v.begin(); it != v.end(); it++) {
			cout << it->p_name << " " << it->p_age << " ";
		}
		cout << endl;
	}
	else {
		cerr << "blank vector" << endl;
	}
}

