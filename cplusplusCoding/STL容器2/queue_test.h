#pragma once
#pragma once
#include <iostream>
#include <queue>
using namespace std;

//��������
//�������Ƚ��ȳ������ݽṹ�����������ڣ�����һ���������ݣ�����һ�˳�����
//ֻ�ܶ���ͷfront�Ͷ�βback������,���Ҳ���ɱ�����
//�����ݱ���Ϊ���push�������ݱ���Ϊ����pop

void queue_test0() {
	//��ʼ��
	queue<int> q1,q3;
	//��ֵ
	if (q1.empty()) {//�Ƿ�Ϊ�գ�
		for (int i = 0; i < 10; i++) {
			q1.push(i);
			cout << "frontΪ��" << q1.front();
			cout << " backΪ��" << q1.back() << endl;
		}
	}
	
	//��������
	queue<int>q2(q1);
	q3 = q2;
	cout << "size of queue q3: " << q3.size() << endl;

	while (!q3.empty()) {
		cout << "frontΪ��" << q3.front();
		cout << " backΪ��" << q3.back() << endl;//�Ƚ��ȳ�������
		q3.pop();
	}
}