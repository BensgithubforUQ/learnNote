#pragma once
#include "vector_base.h"
#include <string>
#include "find.h"
using namespace std;

//sort����
//sort(begin ,end,predicate)

class sortByPersonAgeDescending {
public:
	bool operator()(Person &p1, Person& p2) {
		return p1.p_age > p2.p_age;
	}
};

void sort_test0() {//ֱ�����Զ����������͵�
	vector<Person>v1;
	v1.push_back(Person("��һ", 25));
	v1.push_back(Person("�Ŷ�", 15));
	v1.push_back(Person("����", 35));
	v1.push_back(Person("����", 45));
	v1.push_back(Person("����", 55));
	v1.push_back(Person("����", 65));
	printVector(v1);
	sort(v1.begin(), v1.end(), sortByPersonAgeDescending());
	printVector(v1);
}

void randomshuffle_test0() {
	//ϴ���㷨 random_shuffle(begin ,end);
	vector<Person>v1;
	v1.push_back(Person("��һ", 25));
	v1.push_back(Person("�Ŷ�", 15));
	v1.push_back(Person("����", 35));
	v1.push_back(Person("����", 45));
	v1.push_back(Person("����", 55));
	v1.push_back(Person("����", 65));
	printVector(v1);
	sort(v1.begin(), v1.end(), sortByPersonAgeDescending());
	printVector(v1);
	random_shuffle(v1.begin(), v1.end()); //��������
	printVector(v1);
}

void merge_test0() {
	//�����������ĺϲ������Ҵ浽һ��������
	/*����������������������ġ��ϲ�֮����Ȼ�Ǹ����������*/
	vector<Person>v1;
	v1.push_back(Person("��һ", 25));
	v1.push_back(Person("�Ŷ�", 15));
	v1.push_back(Person("����", 35));
	v1.push_back(Person("����", 45));
	v1.push_back(Person("����", 55));
	v1.push_back(Person("����", 65));
	vector<Person>v2;
	v2.push_back(Person("��һ", 25));
	v2.push_back(Person("���", 15));
	v2.push_back(Person("����", 35));
	v2.push_back(Person("����", 45));
	v2.push_back(Person("����", 55));
	v2.push_back(Person("����", 65));
	sort(v1.begin(), v1.end(), sortByPersonAgeDescending());
	sort(v2.begin(), v2.end(), sortByPersonAgeDescending());
	vector<Person>v3;
	v3.resize(v1.size() + v2.size());//�����Զ�����������ͣ��ⲽҪ����
	//��Ȼ�ᱨ��cannot seek value initialized vector iterator
	//��Ϊv3û�г�ʼ����û��begin��
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin(), sortByPersonAgeDescending());
	//��begin1��end1��begin2��end2��begin3��
	printVector(v3);
}

void reverse_test() {
	//�Զ����������͵�reserve
	vector<Person>v1;
	v1.push_back(Person("��һ", 25));
	v1.push_back(Person("�Ŷ�", 15));
	v1.push_back(Person("����", 35));
	v1.push_back(Person("����", 45));
	v1.push_back(Person("����", 55));
	v1.push_back(Person("����", 65));
	sort(v1.begin(), v1.end(), sortByPersonAgeDescending());
	printVector(v1);
	reverse(v1.begin(), v1.end());
	printVector(v1);
	cout << endl;

}