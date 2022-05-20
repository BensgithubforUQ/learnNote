#pragma once
#include <functional>
#include <iostream>
#include "predicate.h"
using namespace std;

/*��ϵ�º���
* template<class T> bool equal_to<T>;//����
* template<class T> bool not_equal_to<T>;//������
* template<class T> bool greater<T>;//����
* template<class T> bool greater_equal<T>;//���ڵ���
* template<class T> bool less<T>;//С��
* template<class T> bool less_equal<T>;//С�ڵ���

*/

//���򣬶�Ԫν��,��predicate���涨����ˣ�����ֱ����
//class descending {
//	bool operator()(int n1, int n2) {
//		return n1 > n2;
//	}
//};

void printVector(vector<int>&v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test_greater() {
	vector<int> v;
	v.push_back(19);
	v.push_back(29);
	v.push_back(13);
	v.push_back(9);
	v.push_back(1);
	//��ӡ
	printVector(v);
	//sort(v.begin(), v.end(), descending());//����Ҳ���Բ����Լ�д
	sort(v.begin(), v.end(), greater<int>());//��stl�ڽ��ĺ������󣬴��ڹ�ϵ�º���
	printVector(v);
}