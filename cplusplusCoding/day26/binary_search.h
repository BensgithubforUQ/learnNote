#pragma once
#include "vector_base.h"
#include <string>
using namespace std;

//binary_search 
//���ֲ���
/*����ָ��Ԫ�أ����ڷ���true�������ڷ���false*/
//ע�⣬�����������в����ã���������������ֻ����set��map��ʹ�ã�����ʹ���������������������ʹ�ã���Ҫע��������

void binary_search_test() {
	vector<int>v1;
	constructVectorWithSize(v1, 50);
	printVector(v1);
	bool flag = binary_search(v1.begin(), v1.end(), 9);
	if (flag) {
		cout << "the element with value 9 is existing" << endl;
	}
	else {
		sort(v1.begin(), v1.end(), greater<int>());//greater�����Լ�д���Ǹ�descending
		printVector(v1);
		flag = binary_search(v1.begin(), v1.end(), 9, greater<int>());//ע�⣬�����Ĭ�������ģ�����Ĭ�ϵ���������
		//����ǽ��򣬻�Ҫ������ϵ�º���������һ�²��ҹ���
		if (flag) {
			cout << "after sort, the element with value 9 is found" << endl;
		}
		else {
			cout << "the element with value 9 is not existing" << endl;
		}
	}
	
}