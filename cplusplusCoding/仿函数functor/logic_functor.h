#pragma once
#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
�߼��º���
template <class T> bool logical_and<T> //�߼���
template <class T> bool logical_or<T> //�߼���
template <class T> bool logical_not<T> //�߼���
*/

/*�߼��º����ڿ����л������ò���*/
void prindVector(vector<bool> &v) {
	if (v.empty()) {
		cerr << "blank" << endl;
	}
	else {
		for (vector<bool>::iterator it = v.begin(); it != v.end(); it++) {
			if (*it) {
				cout << "true" << " ";
			}
			else {
				cout << "false" << " ";
			}
		}
		cout << endl;
	}
}

void test_logical_not() {
	//logical_not
	vector<bool> v;
	v.push_back(true);
	v.push_back(true);
	v.push_back(true);
	v.push_back(true);
	v.push_back(false);
	v.push_back(false);
	
	prindVector(v);
	vector<bool>v2;
	v2.resize(v.size());//Ҫ�ð����㷨��������ǰ���ٿռ䣬���Ҫ�õ�resize
	//���߼��Ƿº�������v1�е�Ԫ��ȡ����Ȼ��ŵ�v2��
	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
	prindVector(v2);
}