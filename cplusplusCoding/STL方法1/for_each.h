#pragma once
#include "vector_base.h"
using namespace std;


void test_for_each0() {
	vector<int> v1;
	constructVectorWithSize(v1, 10);

	for_each(v1.begin(), v1.end(), PrintInt_functor());//for_each(������������������ӡ������)��
	
	cout << " " << endl;

	for_each(v1.begin(), v1.end(), PrintInt_functor());
	cout << endl;
}