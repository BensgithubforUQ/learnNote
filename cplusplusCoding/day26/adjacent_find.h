#pragma once
#include "vector_base.h"
#include <string>
using namespace std;

//adjacent_find
//�������ڵ��ظ�Ԫ�أ���������Ԫ�صĵ�һ��λ�õĵ�����
//beg��ʼ������
//end����������

void adjacent_find_test() {
	//adjacent test
	vector<int>v1;
	constructVectorWithSize(v1, 50);
	vector<int>::iterator adjacent_it = adjacent_find(v1.begin(),v1.end());
	if (adjacent_it != v1.end()) {
		printVector(v1);
		cout <<"adjacent elements whose value is same: " << *adjacent_it << " " << *(adjacent_it + 1) << endl;
	}
	else {
		cout << "there are no adjacent elements which have same value" << endl;
	}
}