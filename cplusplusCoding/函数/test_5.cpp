#include<iostream>
#include<string>
#include "myHead.h"
using namespace std;

//��������
//����һ���ӷ�����add
int add(int num1, int num2) {
	int sum = num1 + num2;
	return sum;
}

void swap(int num1,int num2) {
	int temp = 0;
	temp = num1;
	num1 = num2;
	num2 = temp;
}

int main() {
	int num1 = 0, num2 = num1;
	cin >> num1 >> num2;
	cout << add(num1, num2) << endl;
	cout << num1 << " " << num2 << endl;
	swapL(num1, num2);
	//�βθı䲻��ı�ʵ�Ρ�
	cout << num1 << " " << num2 << endl;
	return 0;
}