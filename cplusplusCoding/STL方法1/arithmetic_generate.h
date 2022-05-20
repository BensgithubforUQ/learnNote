#pragma once
#include "vector_base.h"
#include <string>
#include <numeric>
using namespace std;

//arithmetic generation
/*����С���㷨��ͷ�ļ�Ϊnumeric*/

void  accumulate_test() {
	vector<int>v1;
	int val = 0,sum = 0;
	constructVectorWithSize(v1, 100);
	
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
		sum += *it;
	}
	if (accumulate(v1.begin(), v1.end(), val) == sum) {//valΪ��ʼ���ۼ�ֵ��
		cout << "�ۼ�ֵΪ��" << sum << endl;
	}
	else {
		cerr << "�㷨��������" << endl;
	}
}

void  fill_test() {
	//����㷨����ָ��������ָ������������Ŀ��Ԫ��
	vector<int>v1;
	constructVectorWithSize(v1, 10);
	printVector(v1);
	v1.resize(20,5);//resize��������ʱ��ָ��ֵ����ָ����Ϊ0
	printVector(v1);
	fill((v1.begin() + 10), v1.end(), 10);
	printVector(v1);
}