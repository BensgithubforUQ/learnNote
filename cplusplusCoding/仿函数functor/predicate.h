#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>
using namespace std;

/*��������Ϊbool�ķº�����Ϊν��
operator()����һ��������ΪһԪν��
operator()��������������Ϊ��Ԫν��*/

void printVector(const vector<int>& v) {
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
class greaterFive { //һԪν��
public:
	bool operator()(int n) {
		return n > 5;
	}
};

void predicate0() {
	vector<int>v1;
	srand((unsigned int)time(NULL));
	int temp = 0;
	for (int i = 0; i < 10; i++) {
		temp = rand() % 10 + 1;
			v1.push_back(temp);
	}

	//������û����5������
	//find_if(v1.begin(), v1.end(), greaterFive());//greaterFive()�����ĺ�������
	//���ص��ǵ�һ������ν�ʷ���ֵ�ĵ�����
	vector<int>::iterator it = find_if(v1.begin(), v1.end(), greaterFive());
	if (it == v1.end()) {
		cout << "��������5��Ԫ��" << endl;
	}
	else {
		cout <<"��" << it - v1.begin() << "����Ϊ:"<<v1[it - v1.begin()]<<", ֵ����5" << endl;
	}
}


class descending { //��Ԫν��
public:
	bool operator()(int n, int m) {
		return n > m;
	}
};


void predicate1() {
	vector<int>v1;
	srand((unsigned int)time(NULL));
	int temp = 0;
	for (int i = 0; i < 10; i++) {
		temp = rand() % 10 + 1;
		v1.push_back(temp);
	}
	//����
	sort(v1.begin(), v1.end(), descending());//����,��Ԫν��ʹ�÷������ö�Ԫν�ʸı��㷨�߼�
	//ע�⣬�ڶ��ڻ��Զ��������stl������ʱ����Ҫ�������Ͷ����ʱ����ö�Ԫν�����Ρ�
	printVector(v1);
}

