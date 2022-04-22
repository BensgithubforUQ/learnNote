#pragma once
#include "vector_base.h"
#include <string>
#include "find.h"
using namespace std;

void copy_test0() {
	//����ָ����Χ�ڵ�Ԫ�ص�����һ��������
	//copy��begin��end��destination��
	vector<int>v1, v2;
	constructVectorWithSize(v1, 10);
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), v2.end(), PrintInt_functor());
}

void replace_test0() {
	//��ָ�������ڵ�Ԫ�ظĳ���Ԫ��
	vector<int>v1;
	constructVectorWithSize(v1, 10);
	sort(v1.begin(), v1.end());//Ĭ������
	for_each(v1.begin(), v1.end(), printInt_function);
	cout << endl;
	//replace�滻
	if (count(v1.begin(), v1.end(), 9) != 0) {
		replace(v1.begin(), v1.end(), 9, 5);
		for_each(v1.begin(), v1.end(), printInt_function);
	}
	else {
		cout << "v1�У�û��9" << endl;
		for_each(v1.begin(), v1.end(), printInt_function);
	}
}

void replace_if_test0() {
	//��ָ�������ڵ�Ԫ�ذ����Զ�����򣬸ĳ���Ԫ��
	//��ָ�������ڵ�Ԫ�ظĳ���Ԫ��
	vector<int>v1;
	constructVectorWithSize(v1, 10);
	sort(v1.begin(), v1.end());//Ĭ������
	for_each(v1.begin(), v1.end(), printInt_function);
	cout << endl;
	//replace�滻
	if (count_if(v1.begin(), v1.end(), greaterFive()) != 0) {
		replace_if(v1.begin(), v1.end(), greaterFive(), 5);
		cout << "�Ѿ�������5�������滻��" << endl;
		for_each(v1.begin(), v1.end(), printInt_function);
	}
	else {
		cout << "v1�У�û�д���5����" << endl;
		for_each(v1.begin(), v1.end(), printInt_function);
	}
}

void swap_test0() {
	//ͬ�����͵�������Ԫ�ػ���
	vector<int>v1;
	constructVectorWithSize(v1, 10);
	vector<int>v2;
	constructVectorWithSize(v2, 20);
	printVector(v1);
	printVector(v2);
	cout << "v1 size " << v1.size() << " v2 size " << v2.size() << endl;
	//swap
	swap(v1, v2);
	printVector(v1);
	printVector(v2);
	cout << "v1 size " << v1.size() << " v2 size " << v2.size() << endl;
	//��size�����ˡ�
}

