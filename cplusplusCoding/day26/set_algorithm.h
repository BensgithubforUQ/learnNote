#pragma once
#include "vector_base.h"
#include <string>

using namespace std;

void set_intersection_test() {
	//�����������Ľ���
	vector<int>v1, v2, v3;
	
	constructVectorWithSize(v1,10);

	constructVectorWithSize(v2,10);

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	printVector(v1);
	printVector(v2);
	v3.resize(min(v1.size(), v2.size()));//ȡС��

	vector<int>::iterator itEnd_intersection = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	//���ظ���������λ�ã����λ���ǽ������ֵ�ĩβ
	//ע�⣬ser_interactionҲֻ�ܶ��Ѿ����������ʹ��
	printVector(v3);
	for (vector<int>::iterator it = v3.begin(); it != itEnd_intersection; it++) {
		cout << *it << " ";
	}
	cout << endl;
	//���ߣ�ֱ�Ӳü�***************************************************************************************
	//ע�⣬���ﻹҪ������β����Ϊset_intersection�������intersection��������С
	//С�ڻ��ߵȱȽ�С�������Ĵ�С����˿��ܻ����ĩβ���0�����
	//��Ϊset_intersection�Ƕ���������㷨���м��㣬�������֪�����������У����Կ���resize
	//����ֻ��Ҫ�����������ж��ٸ�0��ȡ��Сֵ��Ȼ����resizeɾ��ĩβ��0
	int count_zero = min(count(v1.begin(),v1.end(),0), count(v1.begin(), v1.end(), 0));
	count_zero += count(v3.begin(), v3.end(), 0); //����v3���ж�����Ĭ�ϲ����0
	v3.resize(v3.size() - count_zero);
	printVector(v3);
	
}

//�������
void set_union_test() {
	vector<int>v1, v2, v3;

	constructVectorWithSize(v1, 10);

	constructVectorWithSize(v2, 10);

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	printVector(v1);
	printVector(v2);
	//��������������������������һģһ������ʱ��Ӧ����size���
	v3.resize(v1.size() + v2.size());
	auto itEnd_union = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	//��ӡһ�¿���
	printVector(v3);
	for_each(v3.begin(), itEnd_union,PrintInt_functor());
	//Ҳ����resize��

}

void set_difference_test() {
	vector<int>v1, v2, v3,v4;

	constructVectorWithSize(v1, 10);

	constructVectorWithSize(v2, 10);

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	printVector(v1);
	printVector(v2);
	//�����������Ҳ��size���
	v3.resize(v1.size() + v2.size());
	v4.resize(v1.size() + v2.size());
	auto itEnd_difference_base_v1 = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	//set_difference�ǻ��ڵ�һ��������
	auto itEnd_difference_base_v2 = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), v4.begin());
	//��ӡһ�¿���
	printVector(v3);
	printVector(v4);
	//for_each(v3.begin(), itEnd_difference_base_v2, PrintInt_functor());
	//Ҳ����resize��
	//�����пӣ��Ժ���ע���

}